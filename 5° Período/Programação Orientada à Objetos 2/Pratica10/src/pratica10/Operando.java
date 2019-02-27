package pratica10;
//João Paulo de Oliveira
public class Operando implements ExpBooleana{
    private boolean conteudo;
    public boolean operacao(){
        return conteudo;
    }
    public Operando (boolean cont){
        conteudo = cont;
    }
}