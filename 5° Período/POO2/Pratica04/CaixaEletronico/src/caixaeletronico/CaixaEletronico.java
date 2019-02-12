package caixaeletronico;

import caixaeletronico.Caixa.Caixa;

/*
Autor: João Paulo de Oliveira
       11611BCC046
Prática04: Chain of Responsibility
 */
public class CaixaEletronico {

    public static void main(String[] args) {
        //valor fixo de 100 notas de cada valor
        Caixa cx = new Caixa(100);
        //valor fixo de saque
        cx.saque(1196);
    }
}
