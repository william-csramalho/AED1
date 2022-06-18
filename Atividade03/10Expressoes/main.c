#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

struct Item
{
    char chave;
    struct Item *anterior;
};

struct Pilha
{
    struct Item *topo;
};

struct Pilha * criaPilha()
{
    struct Pilha *p = (struct Pilha*) malloc(sizeof(struct Pilha));
    if(p != NULL)
    {
        p->topo = NULL;
    }
    return p;
}

struct Item * criaItem(char chave)
{
    struct Item *it = (struct Item*) malloc(sizeof(struct Item));
    if(it != NULL)
    {
        it->chave = chave;
        it->anterior = NULL;
    }
    return it;
}

int pilhaVazia(struct Pilha *p)
{
    return p->topo == NULL;
}

void empilhar(struct Pilha *p, struct Item *novo)
{
    novo->anterior = p->topo;
    p->topo = novo;
}

struct Item * desempilhar(struct Pilha *p)
{
    struct Item *it = p->topo;
    if(!pilhaVazia(p)) // if(p->topo != NULL) if(it!=NULL)
    {
        p->topo = p->topo->anterior;
    }
    return it;
}

void mostrarPilhaTopoBase(struct Pilha *p)
{
    struct Item *it = p->topo;
    while(it != NULL)
    {
        printf("%d%s", it->chave, it->anterior!=NULL?" ":"\n");
        it = it->anterior;
    }
}

void mostrarPilhaBaseTopo(struct Pilha *p)
{
    struct Pilha *tmpPilha = criaPilha();
    struct Item *it = p->topo;

    while(it != NULL)
    {
        empilhar(tmpPilha, criaItem(it->chave));
        it = it->anterior;
    }

    while(!pilhaVazia(tmpPilha))
    {
        it = desempilhar(tmpPilha);
        printf("%d%s", it->chave, !pilhaVazia(tmpPilha)?" ":"\n");
        free(it);
    }
    free(tmpPilha);
}

int main()
{
    struct Pilha *pilha;
    struct Item *it;
    int chave;
    char op;
    int n;
    int passou;
    char texto[100010];

    scanf("%d\n", &n);

    while(n--){
        pilha = criaPilha();
        passou=1;
        scanf("%s", texto);
        for(int i=0; texto[i]!='\0' && passou; i++){
            switch(texto[i]){
                case '{':
                case '[':
                case '(': {
                    empilhar(pilha, criaItem(texto[i]));
                } break;

                default:{
                    it=desempilhar(pilha);
                    if(it!=NULL ){
                        switch(texto[i]){
                            case '}':{
                                passou=it->chave=='{';
                            }break;
                            case ']':{
                                passou=it->chave=='[';
                            }break;
                            case ')':{
                                passou=it->chave=='(';
                            }break;
                        }
                        free(it);
                    } else {
                        passou=0;
                    }
                }
            }
        }

        if(pilhaVazia(pilha)&&passou){
            printf("S\n");
        } else {
            printf("N\n");
        }

        free(pilha);
    }

    return 0;
}