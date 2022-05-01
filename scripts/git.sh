#!/usr/bin/env sh

set -e

main() {
    sh ./scripts/tests.sh

    git add -A
    git commit -sa
    git push -u origin "$(git rev-parse --abbrev-ref HEAD)"
}

main "$@"
