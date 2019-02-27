
package battleship;


public class Jogo {
    Jogador jogador1;
    Jogador jogador2;
 
    public Jogo(String nome1, String nome2){
        jogador1 = new Jogador(nome1);
        jogador2 = new Jogador(nome2);
        TelaPrincipal tela = new TelaPrincipal();
        tela.telaIntrodução();
        tela.mostraDefesa(jogador1);
        
        //...
        
        
        
        
        /*jogador1.tabela.telaIntrodução();
        
        jogador1.tabela.telaDefesa();
       */
       
     
}
     
    
}
