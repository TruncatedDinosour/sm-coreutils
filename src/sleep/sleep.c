#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#define ERROR(cond, msg)                   \
    if (cond) {                            \
        fputs("sleep: " msg "\n", stderr); \
        exit(1);                           \
    }

static double query_to_seconds(const char *time) {
    const unsigned long long int string_len = strlen(time) - 1;
    const char suffix                       = time[string_len];

    if (suffix >= '0' && suffix <= '9')
        return atof(time);

    char prefix[string_len];
    static unsigned long long multiplier = 1;

    // Init prefix
    strcpy(prefix, time);
    prefix[string_len] = '\0';

    ERROR(prefix[0] == '-', "negative numbers are not allowed");

    switch (suffix) {
        case 's': break;
        case 'm': multiplier = 60; break;
        case 'h': multiplier = 60 * 60; break;
        case 'd': multiplier = 60 * 60 * 24; break;
        default: ERROR(1, "invalid suffix"); break;
    }

    return atof(prefix) * (const double)multiplier;
}

int main(int argc, char *argv[]) {
    ERROR(argc < 2, "not enough arguments");
    static double secs = 0.0;

    for (int aidx = 1; aidx < argc; ++aidx)
        secs += query_to_seconds(argv[aidx]);

    usleep((useconds_t)(secs * 1000000));
    return 0;
}
