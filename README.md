# PreProcessor
My own simple version of a preprocessor.
My preprocessor can be given any number of files: ./tpp file1.c file2.c file3.c ... fileN.c, and should process all of them in sequence.

For each .c file given, our preprocessor will read it line by line, and whenever it sees an include statement, i.e. #include "header.h", it will replace that line with the actual contents of header.h. For each .c file, you should write the preprocessed code to a corresponding .i file. E.g. ./tpp hello.c test.c would produce hello.i and test.i in the same directory.

Example:
:: test.c
#include "vm.h"
int main()
{
    ...
}

:: vm.h
#include "hello.h"
#define VAL 3
int foo(int v);


:: hello.h
int bar(int a, int b);


With the three files above, if we run ./tpp test.c, the output will be test.i as follows:

int bar(int a, int b);

#define VAL 3
int foo(int v);

int main()
{
    ...
}
