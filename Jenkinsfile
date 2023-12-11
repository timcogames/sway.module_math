node {
    def SELECTED_ACTIVE_BRANCH = 'master'

    stage('Options') {
        SELECTED_ACTIVE_BRANCH = input(message: 'Select active branch', parameters: [
            [$class: 'ChoiceParameterDefinition', 
                choices: 'master\ndevelop', 
                name: 'Active branch', 
                description: 'Select option the relevant branch']
        ])
        echo "Active branch is ${SELECTED_ACTIVE_BRANCH}"
    }

    stage('Build') {
        git url: 'https://github.com/timcogames/sway.module_math.git', branch: "${SELECTED_ACTIVE_BRANCH}"
        sh 'git submodule update --init --recursive'
        sh 'mkdir -p build'
        dir('./build') {
            sh '/opt/homebrew/Cellar/cmake/3.27.9/bin/cmake -D GLOB_GTEST_ROOT_DIR=/Users/apriori85/Documents/Third-party/googletest -D GLOB_THIRD_PARTY_DIR=/Users/apriori85/Documents/Third-party -D MODULE_MATH_ENABLE_TESTS=ON -D MODULE_MATH_ENABLE_COVERAGE=ON ../'
            sh '/opt/homebrew/bin/cmake --build ./'
        }

        sh '/opt/homebrew/opt/lcov/bin/lcov --directory ./build/ --capture --output-file ./code_coverage.info -rc lcov_branch_coverage=1'
        sh '/opt/homebrew/opt/lcov/bin/genhtml code_coverage.info --branch-coverage --output-directory ./code_coverage_report/'
        publishHTML(target: [
            allowMissing: false,
            alwaysLinkToLastBuild: false,
            keepAll: true,
            reportDir: 'code_coverage_report',
            reportFiles: 'index.html',
            reportName: 'LCov Report'
        ])

        withCredentials([string(credentialsId: 'MODULE_MATH_CODECOV_TOKEN', variable: 'CODECOV')]) {
            sh 'curl -s https://codecov.io/bash | bash -s - -t $CODECOV || echo "Codecov failed to upload"'
        }
    }
}
