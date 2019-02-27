package javaapplication1;

public class JavaApplication1 {
    public static void main(String[] args) {
        int NumeroDisciplinas = 0;
       Aluno Neiton = new Aluno();
       Neiton.NotaGeral = 0;
       Neiton.nome = "Neiton";
       Neiton.SNumeroDeMatricula = "Pn13VSFAMAT";
       Professor João = new Professor();
       João.AnoEgresso= 2010;
       João.Idade = 18;
       //João.nome.
       GradeCurricular Computacao = new GradeCurricular();
       Computacao.AddDisciplina("POO1", NumeroDisciplinas++);
       Computacao.RmDisciplina("POO1", NumeroDisciplinas);
    }
    
}
