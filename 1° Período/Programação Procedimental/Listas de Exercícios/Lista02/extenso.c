#include <stdio.h>
#include <stdio.h>
#include <string.h>
void centena (char c,int i,char*cat){
    switch(c){
        break;
        case '2':
            strcat (cat,"duzentos ");
        break;
        case '3':
            strcat (cat,"trezentos ");
        break;
        case '4':
            strcat (cat,"quatrocentos ");
        break;
        case '5':
            strcat (cat,"quinhentos ");
        break;
        case '6':
            strcat (cat,"seiscentos ");
        break;
        case '7':
            strcat (cat,"setecentos ");
        break;
        case '8':
            strcat (cat,"oitocentos ");
        break;
        case '9':
            strcat (cat,"novecentos ");
        break;
    }
}
void dezena (char c,int i,char*cat){
    switch(c){
        case '2':
            strcat (cat,"vinte ");
        break;
        case '3':
            strcat (cat,"trinta ");
        break;
        case '4':
            strcat (cat,"quarenta ");
        break;
        case '5':
            strcat (cat,"cinquenta ");
        break;
        case '6':
            strcat (cat,"sessenta ");
        break;
        case '7':
            strcat (cat,"setenta ");
        break;
        case '8':
            strcat (cat,"oitenta ");
        break;
        case '9':
            strcat (cat,"noventa ");
        break;
    }
}
void unidade (char c,int i,char*cat){
    switch(c){
        case '1':
            strcat (cat,"um ");
        break;
        case '2':
            strcat (cat,"dois ");
        break;
        case '3':
            strcat (cat,"tres ");
        break;
        case '4':
            strcat (cat,"quatro ");
        break;
        case '5':
            strcat (cat,"cinco ");
        break;
        case '6':
            strcat (cat,"seis ");
        break;
        case '7':
            strcat (cat, "sete ");
        break;
        case '8':
            strcat (cat,"oito ");
        break;
        case '9':
            strcat (cat,"nove ");
        break;
    }
}
void milhar (char c,int a,char*cat){
    switch(a){
        case 15:
            case 14:
                case 13:
                    c=='1'?strcat(cat,"trilhao "):strcat(cat,"trilhoes ");
        break;
        case 12:
            case 11:
                case 10:
                    c=='1'?strcat(cat,"bilhao "):strcat(cat,"bilhoes ");
        break;
        case 9:
            case 8:
                case 7:
                    c=='1'?strcat(cat,"milhao "):strcat(cat,"milhoes ");
        break;
        case 6:
            case 5:
                case 4:
                strcat(cat,"mil ");
        break;
    }
}
void chev (char*p){
    int i;
    for(i=1;i<strlen(p);i++){
        p[i-1]=p[i];
    }
    p[strlen(p)-1]='\0';
}
int main (int argc, char *argv[]){
    if (argc==2){
            int i,flag=0;
                for (i=0;i<strlen(argv[1]);i++){
                    if (argv[1][i]<48||argv[1][i]>57) flag=1;
                }
                while(argv[1][0]=='0'){
                        chev(argv[1]);
                }
                if (flag==1||strlen(argv[1])>15) puts("Digite um numero inteiro e menor que 1000000000000000!");
                else{
                    char ext[200];
                    int j=strlen(argv[1])%3,k,flag1=0;
                    for (i=0;i<strlen(argv[1]);i++,j--){
                        if (j==0){
                            if(i!=0){
                                if (argv[1][i-1]!='0'||argv[1][i-2]!='0'||argv[1][i-3]!='0'){
                                    milhar(argv[1][i],(strlen(argv[1])-i+1),ext);
                                    flag=1;
                                }
                            }
                            j=3;
                        }
                        if (i!=0){
                            for (k=0;k<strlen(argv[1]);k++){
                                if(argv[1][k]!='0')flag1=1;
                            }
                            if ((flag1&&argv[1][i]!='0')&&!flag){
                                strcat(ext,"e ");
                            }
                        }
                        flag=0;
                        switch(j){
                            case 1:
                                unidade(argv[1][i],i,ext);
                            break;
                            case 2:
                                dezena(argv[1][i],i,ext);
                                if(argv[1][i]=='1'){
                                    if (argv[1][i+1]=='0')strcat (ext,"dez ");
                                    if (argv[1][i+1]=='1')strcat (ext,"onze ");
                                    if (argv[1][i+1]=='2')strcat (ext,"doze ");
                                    if (argv[1][i+1]=='3')strcat (ext,"treze ");
                                    if (argv[1][i+1]=='4')strcat (ext,"quatorze ");
                                    if (argv[1][i+1]=='5')strcat (ext,"quinze ");
                                    if (argv[1][i+1]=='6')strcat (ext,"dezesseis ");
                                    if (argv[1][i+1]=='7')strcat (ext,"dezessete ");
                                    if (argv[1][i+1]=='8')strcat (ext,"dezoito ");
                                    if (argv[1][i+1]=='9')strcat (ext,"dezenove ");
                                    i++;
                                    j--;
                                }
                            break;
                            case 3:
                                if (argv[1][i]=='1'){
                                    if (argv[1][i+1]=='0'&&argv[1][i+2]=='0'){
                                        for (k=0;k<i;k++)if(argv[1][k]!='0')flag1=1;
                                        if (flag1==0)strcat (ext,"cem ");
                                        else strcat (ext,"cem ");
                                        i+=2;
                                    }else  strcat (ext,"cento ");
                                }else centena(argv[1][i],i,ext);
                            break;
                        }
                    }
                    printf("\n%s",ext);
                }
    }else puts("Digite apenas um numero inteiro");
}
