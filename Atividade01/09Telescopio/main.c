#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

int main(){
    long int a, n, f, t;

    while(scanf("%ld", &a)!=EOF){
        t=0;
        scanf("%ld", &n);
        for(int i=0; i<n;i++){
            scanf("%ld", &f);
            t+=!!((f*a)/40000000L);
        }
        printf("%ld\n", t);
    }
    return 0;
}