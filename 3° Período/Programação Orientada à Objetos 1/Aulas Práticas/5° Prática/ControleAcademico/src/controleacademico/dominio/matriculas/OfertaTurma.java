package controleacademico.dominio.matriculas;
import java.util.*;

import controleacademico.dominio.pessoas.Professor;
import controleacademico.dominio.cursos.Disciplina;
import controleacademico.dominio.pessoas.Aluno;

public class OfertaTurma {
    private int ano;
    private Semestre semestre;
    private Disciplina disciplina;
    private Vector<MatriculaAluno> alunosMatriculados;
    private Professor  professor;
    
    public OfertaTurma (int ano, Semestre s, Disciplina d) {
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
    
    public void vinculaProfessor (Professor p) {
        professor = p;
        professor.ficaAlocadoTurma(this);
    }    

    public String nomeDisciplina() {
        return this.disciplina.getNome();
    }
}
