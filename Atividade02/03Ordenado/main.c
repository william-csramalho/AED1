#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

int main(){
    int n;
    int *v;

    while(scanf("%d", &n)!=EOF){
        int i;
        int cresc, decresc;
        cresc=0;
        decresc=0;
        if(!n) {
            printf("S\n");
            continue;
        }
        v=(typeof(v)) malloc(sizeof(int[n]));
        scanf("%d", v);
        for(i=0;i<(n-1);i++){
            scanf("%d", &v[i+1]);
            if(v[i]>v[i+1]){
                decresc=1;
                if(cresc){
                    scanf("%*[^\n]d");
                    break;
                }
            }
            if(v[i]<v[i+1]){
                cresc=1;
                if(decresc){
                    scanf("%*[^\n]d");
                    break;
                }
            }
        }
        if(i==(n-1)) printf("S\n");
        else{
            printf("N\n");
        }
        free(v);
    }

    return 0;
}

