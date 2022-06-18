#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

int main(){
    int n, q, t;//, *m2;
    char *m1, m2[26], troca;

    scanf("%d", &n);

    m1=(typeof(m1)) malloc(n*sizeof(int[26]));

    for(int i=0;i<n; i++) scanf("%s", &m1[i*26]);

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
    free(m1);

    return 0;
}