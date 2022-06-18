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
    struct Item *anterior, *proximo;
};

struct Lista
{
    struct Item *primeiro, *ultimo;
};



struct Lista * criaLista()
{
    struct Lista *l = (struct Lista *) malloc(sizeof(struct Lista));

    if(l != NULL)
    {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

struct Item * criaItem(int chave)
{
    struct Item *it = (struct Item *) malloc(sizeof(struct Item));

    if(it != NULL)
    {
        it->chave = chave;
        it->anterior = NULL;
        it->proximo = NULL;
    }
    return it;
}

int listaVazia(struct Lista *l)
{
    return l->primeiro == NULL && l->ultimo == NULL;
}

void inserir(struct Lista *l, struct Item *novo)
{
    struct Item *atual = l->primeiro;
    int igual=0;

    while(atual != NULL && atual->chave < novo->chave)
    {
        atual = atual->proximo;
    }

/*
    if(atual !=NULL){
        if(atual->chave==novo->chave)
        printf("========\r%d\n", atual->chave);
    }
*/


    //if(atual->chave!=novo->chave){
        if(atual != NULL) // inserindo o primeiro ou no meio
        {
            if(atual->chave!=novo->chave){
                if(atual->anterior != NULL) // no meio
                {
                    atual->anterior->proximo = novo;
                }
                else // o primeiro
                {
                    l->primeiro = novo;
                }
                novo->anterior = atual->anterior;
                atual->anterior = novo;
                novo->proximo = atual;
            }
        }
        else // inserindo no final ou no inicio de uma lista vazia
        {
            if(!listaVazia(l)) // no final
            {
                novo->proximo = l->ultimo->proximo; //*
                l->ultimo->proximo = novo;//*
            }
            else // no inicio
            {
                l->primeiro = novo;
            }
            novo->anterior = l->ultimo;
            l->ultimo = novo;
        }
    //}
}

struct Item * buscar(struct Lista *l, int chave)
{
    struct Item *it = l->primeiro;

    while(it != NULL && it->chave < chave)
    {
        it = it->proximo;
    }

    if(it != NULL && it->chave != chave)
    {
        it = NULL;
    }
    return it;
}

struct Item * remover(struct Lista *l, int chave)
{
    struct Item *atual = buscar(l, chave);

    if(atual != NULL)
    {
        if(atual->anterior != NULL) // eh meio
        {
            atual->anterior->proximo = atual->proximo;
        }
        else // eh primeiro
        {
            l->primeiro = atual->proximo;
        }
        if(atual->proximo != NULL) // eh meio
        {
            atual->proximo->anterior = atual->anterior;
        }
        else // eh ultimo
        {
            l->ultimo = atual->anterior;
        }
    }
    return atual;
}



void mostrarListaPrimeiroUltimo(struct Lista *l)
{
    struct Item *it = l->primeiro;

    while(it != NULL)
    {
        printf("%d ", it->chave);
        //printf("%d%s", it->chave, it->proximo!=NULL?" ":"\n");
        it = it->proximo;
    }
}

void mostrarListaUltimoPrimeiro(struct Lista *l)
{
    struct Item *it = l->ultimo;

    while(it != NULL)
    {
        printf("%d ", it->chave);
        //printf("%d%s", it->chave, it->anterior!=NULL?" ":"\n");
        it = it->anterior;
    }
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
        else if(op == 'E')
        {
            scanf("%d", &chave);
            it = remover(lista, chave);
            if(it != NULL)
            {
                //printf("item %d removido da lista\n", it->chave);
                free(it);
            }
        }
        /*
        else if(op == 'B')
        {
            scanf("%d", &chave);
            printf("item %d%slocalizado na lista\n", chave, buscar(lista, chave)!=NULL?" ":" nao ");
        }
        */
        else if(op == 'M')
        {
            mostrarListaPrimeiroUltimo(lista);
            printf("\n");
        }
        else // U
        {
            mostrarListaUltimoPrimeiro(lista);
            printf("\n");
        }
    }
    return 0;
}