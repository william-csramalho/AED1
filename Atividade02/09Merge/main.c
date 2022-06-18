#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if



void intercala(int *v, int e, int m, int d)
{
    int esq_fim = m-1, i, j, iTemp;

    int vTemp[d-e+1];

    for(i=e, j=m, iTemp=0; i<=esq_fim && j<=d; iTemp++)
    {
        if(v[i] < v[j])
        {
            vTemp[iTemp] = v[i];
            i++;
        }
        else
        {
            vTemp[iTemp] = v[j];
            j++;
        }
    }

    for(;i<=esq_fim; i++, iTemp++)
    {
        vTemp[iTemp] = v[i];
    }

    for(;j<=d; j++, iTemp++)
    {
        vTemp[iTemp] = v[j];
    }

    for(i=e, j=0; i<=d; i++, j++)
    {
        v[i] = vTemp[j];
    }
}

void mergeSort(int *v, int e, int d, int n)
{
    int meio;
    int i;
    if(e < d)
    {
        meio = (e+d)/2;
        mergeSort(v, e, meio, n);
        mergeSort(v, meio+1, d, n);
        for(i=0;i<n-1;i++){
            printf("%d ", v[i]);
        }
        printf("%d\n", v[i]);
        intercala(v, e, meio+1, d);
    }
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
    mergeSort(v, 0, n-1, n);

    for(i=0;i<n-1;i++){
        printf("%d ", v[i]);
    }
    printf("%d\n", v[i]);
    return 0;
}

