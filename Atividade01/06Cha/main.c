#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

int main(){
    int cha, chute, t=0;

    scanf("%d", &cha);

    scanf("%d", &chute);
    t+=chute==cha;
    scanf("%d", &chute);
    t+=chute==cha;
    scanf("%d", &chute);
    t+=chute==cha;
    scanf("%d", &chute);
    t+=chute==cha;
    scanf("%d", &chute);
    t+=chute==cha;

    printf("%d\n", t);

    return 0;
}