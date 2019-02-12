package mario;
//João Paulo de Oliveira
import mario.Estados.*;
public class Mario {
    int pontos;
    static Estado currentState;
    
    public Mario(){
        currentState = new Pequeno();
    }
    public String getEstadoString(){
        return currentState.getClass().getName();
    }
    public void mais1000(){
        pontos += 1000;
    }
    public static void setEstado(Estado state){
        currentState = state;
    }
    public int pegaFlor(){
        currentState.pegaFlor();
        return 0;
    }
    public int pegaPena(){
        currentState.pegaPena();
        return 0;
    }
    public int pegaComgumelo(){
        currentState.pegaComgumelo();
        return 0;
    }
    public int levarDano(){
        currentState.levarDano();
        return 0;
    }
}