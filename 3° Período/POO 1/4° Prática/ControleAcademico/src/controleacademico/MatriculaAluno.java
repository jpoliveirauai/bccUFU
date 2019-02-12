package controleacademico;

public class MatriculaAluno {
    Aluno aluno;
    OfertaTurma oferta;
    StatusMatriculaDisciplina  status;
    float nota;
    
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
}
