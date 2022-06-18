#include <stdio.h>

int main(){
    long int x, y;
    char c[20];
    scanf("%ld %s %ld", &x, c, &y);
    printf("%s, voce completa %ld anos de idade neste ano.\n", c, x-y);
    return 0;
}