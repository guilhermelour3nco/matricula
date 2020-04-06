/**
 * GUILHERME LOURENÇO RA - 18709865
 * 
 * ATENÇÃO PROFESSOR
 * Este código esta hospedado também no GitHub, -> por favor ACESSE E LEIA O ARQUIVO README.md <-
 * https://github.com/guilhermelour3nco/matricula
 * 
 * Este sistema foi produzido em SO Linux, fiz alterações
 * para existir compatibilidade mas não pude obter um computador
 * Windows para fazer o teste. A principal mudança é com a função system("cls")/system("clear").
 * Leia mais na sessão COMENTÁRIOS DO DESENVOLVEDOR no GitHub.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int matriculas;
    char minhasDisciplinas[20][20];
} alunoStr;

typedef struct {
    char nome[20];
    int vinculos;
    char vinculadoCom[20][20];
} profStr;

typedef struct {
    char nome[20];
    int matriculas;
    char matriculados[20][20], ministradoPor[20];
} discStr;

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
void removerAlunos (alunoStr alunos[], int *posAl, discStr disciplinas[], int *posDisc);
void removerVinculoDeProfessor(profStr professores[], int *posProf, discStr disciplinas[], int *posDisc);

int main() {
    alunoStr alunos[20];
    profStr professores[20];
    discStr disciplinas[20];
    // Variaveis com prefixo 'pos' indicam a posição do próximo espaço disponível para ser preenchido, isto é, a última posição do array.
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
            system("cls");
            printf("\n\t\tMain Menu\n\n\n\t-> CADASTRO\n\n\t(1)\tCadastro de Aluno\n\n\t(2)\tCadastro de Professor\n\n\t(3)\tCadastro de Disciplina\n\n\t-> LISTAS\n\n\t(4)\tImprimir Listas\n\n\t-> RECURSOS\n\n\t(5)\tMatricular Alunos\n\n\t(6)\tVincular Professor\n\n\t(7)\tDesvincular Professor\n\n\t(8)\tRemover alunos \n\n\t(9)\tENCERRAR\n\n");
            if(ctrl < 1 || ctrl > 8) printf("OPCAO INVALIDA!\n");
            scanf("%d", &ctrl);

        } while (ctrl < 1 || ctrl > 9);

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
            imprimeListas(alunos, &posAluno, disciplinas, &posDisc, professores, &posProf);
            break;
        case 5:
            cadastrarAlunos(alunos, &posAluno, disciplinas, &posDisc);
            break;
        case 6:
            vincularProfessor(professores, &posProf, disciplinas, &posDisc);
            break;
        case 7:
            removerVinculoDeProfessor(professores, &posProf, disciplinas, &posDisc);
            break;
        case 8:
            removerAlunos(alunos, &posAluno, disciplinas, &posDisc);
            break;
        }
    } while (ctrl != 9);

    return 0;
}

void cadastraAluno(alunoStr alunos[], int *pos){
    char ctrl;

    do{
    system("cls");
    printf("\n\t\tMain Menu\n\n\n\tNome do Aluno:\t");
    scanf("%s", &alunos[*pos].nome);

    system("cls");
    printf("\n\t\tMain Menu\n\n\n\tAluno: %s INCLUIDO COM SUCESSO!\n\n\tDeseja incluir novo aluno? [y/n] ", alunos[(*pos)++].nome);
    scanf("%s", &ctrl);

    } while (ctrl != 'n');
}

void cadastraProf(profStr professores[], int *pos){
    char ctrl;

    do {
    system("cls");
    printf("\n\t\tMain Menu\n\n\n\tNome do Docente:\t");
    scanf("%s", &professores[*pos].nome);

    system("cls");
    printf("\n\t\tMain Menu\n\n\n\tProfessor: %s INCLUIDO COM SUCESSO!\n\n\tDeseja incluir novo docente? [y/n] ", professores[(*pos)++].nome);

    scanf("%s", &ctrl);

    } while (ctrl != 'n');
}

void cadastraDisciplina(discStr disciplinas[], int *pos){
    char c;

    do{
    system("cls");
    printf("\n\t\tMenu de Disciplina\n\n\n\tNome da Disciplina:\t");
    scanf("%s", &disciplinas[*pos].nome);

    system("cls");
    printf("\n\t\tMenu de Disciplina\n\n\n\tA disciplina '%s' foi cadastrada com sucesso!\n\n\tDeseja incluir uma nova Disciplina? [y/n]\n", disciplinas[(*pos)++].nome);
    scanf("%s", &c);
    }while(c != 'n');

}

void imprimeListas (alunoStr alunos[], int *posAl, discStr disciplinas[], int *posDisc, profStr professores[], int *posProf) {
    int i, c;
    do{
        system("cls");
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

void imprimeAlunos(alunoStr alunos[], int *posAl) {
    int i;

    printf("\n\t\t--Lista de Alunos Cadastrados--\n\n\n");

    if(*posAl == 0){
        printf("NENHUM ALUNO FOI CADASTRADO AINDA!");

    }else{
        printf("OPCAO\t\tNOME");
        for(i=0; i<*posAl;i++) {
            printf("\n[%d] \t\t%s\n", i+1, alunos[i].nome);
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
        printf("OPCAO\t\tNOME");
        for(i=0; i<*posDisc; i++) {
            printf("\n[%d] \t\t%s\n", i+1, disciplinas[i].nome);
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
        printf("OPCAO\t\tNOME");
        for(i=0; i<*posProf;i++) {
            printf("\n[%d] \t\t%s\n", i+1, professores[i].nome);
        }
    }

    printf("\n");
}

void imprimeAlunosMatriculados(discStr disciplinas[], int *posDisc) {
    int ctrl, i;
    system("cls");
    imprimeDisciplinas(disciplinas, posDisc);

    printf("\nSelecione uma disciplina: "); scanf("%d", &ctrl);
    for(i=0; i < disciplinas[ctrl-1].matriculas; i++){
        printf("\n- %s", disciplinas[ctrl-1].matriculados[i]);
    }
}

void imprimeDisciplinasMatriculadas(alunoStr alunos[], int *posAl) {
    int ctrl, i;
    system("cls");
    imprimeAlunos(alunos, posAl);

    printf("\nSelecione um aluno: "); scanf("%d", &ctrl);
    for(i=0; i < alunos[ctrl-1].matriculas; i++){
        printf("\n- %s", alunos[ctrl-1].minhasDisciplinas[i]);
    }
}

void disciplinasDoProfessor(profStr professores[], int *posProf) {
    int ctrl, i;
    system("cls");
    imprimeProfessores(professores, posProf);

    printf("\nSelecione um professor: "); scanf("%d", &ctrl);
    for(i=0; i < professores[ctrl-1].vinculos; i++){
        printf("\n- %s", professores[ctrl-1].vinculadoCom[i]);
    }
}

void professorDaDisciplina(discStr disciplinas[], int *posDisc) {
    int ctrl;
    system("cls");
    imprimeDisciplinas(disciplinas, posDisc);

    printf("\nSelecione uma disciplina: ");
    scanf("%d", &ctrl);
    printf("\n- %s", disciplinas[ctrl-1].ministradoPor);
}

void cadastrarAlunos(alunoStr alunos[], int *posAl, discStr disciplinas[], int *posDisc){
    int i, j, opcaoAtual, qtdAl = 0, qtdDisc = 0;
    int listaAlunos[20], listaDisciplinas[20], objetoAtual;
    char alunosSelecionados[20][20], disciplinasSelecionadas[20][20];

    system("cls");
    do {
        imprimeAlunos(alunos, posAl);

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

        system("cls");
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

        printf("\n\nSelecione as disciplinas para incluir \nou 'SELECIONE 0' para continuar: ");
        scanf("%d", &opcaoAtual);

        if(opcaoAtual != 0) {
            strcpy(disciplinasSelecionadas[qtdDisc], disciplinas[opcaoAtual-1].nome);
            listaDisciplinas[qtdDisc++] = opcaoAtual-1;
        }

        system("cls");
    } while (opcaoAtual != 0);

    // Insere alunos selecionados na disciplina.
    // objetoAtual é usado para facilitar a leitura do código.
    for (i=0; i < qtdDisc; i++) {
        for (j=0; j < qtdAl; j++){
            objetoAtual = listaDisciplinas[i];
            strcpy(disciplinas[objetoAtual].matriculados[disciplinas[objetoAtual].matriculas++], alunosSelecionados[j]);
        }
    }
    // Insere disciplinas selecionadas nas disciplinas do aluno.
    for (i=0; i < qtdAl; i++) {
        for (j=0; j < qtdDisc; j++){
            objetoAtual = listaAlunos[i];
            strcpy(alunos[objetoAtual].minhasDisciplinas[alunos[objetoAtual].matriculas++], disciplinasSelecionadas[j]);
        }
    }
    printf("\n\nMatriculas realizadas, pressione UM NUMERO para continuar: ");
    scanf("%d", &opcaoAtual);
}

void vincularProfessor(profStr professores[], int *posProf, discStr disciplinas[], int *posDisc) {
    int i, prof, ctrl, qtdDisc = 0, listaDisciplinas[20];
    char disciplinasSelecionadas[20][20];

    system("cls");
    imprimeProfessores(professores, posProf);

    printf("\n\nSelecione a 'OPCAO' do professor a ser vinculado: ");
    scanf("%d", &prof); prof -= 1;
    system("cls");

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

        system("cls");
    } while (ctrl != 0);

    for(i=0; i < qtdDisc; i++){
        strcpy(disciplinas[listaDisciplinas[i]].ministradoPor, professores[prof].nome);
        strcpy(professores[prof].vinculadoCom[professores[prof].vinculos++], disciplinas[listaDisciplinas[i]].nome);
    }
    printf("\n\nVinculo realizado, pressione UM NUMERO para continuar: ");
    scanf("%d", &i);

}

void removerVinculoDeProfessor(profStr professores[], int *posProf, discStr disciplinas[], int *posDisc) {
    int i, j, prof, ctrl, qtdDisc = 0;
    char disciplinasSelecionadas[20][20];

    system("cls");
    imprimeProfessores(professores, posProf);

    printf("\n\nSelecione a 'OPCAO' do professor a ser desvinculado: ");
    scanf("%d", &prof); prof -= 1;
    system("cls");

    do {
    // Imprime lista do professor
    printf("\n\n\tOPCAO\t\tDISCIPLINA\n");
    for (i=0; i<professores[prof].vinculos; i++) {
        printf("\n\t[%d]\t\t%s", i+1, professores[prof].vinculadoCom[i]);
    }
        if (qtdDisc) {

            printf("\nDisciplinas Selecionadas: ");
            for(i = 0; i < qtdDisc; i++){

                if(i != 0) printf(", ");
                printf("%s", disciplinasSelecionadas[i]);
            }
        }

        printf("\n\nSelecione as disciplinas para desvincular\nou 'SELECIONE 0' para continuar: ");
        scanf("%d", &ctrl);

        if(ctrl != 0) {
            strcpy(disciplinasSelecionadas[qtdDisc++], professores[prof].vinculadoCom[ctrl-1]);
        }

        system("cls");
    } while (ctrl != 0);

    for(i=0; i < professores[prof].vinculos; i++) {
        for(j=0; j<qtdDisc; j++){
            if(strcmp(professores[prof].vinculadoCom[i], disciplinasSelecionadas[j]) == 0){
                strcpy(professores[prof].vinculadoCom[i], professores[prof].vinculadoCom[i+1]);
            }
        }
        strcpy(professores[prof].vinculadoCom[i], professores[prof].vinculadoCom[i+1]);
    }
    for (i=0; i < (*posDisc); i++) {
        if(strcmp(disciplinas[i].ministradoPor, professores[prof].nome) == 0){
            for(j=0; j < qtdDisc; j++){
                if (strcmp(disciplinas[i].nome, disciplinasSelecionadas[j]) == 0){
                strcpy(disciplinas[i].ministradoPor, "");
                printf("ENCONTRADO E REMOVIDO");
                }
            }
        }
    }


    professores[prof].vinculos -= qtdDisc;
    printf("\n\nDESVINCULADO, pressione UM NUMERO para continuar: ");
    scanf("%d", &i);

}

void removerAlunos (alunoStr alunos[], int *posAl, discStr disciplinas[], int *posDisc) {
    // Variaveis auxiliares para o for().
    int i, j, c, d, a;

    int opcaoAtual, qtdAl = 0, qtdDisc = 0;
    char alunosSelecionados[20][20], disciplinasSelecionadas[20][20];

    system("cls");
    do {
        imprimeAlunos(alunos, posAl);

        if (qtdAl){
            printf("\nAlunos Selecionados: ");
            for(i = 0; i < qtdAl; i++){

                if(i != 0) printf(", ");
                printf("%s", alunosSelecionados[i]);
            }
        }

        printf("\n\nSelecione a 'OPCAO' do aluno a ser desmatriculado \nou 'SELECIONE 0' para continuar: ");
        scanf("%d", &opcaoAtual);

        if(opcaoAtual != 0) {
            strcpy(alunosSelecionados[qtdAl++], alunos[opcaoAtual-1].nome);
        }

        system("cls");
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

        printf("\n\nSelecione as disciplinas para excluir \nou 'SELECIONE 0' para continuar: ");
        scanf("%d", &opcaoAtual);

        if(opcaoAtual != 0) {
            strcpy(disciplinasSelecionadas[qtdDisc++], disciplinas[opcaoAtual-1].nome);
        }

        system("cls");
    } while (opcaoAtual != 0);

    for(i=0; i < *posAl; i++) {
        for(j=0; j<qtdAl; j++){

            if(strcmp(alunos[i].nome, alunosSelecionados[j]) == 0){
                for(c =0; c < alunos[i].matriculas; c++){
                    for(d=0; d < qtdDisc; d++){

                        if(strcmp(alunos[i].minhasDisciplinas[c], disciplinasSelecionadas[d]) == 0){

                            if (c +1 == alunos[i].matriculas) {
                            strcpy(alunos[i].minhasDisciplinas[c], "");
                            } else {
                                for(a=0; a < alunos[i].matriculas; a++){
                                    strcpy(alunos[i].minhasDisciplinas[a], alunos[i].minhasDisciplinas[a+1]);
                                }
                            }
                            alunos[i].matriculas--;
                        }
                    }
                }
            }
        }
    }

    for(i=0; i < *posDisc; i++) {
        for(j=0; j<qtdDisc; j++){

            if(strcmp(disciplinas[i].nome, disciplinasSelecionadas[j]) == 0){
                for(c =0; c < disciplinas[i].matriculas; c++){
                    for(d=0; d < qtdAl; d++){

                        if(strcmp(disciplinas[i].matriculados[c], alunosSelecionados[d]) == 0){

                            if (c +1 == disciplinas[i].matriculas) {
                            strcpy(disciplinas[i].matriculados[c], "");
                            } else {
                                for(a=0; a < disciplinas[i].matriculas; a++){
                                    strcpy(disciplinas[i].matriculados[a], disciplinas[i].matriculados[a+1]);
                                }
                            }
                            disciplinas[i].matriculas--;
                        }
                    }
                }
            }
        }
    }
    printf("\n\nDESVINCULADOS, pressione UM NUMERO para continuar: ");
    scanf("%d", &opcaoAtual);
}