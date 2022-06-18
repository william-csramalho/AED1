#include <stdio.h>

int main(){
    long int x, y, idade;
    char c[255];
    scanf("%ld %s %ld", &x, c, &y);
    idade=x-y;
    printf("%s, voce completa %ld ", c, idade);
    //if(idade!=1)
        printf("anos de idade neste ano.\n");
    //else
    //    printf("ano de idade neste ano.\n");
    return 0;
}