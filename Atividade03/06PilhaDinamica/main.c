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
    int chave;
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

struct Item * criaItem(int chave)
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
    struct Pilha *pilha = criaPilha();
    struct Item *it;
    int chave;
    char op;
    while(scanf("\n%c", &op) != EOF)
    {
        if(op == 'E')
        {
            scanf("%d", &chave);
            empilhar(pilha, criaItem(chave));
        }
        else if(op == 'D')
        {
            it = desempilhar(pilha);
            if(it != NULL)
            {
                printf("[%d]\n", it->chave);
                free(it);
            }
        }
        else if(op == 'M')
        {
            mostrarPilhaTopoBase(pilha);
        }
        else // B
        {
            mostrarPilhaBaseTopo(pilha);
        }
    }
    return 0;
}