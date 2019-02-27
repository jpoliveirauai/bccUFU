package governo;

public class Fisica extends Pessoa{
    private int CPF;
    private float rendimentosAnuais;
    
    Fisica(String n,int cpf){
        this.CPF = cpf;
        super.Pessoa(n);
    }
    public void atribuiRendimento(float rendimento){
        this.rendimentosAnuais = rendimento;
    }
    public float calculaImposto(){
        return(float)(this.rendimentosAnuais*0.15);
    }
    public String toString(){
        return "Fisica";
    }
    
}
