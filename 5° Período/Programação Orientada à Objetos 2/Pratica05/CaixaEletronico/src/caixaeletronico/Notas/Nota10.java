package caixaeletronico.Notas;

/**
 *
 * @author a11611BCC046
 */
public class Nota10 extends Notas{
    private int quantidade;
    private final int valor=10;
    public int getQuantidade(){
        return quantidade;
    }
    public Nota10(int x){
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
