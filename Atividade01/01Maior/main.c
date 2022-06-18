#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)

int main(){
    int n,no=iLOWEST(no);

    scanf("%d", &n);
    if(n>no) no=n;

    scanf("%d", &n);
    if(n>no) no=n;

    scanf("%d", &n);
    if(n>no) no=n;

    printf("%d eh o maior.\n", no);

    return 0;
}