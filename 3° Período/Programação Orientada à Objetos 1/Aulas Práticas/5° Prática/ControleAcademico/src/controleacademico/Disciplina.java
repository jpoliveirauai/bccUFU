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
public class Disciplina {
    String nome;
    ArrayList<Disciplina> prerequisitos;
    
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
