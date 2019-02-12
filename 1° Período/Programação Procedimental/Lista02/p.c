#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int p_num(int p, char s[]){
    int i,cont=0,j=0;
    char sai[200];
    for (i=0;i<strlen(s);i++){
        if (s[i]>47 && s[i]<58){
            cont ++;
            if (cont==p){
                while (s[i]>='0' && s[i]<='9'){
                    sai[j]=s[i];
                    i++;
                    j++;
                }
                break;
            }else{
                while (s[i]>='0' && s[i]<='9'){
                        i++;
                }
            }
        }
        //while
    }
    return atoi(sai)==0?-1:atoi(sai);
}


int main (){
    int p;
    char s[200];
    setbuf(stdin,NULL);
    gets(s);
    printf("N: ");
    do{
        scanf("%d",&p);
    }while(p<=0);
    printf("\n i: %d\n", p_num(p,s));
    return 0;
}
