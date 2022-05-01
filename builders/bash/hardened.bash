# Hardens coreuitls

export CFLAGS="-fstack-protector-strong -fstack-protector -fPIE -pie \
    -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2 -O2 \
    -Wno-unused-command-line-argument \
    -U_GLIBCXX_ASSERTIONS -D_GLIBCXX_ASSERTIONS -U_GLIBC_ASSERTIONS -D_GLIBC_ASSERTIONS \
    -fasynchronous-unwind-tables -fexceptions \
    -fpie -fpic -fstack-clash-protection \
    -fstack-protector-all -grecord-gcc-switches -fcf-protection -Werror=format-security \
    -Wl,-z,now"
export CXXFLAGS="$CFLAGS"
export LDFLAGS='-n --no-omagic -O2 -s -S -x'
