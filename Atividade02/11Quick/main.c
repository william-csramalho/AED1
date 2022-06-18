#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

int particiona(int *v, int e, int d, int n)
{
    int i, ii, pm, aux;
    for(i=e, pm=e-1; i<d; i++)
    {
        if(v[i] <= v[d])
        {
            pm++;
            aux = v[pm];
            v[pm] = v[i];
            v[i] = aux;
        }
        for(ii=0;ii<n-1;ii++){
            printf("%d ", v[ii]);
        }
        printf("%d\n", v[ii]);
    }
    aux = v[pm+1];
    v[pm+1] = v[d];
    v[d] = aux;
    for(ii=0;ii<n-1;ii++){
        printf("%d ", v[ii]);
    }
    printf("%d\n", v[ii]);
    return pm+1;
}

void quickSort(int *v, int e, int d, int n)
{
    //int i;
    int p;
    if(e < d)
    {
        p = particiona(v, e, d, n);
        quickSort(v, e, p-1, n);
        quickSort(v, p+1, d, n);
    }
}

void qSort(int *v, int n)
{
    quickSort(v, 0, n-1, n);
}

int main(){
    int n;
    int i;
    scanf("%d", &n);
    int v[n];

    for(i=0;i<n-1;i++){
        scanf("%d", &v[i]);
        printf("%d ", v[i]);
    }
    scanf("%d", &v[i]);
    printf("%d\n", v[i]);

    qSort(v, n);

    for(i=0;i<n-1;i++){
        printf("%d ", v[i]);
    }
    printf("%d\n", v[i]);
    return 0;
}

