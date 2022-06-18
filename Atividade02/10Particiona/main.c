#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

int particiona(int *v, int p, int n)
{
    int i, pm, aux;
    aux=v[n-1];
    v[n-1]=v[p];
    v[p]=aux;
    for(i=0, pm=-1; i<n-1; i++)
    {
        if(v[i] <= v[n-1])
        {
            pm++;
            aux = v[pm];
            v[pm] = v[i];
            v[i] = aux;
        }

    }
    aux = v[pm+1];
    v[pm+1] = v[n-1];
    v[n-1] = aux;
    return pm+1;
}


int main(){
    int n;
    int i;
    int p;
    scanf("%d", &n);
    scanf("%d", &p);
    int v[n];

    for(i=0;i<n-1;i++){
        scanf("%d", &v[i]);
    }
    scanf("%d", &v[i]);

    p=particiona(v, p, n);

    for(i=0;i<n;i++){
        printf("%d\n", v[i]);
    }
    return 0;
}

