import javax.swing.*;
class Pessoa {
    String nome;
    double peso, altura;

    double calculaIMC() {
        return peso / (altura * altura);
    }

    String avaliaIMC() {
        double imc = calculaIMC();
        if (imc < 18.5) {
            return "abaixo do peso!!!";
        }
        if (imc >= 18.5 && imc <= 25) {
            return "com peso normal.";
        }
        if (imc > 25 && imc <= 30) {
            return "acima do peso!";
        }
        return "obeso!!!";
    }

}

public class Teste {

    public static void main(String args[]) {
        Pessoa p = new Pessoa();
        p.nome = JOptionPane.showInputDialog("Entre com seu nome");
        p.altura = Double.parseDouble(
        JOptionPane.showInputDialog("Entre com sua altura"));
        p.peso = Double.parseDouble(JOptionPane.showInputDialog("Entre com seu peso"));
        JOptionPane.showMessageDialog(null,"" + p.nome + " seu IMC = " + p.calculaIMC());
        JOptionPane.showMessageDialog(null,"Isto significa que voce estah " + p.avaliaIMC());       
    }
}