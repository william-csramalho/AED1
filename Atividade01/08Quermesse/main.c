#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

int main(){
    int n, v, t=1;

    do{
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%d", &v);
            if(v==i) printf("Teste %d\n%d\n\n", t++, v);
        }
    } while(n);

    return 0;
}