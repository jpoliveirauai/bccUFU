package pratica10;
//João Paulo de Oliveira
public class Or extends Binario{
    public Or(ExpBooleana op1, ExpBooleana op2){
        super(op1,op2);
    }
    public boolean operacao(){
        return getop1().operacao() || getop2().operacao();
    }
}