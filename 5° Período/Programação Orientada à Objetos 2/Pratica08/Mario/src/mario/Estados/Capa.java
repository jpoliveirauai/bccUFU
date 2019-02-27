package mario.Estados;
//João Paulo de Oliveira

public class Capa extends Estado {
    public int pegaFlor(){
        super.player.setEstado(new Fogo());
        System.out.println("Fogo");
        return 0;
    }
    public int pegaPena(){
        super.player.mais1000();
        System.out.println("+ 1000");
        return 0;
    }
    public int pegaComgumelo(){
        System.out.println("+ 1000");
        super.player.mais1000();
        return 0;
    }
    public int levarDano(){
        super.player.setEstado(new Grande());
        System.out.println("Grande");
        return 0;
    }
}