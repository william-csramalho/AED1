#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int chave;
};

struct Lista
{
    struct Item *itens;
    int tamanho, quantidade;
};

struct Item criaItem(int chave)
{
    struct Item it;
    it.chave = chave;
    return it;
}

struct Lista criaLista(int n)
{
    struct Lista l;
    l.itens = (struct Item*) malloc(n * sizeof(struct Item));
    if(l.itens != NULL)
    {
        l.quantidade = 0;
        l.tamanho = n;
    }
    return l;
}

int listaCheia(struct Lista l)
{
    return l.quantidade == l.tamanho;
}

void inserirLista(struct Lista *l, struct Item novo)
{
    int i, achei, j, igual;
    if(!listaCheia(*l))
    {
        achei = 0;
        i = 0;
        igual=0;
        while(i<l->quantidade && !achei && !igual)
        {
            igual=l->itens[i].chave == novo.chave;
            if(l->itens[i].chave > novo.chave)
            {
                achei = 1;
            }
            else
            {
                i++;
            }
        }
        if(!igual){
            for(j=l->quantidade-1; j>=i; j--)
            {
                l->itens[j+1] = l->itens[j];
            }
            l->itens[i] = novo;
            l->quantidade++;
        }
    }
}

void mostrarLista(struct Lista l)
{
    int i;
    for(i=0; i<l.quantidade; i++)
    {
        printf("%d\n", l.itens[i].chave);
    }
}

int buscarLista(struct Lista l, struct Item it)
{
    int esq = 0, dir = l.quantidade-1, meio;
    while(esq <= dir)
    {
        meio = (esq+dir)/2;
        if(l.itens[meio].chave == it.chave)
        {
            return meio;
        }
        else if(l.itens[meio].chave > it.chave)
        {
            dir = meio-1;
        }
        else
        {
            esq = meio+1;
        }
    }
    return -1;
}

int removerLista(struct Lista *l, struct Item rem)
{
    int j, i = buscarLista(*l, rem);
    if(i != -1)
    {
        for(j=i; j<l->quantidade-1; j++)
        {
            l->itens[j] = l->itens[j+1];
        }
        l->quantidade--;
    }
    return i;
}

int main()
{
    struct Lista lista;
    int n, chave;
    char op;
    scanf("%d", &n);
    lista = criaLista(n);
    while(scanf("\n%c", &op) != EOF){
        if(op == 'I')
        {
            scanf("%d", &chave);
            inserirLista(&lista, criaItem(chave));
        }
        else if(op == 'E')
        {
            scanf("%d", &chave);
            removerLista(&lista, criaItem(chave));
        }
        else {
            mostrarLista(lista);
        }
    }
    mostrarLista(lista);
    return 0;
}

