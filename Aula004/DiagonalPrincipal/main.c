#include <stdio.h>
#include <stdlib.h>

int main(){
    char op;
    int n, total=0;

    scanf("%c", &op);
    scanf("%d", &n);

    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            int val;
            scanf("%d", &val);
            if(i==j) total+=val;
        }
    }

    if(op=='S'){
        printf("%.1f\n", (float) total);
    } else {
        printf("%.1f\n", total/(float) n);
    }


    return 0;
}