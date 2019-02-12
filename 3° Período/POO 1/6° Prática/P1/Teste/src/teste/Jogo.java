package teste;
import java.util.*;
public class Jogo {
    int dado=0;
    boolean acabou=false;
    ArrayList<Jogador> winners = new ArrayList<Jogador>();
    
    boolean inicio(ArrayList<Jogador> jogadores){
        System.out.println("Jogador ");
        while(!acabou){
            for(int i=0;i<jogadores.size();i++){
                dado = ((int)(Math.random()*6)+1);
                System.out.println("Jogador "+(i+1)+" joga do dado:\n" + dado +"\n");
                jogadores.get(i).aumentaPonto(dado);
                if(jogadores.get(i).getPontos()>=10){
                    acabou = true;
                    winners.add(jogadores.get(i));
                }
            }
        }
        return acabou;
}
    ArrayList<Jogador> vencedores(){
        return winners;
    }
}