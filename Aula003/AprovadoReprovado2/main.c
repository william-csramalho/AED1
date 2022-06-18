#include <stdio.h>

int main(){
    double x, y, media;
    scanf("%lf %lf", &x, &y);
    media=(x+y)/2.;
    if(media>=60.){
        printf("APROVADO\n");
    } else {
        if(media>=40){
            printf("EXAME FINAL\n");
        } else{
            printf("REPROVADO\n");
        }
    }
    return 0;
}