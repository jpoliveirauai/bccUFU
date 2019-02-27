package governo;

public abstract class Pessoa implements Contribuinte{
    private String nome;
    public void Pessoa(String nome){
        this.nome = nome;
    }
    public String getNome(){
        return nome;
    }
}
