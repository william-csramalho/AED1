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
};

struct FilaEstatica
{
    struct Item *itens;
    int inicio, final;
    int tamanho;
};

struct FilaEstatica criaFila(int n)
{
    struct FilaEstatica f;
    f.itens = (struct Item*) malloc(n*sizeof(struct Item));
    f.tamanho = n;
    f.inicio = -1;
    f.final = -1;
    return f;
}

struct Item criaItem(int chave)
{
    struct Item it;
    it.chave = chave;
    return it;
}

int filaCheia(struct FilaEstatica f)
{
    return f.final == f.tamanho-1;
}

int filaVazia(struct FilaEstatica f)
{
    return f.inicio == -1 && f.final == -1 || f.inicio > f.final;
}

void mostrarFila(struct FilaEstatica f)
{
    int i;
    if(!filaVazia(f))
    {
        for(i=f.inicio; i<=f.final; i++)
        {
            printf("%d%s", f.itens[i].chave, i!=f.final?" ":"\n");
        }
    }
}

void enfileirar(struct FilaEstatica *f, struct Item novo)
{
    if(!filaCheia(*f))
    {
        if(filaVazia(*f))
        {
            f->inicio++;
        }
        f->final++;
        f->itens[f->final] = novo;
    }
}

struct Item desenfileirar(struct FilaEstatica *f)
{
    struct Item it;
    if(!filaVazia(*f))
    {
        it = f->itens[f->inicio];
        if(f->inicio != f->final)
        {
            f->inicio++;
        }
        else
        {
            f->inicio = -1;
            f->final = -1;
        }
    }
    return it;
}

int main()
{
    struct FilaEstatica fila;
    int n, chave;
    char op;

    scanf("%d", &n);

    fila = criaFila(n);

    while(scanf("\n%c", &op) != EOF)
    {
        if(op == 'E')
        {
            scanf("%d", &chave);
            enfileirar(&fila, criaItem(chave));
        }
        else if(op == 'D')
        {
            if(!filaVazia(fila))
            {
                printf("%d\n", desenfileirar(&fila).chave);
            }
        }
    }
    return 0;
}

