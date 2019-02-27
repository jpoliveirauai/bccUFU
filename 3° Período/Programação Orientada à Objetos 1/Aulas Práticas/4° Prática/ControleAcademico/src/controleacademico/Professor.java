package controleacademico;
import java.util.*;

public class Professor {
    String nome;
    String departamento;
    ArrayList<OfertaTurma> turmasOfertadas;
    
    Professor (String nome, String d) {
        this.nome = nome;
        departamento = d;
    }    
    
    void ficaAlocadoTurma (OfertaTurma o) {
        turmasOfertadas.add(o);
        o.vinculaProfessor(this);
    }
}
