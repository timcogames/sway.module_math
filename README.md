# sway.module_math

[![codecov][codecov-svg]][codecov-url] [![Documentation][codedocs-svg]][codedocs-url] [![License][license-svg]][license-url]

### Клонирование проекта

```console
git clone --recursive https://github.com/timcogames/sway.module_math.git
```

### Сборка проекта

Создаем директорию build и переходим в неё

```console
mkdir build && cd ./build
```

Конфигурируем проект для сборки

```console
cmake -DCUSTOM_THIRDPARTY_DIR=/Users/apriori85/Documents/Third-party -DMODULE_MATH_ENABLE_TESTS=ON -DCUSTOM_GTEST_ROOT_DIR=/Users/apriori85/Documents/Third-party/googletest ../
```

Опция сборки | Тип | Описание | По умолчанию
:---|:---|:---|:---:
`MODULE_MATH_ENABLE_COVERAGE` | `BOOL` | Включает поддержку сбора данных о покрытии кода тестами | `OFF`
`MODULE_MATH_ENABLE_TESTS` | `BOOL` | Включает построение тестов | `OFF`
`CUSTOM_GTEST_ROOT_DIR` | `PATH` | Путь до корневой директории Google библиотеки | `-`

Запускаем сборку

```console
cmake --build ./
```

[codecov-svg]: https://codecov.io/gh/timcogames/sway.module_math/branch/master/graph/badge.svg
[codecov-url]: https://codecov.io/gh/timcogames/sway.module_math
[codedocs-svg]: https://codedocs.xyz/timcogames/sway.module_math.svg
[codedocs-url]: https://codedocs.xyz/timcogames/sway.module_math/
[license-svg]: https://img.shields.io/github/license/mashape/apistatus.svg
[license-url]: LICENSE
