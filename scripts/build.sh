#!/usr/bin/env sh

[ "$SH_DEBUG" ] && set -x
set -e

main() {
    rm -rf bin
    mkdir bin

    back="$(pwd)"

    for dir in src/*; do
        echo "Compiling: $dir"

        cd -- "$dir"

        rm -rf out
        mkdir out

        if [ -f 'Buildfile' ]; then
            sh Buildfile
        else
            echo "WARNING: $dir: No buildfile" >&2
        fi

        cp out/* "$back/bin"
        rm -rf out

        cd -- "$back"
    done
}

main "$@"
