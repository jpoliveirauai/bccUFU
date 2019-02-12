package controleacademico.dominio.pessoas;

import controleacademico.dominio.cursos.GradeCurricular;
import controleacademico.dominio.matriculas.Historico;
import controleacademico.dominio.matriculas.OfertaTurma;
import controleacademico.dominio.cursos.Disciplina;

public class Aluno {
    private String nome;
    private GradeCurricular grade;
    private Historico historico;
    
    public Aluno (String n, GradeCurricular g) {
        nome = n;
        grade = g;
        historico = new Historico(this);
    }
    
    public boolean verificaSeFormou () {
        for (int i = 0; i < grade.nroDisciplinas(); i++) {
        //for (Disciplina d:   grade.disciplinas) {
            if(! historico.constaAprovacao(grade.getDisciplina(i)))
                return false;
        }
        return true;
    }
    public String getNome(){
        return (nome);
    }
    public void matriculaAluno(OfertaTurma oferta){
        this.historico.matriculaDisciplina(oferta);
    }
    public void registraNota(Disciplina d, int nota){
        this.historico.registraResultado(d, nota);
    }
}