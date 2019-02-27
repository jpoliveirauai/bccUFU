package pratica01.Contas;

import pratica01.operacao.*;

public class ContaInvestimento extends ContaBancaria{
        public ContaInvestimento(){
            setRentabilidade(new R_Normal());
            setMensalidade(new M_baixa());
            setMovimentacao(new M_Completa());
            setLimite(new Ch_liberado());
        }
}