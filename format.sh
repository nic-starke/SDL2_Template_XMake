#!/bin/bash
echo "Running clang-format"
find ./ -iname *.h -o -iname *.cpp | xargs clang-format-11 -i -style=file