package pratica10;
//João Paulo de Oliveira
public abstract class Binario implements ExpBooleana{
    private ExpBooleana oper1;
    private ExpBooleana oper2;
    
    public Binario(ExpBooleana op1, ExpBooleana op2){
        oper1 = op1;
        oper2 = op2;
    }
    public ExpBooleana getop1(){return oper1;}
    public ExpBooleana getop2(){return oper2;}
}