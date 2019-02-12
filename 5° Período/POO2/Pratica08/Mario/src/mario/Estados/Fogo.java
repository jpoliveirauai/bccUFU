package mario.Estados;
//João Paulo de Oliveira
public class Fogo extends Estado {
    public int pegaFlor(){
        player.mais1000();
        System.out.println("+ 1000");
        return 0;
    }
    public int pegaPena(){
        player.setEstado(new Capa());
        System.out.println("Capa");
        return 0;
    }
    public int pegaComgumelo(){
        player.mais1000();
        System.out.println("+ 1000");
        return 0;
    }
    public int levarDano(){
        player.setEstado(new Grande());
        System.out.println("Grande");
        return 0;
    }
}