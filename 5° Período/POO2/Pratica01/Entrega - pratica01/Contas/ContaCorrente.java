package pratica01.Contas;
import pratica01.operacao.*;

public class ContaCorrente extends ContaBancaria{
    public ContaCorrente(){
        setRentabilidade(new R_Baixa());
        setMensalidade(new M_Normal());
        setMovimentacao(new M_Completa());
        setLimite(new Ch_liberado());
       
    }
    
}
