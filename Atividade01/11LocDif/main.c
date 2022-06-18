#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *vetorV, *vetorW, i, j, cont, tamanho;
    vetorV = (int*) malloc(n * sizeof(int));
    vetorW = (int*) malloc((n+1) * sizeof(int));
    unsigned char quebra=1;

    scanf("%d", &n);
    tamanho = n;

    for(i=0; i<n; i++)
    {
        scanf("%d", &vetorV[i]);
    }

    for(i=0; i<(n+1); i++)
    {
        scanf("%d", &vetorW[i]);
    }

    for(i = 0; (i<n)&&quebra; i++)
    {
        cont = 0;
        for(j = 0; (j<(n+1))&&quebra; j++)
        {
            if(vetorW[j] != vetorV[i])
            {
                cont++;

                if(cont >= tamanho)
                {
                    printf("%d\n", vetorW[j]);
                    quebra=0;
                }
            }
        }

    }

    return 0;

}