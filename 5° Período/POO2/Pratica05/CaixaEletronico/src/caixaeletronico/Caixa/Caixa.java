package caixaeletronico.Caixa;

import caixaeletronico.Notas.*;
import java.time.Clock;
import java.util.*;

public class Caixa {
    ArrayList<Notas> notas;

    public void saque(int valor){
        int i=0;
//        for(i=0;i<notas.size();i++){
//            if(notas.get(i).getQuantidade()==0){
//                Notas aux = notas.get(i)
//            }
//        }
        while(valor!=0){
            if(notas.get(i).getQuantidade() > 0){
                valor=notas.get(i).SoltaNota(valor);
            }
            i++;
        }
    }
    
    public void produzNotas(int nota100,int nota50,int nota20,int nota10,int nota05){
        notas = new ArrayList(5);
        if(nota100!=0)notas.add(new Nota100(nota100));
        if(nota50!=0)notas.add(new Nota50(nota50));
        if(nota20!=0)notas.add(new Nota20(nota20));
        if(nota10!=0)notas.add(new Nota10(nota10));
        if(nota05!=0)notas.add(new Nota05(nota05));
                
    }
}