package pratica01.Contas;
import pratica01.operacao.Movimentacao;
import pratica01.operacao.Rentabilidade;
import pratica01.operacao.Limite;
import pratica01.operacao.Mensalidade;
public abstract class ContaBancaria {
    private int conta;
    private int senha;
    private int saldo;
    private Limite l;
    private Movimentacao m;
    private Mensalidade men;
    private Rentabilidade r;
    
    public void setRentabilidade(Rentabilidade ren ){
        this.r = ren;
    }
    public void setMensalidade(Mensalidade m){
        this.men = m;
    }
    public void setMovimentacao(Movimentacao mov){
        this.m = mov;
    }
    public void setLimite(Limite lim){
        this.l = lim;
    }
        
}
