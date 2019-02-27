package controleacademico;
import java.util.*;
public class ControleAcademico {

    public static void main(String[] args) {
        Disciplina pp = new Disciplina("PP");
        Disciplina aed1 = new Disciplina("AED1");
        Disciplina poo1 = new Disciplina("POO1");
        Disciplina poo2 = new Disciplina("POO2");
        
        poo2.criaPrerequisito(poo1);
        GradeCurricular grade = new GradeCurricular();
        grade.incluiDisciplina(pp);
        //pp.incluiNaGrade(grade); Seria um bad smell: feature envy
        grade.incluiDisciplina(aed1);
        grade.incluiDisciplina(poo1);
        grade.incluiDisciplina(poo2);
        
        Professor profMarcelo = new Professor("Marcelo", "FACOM");
        Aluno alunoSeverino = new Aluno("Severino", grade);
        
        ArrayList<Disciplina> falta = alunoSeverino.historico.AindaFalta(grade);
        System.out.println("O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        OfertaTurma ofertaPP = new OfertaTurma(2015, Semestre.SEGUNDO, pp);
        alunoSeverino.historico.matriculaDisciplina(ofertaPP);
        System.out.println("O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        falta = alunoSeverino.historico.AindaFalta(grade);
        OfertaTurma ofertaPoo2 = new OfertaTurma(2016,Semestre.PRIMEIRO,poo2);
        alunoSeverino.historico.matriculaDisciplina(ofertaPoo2);
        OfertaTurma ofertaAED1 = new OfertaTurma(2016, Semestre.PRIMEIRO, aed1);
        alunoSeverino.historico.matriculaDisciplina(ofertaAED1);

        OfertaTurma ofertaPOO1 = new OfertaTurma(2016, Semestre.PRIMEIRO, poo1);
        alunoSeverino.historico.matriculaDisciplina(ofertaPOO1);
        
        System.out.println("O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        falta = alunoSeverino.historico.AindaFalta(grade);
        alunoSeverino.historico.registraResultado(pp, 60);
        System.out.println("O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        falta = alunoSeverino.historico.AindaFalta(grade);
        alunoSeverino.historico.registraResultado(aed1, 60);       
        System.out.println("O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        falta = alunoSeverino.historico.AindaFalta(grade);
        alunoSeverino.historico.registraResultado(poo1, 30);
        System.out.println("O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        falta = alunoSeverino.historico.AindaFalta(grade);
    }
    
}
