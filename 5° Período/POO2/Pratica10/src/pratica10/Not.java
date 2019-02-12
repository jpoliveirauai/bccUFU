package pratica10;
//João Paulo de Oliveira
public class Not extends Unario{
    public Not(ExpBooleana op1){
        super(op1);
    }
    public boolean operacao(){
        return !(getop1().operacao());
    }
}