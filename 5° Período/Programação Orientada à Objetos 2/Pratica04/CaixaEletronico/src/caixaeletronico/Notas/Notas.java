package caixaeletronico.Notas;


public abstract class Notas {
    //int valor, quantidade;
    //public int SoltaNota(int saque);
    public abstract int getValor();
    public int SoltaNota(int saque){
        int i=0;
        while(saque-getValor()>=0){
            saque-=getValor();
            //System.out.println(saq);
            i++;
        }
        System.out.println(i +" Nota(s) de " + getValor());
        return saque;
    }
}
