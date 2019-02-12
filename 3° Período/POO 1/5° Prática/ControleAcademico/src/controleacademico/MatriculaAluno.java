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
