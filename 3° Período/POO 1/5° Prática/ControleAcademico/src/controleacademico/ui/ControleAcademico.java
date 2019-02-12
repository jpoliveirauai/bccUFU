package controleacademico.ui;
import javax.swing.*;
import controleacademico.dominio.cursos.Disciplina;
import controleacademico.dominio.cursos.*;
import controleacademico.dominio.matriculas.*;
import controleacademico.dominio.pessoas.*;

public class ControleAcademico {
    
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
        
        JOptionPane.showMessageDialog(null,"O aluno " + alunoSeverino.getNome()+ " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        
        OfertaTurma ofertaPP = new OfertaTurma(2015, Semestre.SEGUNDO, pp);
        alunoSeverino.matriculaAluno(ofertaPP);
        JOptionPane.showMessageDialog(null,"O aluno " + alunoSeverino.getNome() + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));

        OfertaTurma ofertaAED1 = new OfertaTurma(2016, Semestre.PRIMEIRO, aed1);
        alunoSeverino.matriculaAluno(ofertaAED1);

        OfertaTurma ofertaPOO1 = new OfertaTurma(2016, Semestre.PRIMEIRO, poo1);
        alunoSeverino.matriculaAluno(ofertaPOO1);
        
        JOptionPane.showMessageDialog(null,"O aluno " + alunoSeverino.getNome() + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        
        alunoSeverino.registraNota(pp, 60);
        JOptionPane.showMessageDialog(null,"O aluno " + alunoSeverino.getNome() + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        alunoSeverino.registraNota(aed1, 60);       
        JOptionPane.showMessageDialog(null,"O aluno " + alunoSeverino.getNome() + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        alunoSeverino.registraNota(poo1, 60);
        JOptionPane.showMessageDialog(null,"O aluno " + alunoSeverino.getNome() + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
    }
    
}
