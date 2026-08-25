#include <stdio.h>
#include <stdlib.h>

void main()
{
    unsigned int n;
    scanf("%hx", &n);

    printf("a) %04X\n", (n >> 8));
    printf("b) %04X\n", (n & 0x00FF));
    printf("c) %04X\n", (n & 0x0001));
    printf("d) %04X\n", (n >> 15));
    printf("e) %04X\n", (n >> 4));
    printf("f) %04X\n", (n & 0x000F));
}
