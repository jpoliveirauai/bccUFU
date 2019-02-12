
#include <stdio.h>

int main(){
    int i, j, k;
    do
    for(i=0;i<12;i++)
    {
     for(j=0;j<60;j++)
     {
      for(k=0;k<60;k++)
      {
          printf("%02d:%02d:%02d\r",i,j,k);             
      }
     }
    }
    while(1);
    system("PAUSE");
    return 0;
}
