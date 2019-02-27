package mario.Estados;
//João Paulo de Oliveira
public class Morto extends Estado{
    public int pegaFlor(){
        System.out.println("Impossível, estou morto");
        return 0;
    }
    public int pegaPena(){
        System.out.println("Impossível, estou morto");
        return 0;
    }
    public int pegaComgumelo(){
        System.out.println("Impossível, estou morto");
        return 0;
    }
    public int levarDano(){
        System.out.println("Impossível, estou morto");
        return 0;
    }
}