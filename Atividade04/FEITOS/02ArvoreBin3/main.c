#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

struct No
{
    char chave;
    struct No *pai;
    struct No *direita;
    struct No *esquerda;
};

struct Arvore
{
    struct No *raiz;
};

struct Arvore * criaArvore()
{
    struct Arvore *t = (struct Arvore*) malloc(sizeof(struct Arvore));

    if(t != NULL)
    {
        t->raiz = NULL;
    }
    return t;
}

struct No * criaNo(char chave)
{
    struct No * no = (struct No*) malloc(sizeof(struct No));

    if(no != NULL)
    {
        no->chave = chave;
        no->esquerda = NULL;
        no->direita = NULL;
        no->pai = NULL;
    }
    return no;
}

void inserir(struct Arvore *t, struct No *novo)
{
    struct No *pai = NULL, *filho = t->raiz;
    //char igual;

    while(filho != NULL)
    {
        pai = filho;

        //igual=filho->chave==novo->chave;
        if(filho->chave < novo->chave)
        {
            filho = filho->direita;
        }
        else
        {
            filho = filho->esquerda;
        }
    }

    if(pai != NULL) // inserindo no folha
    {
        novo->pai = pai;
        if(pai->chave > novo->chave) // filho da esquerda
        {
            pai->esquerda = novo;
        }
        else // filho da direita
        {
            pai->direita = novo;
        }
    }
    else // inserindo no raiz
    {
        t->raiz = novo;
    }
}

void preOrder(struct No *r)
{
    if(r != NULL)
    {
        printf("%c ", r->chave);
        /*
        if(r->esquerda != NULL)
            printf(" ");
            */
        preOrder(r->esquerda);
        /*if(r->direita != NULL)
            printf(" ");*/
        preOrder(r->direita);
    }
}

void postOrder(struct No *r)
{
    if(r != NULL)
    {
        postOrder(r->esquerda);
        postOrder(r->direita);
        printf("%c ", r->chave);
        /*
        if(r->pai!=NULL)
            printf(" ");*/
    }
}

void inOrder(struct No *r)
{
    if(r != NULL)
    {
        inOrder(r->esquerda);
        printf("%c ", r->chave);
/*
        if(r->direita==NULL && r->esquerda==NULL) {
            printf("%d", r->chave);
        } else{
            if(r->direita!=NULL && r->esquerda==NULL){
            printf("%d ", r->chave);
            } else {
                if(r->direita==NULL && r->esquerda!=NULL){
                    printf(" %d", r->chave);
                } else {
                    printf(" %d ", r->chave);
                }
            }
        }
        */
        inOrder(r->direita);
    }
}
struct No * sucessor(struct No *filho)
{
    struct No * anterior = NULL;

    while(filho != NULL)
    {
        anterior = filho;
        filho = filho->esquerda;
    }

    if(anterior->pai->esquerda == anterior) // anterior (sucessor) eh filho esquerdo de seu pai
    {
        anterior->pai->esquerda = anterior->direita;
    }
    else // anterior (sucessor) eh filho direito de seu pai
    {
        anterior->pai->direita = anterior->direita;
    }
    if(anterior->direita != NULL)
    {
        anterior->direita->pai = anterior->pai;
    }
    return anterior;
}

struct No * remover(struct Arvore *t, int chave)
{
    struct No *anterior = NULL, *filho = t->raiz, *subs;

    while(filho != NULL && filho->chave != chave)
    {
        anterior = filho;
        if(filho->chave < chave)
        {
            filho = filho->direita;
        }
        else
        {
            filho = filho->esquerda;
        }
    }

    if(filho != NULL)
    {
        if(filho->esquerda == NULL && filho->direita == NULL) // eh folha!
        {
            if(anterior != NULL) // nao eh raiz
            {
                if(anterior->esquerda == filho) // eh filho da esquerda do pai
                {
                    anterior->esquerda = NULL;
                }
                else // eh filho da direita do pai
                {
                    anterior->direita = NULL;
                }
            }
            else // eh raiz
            {
                t->raiz = NULL;
            }
        }
        else if(filho->esquerda != NULL && filho->direita != NULL) // eh pai de dois filhos
        {
            subs = sucessor(filho->direita);

            if(anterior != NULL) // nao eh raiz
            {
                if(anterior->esquerda == filho) // filho eh filho da esquerda de seu pai (anterior)
                {
                    anterior->esquerda = subs;
                }
                else // filho eh filho da direita de seu pai (anterior)
                {
                    anterior->direita = subs;
                }
            }
            else // eh raiz
            {
                t->raiz = subs;
            }
            subs->pai = anterior;

            subs->esquerda = filho->esquerda;
            if(filho->esquerda != NULL)
            {
                filho->esquerda->pai = subs;
            }

            subs->direita = filho->direita;
            if(filho->direita != NULL)
            {
                filho->direita->pai = subs;
            }
        }
        else // pai de filho unico
        {
            if(anterior != NULL) // nao eh raiz
            {
                if(anterior->esquerda == filho) // eh filho do lado esquerdo do pai
                {
                    if(filho->esquerda != NULL) // tem filho na esquerda
                    {
                        anterior->esquerda = filho->esquerda; // avo na subarvore esquerda assume o neto da esquerda
                        filho->esquerda->pai = anterior;
                    }
                    else // tem filho na direita
                    {
                        anterior->esquerda = filho->direita; // avo na subarvore esquerda assume o neto da direita
                        filho->direita->pai = anterior;
                    }
                }
                else // eh filho do lado direito
                {
                    if(filho->esquerda != NULL)
                    {
                        anterior->direita = filho->esquerda;
                        filho->esquerda->pai = anterior;
                    }
                    else
                    {
                        anterior->direita = filho->direita;
                        filho->direita->pai = anterior;
                    }
                }
            }
            else // eh raiz
            {
                if(filho->esquerda != NULL) // raiz tem filho na esquerda
                {
                    t->raiz = filho->esquerda;
                }
                else // raiz tem filho na direita
                {
                    t->raiz = filho->direita;
                }
                t->raiz->pai = NULL;
            }
        }
    }
    return filho;
}



int main() {
    struct Arvore *arvore = criaArvore();
    struct No *no;
    int ret;
    char chave;
    char comando[11];

    while(scanf("%s", comando) != EOF) {
        if(!strcmp(comando, "insert")) {
            ret = scanf("%1s", &chave);
            //printf("%s %c\n", comando, chave);
            inserir(arvore, criaNo(chave));
        } elif(!strcmp(comando, "delete")) {
            ret = scanf("%1s", &chave);
            //printf("%s %c\n", comando, chave);/**/
            no = remover(arvore, chave);
            if(no != NULL) {
                //printf("%c\n", no->chave);
                free(no);
            }
        } elif(!strcmp(comando,"pre-order")) {
            //printf("%s\n", comando);/**/
            preOrder(arvore->raiz);
            printf("\n");
        } elif(!strcmp(comando,"in-order")) {
            //printf("%s\n", comando);/**/
            inOrder(arvore->raiz);
            printf("\n");
        } elif(!strcmp(comando,"post-order")) {
            //printf("%s\n", comando);/**/
            postOrder(arvore->raiz);
            printf("\n");
        }
    }
    return 0;
}

