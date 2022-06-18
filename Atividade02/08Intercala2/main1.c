#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

void intercala(int *v1, int n1, int n2){
    int i, i1=0, i2=0, n=n1+n2, *v2;
    int aux[n];
    v2=v1+n1;
    
    for(i=0;i<n;i++){
        if(i1<n1){
            if(i2<n2){
                if(v1[i1]<=v2[i2]){
                    aux[i]=v1[i1++];
                } else{
                    aux[i]=v2[i2++];
                }
            } else {
                 aux[i]=v1[i1++];
            }
        } else {
            aux[i]=v2[i2++];
        }
    }
    for(i=0;i<n;i++){
        v1[i]=aux[i];
    }
}

int main(){
    int n1,n2;
    int i;
    scanf("%d %d", &n1, &n2);
    int n=n1+n2;
    int v[n];

    for(i=0;i<n;i++){
        scanf("%d", &v[i]);
    }

    intercala(v,n1, n2);

    for(i=0; i<n; i++){
        printf("%d\n", v[i]);
    }
    return 0;
}

