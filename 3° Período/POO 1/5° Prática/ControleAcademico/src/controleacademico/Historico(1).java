package controleacademico;
import java.util.*;

public class Historico {
    ArrayList<MatriculaAluno> disciplinasMatriculadas;
    Aluno aluno;
     
    Historico (Aluno a) {
         aluno = a;
         disciplinasMatriculadas = new ArrayList<MatriculaAluno>();
    }
    
    void matriculaDisciplina (OfertaTurma oferta) {
        boolean podeCursar = true;
        for(int i=0;i<oferta.disciplina.prerequisitos.size();i++){
            if(!this.constaAprovacao(oferta.disciplina.prerequisitos.get(i))){
                podeCursar = false;
            }
        }
        if(podeCursar == false){
             System.out.println("Não atendeu o pré-requesito na matéria "+oferta.nomeDisciplina());
             oferta.cancelaMatricula(aluno);
             return;
        }
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
    ArrayList<Disciplina> AindaFalta(GradeCurricular grade){
        ArrayList<Disciplina> faltantes = new ArrayList<Disciplina>();
        for(int i=0,j=0;i<grade.disciplinas.size();i++){
            if(!this.constaAprovacao(grade.disciplinas.get(i))){
                faltantes.add(grade.disciplinas.get(i));
                System.out.println("falta "+faltantes.get(j++).nome);
            }
                
        }
        return faltantes;
    }
}
    
     
     

