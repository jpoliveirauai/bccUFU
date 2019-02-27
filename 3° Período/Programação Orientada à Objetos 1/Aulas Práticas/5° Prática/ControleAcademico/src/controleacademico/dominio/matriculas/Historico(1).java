package controleacademico.dominio.matriculas;
import java.util.*;
import controleacademico.dominio.pessoas.Aluno;
import controleacademico.dominio.cursos.Disciplina;
import controleacademico.dominio.matriculas.MatriculaAluno;

public class Historico {
    private ArrayList<MatriculaAluno> disciplinasMatriculadas;
    private Aluno aluno;
     
    public Historico (Aluno a) {
         aluno = a;
         disciplinasMatriculadas = new ArrayList<MatriculaAluno>();
    }
    
    public void matriculaDisciplina (OfertaTurma oferta) {
        MatriculaAluno m = new MatriculaAluno (aluno, oferta);
         this.disciplinasMatriculadas.add(m);
         oferta.matriculaAluno(m);
    }
     
    public boolean constaAprovacao (Disciplina d) {
         for (MatriculaAluno m: disciplinasMatriculadas) {
             if (m.aprovado(d))
                 return true;
         }
         return false;
    }
    
    public void registraResultado (Disciplina d, int nota) {
        for (MatriculaAluno m: disciplinasMatriculadas) {
            if (m.getOferta().nomeDisciplina().equals(d.getNome()) && m.getStatus() == StatusMatriculaDisciplina.CURSANDO)
                m.registraNota(nota);
        }
    }
}
    
     
     

