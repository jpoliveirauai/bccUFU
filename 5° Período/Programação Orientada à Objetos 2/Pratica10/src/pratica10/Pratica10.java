package pratica10;
/*
Participantes:
    João Paulo de Oliveira      11611BCC046
    Dener Cirilo Fontes         11511BCC058
*/
public class Pratica10 {

    public static void main(String[] args) {
        ExpBooleana e = new And(
                                new And(
                                        new Operando(true), 
                                        new Xor(
                                                new Operando(false),
                                                new Operando(true))),
                                new Not(new Operando(false)));
        if (e.operacao()) System.out.println("Verdadeiro");
        else System.out.println("False");
    }
}
