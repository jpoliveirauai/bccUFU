package teste;

import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class minicalc {
    JFrame janela;
    public minicalc(){
        janela = new JFrame("MiniCalc");
//        int a,b;
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janela.setSize(350,100);
        JTextField op01 = new JTextField(5);
        JTextField op02 = new JTextField(5);
        JTextField op11 = new JTextField(5);
        JTextField op12 = new JTextField(5);
        JTextField re1 = new JTextField(5);
        JTextField re2 = new JTextField(5);
        op01.setText("0");
        op11.setText("0");
        op02.setText("0");
        op12.setText("0");
        re1.setEnabled(false);
        re2.setEnabled(false);
        JButton igual1 = new JButton("=");
        JButton igual2 = new JButton("=");
        JLabel mais = new  JLabel("+");
        JLabel vezes = new  JLabel("*");
        JPanel soma = new JPanel();
        JPanel multiplica = new JPanel();
        
        
        igual1.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                final int a = Integer.parseInt(op02.getText()) + Integer.parseInt(op01.getText());
                re1.setText(Integer.toString(a));
            }
        });
        igual2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                final int b = Integer.parseInt(op12.getText()) + Integer.parseInt(op11.getText());
                re2.setText(Integer.toString(b));
            }
        });
        soma.add(op01);
        soma.add(mais);
        soma.add(op02);
        soma.add(igual1);
        soma.add(re1);
        janela.add(soma,BorderLayout.NORTH);
        multiplica.add(op11);
        multiplica.add(mais);
        multiplica.add(op12);
        multiplica.add(igual2);
        multiplica.add(re2);
        janela.add(multiplica,BorderLayout.SOUTH);
        janela.setVisible(true);
    }
    
}
