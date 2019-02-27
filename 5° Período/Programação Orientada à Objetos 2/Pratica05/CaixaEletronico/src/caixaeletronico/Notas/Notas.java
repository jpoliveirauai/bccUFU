package caixaeletronico.Notas;


public abstract class Notas {
    //int valor, 
    
    //public int SoltaNota(int saque);
    public abstract int getValor();
    public abstract int getQuantidade();
    public abstract void decQuantidade();
    public int SoltaNota(int saque){
        int i=0;
        while(saque-getValor()>=0){
            saque-=getValor();
            this.decQuantidade();
            i++;
        }
        System.out.println(i +" Nota(s) de " + getValor());
        return saque;
    }
}
