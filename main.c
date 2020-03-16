#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    strcpy(disciplina[0].matriculados[0], alunos[(*pos)].nome);
    puts(disciplina[0].matriculados[0]);
*/

typedef struct {
    char nome[20];
    int ra;
    char minhasDisciplinas[20][20];
} alunoStr;

typedef struct {
    char nome[20];
    int cod;
} profStr;

typedef struct {
    char nome[20];
    int id;
    char matriculados[20][20];
} discStr;

void removeAluno(alunoStr alunos[], int *pos);
void cadastraAluno(alunoStr alunos[], int *pos);
void imprimeAlunos(alunoStr alunos[], int *posAl);
void imprimeDisciplinas(discStr disciplinas[], int *posDisc);
void imprimeListas(alunoStr alunos[], int *pos, discStr disciplinas[], int *posDisc);
void novaDisciplina(discStr disciplinas[], int *pos);
void cadastraProf(profStr professores[], int *pos);
void cadastrarAlunos(alunoStr alunos[], int *posAl, discStr disciplinas[], int *posDisc);

int main() {
    alunoStr alunos[20];
    profStr professores[20];
    discStr disciplinas[20];
    int posAluno = 0, posProf = 0, posDisc = 0, ctrl=1;

    do {
        do {
            system("cls");
            printf("\n\t\tMain Menu\n\n\n\t(1)\tCadastro de Aluno [ON]\n\n\t(2)\tCadastro de Professor [ON]\n\n\t(3)\tCadastro de Disciplina [ON]\n\n\t(4)\tRemover Aluno [ON]\n\n\t(5)\tImprimir Listas\n\n\t(6)\tMatricular Alunos\n\n\t(7)\tENCERRAR [ON]\n\n");
            if(ctrl < 1 || ctrl > 6) printf("OPCAO INVALIDA!\n");
            scanf("%d", &ctrl);

        } while (ctrl < 1 || ctrl > 7);

    switch (ctrl) {
    case 1:
        cadastraAluno(alunos, &posAluno);
        break;
    case 2:
        cadastraProf(professores, &posProf);
        break;
    case 3:
        novaDisciplina(disciplinas, &posDisc);
        break;
    case 4:
        removeAluno(alunos, &posAluno);
        break;
    case 5:
        imprimeListas(alunos, &posAluno, disciplinas, &posDisc);
        break;
    case 6:
        cadastrarAlunos(alunos, &posAluno, disciplinas, &posDisc);
        break;
    }
    } while (ctrl != 7);

    return 0;
}

void cadastrarAlunos(alunoStr alunos[], int *posAl, discStr disciplinas[], int *posDisc){
    int i, opcaoAtual, qtdAl = 0, qtdDisc = 0;
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
        printf("\n\nSelecione os alunos a serem matriculados: ");
        scanf("%d", &opcaoAtual);

        strcpy(alunosSelecionados[qtdAl++], alunos[opcaoAtual-1].nome);
        system("cls");
    } while (opcaoAtual != 10);


    do {
        imprimeDisciplinas(disciplinas, posDisc);

        if (qtdDisc) {

            printf("\Disciplinas Selecionadas: ");
            for(i = 0; i < qtdDisc; i++){

                if(i != 0) printf(", ");
                printf("%s", disciplinasSelecionadas[i]);
            }
        }
        printf("\n\nSelecione as disciplinas para incluir: ");
        scanf("%d", &opcaoAtual);

        strcpy(disciplinasSelecionadas[qtdDisc++], disciplinas[opcaoAtual-1].nome);
        system("cls");
    } while (opcaoAtual != 10);
}

void novaDisciplina(discStr disciplinas[], int *pos){
    char c;

    do{
    system("cls");
    printf("\n\t\tMenu de Disciplina\n\n\n\tNome da Disciplina:\t");
    fflush(stdin);
    gets(disciplinas[*pos].nome);

    system("cls");
    printf("\n\t\tMenu de Disciplina\n\n\n\tA disciplina '%s' foi cadastrada com sucesso!\n\n\tDeseja incluir uma nova Disciplina? [y/n]\n", disciplinas[(*pos)++].nome);
    fflush(stdin);
    scanf("%c", &c);
    }while(c != 'n');

}

void removeAluno(alunoStr alunos[], int *pos){
    int i, c;

    system("cls");
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
    system("cls");
    printf("\n\t\tMain Menu\n\n\n\tNome do Aluno:\t");
    fflush(stdin);
    gets(alunos[*pos].nome);

    printf("\n\tRA do Aluno:\t");
    scanf("%d", &alunos[*pos].ra);

    system("cls");
    printf("\n\t\tMain Menu\n\n\n\tAluno: %s INCLUIDO COM SUCESSO!\n\n\tDeseja incluir novo aluno? [y/n] ", alunos[(*pos)++].nome);
    fflush(stdin);
    scanf("%c", &ctrl);

    } while (ctrl != 'n');
}

void cadastraProf(profStr professores[], int *pos){
    system("cls");
    printf("\n\t\tMain Menu\n\n\n\tNome do Docente:\t");
    fflush(stdin);
    gets(professores[*pos].nome);

    printf("\n\tCodigo do Professor:\t");
    scanf("%d", &professores[*pos].cod);

    system("cls");
    printf("\n\t\tMain Menu\n\n\n\tProfessor: %s INCLUIDO COM SUCESSO!\n\n\t", professores[(*pos)++].nome);

    system("pause");
}

void imprimeAlunos(alunoStr alunos[], int *posAl) {
    int i;

    printf("\n\t\tLista de Alunos Cadastrados\n\n\n");

    if(*posAl == 0){
        printf("NENHUM ALUNO FOI CADASTRADO AINDA!");

    }else{

    for(i=0; i<*posAl;i++)
    {
        printf("NOME:\t%s\t\tRA: %d\n", alunos[i].nome, alunos[i].ra);
    }
    }

    printf("\n");
}

void imprimeDisciplinas(discStr disciplinas[], int *posDisc) {
    int i;

    printf("\n\t\tLista de Disciplinas Cadastradas\n\n\n");

    if(*posDisc == 0){
        printf("NENHUMA DISCIPLINA FOI CADASTRADA AINDA!");

    }else{
        for(i=0; i<*posDisc; i++) {
            printf("NOME:\t%s\t\tID: %d\n", disciplinas[i].nome, disciplinas[i].id);
        }
    }

    printf("\n");
}

void imprimeListas (alunoStr alunos[], int *posAl, discStr disciplinas[], int *posDisc) {
    system("cls");
    imprimeAlunos(alunos, posAl);
    imprimeDisciplinas(disciplinas, posDisc);
    system("pause");
}
