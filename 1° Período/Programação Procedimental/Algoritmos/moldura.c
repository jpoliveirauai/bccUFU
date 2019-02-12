#include <stdio.h>

int main(){
	int x,y,i,j;
	do{
        scanf("%d %d",&x,&y);
    }while(x<1||y<1);
    for(i=1;i<=y;i++){
        if (i==1||i==y){
            for(j=1;j<=x;j++)putchar('*');
        }else{
            putchar('*');
            for(j=1;j<=x-2;j++)putchar(' ');
            putchar('*');
        }
        puts("\n");
    }

}
