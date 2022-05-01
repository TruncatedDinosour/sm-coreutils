# Adds debug info

export STRIP='true'
export AFLAGS='-g -gdwarf -O0'
export LDFLAGS='-O0 --compress-debug-sections=none --eh-frame-hdr --gc-sections'
export CFLAGS='-g -g3 -O0 -fno-eliminate-unused-debug-types'
export CXXFLAGS="$CFLAGS"
