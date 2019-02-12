package agendinha;

import java.util.*;

public class Agenda {
    private ArrayList<Pessoa> agenda = new ArrayList<Pessoa>();
    
    void addPessoa(String nome, String numero,String endereco){
        agenda.add(new Pessoa(nome, numero,endereco));
    }
}
