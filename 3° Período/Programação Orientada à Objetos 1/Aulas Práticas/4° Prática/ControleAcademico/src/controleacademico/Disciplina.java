package controleacademico;
import java.util.*;

public class Disciplina {
    String nome;
    ArrayList<Disciplina> prerequisitos = new ArrayList<Disciplina>();
    Disciplina (String nome) {
        this.nome = nome;
    }
    
    void criaPrerequisito (Disciplina d) {
        prerequisitos.add(d);
    }

    String getNome() {
        return nome;
    }
}
