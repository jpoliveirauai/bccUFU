package caixaeletronico.Caixa;

import caixaeletronico.Notas.*;
import java.time.Clock;
import java.util.*;

public class Caixa {
    ArrayList<Notas> notas = new ArrayList(7);
    /*
    100: 0
    50:  1
    20:  2
    10:  3
    05:  4
    02:  5
    */
    
    
    public Caixa(int quantidade){
        notas.add(new Nota100(quantidade));
        notas.add(new Nota50(quantidade));
        notas.add(new Nota20(quantidade));
        notas.add(new Nota10(quantidade));
        notas.add(new Nota05(quantidade));
        notas.add(new Nota02(quantidade));
        notas.add(new Nota01(quantidade));
        
    }
    public void saque(int valor){
        int i=0;
        while(valor!=0){
            valor=notas.get(i).SoltaNota(valor);
            i++;
        }
    }
}
            
  
