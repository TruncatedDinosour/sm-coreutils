#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <aio.h>
#include <pwd.h>
#include <grp.h>

#define MX(cond)  \
    if (cond) {   \
        return 1; \
    }

static const char *get_username(void) {
    uid_t uid               = geteuid();
    const struct passwd *pw = getpwuid(uid);

    if (!pw) {
        printf("Failed to get passwd entry for UID %d\n", uid);
        return NULL;
    }

    return pw->pw_name;
}

static void *mmalloc(const unsigned long long bytes) {
    void *m_bytes = malloc(bytes);

    if (!m_bytes) {
        perror("malloc()");
        exit(33);
    }

    return m_bytes;
}

static int get_group_count(const char *username, const struct passwd *pw) {
    if (!pw) {
        printf("Unknown username: %s\n", username);
        return -1;
    }

    static int ngroups = 0;

    gid_t *groups = mmalloc(sizeof(*groups));

    getgrouplist(username, pw->pw_gid, groups, &ngroups);
    free(groups);

    return ngroups;
}

static void print_group_list(const char *username,
                             const struct passwd *pw,
                             const unsigned int group_count) {
    gid_t *groups = mmalloc(sizeof(*groups) * group_count);

    int _tmp_ngroups = (int)group_count;
    getgrouplist(username, pw->pw_gid, groups, &_tmp_ngroups);

    fputs(getgrgid(groups[0])->gr_name, stdout);
    for (unsigned int grp = 1; grp < group_count - 1; ++grp)
        printf(" %s", getgrgid(groups[grp])->gr_name);

    free(groups);
    puts("");
}

int main(int argc, char *argv[]) {
    const char *username = argc > 1 ? argv[1] : get_username();
    MX(!username);

    const struct passwd *pw = getpwnam(username);

    const int group_count = get_group_count(username, pw);
    MX(group_count == -1);

    print_group_list(username, pw, (const unsigned int)group_count);

    return 0;
}
