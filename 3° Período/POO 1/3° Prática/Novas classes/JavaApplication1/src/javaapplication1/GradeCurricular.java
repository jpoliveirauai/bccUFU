package javaapplication1;

public class GradeCurricular{
    String Disciplinas[] = new String[100];
    //private String NomeDisciplina;
    void AddDisciplina(String NomeDisciplina,int i){
        Disciplinas[i] = NomeDisciplina;
    }
    void RmDisciplina(String NomeDisciplina, int tamanho){
        int i,j,f = 0;
        for(i=0;i<tamanho-1;i++){
            if(Disciplinas[i].equals(NomeDisciplina)){
                f=1;
                Disciplinas[i]="";
            }
            if(f==1){
                Disciplinas[i]=Disciplinas[i+1];
            }
            }
        }
}