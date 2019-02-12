package pratica01.Contas;
import pratica01.operacao.*;

public class ContaPoupanca extends ContaBancaria{
    public ContaPoupanca(){
        setRentabilidade(new R_Normal());
        setMensalidade(new M_baixa());
        setMovimentacao(new M_Simplificada());
        setLimite(new Ch_bloqueado());
    }
}
