package mario.Estados;
//João Paulo de Oliveira
import mario.Mario;
public abstract class Estado {
    protected static Mario player = new Mario();
    public abstract int pegaFlor();
    public abstract int pegaPena();
    public abstract int pegaComgumelo();
    public abstract  int levarDano();
}