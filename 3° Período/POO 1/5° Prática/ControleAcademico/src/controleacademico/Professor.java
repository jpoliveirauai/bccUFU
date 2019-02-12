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
