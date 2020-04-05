#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int ra, matriculas;
    char minhasDisciplinas[20][20];
} alunoStr;

typedef struct {
    char nome[20];
    int cod, vinculos;
    char vinculadoCom[20][20]
} profStr;

typedef struct {
    char nome[20];
    int id, matriculas;
    char matriculados[20][20], ministradoPor[20];
} discStr;

void removeAluno(alunoStr alunos[], int *pos);
void cadastraAluno(alunoStr alunos[], int *pos);
void imprimeAlunos(alunoStr alunos[], int *posAl);
void imprimeDisciplinas(discStr disciplinas[], int *posDisc);
void imprimeProfessores(profStr professores[], int *posProf);
void imprimeDisciplinasMatriculadas(alunoStr alunos[], int *posAl);
void imprimeAlunosMatriculados(discStr disciplinas[], int *posDisc);
void disciplinasDoProfessor(profStr professores[], int *posProf);
void professorDaDisciplina(discStr disciplinas[], int *posDisc);
void imprimeListas(alunoStr alunos[], int *pos, discStr disciplinas[], int *posDisc, profStr professores[], int *posProf);
void cadastraDisciplina(discStr disciplinas[], int *pos);
void cadastraProf(profStr professores[], int *pos);
void cadastrarAlunos(alunoStr alunos[], int *posAl, discStr disciplinas[], int *posDisc);
void vincularProfessor(profStr professores[], int *posProf, discStr disciplinas[], int *posDisc);

int main() {
    alunoStr alunos[20];
    profStr professores[20];
    discStr disciplinas[20];
    int posAluno = 0, posProf = 0, posDisc = 0, ctrl=1, i;

    // Initial set up.
    for(i=0; i<20; i++){
        alunos[i].matriculas = 0;
        professores[i].vinculos = 0;
        disciplinas[i].matriculas = 0;
    }

    do {
        // Menu constructor.
        do {
            system("clear");
            printf("\n\t\tMain Menu\n\n\n\t(1)\tCadastro de Aluno [ON]\n\n\t(2)\tCadastro de Professor [ON]\n\n\t(3)\tCadastro de Disciplina [ON]\n\n\t(4)\tRemover Aluno [ON]\n\n\t(5)\tImprimir Listas [ON]\n\n\t(6)\tMatricular Alunos [ON]\n\n\t(7)\tVincular Professor \n\n\t(8)\tENCERRAR [ON]\n\n");
            if(ctrl < 1 || ctrl > 7) printf("OPCAO INVALIDA!\n");
            scanf("%d", &ctrl);

        } while (ctrl < 1 || ctrl > 8);

        switch (ctrl) {
        case 1:
            cadastraAluno(alunos, &posAluno);
            break;
        case 2:
            cadastraProf(professores, &posProf);
            break;
        case 3:
            cadastraDisciplina(disciplinas, &posDisc);
            break;
        case 4:
            removeAluno(alunos, &posAluno);
            break;
        case 5:
            imprimeListas(alunos, &posAluno, disciplinas, &posDisc, professores, &posProf);
            break;
        case 6:
            cadastrarAlunos(alunos, &posAluno, disciplinas, &posDisc);
            break;
        case 7:
            vincularProfessor(professores, &posProf, disciplinas, &posDisc);
            break;
        }
    } while (ctrl != 8);

    return 0;
}

void vincularProfessor(profStr professores[], int *posProf, discStr disciplinas[], int *posDisc) {
    int i, j, prof, ctrl, qtdDisc = 0, listaDisciplinas[20];
    char disciplinasSelecionadas[20][20];

    system("clear");
    imprimeProfessores(professores, posProf);

    printf("\n\nSelecione a 'OPCAO' do professor a ser vinculado: ");
    scanf("%d", &prof); prof -= 1;
    system("clear");

    do {
        imprimeDisciplinas(disciplinas, posDisc);

        if (qtdDisc) {

            printf("\nDisciplinas Selecionadas: ");
            for(i = 0; i < qtdDisc; i++){

                if(i != 0) printf(", ");
                printf("%s", disciplinasSelecionadas[i]);
            }
        }

        printf("\n\nSelecione as disciplinas para incluir\nou 'SELECIONE 0' para continuar: ");
        scanf("%d", &ctrl);

        if(ctrl != 0) {
            strcpy(disciplinasSelecionadas[qtdDisc], disciplinas[ctrl-1].nome);
            listaDisciplinas[qtdDisc++] = ctrl-1;
        }

        system("clear");
    } while (ctrl != 0);

    for(i=0; i < qtdDisc; i++){
        strcpy(disciplinas[listaDisciplinas[i]].ministradoPor, professores[prof].nome);
        strcpy(professores[prof].vinculadoCom[professores[prof].vinculos++], disciplinas[listaDisciplinas[i]].nome);
        printf("\n%s %s", disciplinas[listaDisciplinas[i]].ministradoPor, professores[prof].vinculadoCom[professores[prof].vinculos-1]);
    }
    scanf("%d", &i);

}

void cadastrarAlunos(alunoStr alunos[], int *posAl, discStr disciplinas[], int *posDisc){
    int i, j, opcaoAtual, qtdAl = 0, qtdDisc = 0;
    int listaAlunos[20], listaDisciplinas[20], objetoAtual;
    char alunosSelecionados[20][20], disciplinasSelecionadas[20][20];

    system("clear");
    do {
        imprimeAlunos(alunos, posAl);

        // Imprime apenas após primeira entrada.
        if (qtdAl){
            printf("\nAlunos Selecionados: ");
            for(i = 0; i < qtdAl; i++){

                if(i != 0) printf(", ");
                printf("%s", alunosSelecionados[i]);
            }
        }

        printf("\n\nSelecione a 'OPCAO' do aluno a ser matriculado \nou 'SELECIONE 0' para continuar: ");
        scanf("%d", &opcaoAtual);

        if(opcaoAtual != 0) {
            strcpy(alunosSelecionados[qtdAl], alunos[opcaoAtual-1].nome);
            listaAlunos[qtdAl++] = opcaoAtual-1;
        }

        system("clear");
    } while (opcaoAtual != 0);

    do {
        imprimeDisciplinas(disciplinas, posDisc);

        if (qtdDisc) {

            printf("\nDisciplinas Selecionadas: ");
            for(i = 0; i < qtdDisc; i++){

                if(i != 0) printf(", ");
                printf("%s", disciplinasSelecionadas[i]);
            }
        }

        printf("\n\nSelecione as disciplinas para incluir: ");
        scanf("%d", &opcaoAtual);

        if(opcaoAtual != 0) {
            strcpy(disciplinasSelecionadas[qtdDisc], disciplinas[opcaoAtual-1].nome);
            listaDisciplinas[qtdDisc++] = opcaoAtual-1;
        }

        system("clear");
    } while (opcaoAtual != 0);

    // Insere alunos selecionados na disciplina.
    // objetoAtual é usado para facilitar a leitura do código.
    for (i=0; i < qtdDisc; i++) {
        for (j=0; j < qtdAl; j++){
            objetoAtual = listaDisciplinas[i];
            strcpy(disciplinas[objetoAtual].matriculados[disciplinas[objetoAtual].matriculas++], alunosSelecionados[j]);
            printf("\n%s", disciplinas[objetoAtual].matriculados[disciplinas[objetoAtual].matriculas-1]);
        }
    }
    // Insere disciplinas selecionadas nas disciplinas do aluno.
    for (i=0; i < qtdAl; i++) {
        for (j=0; j < qtdDisc; j++){
            objetoAtual = listaAlunos[i];
            strcpy(alunos[objetoAtual].minhasDisciplinas[alunos[objetoAtual].matriculas++], disciplinasSelecionadas[j]);
            printf("\n%s", alunos[objetoAtual].minhasDisciplinas[alunos[objetoAtual].matriculas-1]);
        }
    }
    
    scanf("%d", &opcaoAtual);
}

void cadastraDisciplina(discStr disciplinas[], int *pos){
    char c;

    do{
    system("clear");
    printf("\n\t\tMenu de Disciplina\n\n\n\tNome da Disciplina:\t");
    fflush(stdin);
    scanf("%s", &disciplinas[*pos].nome);

    system("clear");
    printf("\n\t\tMenu de Disciplina\n\n\n\tA disciplina '%s' foi cadastrada com sucesso!\n\n\tDeseja incluir uma nova Disciplina? [y/n]\n", disciplinas[(*pos)++].nome);
    fflush(stdin);
    scanf("%s", &c);
    }while(c != 'n');

}

void removeAluno(alunoStr alunos[], int *pos){
    int i, c;

    system("clear");
    printf("\n\t\tMain Menu\n\n");
    imprimeAlunos(alunos, pos);

    do {
        printf("\nAluno a ser removido: ");
        scanf("%d", &c);

        if (c < 1 || c > *pos) printf("\nOpcao invalida!\n");

    } while (c < 1 || c > *pos);

    for(i = c-1; i+1 < *pos; i++) {
        strcpy(alunos[i].nome, alunos[i+1].nome);
        alunos[i].ra = alunos[i+1].ra;
    }
    (*pos)--;
}

void cadastraAluno(alunoStr alunos[], int *pos){
    char ctrl;

    do{
    system("clear");
    printf("\n\t\tMain Menu\n\n\n\tNome do Aluno:\t");
    fflush(stdin);
    scanf("%s", &alunos[*pos].nome);

    printf("\n\tRA do Aluno:\t");
    scanf("%d", &alunos[*pos].ra);

    system("clear");
    printf("\n\t\tMain Menu\n\n\n\tAluno: %s INCLUIDO COM SUCESSO!\n\n\tDeseja incluir novo aluno? [y/n] ", alunos[(*pos)++].nome);
    fflush(stdin);
    scanf("%s", &ctrl);

    } while (ctrl != 'n');
}

void cadastraProf(profStr professores[], int *pos){
    int i;

    system("clear");
    printf("\n\t\tMain Menu\n\n\n\tNome do Docente:\t");
    fflush(stdin);
    scanf("%s", &professores[*pos].nome);

    printf("\n\tCodigo do Professor:\t");
    scanf("%d", &professores[*pos].cod);

    system("clear");
    printf("\n\t\tMain Menu\n\n\n\tProfessor: %s INCLUIDO COM SUCESSO!\n\n\t", professores[(*pos)++].nome);

    scanf("%d", &i);
}

void imprimeAlunos(alunoStr alunos[], int *posAl) {
    int i;

    printf("\n\t\t--Lista de Alunos Cadastrados--\n\n\n");

    if(*posAl == 0){
        printf("NENHUM ALUNO FOI CADASTRADO AINDA!");

    }else{
        for(i=0; i<*posAl;i++) {
            printf("OPCAO\t\tNOME\t\tRA\n[%d] \t\t%s\t\t %d\n", i+1, alunos[i].nome, alunos[i].ra);
        }
    }

    printf("\n");
}

void imprimeDisciplinas(discStr disciplinas[], int *posDisc) {
    int i;

    printf("\n\t\t--Lista de Disciplinas Cadastradas--\n\n\n");

    if(*posDisc == 0){
        printf("NENHUMA DISCIPLINA FOI CADASTRADA AINDA!");

    }else{
        for(i=0; i<*posDisc; i++) {
            printf("OPCAO\t\tNOME\t\tID\n[%d] \t\t%s\t\t %d\n", i+1, disciplinas[i].nome, disciplinas[i].id);
        }
    }

    printf("\n");
}

void imprimeProfessores(profStr professores[], int *posProf) {
    int i;

    printf("\n\t\t--Lista de Professores Cadastrados--\n\n\n");

    if(*posProf == 0){
        printf("NENHUM PROFESSOR FOI CADASTRADO AINDA!");

    }else{
        for(i=0; i<*posProf;i++) {
            printf("OPCAO\t\tNOME\t\tCOD\n[%d] \t\t%s\t\t %d\n", i+1, professores[i].nome, professores[i].cod);
        }
    }

    printf("\n");
}

void imprimeAlunosMatriculados(discStr disciplinas[], int *posDisc) {
    int ctrl, i, j;
    system("clear");
    imprimeDisciplinas(disciplinas, posDisc);

    printf("\nSelecione uma disciplina: "); scanf("%d", &ctrl);
    for(i=0; i < disciplinas[ctrl-1].matriculas; i++){
        printf("\n- %s", disciplinas[ctrl-1].matriculados[i]);
    }
    scanf("%d", &i);
}

void imprimeDisciplinasMatriculadas(alunoStr alunos[], int *posAl) {
    int ctrl, i;
    system("clear");
    imprimeAlunos(alunos, posAl);

    printf("\nSelecione um aluno: "); scanf("%d", &ctrl);
    for(i=0; i < alunos[ctrl-1].matriculas; i++){
        printf("\n- %s", alunos[ctrl-1].minhasDisciplinas[i]);
    }
    scanf("%d", &i);
}

void disciplinasDoProfessor(profStr professores[], int *posProf) {
    int ctrl, i;
    system("clear");
    imprimeAlunos(professores, posProf);

    printf("\nSelecione um professor: "); scanf("%d", &ctrl);
    for(i=0; i < professores[ctrl-1].vinculos; i++){
        printf("\n- %s", professores[ctrl-1].vinculadoCom[i]);
    }
    scanf("%d", &i);
}

void professorDaDisciplina(discStr disciplinas[], int *posDisc) {
    int ctrl, i;
    system("clear");
    imprimeDisciplinas(disciplinas, posDisc);

    printf("\nSelecione uma disciplina: "); scanf("%d", &ctrl);
    printf("\n- %s", disciplinas[ctrl-1].ministradoPor);
    scanf("%d", &i);
}

void imprimeListas (alunoStr alunos[], int *posAl, discStr disciplinas[], int *posDisc, profStr professores[], int *posProf) {
    int i, c;
    do{
        system("clear");
        printf("\t\t--Menu de listagem--\n\n\n\t(1)\tImprimir todos os alunos\n\t(2)\tImprimir todos as disciplinas\n\t(3)\tImprimir todos os professores\n\t(4)\tConsultar alunos de uma disciplina\n\t(5)\tConsultar disciplinas de um aluno\n\t(6)\tConsultar disciplinas de um professor\n\t(7)\tConsultar professor da disciplina\n\nSelecione: ");
        scanf("%d", &i);

        switch (i) {
        case 1:
            imprimeAlunos(alunos, posAl);
            break;
        case 2:
            imprimeDisciplinas(disciplinas, posDisc);
            break;
        case 3:
            imprimeProfessores(professores, posProf);
            break;
        case 4:
            imprimeAlunosMatriculados(disciplinas, posDisc);
            break;
        case 5:
            imprimeDisciplinasMatriculadas(alunos, posAl);
            break;
        case 6:
            disciplinasDoProfessor(professores, posProf);
            break;
        case 7:
            professorDaDisciplina(disciplinas, posDisc);
            break;
        }
    printf("\nNova consulta? [y/n]\n");
    scanf("%s", &c);
    }while(c != 'n');
}
