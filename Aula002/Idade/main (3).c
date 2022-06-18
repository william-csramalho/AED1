#include <stdio.h>

int main(){
    int x, y;
    char *c;
    scanf("%d %s %d", &x, c, &y);
    printf("%s, voce completa %d anos de idade neste ano.\n", c, x-y);
    return 0;
}