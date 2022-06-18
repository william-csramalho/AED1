#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if



void bubbleSort(int *v, int n)
{
    int i, j, k, aux, trocas;
    trocas=0;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(v[j] > v[j+1])
            {
                trocas++;
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;

                for(k=0;k<n-1;k++){
                    printf("%d ", v[k]);
                }
                printf("%d\n", v[k]);
            }
        }
    }

   for(k=0;k<n-1;k++){
        printf("%d ", v[k]);
    }
    printf("%d\n", v[k]);
    printf("Trocas: %d\n", trocas);

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
    bubbleSort(v, n);
    return 0;
}

