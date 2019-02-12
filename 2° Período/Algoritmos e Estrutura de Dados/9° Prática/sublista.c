List sub(List lista, int inicio, int fim){
    if(inicio>fim||fim>lista.size||inicio<1){
        printf("Parametros Incorreto\n");
        exit(1);
    }
    List sub;
    sub.size = 0;
    int i;
    ListElmt *no;
    no = lista.head;
    for(i=1;i<=lista.size;i++){
        if(i>=inicio)
            insere(&sub,no->data);
        no = no->next;
    }
    return sub;
}
