#include <stdio.h>

int main(){
    int x, y, divi,rest;
    scanf("%d %d", &x, &y);
    divi=x/y;
    rest=x%y;
    printf("%d %d\n", divi, rest);

    return 0;
}