#include <stdio.h>

int main(){
    int x, y, idade;
    char c[100];
    scanf("%d", &x);
    scanf("%s", c);
    scanf("%d", &y);
    idade=x-y;
    printf("%s, voce completa %d anos de idade neste ano.\n", c, idade);
    return 0;
}