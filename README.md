# sway.module_math

[![BCH compliance](https://bettercodehub.com/edge/badge/timcogames/sway.module_math?branch=master)](https://bettercodehub.com/)
[![Documentation](https://codedocs.xyz/timcogames/sway.module_math.svg)](https://codedocs.xyz/timcogames/sway.module_math/)

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
cmake -DBOOST_ROOT=/usr/local -DCMAKE_BUILD_TYPE=Release -DMODULE_MATH_ENABLE_TESTS=ON ../
```

Опция сборки | Тип | Описание | По умолчанию
:---|:---|:---|:---:
`BOOST_ROOT` | PATH | Путь до корневой директории Boost библиотеки | `-`
`MODULE_MATH_ENABLE_TESTS` | BOOL | Включает построение тестов | `OFF`

Запускаем сборку

```console
cmake --build .
```
