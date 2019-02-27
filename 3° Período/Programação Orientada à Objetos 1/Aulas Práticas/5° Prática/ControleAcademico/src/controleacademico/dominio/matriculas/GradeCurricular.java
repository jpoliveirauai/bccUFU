/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controleacademico;
import java.util.Vector;
/**
 *
 * @author Marcelo
 */
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
