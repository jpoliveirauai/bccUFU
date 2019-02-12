#include <stdio.h>

int main(){
    int dado[6]={0,0,0,0,0,0},x,i;
    for(i=0;i<1000000;i++){
        srand(time(NULL));
        x=rand()%6;
        printf ("%d\n",x);
        switch(x){
            case 0:
                dado[x]++;
            break;
            case 1:
                dado[x]++;
            break;
            case 2:
                dado[x]++;
            break;
            case 3:
                dado[x]++;
            break;
            case 4:
                dado[x]++;
            break;
            case 5:
                dado[x]++;
            break;
        }
    }
    for (i=0;i<6;i++){
        printf("face %d: %d\n",i+1,dado[i]);
    }
}
