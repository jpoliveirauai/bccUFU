package teste;

import javax.swing.*;
public class JogoMemoria {
   public String palavras[] = null;
   JogadorMemoria jogadores[];
   JogoMemoria () {
	   String palavra;
	   convidaJogadores();
	   brincaComPalavras();
	   JOptionPane.showMessageDialog(null,jogadores[vencedor()].nome + " ganhou!!!");
   }
   void convidaJogadores () {
	   int nroJogadores = Integer.parseInt(JOptionPane.showInputDialog("Digite nro. jogadores"));
	   palavras = new String[nroJogadores];
	   jogadores = new JogadorMemoria[nroJogadores];
	   for (int i=0; i<nroJogadores; i++) {
		   jogadores[i] = new JogadorMemoria(JOptionPane.showInputDialog("Escreva seu nome"));
		   palavras[i] = JOptionPane.showInputDialog("Forneça uma palavra qualquer");
	   }
   }
   void brincaComPalavras () {
      do {
         for (int i=0; i<jogadores.length; i++) {
      	    for (int j=0; j < jogadores.length; j++)
	       if (i!=j) {
	          String palavra = JOptionPane.showInputDialog(jogadores[i].nome +
                                                   ", lembre a palavra do "+jogadores[j].nome);
	          if (palavras[j].equals(palavra))
	    	       jogadores[i].aumentaPontos();
	    	}
	  }
	  jogadores[ganhadorRodada()].aumentaRodadasGanhas();
	  JOptionPane.showMessageDialog(null,"O ganhador da rodada foi " + jogadores[ganhadorRodada()].nome);
	      for (int i=0; i<jogadores.length;i++)
	    	  jogadores[i].pontos = 0;
	   } while (JOptionPane.showInputDialog("Quer parar? (s/n)").equals("n"));
   }
   boolean temPalavra (String p) {
	   for (int i = 0; i<palavras.length; i++)
		   if (palavras[i].equals(p))
			   return true;
	   return false;
   }
   int vencedor () {
	   int maioral=0;
	   for (int i=1; i< jogadores.length; i++)
		   if (jogadores[i].melhor(jogadores[maioral]))
			   maioral = i;
	   return maioral;
   }
   int ganhadorRodada () {
	   int ganhador=0;
	   for (int i=1; i<jogadores.length; i++)
		   if (jogadores[i].pontos > jogadores[ganhador].pontos)
			   ganhador = i;	   
	   return ganhador;
   }
   public static void main (String args[]) {
	   new JogoMemoria();
   }
}

class JogadorMemoria {
	String nome;
	int    pontos;
	int    rodadasGanhas;
	JogadorMemoria (String n) {
		nome = n;
	}
	boolean melhor (JogadorMemoria outro) {
		if (this.rodadasGanhas > outro.rodadasGanhas)
			return true;
		return false;
	}
	void aumentaPontos () {
		pontos++;
	}
       void aumentaRodadasGanhas () {
    	   rodadasGanhas++;
       }
}
