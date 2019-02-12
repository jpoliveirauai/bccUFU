package pratica01.Contas;
import pratica01.operacao.*;

public class ContaSalario extends ContaBancaria{
        public ContaSalario(){
        setRentabilidade(new R_Baixa());
        setMensalidade(new M_Normal());
        setMovimentacao(new M_Simplificada());
        setLimite(new Ch_bloqueado());
    }
}
