package controleeventos;

public class ApresentadorArtigo extends Apresentador{
    
    public ApresentadorArtigo(String n, Evento e, String t){
        super(n,e,t);
    }
    public String certificado () {
        return "Declaramos que " + getNome() + " apresentou o artigo " +
            getTitulo() + " no " + getEvento().getNome();
    } 
    public String nomeLista(){
        return getNome()+"\n";
    }
}
