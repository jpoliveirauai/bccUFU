package revisao_p1;

public class Revisao_P1 {
String nome, endereco;

String informacoes () {
    return "Nome: " + nome + "\nEndereco: " + endereco + "\n";
}
public static void main(String args[]) {
    Revisao_P1 grupo[] = new Revisao_P1[2];
    grupo[0] = new Revisao_P1();
    grupo[1]     = new Revisao_P1();
    grupo[0].nome = "Joao"; grupo[1].nome = "Jose";
    grupo[0].endereco = "Rua A, I"; grupo[1].endereco = "Rua B, 2";
    for (int i=0; i<2; i++)
        System.out.println(grupo[i].informacoes());
    }
}
