# Sm coreutils

> Small, robust and fast core utilities in user-space for x86_64 Linux

# License

Copylefted under the [CC BY-SA 2.0 license](https://creativecommons.org/licenses/by-sa/2.0/)

# Config

## Env vars:

- `CC` = C compiler
- `AC` = Assembly compiler
- `LD` = Linker
- `STRIP` = Stripper
- `AFLAGS` = Extra assembly flags
- `CFLAGS` = Extra C flags
- `STRIPFLAGS` = Extra stripper flags
- `LDFLAGS` = Extra linker flags
- `CXX` = C++ compiler
- `CXXFLAGS` = Extra C++ flags

# Requirements for building

- Nasm copiler
- GCC or any other C compiler
- Binutils
- A binary linker
- Any x86_64 computer running Linux

# Contributing

- Follow this build structure:

`src/{util}/{Buildfile,...}`

> Buildfile is a POSIX sh script to compile your code,
> it's output should go into `out` directory which will automatically
> be created

- Make your utilities small and fast

> Use compiler flags, stripping, better code
> to make them fast and small

# Getting started

## Install

```bash
$ su -c './setup/setup.sh install'
```

## Uninstall

```bash
$ su -c './setup/setup.sh uninstall'
```

# Progress

See [PROGRESS.md](/PROGRESS.md)
