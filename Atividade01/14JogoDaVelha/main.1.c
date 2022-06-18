#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

int main(){
    int n;//, *m2;
    char *m1, troca;
//    printf("%ld\n", sizeof(char[10][10]));

    scanf("%d", &n);

    m1=(typeof(m1)) malloc(sizeof(char[n][n]));

    for(int i=0;i<((n+1)*(n+1)); i++) scanf("%hhu", &m1[i]);

    for(int i=0;i<n;i++){
        int j;
        unsigned char troca1, troca2;

        troca1=1;
        troca2
        for(j=0; (j<(n-1)) && troca; j++){
            if(m1[j+n*i]=='-' || m1[j+n*i]!=m1[j+1+n*i]) {
                troca=0, break;
            }
        }
        if(troca){
            printf("%c venceu!\n", m1[j+n*i]);
            return 0;
        }
        troca=1;
        for(j=0; (j<(n-1)) && troca; j++){
            if(m1[n+j*i]=='-' || m1[n+j*i]!=m1[n+1+j*i]) {
                troca=0, break;
            }
        }
        if(troca){
            printf("%c venceu!\n", m1[n+j*i]);
            return 0;
        }
    }
    /*
    scanf("%d", &q);

    for(int i=0; i<q; i++){
        scanf("%s", m2);
        t=0;
        for(int j=0;(j<n); j++){
            troca=1;
            for(int k=0; (k<26); k++){
                if(m2[k]!=m1[j*26+k]){
                    troca=0;
                    break;
                }
                if(m2[k]=='\0' && m1[j*26+k]=='\0') break;
            }
            if(troca) t++;
        }
        printf("%d\n", t);
    }
    */
    free(m1);


    return 0;
}