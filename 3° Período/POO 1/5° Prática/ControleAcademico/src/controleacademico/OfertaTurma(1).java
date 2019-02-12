package controleacademico;
import java.util.*;

public class OfertaTurma {
    int ano;
    Semestre semestre;
    Disciplina disciplina;
    Vector<MatriculaAluno> alunosMatriculados;
    Professor  professor;
    
    OfertaTurma (int ano, Semestre s, Disciplina d) {
        this.ano = ano;
        this.semestre = s;
        this.disciplina = d; 
        alunosMatriculados = new Vector<MatriculaAluno>();
    }
    void matriculaAluno (MatriculaAluno m) {
        alunosMatriculados.add(m);
    }
    
    void cancelaMatricula (Aluno a) {
        alunosMatriculados.remove(a);
    }
    
    void vinculaProfessor (Professor p) {
        professor = p;
        professor.ficaAlocadoTurma(this);
    }    

    String nomeDisciplina() {
        return this.disciplina.getNome();
    }
}
