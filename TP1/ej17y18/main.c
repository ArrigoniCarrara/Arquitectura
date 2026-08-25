#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mayus(char str[], int len){


    int i;

    for(i = 0; i < len; i++)
        str[i] &= 0xDF;


}

int integer(char str[], int len){

    int i = 0, signo = 1, aux, num = 0;

    if (str[0] == '-'){
        signo = -1;
        i = 1;
    }

    for( i; i < len; i++){

        aux = str[i] & 0x0F;
        num = num * 10 + aux;

    }

    return num * signo;
}

int main()
{
    char str[30];
    int len;
    scanf("%s", str);
    len = strlen(str);
    mayus(str, len);
    printf("%s\n", str);

    scanf("%s", str);
    len = strlen(str);
    printf("%d", integer(str, len));

    return 0;
}
//\n
