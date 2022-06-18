#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

int main(){
    int t, a, b;

    scanf("%d", &t);
    scanf("%d", &a);
    scanf("%d", &b);

    if((t-a)>=b)
        printf("Farei hoje!\n");
    else
        printf("Deixa para amanha!\n");

    return 0;
}