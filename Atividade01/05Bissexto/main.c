#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

int main(){
    int n;

    scanf("%d", &n);
    if(!(n%400)||((n%100)&&!(n%4)))
        printf("ANO BISSEXTO\n");
    else
        printf("ANO NAO BISSEXTO\n");

    return 0;
}