package battleship;

import java.awt.*;
import javax.swing.*;

public class Jogador {

    int nBarco1, nBarco2_1,nBarco2_2, nBarco3_1,nBarco3_2, nBarco2_3, nBarco4;
    String nome;
    int pontos;
    int tabuleiroAta[][];
    int tabuleiroDef[][];
    TelaPrincipal tabela;

    public Jogador(String nome) {
        this.nome = nome;
        this.pontos = 0;
        tabuleiroDef = new int[10][10];
        nBarco1 = 4;
        nBarco3_1 = 3;
        nBarco3_2 = 3;
        
        nBarco2_1 = 2;
        nBarco2_2 = 2;
        nBarco2_3 = 2;
        nBarco4 = 4;
        //tabela = new TelaPrincipal();
    }
    public boolean insereBarco(JButton b){
        if(insereBarco4(b)==1)return true;
            else if(insereBarco3_2(b)==1) return true;
                else if(insereBarco3_1(b)==1) return true;
                    else if(insereBarco2_3(b)==1) return true;
                        else if(insereBarco2_2(b)==1) return true;
                            else if(insereBarco2_1(b)==1) return true;
                                else if(insereBarco1(b)==1) return true;
        if(nBarco2_1==0 && nBarco2_2==0 && nBarco2_3==0 && nBarco4==0) return false;
        return true;
    }
    
    

    private int insereBarco4(JButton b) {
        if (nBarco4 == 0) {
            //System.out.println("tah");
            return 0;
        }
        int n = Integer.parseInt(b.getName());
        int n0, n1;
        n0 = n % 10;
        n = (int) n / 10;
        n1 = n % 10;
        if (tabuleiroDef[n1][n0] != 0) {
            return -1;
        }
        if (nBarco4 < 3) {
            boolean vertical = true;
            if(ehVizinho(n1, n0, 4)){
                int i1 = retornaLinhaViziho(n1, n0, 4),j1 = retornaColunaViziho(n1, n0, 4);
                if(i1==-1||j1==-1){
                    return -1;
                }
                int i2 = retornaLinhaViziho(i1, j1, 4),j2 = retornaColunaViziho(i1, j1, 4);
                if(i1==i2) vertical = false;
                if(j1==j2) vertical = true;
                if(vertical == true && n0!=j1) return -1;
                if(vertical == false && n1!=i1) return -1;
            }else return -1;
        }
        if (nBarco4 == 3) {
            if (!ehVizinho(n1, n0, 4)) {
                return -1;
            }
        }
        tabuleiroDef[n1][n0] = 4;
        b.setBackground(Color.PINK);
        b.setEnabled(false);
        printMatriz(); //Coloca barco de 1 cano;
        nBarco4--;
        return 1;
    }
    
    private int insereBarco3_2(JButton b) {
        if (nBarco3_2 == 0||nBarco4!=0) {
            return 0;
        }
        int n = Integer.parseInt(b.getName());
        int n0, n1;
        n0 = n % 10;
        n = (int) n / 10;
        n1 = n % 10;
        
        if (tabuleiroDef[n1][n0] != 0) {
            return -1;
        }
        if (nBarco3_2 == 1) {
            boolean vertical = true;
            if(ehVizinho(n1, n0, 3)){
                int i1 = retornaLinhaViziho(n1, n0, 3),j1 = retornaColunaViziho(n1, n0, 3);
                if(i1==-1||j1==-1){
                    return -1;
                }
                int i2 = retornaLinhaViziho(i1, j1, 3),j2 = retornaColunaViziho(i1, j1, 3);
                if(i1==i2) vertical = false;
                if(j1==j2) vertical = true;
                if(vertical == true && n0!=j1) return -1;
                if(vertical == false && n1!=i1) return -1;
            }else return -1;
        }
        if (nBarco3_2 == 2) {
            if (!ehVizinho(n1, n0, 3)) {
                return -1;
            }
        }
        tabuleiroDef[n1][n0] = 3;
        b.setBackground(Color.ORANGE);
        b.setEnabled(false);
        printMatriz(); //Coloca barco de 1 cano;
        nBarco3_2--;
        return 1;
    }
    
    private int insereBarco3_1(JButton b) {
        if (nBarco3_1 == 0|| nBarco3_2!=0) {
            return 0;
        }
        int n = Integer.parseInt(b.getName());
        int n0, n1;
        n0 = n % 10;
        n = (int) n / 10;
        n1 = n % 10;
        
        if (tabuleiroDef[n1][n0] != 0) {
            return -1;
        }
        if (nBarco3_1 == 1) {
            boolean vertical = true;
            if(ehVizinho(n1, n0, 3)){
                int i1 = retornaLinhaViziho(n1, n0, 3),j1 = retornaColunaViziho(n1, n0, 3);
                if(i1==-1||j1==-1){
                    return -1;
                }
                int i2 = retornaLinhaViziho(i1, j1, 3),j2 = retornaColunaViziho(i1, j1, 3);
                if(i1==i2) vertical = false;
                if(j1==j2) vertical = true;
                if(vertical == true && n0!=j1) return -1;
                if(vertical == false && n1!=i1) return -1;
            }else return -1;
        }
        if (nBarco3_1 == 2) {
            if (!ehVizinho(n1, n0, 3)) {
                return -1;
            }
        }
        tabuleiroDef[n1][n0] = 3;
        b.setBackground(Color.ORANGE);
        b.setEnabled(false);
        printMatriz(); //Coloca barco de 1 cano;
        nBarco3_1--;
        return 1;
    }
    
    private int insereBarco2_3(JButton b){
        if (nBarco2_3 == 0|| nBarco3_1!=0) {
            return 0;
        }
        int n = Integer.parseInt(b.getName());
        int n0, n1;
        n0 = n % 10;
        n = (int) n / 10;
        n1 = n % 10;
        
        if (tabuleiroDef[n1][n0] != 0) {
            return -1;
        }
        if (nBarco2_3 == 1) {
            if (!ehVizinho(n1, n0, 2)) {
                return -1;
            }
        }
        tabuleiroDef[n1][n0] = 2;
        b.setBackground(Color.GREEN);
        b.setEnabled(false);
        printMatriz(); //Coloca barco de 1 cano;
        nBarco2_3--;
        return 1;
    }
    
    private int insereBarco2_2(JButton b){
        if (nBarco2_2 == 0||nBarco2_3!=0) {
            return 0;
        }
        int n = Integer.parseInt(b.getName());
        int n0, n1;
        n0 = n % 10;
        n = (int) n / 10;
        n1 = n % 10;
        
        if (tabuleiroDef[n1][n0] != 0) {
            return -1;
        }
        if (nBarco2_2 == 1) {
            if (!ehVizinho(n1, n0, 2)) {
                return -1;
            }
        }
        tabuleiroDef[n1][n0] = 2;
        b.setBackground(Color.GREEN);
        b.setEnabled(false);
        printMatriz(); //Coloca barco de 1 cano;
        nBarco2_2--;
        return 1;
    }
    
    private int insereBarco2_1(JButton b){
        if (nBarco2_1 == 0 || nBarco2_2!=0) {
            return 0;
        }
        int n = Integer.parseInt(b.getName());
        int n0, n1;
        n0 = n % 10;
        n = (int) n / 10;
        n1 = n % 10;
        
        if (tabuleiroDef[n1][n0] != 0) {
            return -1;
        }
        if (nBarco2_1 == 1) {
            if (!ehVizinho(n1, n0, 2)) {
                return -1;
            }
        }
        tabuleiroDef[n1][n0] = 2;
        b.setBackground(Color.GREEN);
        b.setEnabled(false);
        printMatriz(); //Coloca barco de 1 cano;
        nBarco2_1--;
        return 1;
    }
    
    private int insereBarco1(JButton b) {
        if (nBarco1 == 0 || nBarco2_1!=0) {
            return 0;
        }
        int n = Integer.parseInt(b.getName());
        int n0, n1;
        n0 = n % 10;
        n = (int) n / 10;
        n1 = n % 10;
        if (tabuleiroDef[n1][n0] != 0) {
            return -1;
        }
        tabuleiroDef[n1][n0] = 1;
        b.setBackground(Color.black);
        b.setEnabled(false);
        printMatriz(); //Coloca barco de 1 cano;
        nBarco1--;
        return 1;
    }

    public boolean venceu() {
        if (pontos == 20) {
            return true;
        } else {
            return false;
        }
    }

    public int acertou(int n) {
        int n0, n1;
        n0 = n % 10;
        n = (int) n / 10;
        n1 = n % 10;
        if (tabuleiroAta[n1][n0] == 1) {
            pontos++;
            tabuleiroAta[n1][n0] = 2;
            return 1;
        }
        tabuleiroAta[n1][n0] = 2;
        return 0;
    }

    boolean ehVizinho(int i, int j, int barco){
        if(j+1<10)
            if (tabuleiroDef[i][j + 1] == barco)return true;
        if(j-1>=0)
            if (tabuleiroDef[i][j - 1] == barco)return true;
        if(i+1<10)
            if (tabuleiroDef[i + 1][j] == barco)return true;
        if(i-1>=0)
            if (tabuleiroDef[i - 1][j] == barco)return true;
        return false;
    }
    int retornaLinhaViziho(int i,int j,int barco){
        if(i+1<10)
            if (tabuleiroDef[i + 1][j] == barco)return i+1;
        if(i-1>=0)
            if (tabuleiroDef[i - 1][j] == barco)return i-1;
        if(j+1<10)
            if (tabuleiroDef[i][j + 1] == barco)return i;
        if(j-1>=0)
            if (tabuleiroDef[i][j - 1] == barco)return i;
        return -1;
    }
    int retornaColunaViziho(int i,int j,int barco){
        if(i+1<10)
            if (tabuleiroDef[i + 1][j] == barco)return j;
        if(i-1>=0)
            if (tabuleiroDef[i - 1][j] == barco)return j;
        if(j+1<10)
            if (tabuleiroDef[i][j + 1] == barco)return j+1;
        if(j-1>=0)
            if (tabuleiroDef[i][j - 1] == barco)return j-1;
        return -1;
    }
    
    public void printMatriz() {
        for (int i = 0; i < 10; i++) {
            System.out.println(" ");
            for (int j = 0; j < 10; j++) {
                System.out.print(" " + Integer.toString(tabuleiroDef[i][j]));
            }
        }
        System.out.println(" ");
    }

}
