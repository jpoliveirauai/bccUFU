package teste;
import javax.swing.*;
import java.util.*;
public class Teste {
    public static void main(String[] args) {
        int n = Integer.parseInt(JOptionPane.showInputDialog("Digite o número de Jogadores:"));
        String name;
        ArrayList<Jogador> jogadores = new ArrayList<Jogador>();
        ArrayList<Jogador>vencedores = new ArrayList<Jogador>();
        
        for(int i=0;i<n;i++){
            name = JOptionPane.showInputDialog("Digite o nome do Jogador "+ (i+1) +":");
            jogadores.add(new Jogador(name));
        }
        Jogo novoJogo = new Jogo();
        if(novoJogo.inicio(jogadores)){
            vencedores = novoJogo.vencedores();
            System.out.println("Vencedores:");
            for(int i=0;i<vencedores.size();i++){
                System.out.println(vencedores.get(i).getNome() +" "+vencedores.get(i).getPontos()+" pontos");
            }
        }
    }
}
