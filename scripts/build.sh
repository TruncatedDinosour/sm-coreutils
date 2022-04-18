#!/usr/bin/env sh

[ "$SH_DEBUG" ] && set -x
set -e

log() { echo " ${2:-*} $1"; }

main() {
    log 'Pre-build cleanup... '
    rm -rf bin
    mkdir bin
    log 'Cleanup finished'

    back="$(pwd)"

    log 'Starting compilation threads'
    for dir in src/*; do
        {
            bdir="$(basename -- "$dir")"

            log "Starting compilation thread: '$bdir'" '**'

            cd -- "$dir"

            if [ -f 'Buildfile' ]; then
                rm -rf out
                mkdir out

                sh Buildfile

                cp out/* -- "$back/bin"
                rm -rf out
            else
                log "WARNING: $bdir: No buildfile" '***' >&2
            fi

            cd -- "$back"

            log "Compilation thread '$bdir' finished" '**'
        } &
    done
    log 'Compilation threads created'

    log 'Waiting for compilation threads to finish'
    wait
    log 'Compilation threads finished'
}

main "$@"
