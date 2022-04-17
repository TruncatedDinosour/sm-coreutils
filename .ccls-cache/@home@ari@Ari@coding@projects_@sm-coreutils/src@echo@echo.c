#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int idx = 1; idx < argc; ++idx) {
        fputs(argv[idx], stdout);

        if (idx + 1 < argc)
            putc(' ', stdout);
    }

    puts("");
    return 0;
}
