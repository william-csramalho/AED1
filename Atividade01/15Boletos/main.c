#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

typedef struct{
    char banco[100];
    char cedente[100];
    char sacado[100];
    double valorcobrado;
} tBoleto;

void qqsort(tBoleto *a, int left, int right) {
    int i, j;
    tBoleto x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i].valorcobrado > x.valorcobrado && i < right) {
            i++;
        }
        while(a[j].valorcobrado < x.valorcobrado && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        qqsort(a, left, j);
    }
    if(i < right) {
        qqsort(a, i, right);
    }
}

int main(){
    int n;
    tBoleto* boletos;

    scanf("%d", &n);

    boletos=(typeof(boletos)) malloc(sizeof(tBoleto[n]));

    for(int i=0;i<n; i++){
        char diav, diap;
        double valor, multa;
        scanf("%s %s %s %lf %hhu %hhu %lf",
        boletos[i].banco,
        boletos[i].cedente,
        boletos[i].sacado,
        &valor,
        &diav,
        &diap,
        &multa
        );
        diap=(diap-diav);
        diap=diap<0?0:diap;
        boletos[i].valorcobrado=valor+diap*multa;
    }

    qqsort(boletos, 0, n-1);

    for(int i=0; i<n; i++){
        printf("%s %s %s %.2lf\n",
        boletos[i].sacado,
        boletos[i].cedente,
        boletos[i].banco,
        boletos[i].valorcobrado);
    }
    free(boletos);
    return 0;
}

