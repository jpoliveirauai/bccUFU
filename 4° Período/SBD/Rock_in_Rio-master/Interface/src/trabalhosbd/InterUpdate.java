/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalhosbd;
import DAL.Conectabd;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;



/**
 *
 * @author Lucas
 */
public class InterUpdate extends javax.swing.JInternalFrame {

    Connection conecta = null;
    PreparedStatement pst;
    ResultSet rs;
    /**
     * Creates new form InterUpdate
     */
    public InterUpdate(String nome, String senha) throws SQLException, ClassNotFoundException {
        initComponents();
        
        if(conecta != null){
            conecta.close();
        };
        conecta = Conectabd.Conectabd(nome, senha);
    }

    public void MudaNomeBanda(){
        String vazio = BandaNovo.getText();
        if(vazio.isEmpty())
         {
            
         }else
        {
           String sql = "Update banda set nome = ? where nome = ? ";  
            try {
                pst = conecta.prepareStatement(sql);
                pst.setString(1, BandaNovo.getText());
                pst.setString(2, BandaAntigo.getText());
                pst.execute();
                
                JOptionPane.showMessageDialog(null,"Nome da banda alterado com sucesso!");
            } catch (SQLException ex) {
                Logger.getLogger(InterUpdate.class.getName()).log(Level.SEVERE, null, ex);
                JOptionPane.showMessageDialog(null,"Erro!");
            }
                     
           
         }
        
    }
    
    public void MudaGeneroBanda(){
        String vazio = NovoGenero.getText();
        if(vazio.isEmpty()){
            
        }else{
            String sql = "Update banda set genero = ? where nome = ?";
            
            try {
                pst = conecta.prepareStatement(sql);
                pst.setString(1, NovoGenero.getText());
                pst.setString(2, BandaAntigo.getText());
                pst.execute();
                
                JOptionPane.showMessageDialog(null,"Genero da banda alterado com sucesso!");
            } catch (SQLException ex) {
                Logger.getLogger(InterUpdate.class.getName()).log(Level.SEVERE, null, ex);
                JOptionPane.showMessageDialog(null,"Erro!");
            }
        }
        
        
    }
    
    public void MudaNomeArtista(){
        String vazio = ArtistaNovo.getText();
        if(vazio.isEmpty()){
            
        }else{
            String sql = "update artista set nome = ? where nome = ?";
            
            try {
                pst = conecta.prepareStatement(sql);
                pst.setString(1, ArtistaNovo.getText());
                pst.setString(2, ArtistaAntigo.getText());
                pst.execute();
                
                JOptionPane.showMessageDialog(null,"Nome do artista alterado com sucesso!");
            } catch (SQLException ex) {
                Logger.getLogger(InterUpdate.class.getName()).log(Level.SEVERE, null, ex);
                JOptionPane.showMessageDialog(null,"Erro!");
            }
        }
        
    }
    
    
    public void MudaNacionalidade(){
        String vazio = NacionalidadeNova.getText();
        if(vazio.isEmpty()){
            
        }else{
            String sql = "update artista set nacionalidade = ? where nome = ?";
            
            try {
                pst = conecta.prepareStatement(sql);
                pst.setString(1, NacionalidadeNova.getText());
                pst.setString(2, ArtistaAntigo.getText());
                pst.execute();
                
                JOptionPane.showMessageDialog(null,"Nacionalidade do artista alterado com sucesso!");
            } catch (SQLException ex) {
                Logger.getLogger(InterUpdate.class.getName()).log(Level.SEVERE, null, ex);
                JOptionPane.showMessageDialog(null,"Erro!");
            }
           
        }
        
    }
    
    public void  MudaArtistadeBanda(){
        String vazio = ArtistaBanda.getText();
        String vazio2 = BandaAntiga.getText();
        String vazio3 = BandaNova.getText();
        if(vazio.isEmpty() || vazio2.isEmpty() || vazio3.isEmpty()){
            
        }else{
            String sql = "Update toca_em set banda = (select cod from banda where nome = ?) where artista = ? and banda = (select cod from banda where nome = ?)";
            
            try {
                pst = conecta.prepareStatement(sql);
                pst.setString(1, BandaNova.getText());
                pst.setString(2, ArtistaBanda.getText());
                pst.setString(3, BandaAntiga.getText());
                
                pst.execute();
                JOptionPane.showMessageDialog(null,"O Artista foi movido para outra banda com sucesso!");
            } catch (SQLException ex) {
                Logger.getLogger(InterUpdate.class.getName()).log(Level.SEVERE, null, ex);
                JOptionPane.showMessageDialog(null,"Erro!");
            }
        }
        
        
    }
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        BandaAntigo = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        jButton1 = new javax.swing.JButton();
        BandaNovo = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        ArtistaAntigo = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        ArtistaNovo = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        ArtistaBanda = new javax.swing.JTextField();
        BandaAntiga = new javax.swing.JTextField();
        jLabel8 = new javax.swing.JLabel();
        jButton3 = new javax.swing.JButton();
        jButton4 = new javax.swing.JButton();
        jLabel15 = new javax.swing.JLabel();
        jLabel16 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        BandaNova = new javax.swing.JTextField();
        jLabel9 = new javax.swing.JLabel();
        NacionalidadeNova = new javax.swing.JTextField();
        jLabel10 = new javax.swing.JLabel();
        NovoGenero = new javax.swing.JTextField();
        jLabel11 = new javax.swing.JLabel();

        setBackground(new java.awt.Color(255, 255, 255));
        setClosable(true);
        setIconifiable(true);

        jLabel1.setText("Digite o nome da Banda:");

        BandaAntigo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BandaAntigoActionPerformed(evt);
            }
        });

        jLabel2.setText("Digite o novo nome da banda:");

        jButton1.setText("Atualizar Banda");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jLabel3.setText("Digite o nome do artista:");

        jLabel4.setText("Digite o novo nome do artista:");

        ArtistaNovo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ArtistaNovoActionPerformed(evt);
            }
        });

        jLabel5.setText("Digite o nome do Artista:");

        jLabel8.setText("Digite o nome da banda antiga:");

        jButton3.setText("Mover Artista");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jButton4.setText("Atualizar Artista");
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });

        jLabel15.setFont(new java.awt.Font("Cooper Black", 0, 11)); // NOI18N
        jLabel15.setText("Mudar o nome de uma banda:");

        jLabel16.setFont(new java.awt.Font("Cooper Black", 0, 11)); // NOI18N
        jLabel16.setText("Mudar as informações do Artista:");

        jLabel6.setFont(new java.awt.Font("Cooper Black", 0, 11)); // NOI18N
        jLabel6.setText("Mudar um artista de banda:");

        jLabel7.setText("Digite o nome da nova banda:");

        BandaNova.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BandaNovaActionPerformed(evt);
            }
        });

        jLabel9.setText("Digite a nova nacionalidade do artista:");

        NacionalidadeNova.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                NacionalidadeNovaActionPerformed(evt);
            }
        });

        jLabel10.setText("Digite o novo gênero da banda:");

        jLabel11.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagens/rock-in-rio.png"))); // NOI18N

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel1)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel15)
                                    .addComponent(BandaNovo, javax.swing.GroupLayout.PREFERRED_SIZE, 129, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jLabel10)
                                    .addComponent(jButton1)
                                    .addComponent(NovoGenero, javax.swing.GroupLayout.PREFERRED_SIZE, 128, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGap(84, 84, 84)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel3)
                                    .addComponent(jLabel16)
                                    .addComponent(ArtistaAntigo, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jLabel4)
                                    .addComponent(jLabel9)
                                    .addComponent(ArtistaNovo, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jButton4)
                                    .addComponent(NacionalidadeNova, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addComponent(jLabel2)
                            .addComponent(BandaAntigo, javax.swing.GroupLayout.PREFERRED_SIZE, 124, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(79, 79, 79)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel7)
                            .addComponent(jButton3)
                            .addComponent(BandaAntiga, javax.swing.GroupLayout.PREFERRED_SIZE, 128, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel8)
                            .addComponent(ArtistaBanda, javax.swing.GroupLayout.PREFERRED_SIZE, 124, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel5)
                            .addComponent(jLabel6)
                            .addComponent(BandaNova, javax.swing.GroupLayout.PREFERRED_SIZE, 130, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addContainerGap())
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(jLabel11)
                        .addGap(124, 124, 124))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addComponent(jLabel11, javax.swing.GroupLayout.PREFERRED_SIZE, 136, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(49, 49, 49)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel15)
                    .addComponent(jLabel16)
                    .addComponent(jLabel6))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(jLabel3)
                    .addComponent(jLabel5))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED, 22, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(BandaAntigo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(ArtistaAntigo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(ArtistaBanda, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(jLabel4)
                    .addComponent(jLabel8))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(BandaNovo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(ArtistaNovo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(BandaAntiga, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(jLabel9)
                    .addComponent(jLabel10))
                .addGap(15, 15, 15)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(BandaNova, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(NacionalidadeNova, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(NovoGenero, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jButton3)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jButton4)
                        .addComponent(jButton1)))
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void BandaAntigoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BandaAntigoActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_BandaAntigoActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        MudaGeneroBanda();
        MudaNomeBanda();
    }//GEN-LAST:event_jButton1ActionPerformed

    private void ArtistaNovoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ArtistaNovoActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_ArtistaNovoActionPerformed

    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton4ActionPerformed
        MudaNacionalidade();
        MudaNomeArtista();
    }//GEN-LAST:event_jButton4ActionPerformed

    private void BandaNovaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BandaNovaActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_BandaNovaActionPerformed

    private void NacionalidadeNovaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_NacionalidadeNovaActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_NacionalidadeNovaActionPerformed

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
        MudaArtistadeBanda();
    }//GEN-LAST:event_jButton3ActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField ArtistaAntigo;
    private javax.swing.JTextField ArtistaBanda;
    private javax.swing.JTextField ArtistaNovo;
    private javax.swing.JTextField BandaAntiga;
    private javax.swing.JTextField BandaAntigo;
    private javax.swing.JTextField BandaNova;
    private javax.swing.JTextField BandaNovo;
    private javax.swing.JTextField NacionalidadeNova;
    private javax.swing.JTextField NovoGenero;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel15;
    private javax.swing.JLabel jLabel16;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    // End of variables declaration//GEN-END:variables
}
