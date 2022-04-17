#!/usr/bin/env sh

[ "$SH_DEBUG" ] && set -x
set -e

log() { echo " * $1"; }
slog() {
    log "$1"
    log 'Sleeping 5 seconds...'
    sleep 5
}

usage() {
    {
        echo "Usage: $0 <subcommand>"
        echo
        echo 'install               install all coreutils'
        echo 'uninstall             uninstall all coreutils'
        echo 'update                update existing coreutils'
    } >&2
}

main() {
    [ "$(id -u)" != 0 ] && log 'Run me as root!' >&2 && exit 1
    export INSTALL_INTO="${INSTALL_INTO:-/usr/sm}"

    case "$1" in
    install)
        log 'Building coreutils...'

        chmod +x ./scripts/build.sh
        ./scripts/build.sh

        slog "Installing everything into $INSTALL_INTO"

        rm -rfv -- "$INSTALL_INTO"
        cp -vr bin -- "$INSTALL_INTO"

        log 'Done!'
        log 'Now add this to your bashrc or whatever shell you use:'
        log "export PATH=\"$INSTALL_INTO:\$PATH\""
        ;;
    uninstall)
        slog "Removing $INSTALL_INTO..."
        rm -rfv -- "$INSTALL_INTO"
        ;;
    update)
        main uninstall
        main install
        ;;
    *) usage ;;
    esac
}

main "$@"
