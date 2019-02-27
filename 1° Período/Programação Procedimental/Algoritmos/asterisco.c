#include <stdio.h>

int main(){
	int i,h,j,l;
	scanf("%d",&h);
	for (i=1;i<=h;i++){
        for(j=0;j<i;j++){
            putchar('*');
        }
        puts("\n");
	}
	puts("\n\n\n");
	for (i=1;i<=h;i++){
        for (l=h-i,j=0;j<=l;j++)putchar(' ');
        for(j=0;j<i;j++){
            putchar('*');
        }
        puts("\n");
	}
}
