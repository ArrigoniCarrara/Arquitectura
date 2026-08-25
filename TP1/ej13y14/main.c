#include <stdio.h>
#include <stdlib.h>

void dias(int num){

    char *vec[] = {"Domingo","Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
    int i;

    for (i = 0; i < 7; i++){
        if( (num & (1 << i)) >> i == 1)
            printf("%s\n", vec[i]);
    }
}

void weekday_set(int ind, int *c){

    *c = *c | (1 << ind);

}


int main()
{
    int num, ind;
    int c = 0;
    scanf(" %d", &ind);
    scanf(" %d", &c);
    weekday_set(ind, &c);
    printf("%d\n", c);
    dias(c);
    return 0;
}

