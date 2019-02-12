package controleacademico.dominio.cursos;
import java.util.Vector;

public class GradeCurricular {
    private Vector<Disciplina> disciplinas = new Vector<Disciplina>();
    
    public void incluiDisciplina (Disciplina d) {
        disciplinas.add(d);
    }
    
    void removeDisciplina (Disciplina d) {
        disciplinas.remove(d);
    }

    public int nroDisciplinas() {
        return disciplinas.size();
    }
    public Disciplina getDisciplina(int i){
        return disciplinas.get(i);
    }
}
