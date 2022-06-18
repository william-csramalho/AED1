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
    int chave, i, j, k, trocas, comparacoes, piorcaso,melhorcaso;
    trocas=0;
    comparacoes=0;
    for(i=1; i<n; i++)
    {
        chave = v[i];
        j = i-1;
        while(j>=0 && v[j]>chave)
        {
            trocas++;
            v[j+1] = v[j];
            v[j] = chave;
            j--;
            for(k=0;k<n-1;k++){
                printf("%d ", v[k]);
            }
            printf("%d\n", v[k]);
        }
    }
    for(k=0;k<n-1;k++){
        printf("%d ", v[k]);
    }
    printf("%d\n", v[k]);
    printf("Trocas:%d\n", trocas);
    piorcaso=(n*n-n)/2;
    melhorcaso=n-1;
    if(trocas<=melhorcaso) printf("MELHOR CASO\n");
    elif(trocas>=piorcaso) printf("PIOR CASO\n");
    else printf("CASO ALEATORIO\n");
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
    insertionSort(v, n);
    return 0;
}

