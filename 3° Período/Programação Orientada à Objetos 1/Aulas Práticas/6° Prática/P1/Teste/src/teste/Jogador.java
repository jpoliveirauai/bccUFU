package teste;

public class Jogador {
    private String nome;
    private int pontos =0;
    public Jogador(String n){
        nome = new String();
        nome = n;
    }
    void aumentaPonto (int x){
        pontos+=x;
    }
    String getNome(){
        return nome;
    }

    int getPontos(){
        return pontos;    
    }
}
