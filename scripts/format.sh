#!/bin/bash

for file in "$@"; do
  if [[ "$file" == *.c || "$file" == *.h ]]; then
    echo "Formatting C file: $file"
    clang-format -style=file:.clang-format-c -i "$file"
  elif [[ "$file" == *.cpp || "$file" == *.hpp || "$file" == *.inl ]]; then
    echo "Formatting C++ file: $file"
    clang-format -style=file:.clang-format-cpp -i "$file"
  else
    echo "Unsupported file type: $file"
  fi
done
