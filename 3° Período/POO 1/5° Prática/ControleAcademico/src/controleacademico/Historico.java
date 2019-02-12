/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controleacademico;
import java.util.*;
/**
 *
 * @author Marcelo
 */
public class Historico {
    ArrayList<MatriculaAluno> disciplinasMatriculadas;
    Aluno aluno;
     
    Historico (Aluno a) {
         aluno = a;
         disciplinasMatriculadas = new ArrayList<MatriculaAluno>();
    }
    
    void matriculaDisciplina (OfertaTurma oferta) {
        MatriculaAluno m = new MatriculaAluno (aluno, oferta);
         this.disciplinasMatriculadas.add(m);
         oferta.matriculaAluno(m);
    }
     
    boolean constaAprovacao (Disciplina d) {
         for (MatriculaAluno m: disciplinasMatriculadas) {
             if (m.aprovado(d))
                 return true;
         }
         return false;
    }
    
    void registraResultado (Disciplina d, int nota) {
        for (MatriculaAluno m: disciplinasMatriculadas) {
            if (m.oferta.nomeDisciplina().equals(d.nome) && m.status == StatusMatriculaDisciplina.CURSANDO)
                m.registraNota(nota);
        }
    } 
//   void verificaSeFormou () {
//         
//   }
}
    
     
     

