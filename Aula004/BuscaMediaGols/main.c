#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nomejogador[51];
    int qtdgols;
} tJogador;

typedef struct{
    char nometime[51];
    tJogador* jogadores;
} tTime;

int main(){
    int* v;
    tTime* times;
    int n;

    scanf("%d", &n);
    times = (tTime * ) malloc(n*sizeof(tTime));
    for(int i=0; i<n;i++){
        int totalgols=0, qtdjogador, mediagols;
        scanf("%s", times[i].nometime);
        scanf("%d", &qtdjogador);

        times[i].jogadores = (tJogador*) malloc(qtdjogador * sizeof(tJogador));
        for(int j=0; j<qtdjogador; j++){
            int qtdgols;
            scanf("%s", times[i].jogadores[j].nomejogador);
            scanf("%d", &qtdgols);
            times[i].jogadores[j].qtdgols=qtdgols;
            totalgols+=qtdgols;
        }

        mediagols=totalgols/qtdjogador;

        for(int j=0; j<qtdjogador; j++){
            if(times[i].jogadores[j].qtdgols>mediagols){
                printf("[%s] %s\n", times[i].nometime, times[i].jogadores[j].nomejogador);
            }
        }
    }


    return 0;
}