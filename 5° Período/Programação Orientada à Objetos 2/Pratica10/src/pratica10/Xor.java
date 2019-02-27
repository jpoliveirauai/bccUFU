package pratica10;
//João Paulo de Oliveira
public class Xor extends Binario{
    public Xor(ExpBooleana op1, ExpBooleana op2){
        super(op1,op2);
    }
    public boolean operacao(){
        return getop1().operacao() ^ getop2().operacao();
    }
}