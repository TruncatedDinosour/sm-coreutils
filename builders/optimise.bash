# Adds optmisation flags

export AFLAGS='-O3'
export LDFLAGS='-O3 -flto'
export CFLAGS='-ffast-math -flto -march=native -O3'
export CXXFLAGS="$CFLAGS"
