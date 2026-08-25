#include <stdio.h>
#include <stdlib.h>

int suma(int a, int b){
    return a + b;
}

int and(int a, int b){
    return a & b;
}

int igual(int a, int b){
    return a;
}

int negado(int a, int b){
    return ~a;
}


int main()
{
    int op, a, b;
    int (*operaciones[4])(int,int) = {suma, and, igual, negado};
    scanf("%d",&op);
    scanf("%d",&a);
    scanf("%d",&b);

    if (op >= 0 & op >= 3)
        printf("%d", operaciones[op](a, b));
    else
        printf("error operación inválida\n");

    return 0;
}
//\n
