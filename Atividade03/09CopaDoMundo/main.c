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
};

struct FilaEstaticaCircular
{
    struct Item *itens;
    int inicio, final;
    int tamanho;
};

struct FilaEstaticaCircular criaFilaCircular(int n)
{
    struct FilaEstaticaCircular f;
    f.itens = (struct Item*) malloc(n*sizeof(struct Item));
    f.tamanho = n;
    f.inicio = 0;
    f.final = 0;
    return f;
}

struct Item criaItem(int chave)
{
    struct Item it;
    it.chave = chave;
    return it;
}

int filaCircularCheia(struct FilaEstaticaCircular f)
{
    return (f.final+1)%f.tamanho == f.inicio;
}

int filaCircularVazia(struct FilaEstaticaCircular f)
{
    return f.inicio == f.final;
}

void mostrarFilaCircular(struct FilaEstaticaCircular f)
{
    int i;
    for(i=f.inicio; i!=f.final; i=(i+1)%f.tamanho)
    {
        printf("%c\n", f.itens[i].chave);
    }
}

void enfileirarCirculando(struct FilaEstaticaCircular *f, struct Item novo)
{
    if(!filaCircularCheia(*f))
    {
        f->itens[f->final] = novo;
        f->final = (f->final+1)%f->tamanho;
    }
}

struct Item desenfileirarCirculando(struct FilaEstaticaCircular *f)
{
    struct Item it;
    if(!filaCircularVazia(*f))
    {
        it = f->itens[f->inicio];
        f->inicio = (f->inicio+1)%f->tamanho;
    }
    return it;
}

int main()
{
    struct FilaEstaticaCircular fila;
    int r1, r2;

    fila = criaFilaCircular('P'-'A'+2);

    for(int i='A'; i<='P';i++)
        enfileirarCirculando(&fila, criaItem(i));

    while(scanf("%d %d", &r1, &r2) != EOF)
    {
        struct Item time1=desenfileirarCirculando(&fila);
        struct Item time2=desenfileirarCirculando(&fila);
        if(r1>r2)
            enfileirarCirculando(&fila, time1);
        else
            enfileirarCirculando(&fila, time2);
    }
    mostrarFilaCircular(fila);
    
    return 0;
}

