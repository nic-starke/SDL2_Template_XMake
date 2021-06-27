#!/bin/bash
echo "Running clang-format"
find ./src -iname *.h -o -iname *.c | xargs clang-format-11 -i -style=file