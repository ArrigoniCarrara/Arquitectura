#include <stdio.h>
#include <stdlib.h>

void desencripto(short int num, int *aa, int *mm, int *dd){

    int flag = 0;
    *dd = num >> 11 & 0x1F;// Usa shift aritmetico debo ignorar todos los nuevos unos
    *mm = (num >> 7) & 0x00F;
    *aa = num & 0x007F;
    if (*aa > 50){
        *aa = 1900 + *aa;
        flag = 1;
    }
    else
        *aa = 2000 + *aa;
    printf("La fecha es: (%d-%d-%d)\n", *aa, *mm, *dd);
    if (flag)
        *aa -= 1900;
    else
        *aa -= 2000;
}

short int encripto(int aa, int mm, int dd){

    int num = 0;
    num = dd;
    num = ((((num << 4) | mm) << 7) | aa);
    return num;
}

int main()
{
    short int num;
    int aa, mm, dd;
    scanf("%hd", &num);
    desencripto(num, &aa, &mm, &dd);
    if (num == encripto(aa,mm,dd))
        printf("Funciona");

    return 0;
}
//\n
