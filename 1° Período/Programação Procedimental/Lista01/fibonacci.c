#include <stdio.h>
#include <stdlib.h>

main(){
    int f=0,f1=1,i,n,c=0;
    puts("N:\n");
    scanf("%d",&n);
    puts("Sequencia de fibonacci:");
    for (i=0;i<n;i++){
        c = f+f1;
        f=f1;
        f1=c;
        printf("%d%c", f , i!=n-1?',':'\n');
    }

    return 0;
}
