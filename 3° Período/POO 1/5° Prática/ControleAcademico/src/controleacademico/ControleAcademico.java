/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controleacademico;

/**
 *
 * @author Marcelo
 */
public class ControleAcademico {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Disciplina pp = new Disciplina("PP");
        Disciplina aed1 = new Disciplina("AED1");
        Disciplina poo1 = new Disciplina("POO1");
        GradeCurricular grade = new GradeCurricular();
        grade.incluiDisciplina(pp);
        //pp.incluiNaGrade(grade); Seria um bad smell: feature envy
        grade.incluiDisciplina(aed1);
        grade.incluiDisciplina(poo1);
        Professor profMarcelo = new Professor("Marcelo", "FACOM");
        Aluno alunoSeverino = new Aluno("Severino", grade);
        
        System.out.println("O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        
        OfertaTurma ofertaPP = new OfertaTurma(2015, Semestre.SEGUNDO, pp);
        alunoSeverino.historico.matriculaDisciplina(ofertaPP);
        System.out.println("O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));

        OfertaTurma ofertaAED1 = new OfertaTurma(2016, Semestre.PRIMEIRO, aed1);
        alunoSeverino.historico.matriculaDisciplina(ofertaAED1);

        OfertaTurma ofertaPOO1 = new OfertaTurma(2016, Semestre.PRIMEIRO, poo1);
        alunoSeverino.historico.matriculaDisciplina(ofertaPOO1);
        
        System.out.println("O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        
        alunoSeverino.historico.registraResultado(pp, 60);
        System.out.println("O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        alunoSeverino.historico.registraResultado(aed1, 60);       
        System.out.println("O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        alunoSeverino.historico.registraResultado(poo1, 60);
        System.out.println("O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
    }
    
}
