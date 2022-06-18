#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, val;
    int* v;

    scanf("%d", &n);
    v = (int*) malloc(n*sizeof(int));
    for(int i=0; i<n;i++) scanf("%d", &v[i]);
    scanf("%d", &m);

    for(int i=0; i<m;i++){
        unsigned char achei=0;
        scanf("%d", &val);
        for(int j=0;j<n;j++){
            if(v[j]==val){
                achei=1;
                break;
            }
        }
        if(achei){
            printf("ACHEI\n");
        } else {
            printf("NAO ACHEI\n");
        }
    }
    free(v);

    return 0;
}