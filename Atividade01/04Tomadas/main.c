#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)

int main(){
    int n, t=0;

    scanf("%d", &n);
    t+=n;
    scanf("%d", &n);
    t+=n-1;
    scanf("%d", &n);
    t+=n-1;
    scanf("%d", &n);
    t+=n-1;

    printf("%d\n", t);
    return 0;
}