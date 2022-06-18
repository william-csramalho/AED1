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
    struct Lista lista1, lista2;
    int n1, n2, chave;
    char op;

    scanf("%d %d", &n1, &n2);

    lista1 = criaLista(n1);
    lista2 = criaLista(n2);

    int n1t=n1;
    int n2t=n2;



    while(n1t){
        n1t--;
        scanf("\n%c", &op);
        if(op == 'I')
        {
            scanf("%d", &chave);
            inserirLista(&lista1, criaItem(chave));
        }
        else if(op == 'E')
        {
            scanf("%d", &chave);
            removerLista(&lista1, criaItem(chave));
        }
    }

    while(n2t){
        n2t--;
        scanf("\n%c", &op);
        if(op == 'I')
        {
            scanf("%d", &chave);
            inserirLista(&lista2, criaItem(chave));
        }
        else if(op == 'E')
        {
            scanf("%d", &chave);
            removerLista(&lista2, criaItem(chave));
        }
    }

/*
mostrarLista(lista1);
printf("======\n");
mostrarLista(lista2);
printf("======\n");
*/

    if(lista1.quantidade>lista2.quantidade){
        printf("NAO\n");
    } else {
        for(int i=0; i<lista1.quantidade; i++){
            if(buscarLista(lista2, lista1.itens[i])==-1){
                printf("NAO\n");
                return 0;
            }
        }
        printf("SIM\n");
    }
    return 0;
}

