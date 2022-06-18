#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

void insertionSort(int *v, int n)
{
    int chave, i, j;
    for(i=1; i<n; i++)
    {
        chave = v[i];
        j = i-1;
        while(j>=0 && v[j]>chave)
        {
            v[j+1] = v[j];
            v[j] = chave;
            j--;
        }
    }
}

int main(){
    int n1,n2,n;
    int i;
    scanf("%d %d", &n1, &n2);
    n=n1+n2;
    int v[n];

    for(i=0;i<n;i++){
        scanf("%d", &v[i]);
    }
    insertionSort(v, n);
    for(i=0;i<n;i++){
        printf("%d\n", v[i]);
    }
    return 0;
}

