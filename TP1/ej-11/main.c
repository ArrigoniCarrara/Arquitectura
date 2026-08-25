#include <stdio.h>
#include <stdlib.h>
#define BITS 32

void retornostring(int n, char* s) {

    int i, desplazamiento;

    for (i = 0; i < BITS; i++) {
        desplazamiento = (BITS - 1) - i;

        if ((n >> desplazamiento) & 1)
            s[i] = '1';
        else
            s[i] = '0';
    }

    s[BITS] = '\0';
}

void main() {
    int n;
    char s[BITS + 1];

    if (scanf("%d", &n) == 1) {
        retornostring(n, s);
        printf("%s\n", s);
    }
}
