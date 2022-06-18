#include <stdio.h>

int main(){
    int xa, xo=-1;

    do{
        scanf("%d", &xa);
        if(xa>xo) xo=xa;
    } while(xa>0);
    if(xo<0){
        printf("nenhum numero informado\n");
    } else{
        printf("%d\n", xo);
    }


    return 0;
}