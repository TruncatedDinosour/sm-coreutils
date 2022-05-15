#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[]) {
    static unsigned char sep;
    static unsigned int envi = 0;

    if (argc >= 2) {
        if (argv[1][0] != '-')
            return 1;

        if (strcmp(argv[1], "-0") == 0 || strcmp(argv[1], "--null") == 0)
            sep = '\0';
        else {
            fprintf(stderr, "printenv: unknown argument '%s'\n", argv[1]);
            return 2;
        }
    } else
        sep = '\n';

    while (envp[envi])
        printf("%s%c", envp[envi++], sep);

    return 0;
}
