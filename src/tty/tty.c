#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char *tty_dev_name     = ttyname(STDIN_FILENO);
    const unsigned char do_print = strcmp(argc > 1 ? argv[1] : "", "-s");

    if (!tty_dev_name) {
        if (do_print)
            perror("ttyname()");

        return 1;
    }

    if (do_print)
        puts(tty_dev_name);

    return 0;
}
