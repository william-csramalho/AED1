#include <stdio.h>
#include <stdlib.h>

#define iLOWEST(x) (1LL<<(sizeof(typeof(x))*8-1))
#define iBIGGEST(x) ~(1LL<<(sizeof(typeof(x))*8-1))
#define sizeofv(vet) (sizeof(vet)/sizeof((vet)[0]))
#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)<(b)?(a):(b)
#define elif else if

int main(){
    int n, d, Sheldon,Leonard;
    unsigned char v;

    scanf("%d", &n);
    v=0;
    Sheldon=0;
    Leonard=0;

    while((scanf("%d", &d)!=EOF)&&((Sheldon<n)&&(Leonard<n))){
        if(v=!v){
            Sheldon+=!(d%2)==!(Sheldon%2);
        } else{
            Leonard+=!(d%2)==!(Leonard%2);
        }
    }
    if(Sheldon>Leonard){
        printf("Sheldon\n");
    } else {
        printf("Leonard\n");
    }
    
    return 0;
}