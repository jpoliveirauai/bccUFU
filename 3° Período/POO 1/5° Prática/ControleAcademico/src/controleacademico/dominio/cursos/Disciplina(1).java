package controleacademico.dominio.cursos;
import java.util.*;

public class Disciplina {
    private String nome;
    private ArrayList<Disciplina> prerequisitos;
    
    public Disciplina (String nome) {
        this.nome = nome;
    }
    
    void criaPrerequisito (Disciplina d) {
        prerequisitos.add(d);
    }

    public String getNome() {
        return nome;
    }
}