#include <stdio.h>
#define ta 4
int main(){
    int mat[ta][ta],i,j,lds=0,cds=3,cmp[6]={0,0,0,0,0,0},cmp1[4]={0,0,0,0},interr=0;
    for(i=0;i<ta;i++){
        for(j=0;j<ta;j++){
            scanf("%d",&mat[i][j]);
            switch (j){
                case 0:
                    cmp[0]+=mat[i][j];
                break;
                case 1:
                    cmp[1]+=mat[i][j];
                break;
                case 2:
                    cmp[2]+=mat[i][j];
                break;
                case 3:
                    cmp[3]+=mat[i][j];
                break;
            }
            if (i==j) cmp[4]+=mat[i][j];
            if(i==lds&&j==cds){
                cmp[5]+=mat[i][j];
                lds++;
                cds--;
            }
            switch (i){
                case 0:
                    cmp1[0]+=mat[i][j];
                break;
                case 1:
                    cmp1[1]+=mat[i][j];
                break;
                case 2:
                    cmp1[2]+=mat[i][j];
                break;
                case 3:
                    cmp1[3]+=mat[i][j];
                break;
            }
        }
    }for(i=0;i<6;i++) {
        for(j=0;j<4;j++) {
            if (cmp[i]!=cmp1[j]) interr=1;
        }
    }
    if (interr) printf("\nA matriz dada nao eh um quadrado magico"); else printf("\nA matriz dada eh um quadrado magico");
    return  0;
    system("pause");
}
