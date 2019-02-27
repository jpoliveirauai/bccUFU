package caixaeletronico;

import caixaeletronico.Caixa.*;

/*
Autor: João Paulo de Oliveira
       11611BCC046
       Matheus Pimenta Reis
       11611BCC038
Prática05: Factory
 */
public class CaixaEletronico {

    public static void main(String[] args) {
        //valor fixo de 100 notas de cada valor
        Caixa cx = new Caixa();
        cx.produzNotas(10,0,300,4,5);
        //valor fixo de saque
        cx.saque(1575);
    }
}
