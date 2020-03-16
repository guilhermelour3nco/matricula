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
void imprimeListas(alunoStr alunos[], int *pos);

int main() {
    alunoStr alunos[20];
    profStr professores[20];
    discStr disciplinas[20];
    int posAluno = 0, posProf = 0, posDisc = 0, ctrl=1;

    // buildMenu(alunos, &posAluno);

    do{
    do{
        system("cls");
        printf("\n\t\tMain Menu\n\n\n\t(1)\tCadastro de Aluno\n\n\t(2)\tCadastro de Professor\n\n\t(3)\tCadastro de Disciplina\n\n\t(4)\tImprimir Listas\n\n\t(5)\tENCERRAR\n\n");
        if(ctrl < 1 || ctrl > 5) printf("OPCAO INVALIDA!\n");
        scanf("%d", &ctrl);

    } while(ctrl < 1 || ctrl > 5);

    switch(ctrl){
    case 1:
        cadastraAluno(alunos, &posAluno);
        break;
    case 2:
        cadastraProf(professores, &posProf);
        break;
    case 3:
        removeAluno(alunos, &posAluno);
        break;
    case 4:
        imprimeListas(alunos, &posAluno);
        break;
    }
    }while(ctrl != 5);

    return 0;
}

void removeAluno(alunoStr alunos[], int *pos){
    int i, c;

    for(i=0; i<*pos;i++){
        printf("(%d)\tNOME:\t%s\t\tRA: %d\n", i+1, alunos[i].nome, alunos[i].ra);
    }
    printf("\nAluno a ser removido: "); scanf("%d", &c);

    for(i = c-1; i+1 < *pos; i++){
        strcpy(alunos[i].nome, alunos[i+1].nome);
        alunos[i].ra = alunos[i+1].ra;
    }
    (*pos)--;
}

void cadastraAluno(alunoStr alunos[], int *pos){

    system("cls");
    printf("\n\t\tMain Menu\n\n\n\tNome do Aluno:\t");
    fflush(stdin);
    gets(alunos[*pos].nome);

    printf("\n\tRA do Aluno:\t");
    scanf("%d", &alunos[*pos].ra);

    system("cls");
    printf("\n\t\tMain Menu\n\n\n\tAluno: %s INCLUIDO COM SUCESSO!\n\n\t", alunos[(*pos)++].nome);

    system("pause");
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

void imprimeListas (alunoStr alunos[], int *posAl) {
    int i;

    system("cls");
    printf("\n\t\tLista de Alunos Cadastrados\n\n\n");

    if(*posAl == 0){
        printf("NENHUM ALUNO FOI CADASTRADO AINDA!");
    }else{
    for(i=0; i<*posAl;i++){
        printf("NOME:\t%s\t\tRA: %d\n", alunos[i].nome, alunos[i].ra);
    }}

    printf("\n");
    system("pause");
}
