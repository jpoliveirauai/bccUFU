
package DAL;
import java.sql.*;
import javax.swing.JOptionPane;

public class Conectabd {
    
     private static final String url = "jdbc:postgresql://localhost:5432/rock_in_rio?currentSchema=palcos";
    
    
    
    public static Connection Conectabd(String u, String s) throws ClassNotFoundException{
        String user;
        String password;
       
        user = u;
        password = s;
        
        try{
        Class.forName("org.postgresql.Driver");
        Connection con = DriverManager.getConnection(url,user,password);
        //JOptionPane.showMessageDialog(null, "Conexão estabelecida com sucesso!");
        return con;
        }
            catch(SQLException error){
            JOptionPane.showMessageDialog(null, error);
            return null;
        }
        
    }
}
