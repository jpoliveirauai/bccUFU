package caixaeletronico.Notas;

public class Nota05 extends Notas{
    private int quantidade;
    private final int valor=5;
    public int getQuantidade(){
        return quantidade;
    }
    public Nota05(int x){
        if (x>=0)quantidade = x;
        else System.out.println("Valor Inválido\n");
    }
    public int getValor(){
        return valor;
    }
    public void decQuantidade(){
        quantidade--;
    }

}
