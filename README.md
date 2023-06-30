# cshare_lib

This is a practise sample to write a simple customized shared library
and use by a sample locally.

With the used gcc commands,
the sample program uses both static linker and dynamic linker.

## Analysis
The static linker, ld, needs to know information of dynamic symbols in
libload.so during the linking stage; the dynamic linker, ld.so,
resolves dynamic symbols in libload.so after the program starts to run.

So, we need to pass two kinds of parameters to gcc:
- to ld: -I -L -l. If not set, ld cannot find symbols.
- to ld.so: -Wl,rpath. If not set, ld.so cannot not find symbols

## Question
Symbol resolution is performed by ld.so. Why ld needs dynamic symbol information?

This page asks the same question
[why need share lib during compile](https://stackoverflow.com/questions/48770958/why-do-we-need-the-shared-library-during-compile-time).

In summary, we **`must`** pass `-I, -L and -l` to gcc during compile/link time,
if the customized dynamic library doesn't locate in the default system
path, like pthread.

