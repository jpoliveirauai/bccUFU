package mario.Estados;
//João Paulo de Oliveira
public class Pequeno extends Estado     {
    @Override
    public int pegaFlor(){
        super.player.setEstado(new Fogo());
        System.out.println("Fogo");
        return 0;
    }
    @Override
    public int pegaPena(){
        super.player.setEstado(new Capa());
        System.out.println("Capa");
        return 0;
    }
    @Override
    public int pegaComgumelo(){
        super.player.setEstado(new Grande());
        System.out.println("Grande");
        return 0;
    }
    @Override
    public int levarDano(){
        super.player.setEstado(new Morto());
        System.out.println("Morto");
        return 0;
    }
}