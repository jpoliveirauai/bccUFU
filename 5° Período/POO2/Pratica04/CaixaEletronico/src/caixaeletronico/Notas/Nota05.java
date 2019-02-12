package caixaeletronico.Notas;

public class Nota05 extends Notas{
    private int quantidade;
    private int valor=5;
    
    public Nota05(int x){
        if (x>=0)quantidade = x;
        else System.out.println("Valor Inválido\n");
    }
    public int getValor(){
        return valor;
    }

}
