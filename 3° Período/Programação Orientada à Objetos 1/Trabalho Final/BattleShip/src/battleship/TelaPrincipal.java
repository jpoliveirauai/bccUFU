package battleship;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class TelaPrincipal{
    private JFrame introducao;
    private JFrame defesa1;
    private JFrame defesa2;
    JButton[][] matrizBotoes;
    Jogador player1;
    Jogador player2;
    public TelaPrincipal(Jogador jog1,Jogador jog2){
        introducao = new JFrame("Batalha Naval");
        
    }
    void telaIntrodução(){
        introducao.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
        introducao.setBounds(0, 0,1045, 590); // configurações da tela de laucher
        
        JLabel imagem = new JLabel(new ImageIcon("imagens/battleship.gif"));
        JButton star = new JButton("  Start a game  ");
        imagem.setBorder(BorderFactory.createTitledBorder("Click para ir para tela inicial"));
        introducao.add(imagem);
        introducao.add(star,BorderLayout.SOUTH);
        star.addActionListener(start);
        introducao.setVisible(true);
        
    }
   
    void telaDefesa(Jogador player){
        JButton next = new JButton(" Next ");
        next.setEnabled(false);
       
        defesa1 = new JFrame("Tela Defesa");
        defesa1.setBounds(0, 0, 1030, 580); // Configurações da tela Defesa
      
        JPanel tabela = new JPanel(new GridLayout(10,10)); // Cria matriz de Defesa
        JPanel num = new JPanel(new GridLayout(10,1)); // Cria do 0 ao 9
        JButton botaoD[] = new JButton[10];    
        for(int i = 0; i < 10; i++){
             botaoD[i] = new JButton(Integer.toString(i));
             botaoD[i].setEnabled(false);
             num.add(botaoD[i]);
        }
        JPanel num2 = new JPanel(new GridLayout(1,10)); // Cria do 0 ao 9
        JButton botaoD2[] = new JButton[10];    
        for(int i = 0; i < 10; i++){
             botaoD2[i] = new JButton(Integer.toString(i));
             botaoD2[i].setEnabled(false);
             num2.add(botaoD2[i]);
        }
        
        matrizBotoes = new JButton[10][10];
        int i, j;
        for(i = 0; i < 10; i++){
            for(j = 0; j < 10; j++){
                matrizBotoes[i][j] = new JButton();
                matrizBotoes[i][j].setName(Integer.toString(i)+Integer.toString(j));
                matrizBotoes[i][j].addActionListener(insereBarco);
                tabela.add(matrizBotoes[i][j]);               
            }                
        }        
        defesa1.add(tabela,BorderLayout.CENTER);
        defesa1.add(num,BorderLayout.WEST);
        defesa1.add(next,BorderLayout.SOUTH);
        defesa1.add(num2,BorderLayout.NORTH);
        defesa1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    
    ActionListener start = new ActionListener (){
        public void actionPerformed(ActionEvent e){
           introducao.setVisible(false);
           //defesa1.setVisible(true);
        }
    };       
    
     ActionListener insereBarco = new ActionListener (){
            public void actionPerformed(ActionEvent e){
                if(jog1.insereBarco((JButton)e.getSource())==false) {
                    next.setEnabled(true);
                    System.out.println("hola");
                }
            }
        };
        // ******** Metodos das funções
    void mostraDefesa(Jogador j){
        telaDefesa(j);
        defesa1.setVisible(true);
    }
    void tiraTelaDef(){
        defesa1.setVisible(false);
    }
        
}
