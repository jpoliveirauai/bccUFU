package controleeventos;

public class Apresentador extends Participante {

    private String titulo;

    public Apresentador(String n, Evento e, String t) {
        super(n, e);
        titulo = "\"" + t + "\"";
    }

    protected String getTitulo() {
        return titulo;
    }
    public String nomeLista(){
        return getNome()+"\n";
    }
}
