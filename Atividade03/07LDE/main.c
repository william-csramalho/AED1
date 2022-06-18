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
    struct Item *proximo;
};

struct Lista
{
    struct Item *inicio;
};

struct Lista * criaLista()
{
    struct Lista *l = (struct Lista *) malloc(sizeof(struct Lista));

    if(l != NULL)
    {
        l->inicio = NULL;
    }
    return l;
}

struct Item * criaItem(int chave)
{
    struct Item *it = (struct Item *) malloc(sizeof(struct Item));

    if(it != NULL)
    {
        it->chave = chave;
        it->proximo = NULL;
    }
    return it;
}

void inserir(struct Lista *l, struct Item *novo)
{
    struct Item *anterior = NULL, *atual = l->inicio;
    int achei = 0, igual=0;

    while(atual != NULL && !achei && !igual)
    {
        igual=atual->chave==novo->chave;
        if(atual->chave > novo->chave)
        {
            achei = 1;
        }
        else
        {
            anterior = atual;
            atual = atual->proximo;
        }
    }

    if(!igual){

        if(anterior != NULL)
        {
            anterior->proximo = novo;
        }
        else
        {
            l->inicio = novo;
        }
        novo->proximo = atual;
    }
}

struct Item * remover(struct Lista *l, int chave)
{
    struct Item *anterior = NULL, *atual = l->inicio;

    while(atual != NULL && atual->chave < chave)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if(atual != NULL && atual->chave == chave)
    {
        if(anterior != NULL)
        {
            anterior->proximo = atual->proximo;
        }
        else
        {
            l->inicio = atual->proximo;
        }
    }
    else
    {
        atual = NULL;
    }
    return atual;
}

struct Item * buscar(struct Lista *l, int chave)
{
    struct Item *it = l->inicio;

    while(it != NULL && it->chave < chave )
    {
        it = it->proximo;
    }

    if(it != NULL && it->chave != chave)
    {
        it = NULL;
    }
    return it;
}

void mostrar(struct Lista *l)
{
    struct Item *it = l->inicio;

    while(it != NULL)
    {
        printf("%d%s", it->chave, it->proximo!=NULL?" ":"\n");
        it = it->proximo;
    }
}

void desalocarLista(struct Lista *l)
{
    struct Item *it = l->inicio, *proximo;
    while(it != NULL)
    {
        proximo = it->proximo;
        free(it);
        it = proximo;
    }
    free(l);
}

int main()
{
    struct Lista *lista = criaLista();
    struct Item *it;
    int chave;
    char op;

    while(scanf("\n%c", &op) != EOF)
    {
        if(op == 'I')
        {
            scanf("%d", &chave);
            inserir(lista, criaItem(chave));
        }
        else if(op == 'R')
        {
            scanf("%d", &chave);
            it = remover(lista, chave);
            if(it != NULL)
            {
                //printf("item %d removido da lista\n", it->chave);
                free(it);
            }
        }
        else if(op == 'B')
        {
            scanf("%d", &chave);
            printf(buscar(lista, chave)!=NULL?"SIM\n":"NAO\n");
        }
        else // M
        {
            mostrar(lista);
        }
    }
    desalocarLista(lista);
    return 0;
}