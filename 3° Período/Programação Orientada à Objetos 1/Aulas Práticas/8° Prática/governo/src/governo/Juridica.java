package governo;

public class Juridica extends Pessoa{
    private int cnpj;
    private float fa;
    private float ci;
    Juridica (String n,int CNPJ){
        this.cnpj = CNPJ;
        super.Pessoa(n);
    }
    public void atribuiFaturamentoAnual(int x){
        this.fa = x;
    }
    public void atribuiContribuicoesIsentas(int y){
        this.ci = y ;
    }
    public float  calculaImposto(){
        return (float)(0.2*(fa-ci));
    }
    public String toString(){
        return "Juridica";
    }
}
