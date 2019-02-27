package pratica10;
//João Paulo de Oliveira
public abstract class Unario implements ExpBooleana{
    private ExpBooleana oper1;
    public Unario(ExpBooleana op1){
        oper1 = op1;
    }
    
    public ExpBooleana getop1(){return oper1;}
}