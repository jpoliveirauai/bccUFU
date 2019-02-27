/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package caixaeletronico.Notas;

/**
 *
 * @author a11611BCC046
 */
public class Nota50 extends Notas{
    private int quantidade;
    private int valor=50;
    public Nota50(int x){
        if (x>=0)quantidade = x;
        else System.out.println("Valor Inválido\n");
    }
    public int getValor(){
        return valor;
    }
}
