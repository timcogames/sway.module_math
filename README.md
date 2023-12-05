# sway.module_math

[![codecov][codecov-svg]][codecov-url] [![Documentation][codedocs-svg]][codedocs-url] [![License][license-svg]][license-url]

## Зависимости

[glm (Временная зависимость)](https://github.com/g-truc/glm)\
[cmake v3.14.3](https://cmake.org/files/v3.14)\
[googletest](https://google.github.io/googletest/)

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
cmake -D GLOB_THIRD_PARTY_DIR=/Users/<USER_NAME>/Documents/Third-party \
      -D GLOB_GTEST_ROOT_DIR=/Users/<USER_NAME>/Documents/Third-party/googletest \
      -D MODULE_MATH_ENABLE_TESTS=ON ../
```

Опция сборки | Тип | Описание | По умолчанию
:---|:---|:---|:---:
`GLOB_THIRD_PARTY_DIR` | PATH | Путь до корневой директории Other библиотек | `-`
`GLOB_EMSCRIPTEN_PLATFORM` | BOOL | Использует Emscripten компилятор | `OFF`
`GLOB_EMSCRIPTEN_USE_BINDINGS` | BOOL | Использует Emscripten привязки для функций | `OFF`
`GLOB_EMSCRIPTEN_ROOT_DIR` | PATH | Путь до корневой директории Emscripten библиотеки | `-`
`GLOB_BOOST_ROOT_DIR` | PATH | Путь до корневой директории Boost библиотеки (Не используется) | `-`
`GLOB_GTEST_ROOT_DIR` | PATH | Путь до корневой директории GTest библиотеки | `-`

Опция сборки | Тип | Описание | По умолчанию
:---|:---|:---|:---:
`MODULE_MATH_ENABLE_COVERAGE` | BOOL | Включает поддержку сбора данных о покрытии кода тестами | `OFF`
`MODULE_MATH_ENABLE_TESTS` | BOOL | Включает построение тестов | `OFF`

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
