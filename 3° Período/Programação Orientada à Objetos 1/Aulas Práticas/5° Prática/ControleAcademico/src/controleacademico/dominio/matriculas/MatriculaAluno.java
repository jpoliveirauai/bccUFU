package controleacademico.dominio.matriculas;

import controleacademico.dominio.pessoas.Aluno;
import controleacademico.dominio.cursos.Disciplina;

public class MatriculaAluno {
    private Aluno aluno;
    private OfertaTurma oferta;
    private StatusMatriculaDisciplina  status;
    private float nota;
    
    MatriculaAluno (Aluno a, OfertaTurma o) {
        aluno = a;
        oferta = o;
        status = StatusMatriculaDisciplina.CURSANDO;
    }
    
    Aluno alunoMatriculado () {
        return aluno;
    }
    
    OfertaTurma turmaMatriculada() {
        return oferta;
    }
    
    void registraNota (float n) {
        this.nota = n;
        if (this.nota >= 60)
            status = StatusMatriculaDisciplina.APROVADA;
        else
            status = StatusMatriculaDisciplina.REPROVADA;            
    }
    
    void trancaMatricula () {
        this.status = StatusMatriculaDisciplina.TRANCADA;
    }    
    
    boolean aprovado (Disciplina d) {
        return d.getNome().equals(oferta.nomeDisciplina()) && status == StatusMatriculaDisciplina.APROVADA;
    }
    
    public OfertaTurma getOferta(){
        return oferta;
    }
    public StatusMatriculaDisciplina getStatus(){
        return status;
    }
}
