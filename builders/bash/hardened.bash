# Hardens coreuitls

export CFLAGS="-fstack-protector-strong -fstack-protector -fPIE -pie \
    -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2 -O2 \
    -Wno-unused-command-line-argument \
    -U_GLIBCXX_ASSERTIONS -D_GLIBCXX_ASSERTIONS -U_GLIBC_ASSERTIONS -D_GLIBC_ASSERTIONS \
    -fasynchronous-unwind-tables -fexceptions \
    -fpie -fpic -fstack-clash-protection \
    -fstack-protector-all -g0 -grecord-gcc-switches -fcf-protection -Werror=format-security \
    --param ssp-buffer-size=4 -fstack-clash-protection -ftrapv \
    -Werror=format-security -Wconversion -Wsign-conversion \
    -Wl,-z,relro,-z,now,-z,noexecstack"

if [ "$CC" = clang ]; then
    CFLAGS+="  -arch x86_64 -mharden-sls=all -fcf-protection=full"
fi

export CXXFLAGS="$CFLAGS"
export LDFLAGS='-n --no-omagic -O2 -z relro -z now -z noexecstack'
