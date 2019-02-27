package agendinha;
import javax.swing.*;

public class Janela implements ActionListener {
    public Janela(){
        final JButton botaoApagar = new JButton("Apagar");
        final JButton botaoCadastrar = new JButton("Cadastrar");
        final JButton botaoProcurar = new JButton("Procurar");
        final JTextField campoNome = new JTextField(30);
        final JTextField campoTelefone = new JTextField(25);
        final JTextField campoEndereco = new JTextField(25);    
        final JFrame janela = new JFrame("Agenda");
        janela.setSize(400, 200);
        JPanel painel = new JPanel();
        JLabel nome = new JLabel("Nome:");
        JLabel telefone = new JLabel("Telefone:");
        JLabel endereco = new JLabel("Endereço");
        painel.add(nome);
        painel.add(campoNome);
        botaoApagar.addActionListener(l);
        painel.add(telefone);
        painel.add(campoTelefone);
        painel.add(new JLabel("\n"));
        painel.add(endereco);
        painel.add(campoEndereco);
        painel.add(botaoApagar);
        painel.add(botaoCadastrar);
        painel.add(botaoProcurar);
        janela.getContentPane().add(painel);
        botaoApagar.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                campoTelefone.setText("");
                campoEndereco.setText("");
                campoNome.setText("");
            }
        });
/*
        //Quando o usuário clicar no botao, limpa o campo de texto
        botaoLimpa.addActionListener (new ActionListener() {
            public void actionPerformed (ActionEvent e) {
        campoTexto.setText("");
 }
 });*/
 janela.setVisible(true);
    }
}
