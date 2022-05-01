#!/usr/bin/env sh

set -e

main() {
    echo 'Testing GCC'
    CC=gcc CXX=g++ sh ./scripts/build.sh

    echo 'Testing Clang'
    CC=clang CXX=clang++ sh ./scripts/build.sh
}

main "$@"
