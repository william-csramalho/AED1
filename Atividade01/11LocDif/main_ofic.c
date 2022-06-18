#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

int main(){
    int n, *m1, m2;//, *m2;
    char troca=0;

    scanf("%d", &n);

    m1=(typeof(m1)) malloc(n*sizeof(int));

    for(int i=0;i<n; i++) scanf("%d", &m1[i]);

    for(int i=0;(i<n) && (!troca); i++){
        scanf("%d", &m2);
        troca=1;
        for(int j=0;(j<n)&&troca; j++){
            if(m2==m1[j]) troca=0;
        }
    }

    if(!troca){
        scanf("%d", &m2);
    }
    printf("%d\n", m2);
    free(m1);

    return 0;
}