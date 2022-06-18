#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

int main(){
    int n;
    char *m1, troca1=0, troca2=0, troca3=0, troca4=0;
    int j;
    int i;

    scanf("%d", &n);

    m1=(typeof(m1)) malloc(sizeof(char[n][n]));

    for(i=0;i<(n*n); i++) scanf("%1s", &m1[i]);
    troca3=1;
    troca4=1;
    for(i=0;i<n && !(troca1||troca2);i++){
        troca1=1;
        troca2=1;
        for(j=0; (j<(n-1)) && (troca1||troca2||troca3||troca4); j++){
            if(troca1){
                if(m1[j+n*i]=='-' || m1[j+n*i]!=m1[j+1+n*i]) {
                    troca1=0;
                }
            }
            if(troca2){
                if(m1[i+j*n]=='-' || m1[i+j*n]!=m1[i+n*(j+1)]) {
                    troca2=0;
                }
            }
            if(troca3){
                if(m1[j+n*j]=='-' || m1[j+n*j]!=m1[j+1+n*(j+1)]){
                    troca3=0;
                }
            }
            if(troca4){
                if(m1[n-1-j+n*j]=='-'|| m1[n-1-j+n*j]!=m1[n-j-2+n*(j+1)]){
                    troca4=0;
                }
            }
        }
        if(troca1){
            printf("%c venceu!\n", m1[j+n*i]);
            break;
        } else{
            if(troca2){
                printf("%c venceu!\n", m1[i+j*n]);
                break;
            } else {
                if(troca3){
                    printf("%c venceu!\n", m1[j+n*j]);
                    break;
                } else {
                    if(troca4){
                        printf("%c venceu!\n", m1[n-1-j+n*j]);
                        break;
                    }
                }
            }
        }
    }
    if(!(troca1||troca2||troca3||troca4)){
        printf("empate!\n");
    }
    free(m1);
    return 0;
}