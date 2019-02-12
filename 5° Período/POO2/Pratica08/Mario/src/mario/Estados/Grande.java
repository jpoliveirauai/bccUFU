package mario.Estados;
//João Paulo de Oliveira
public class Grande extends Estado {
    public int pegaFlor(){
        player.setEstado(new Fogo());
        System.out.println("Fogo");
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
        player.setEstado(new Pequeno());
        System.out.println("Pequeno");
        return 0;
    }
}