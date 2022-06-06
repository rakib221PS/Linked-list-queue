#include <stdlib.h>
#include <stdio.h>

void f() {
    printf("hello from C\n");
}

int fact(int x) {
    int r = x;
    while (x --> 1) {
        r *= x;
    }
    return r;
}
