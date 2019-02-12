package governo;

import java.util.*;
import javax.swing.*;
public class Governo {
    public static void main(String[] args) {
        ArrayList <Pessoa> galera = new ArrayList <Pessoa>();
        Fisica f;
        Juridica j;
        String nome = new String();
        int escolha,numero,ci,fa,ra;
        int n = Integer.parseInt(JOptionPane.showInputDialog("Digite o número de pessoas a serem criadas:"));
        for(int i=0;i<n;i++){
            escolha = Integer.parseInt(JOptionPane.showInputDialog("Digite:\n1 - Pessoa Física\n2 - Pessoa Jurídica"));
            if(escolha==1){
                nome = JOptionPane.showInputDialog("Digite o nome:");
                numero = Integer.parseInt(JOptionPane.showInputDialog("Digite o número de CPF:"));
                f = new Fisica(nome,numero);
                ra = Integer.parseInt(JOptionPane.showInputDialog("Digite a Renda Anual"));
                f.atribuiRendimento(ra);
                galera.add(f);
            }
            if(escolha==2){
                nome = JOptionPane.showInputDialog("Digite o nome:");
                numero = Integer.parseInt(JOptionPane.showInputDialog("Digite o número de CNPJ:"));
                j = new Juridica(nome,numero);
                ci = Integer.parseInt(JOptionPane.showInputDialog("Digite a Contribuição Isenta:"));
                fa = Integer.parseInt(JOptionPane.showInputDialog("Digite a Fatura Anual:"));
                j.atribuiContribuicoesIsentas(ci);
                j.atribuiFaturamentoAnual(fa);
                galera.add(j);
            }
        }
        System.out.println("        Nome          Pessoa       Impostos");
        for(int i=0;i<n;i++){
            System.out.println(galera.get(i).getNome()+"   "+galera.get(i).toString()+"   "+galera.get(i).calculaImposto());
        }
        
    }
}
