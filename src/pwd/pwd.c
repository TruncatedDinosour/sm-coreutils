#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>

int main(void) {
    static char cwd[PATH_MAX] = "";

    if (!getcwd(cwd, PATH_MAX)) {
        perror("getcwd()");
        return 1;
    }

    puts(cwd);
    return 0;
}
