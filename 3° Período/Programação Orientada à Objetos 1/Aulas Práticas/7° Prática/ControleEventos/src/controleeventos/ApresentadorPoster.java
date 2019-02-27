package controleeventos;

public class ApresentadorPoster extends Apresentador {
     public ApresentadorPoster(String n, Evento e, String t) {
     super(n,e,t);
  }
  public String certificado () {
    return "Declaramos que " + getNome() + " apresentou o poster " +
        getTitulo() + " no " + getEvento().getNome();
  }
    public String nomeLista(){
        return getNome()+"\n";
    }
}
