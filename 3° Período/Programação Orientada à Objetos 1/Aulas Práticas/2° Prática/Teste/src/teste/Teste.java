package teste;

public class Teste {
   
    public static void main (String args[]) {
        Historico h1 = new Historico();

        Disciplina d3 = new Disciplina(" MCC");   
        Disciplina d2 = new Disciplina("AED1");    
        Disciplina d1 = new Disciplina("POO1");

        d2.atualizaResultado(92);
        d3.atualizaResultado(55);

        h1.matriculaDisciplina(d1);
        h1.matriculaDisciplina(d2);
        h1.matriculaDisciplina(d3);
        h1.imprime();
    }
}
 