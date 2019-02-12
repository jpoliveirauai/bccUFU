package controleacademico;

import java.util.Vector;


public class GradeCurricular {
    Vector<Disciplina> disciplinas = new Vector<Disciplina>();
    
    void incluiDisciplina (Disciplina d) {
        disciplinas.add(d);
    }
    
    void removeDisciplina (Disciplina d) {
        disciplinas.remove(d);
    }

    int nroDisciplinas() {
        return disciplinas.size();
    }
}
