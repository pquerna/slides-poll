#!/bin/sh

set -e

clang-format -style=google -i select_intro.c fd_set.c poll_intro.c

clang++ -c -o /dev/null fd_set.c

clang++ -c -o /dev/null select_intro.c

clang++ -c -o /dev/null poll_intro.c