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
cmake -DCMAKE_BUILD_TYPE=Release ../
```

Опция сборки | Описание | По умолчанию
:---|:---|:---:
`ENABLE_TESTS` | Включает построение тестов | `OFF`

Запускаем сборку

```console
cmake --build .
```
