#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// struct como nao temos uma biblioteca para trabalhar com datas criei uma struct
struct Data
{
    int dia;
    int mes;
    int ano;
};
// um tipo livro para facilitar o cadastro de livros
struct Book
{
    int Codigo;
    char Titulo[100];
    char Autor[80];
    char Editora[80];
    int AnoPublicacao;
    int QuantidadeDisponivel;
    bool Status;
};

// um tipo Usuario para facilitar o cadastro de usuario

struct User
{
    int  Matricula;
    char Nome[100];
    char Curso[100];
    char Telefone[15];
    struct Data DataCadastro;
};

//Struct do tipo emprestimo para facilitar o emprestimo de um livro
struct  Loan
{
    int Codigo;
    int MatriculaUser;
    int CodigoLivro;
    struct Data DataEmprestimo;
    struct Data DataDevoucao;
    bool Status;
};

void MenuLivro(void);
void MenuUsuario(void);
void MenuEmprestimo(void);
// Funcao Menu principal
void MenuPrincipal(void){
    int opcao;
    system("clear");
    printf("|-------------------- Biblioteca --------------------|\n");
    printf("\n");
    printf("|1 - Livro\n");
    printf("|2 - Usuarios\n");
    printf("|3 - Emprestimo\n");
    printf("|4 - Sair\n");
    printf("\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            MenuLivro();
            break;
        case 2:
            MenuUsuario();
            break;
        case 3:
            MenuEmprestimo();
            break;
        case 4:
        default:
            system("clear");
            printf("Opcao Invalida");
            MenuPrincipal();
            break;
    };
};

// Funcao Livro;
void MenuLivro()
{
    int opcao;
    system("clear");
    printf("|--------------------- Livros --------------------|\n");
    printf("\n");
    printf("|1 - Cadastra Livro\n");
    printf("|2 - Consultar Livro\n");
    printf("|3 - Relatorio de Livros\n");
    printf("|4 - Sair/Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
        default:
            MenuPrincipal();
            break;
    }
}
//Menu Usuario
void MenuUsuario()
{
    int opcao;
    system("clear");
    printf("|--------------------- Livros --------------------|\n");
    printf("\n");
    printf("|1 - Cadastra Usuario\n");
    printf("|2 - Consultar Usuario\n");
    printf("|3 - Relatorio de Usuario\n");
    printf("|4 - Sair/Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
        default:
            MenuPrincipal();
            break;
    }
}
//Menu Usuario
void MenuEmprestimo()
{
    int opcao;
    system("clear");
    printf("|--------------------- Emprestimo --------------------|\n");
    printf("\n");
    printf("|1 - Cadastra Emprestimo\n");
    printf("|2 - Consultar Emprestimo\n");
    printf("|3 - Relatorio de Emprestimo\n");
    printf("|4 - Sair/Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
        default:
            MenuPrincipal();
            break;
    }
}


int main(void) {
    struct Book books[100];
    struct User users[100];
    struct Loan loans[100];

    MenuPrincipal();


}