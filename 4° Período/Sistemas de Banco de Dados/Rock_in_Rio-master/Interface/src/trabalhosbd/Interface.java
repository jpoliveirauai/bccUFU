
package trabalhosbd;

import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.JOptionPane;

public class Interface {
    
    public Interface(){
        JFrame janelainterface = new JFrame("ROCK IN RIO");    //Declaração da janela principal
        janelainterface.setSize(910,553);
        janelainterface.setBackground(Color.black);
        janelainterface.setUndecorated(true);          //Setar isso aqui para true depois
        janelainterface.setLocationRelativeTo(null);
        Container conteudo = janelainterface.getContentPane(); 
             
        ImagePanel background = new ImagePanel("Imagens/Rock-In-Rio.jpg"); //Declaração do painel de conteudo
        janelainterface.add(background);
        
       
       
        JButton sair = new JButton("Sair");
        JButton login = new JButton("Login");
        //JButton cadastro = new JButton("Cadastre-se");
        
        
        background.setLayout(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        c.fill = GridBagConstraints.HORIZONTAL;
        c.anchor = GridBagConstraints.FIRST_LINE_START; //bottom of space
             
        
        //background.add(cadastro,c); 
        background.add(login,c);  
        background.add(sair, c);
        
        sair.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent evt){
                janelainterface.dispose();
            }
        }
        );
        
        login.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent evt){
                
                try {                  
                    JanelaLogin janelaLogin = new JanelaLogin();
                } catch (ClassNotFoundException ex) {
                    Logger.getLogger(Interface.class.getName()).log(Level.SEVERE, null, ex);
                }
                 janelainterface.dispose();
        
            }
        }
        ); 
        
        /*cadastro.addActionListener(new ActionListener(){
        
        public void actionPerformed(ActionEvent evt){
            
                JanelaCadastro janelaCadastro = new JanelaCadastro();
                janelainterface.dispose();
        }
                
        }
                
        );*/
       
       
         
        janelainterface.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janelainterface.setVisible(true);
        janelainterface.setResizable(false);
        
                
    }
}
