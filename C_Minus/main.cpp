#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <fstream>

using namespace::std;

int token;            // current token
char* src, * old_src;  // pointer to source code string;
int poolsize;         // default size of text/data/stack
int line;             // line number

void next() {
    token = *src++;
    return;
}

void expression(int level) {
    // do nothing
}

void program() {
    next();                  // get next token
    while (token > 0) {
        printf("token is: %c\n", token);
        next();
    }
}


int eval() { // do nothing yet
    return 0;
}

int main(int argc, char** argv)
{
    char filename[51];        //file name
    int i;
    poolsize = 256 * 1024; // arbitrary size
    line = 1;
    gets_s(filename, 50);
    FILE* fd = fopen(filename, "r+");

    if (!fd) {
        printf("could not open(%s)\n", filename);
        return -1;
    }

    if (!(src = old_src = (char*)malloc(poolsize))) {
        printf("could not malloc(%d) for source area\n", poolsize);
        return -1;
    }

    // read the source file
    if ((i = fread(src, 1, poolsize - 1, fd)) <= 0) {
        printf("read() returned %d\n", i);
        return -1;
    }
    src[i] = 0; // add EOF character
    fclose(fd);

    program();
    return eval();
}