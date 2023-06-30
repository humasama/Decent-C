# cshare_lib

This is a practise sample to write a simple customized shared library
and use by a sample locally.

The sample program uses load() function defined in libload.so.

## Default GCC Command
The static linker, ld, needs to know information of dynamic symbols in
libload.so during the linking stage; the dynamic linker, ld.so,
resolves dynamic symbols in libload.so after the program starts to run.

So, we need to pass two kinds of parameters to gcc:
- to ld: -I -L -l. If not set, ld cannot find symbols.
- to ld.so: -Wl,rpath. If not set, ld.so cannot not find symbols

### Question
Symbol resolution is performed by ld.so. Why ld needs dynamic symbol information?

### Answer
This page asks the same question
[why need share lib during compile](https://stackoverflow.com/questions/48770958/why-do-we-need-the-shared-library-during-compile-time).

In summary, we **must** pass `-l` to ld, even if the symbols are dynamic
symbols.
- If the used dynamic library is in the default system path, like pthread,
we don't need to pass `-L and -I`;
- Otherwise, for customized libraries, we must pass `-I -L -l` to ld.

## How to avoid passing -l, -I and -L during compile?
We need `weak symbol`, and here are the steps:
- In src/load.c, claim weak_load() is a weak symbol (`#pragma weak weak_load`);
- In sample, declare weak_load() as a weak symbol.

Note that we must explicitly resolve weak symbols.
we must load its located dynamic library and search for the symbols' VA.
Therefore, we have two methods to complete the above work:
1. use dlopen() to manually resolve the symbols;
2. inform ld.so to load the symbols' dynamic library, then ld.so can
   resolves the symbols.

In the sample, we use the method #1.

## How to use
1. Use weak symbols.
```
cd ./src
make type=weak
cd ./sample
make type=weak
./execve YOUT_PROGRAM
```
2. Use strong symbols.
```
cd ./src
make
cd ./sample
make
./execve YOUT_PROGRAM
```
