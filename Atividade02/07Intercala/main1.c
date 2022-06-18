#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

void intercala(int *v1, int n1, int *v2, int n2, int *vr){
    int i, i1=0, i2=0, n=n1+n2, aux;
        
    for(i=0;i<n;i++){
        if(i1<n1){
            if(i2<n2){
                if(v1[i1]<=v2[i2]){
                    vr[i]=v1[i1++];
                } else{
                    vr[i]=v2[i2++];
                }
            } else {
                 vr[i]=v1[i1++];
            }
        } else {
            vr[i]=v2[i2++];
        }
    }
}

int main(){
    int n1,n2,n;
    int i;
    scanf("%d %d", &n1, &n2);
    int v1[n1];
    int v2[n2];
    int vr[n1+n2];

    for(i=0;i<n1;i++){
        scanf("%d", &v1[i]);
    }
    for(i=0;i<n2;i++){
        scanf("%d", &v2[i]);
    }

    intercala(v1,n1,v2,n2,vr);

    for(i=0;i<n1+n2;i++){
        printf("%d\n", vr[i]);
    }
    return 0;
}

