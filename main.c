#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//enum status
enum Status
{
    Disponivel = 0 ,
    Indisponivel = 1
};
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
    enum Status StatusEmprestimo;
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



// Iniciando Funcoes dos sub-menus
void MenuLivro(struct Book books[], int *totalLivros);
void MenuUsuario(void);
void MenuEmprestimo(void);
// Funcao Menu principal
void MenuPrincipal(void){
    struct Book books[100];
    struct User users[100];
    struct Loan Loan[100];
    int totalLivros = 0;
    int opcao;
    do {
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
                MenuLivro(books, &totalLivros);
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
                break;
        };
    }while (opcao != 4);

};

// Iniciando Funcoes do sub-menu Livros.
void CadastraLivro(struct Book books[], int *totalLivros);
void GetFirstBook(struct Book books[], int *totalLivros);
void GetAllBooks(struct Book books[], int *totalLivros);
// Funcoes MenuLivro
void MenuLivro(struct Book books[], int *totalLivros)
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
            CadastraLivro(books, totalLivros);
            break;
        case 2:
            GetFirstBook(books, totalLivros);
            break;
        case 3:
            GetAllBooks(books, totalLivros);
            break;
        case 4:
        default:
            return;
            break;
    }
}
void CadastraLivro(struct Book books[], int *totalLivros)
{
    int quantidade;
    int status;
    system("clear");
    printf("|--------------------- Cadastro de Livros --------------------|\n");
    printf("\n");
    printf("Quantos livros deseja cadastra: ");
    scanf("%d", &quantidade);

    for (int i = 0; i <= quantidade - 1; i++)
    {
        books[*totalLivros].Codigo = *totalLivros;
        printf("Codigo do Livro: %d", *totalLivros);
        printf("\nDigite o Titulo do Livro: ");
        scanf("%s", books[*totalLivros].Titulo);
        printf("Digite o Autor: ");
        scanf("%s", books[*totalLivros].Autor);
        printf("Digite a Editora: ");
        scanf("%s", books[*totalLivros].Editora);
        printf("Digite o Ano de Publicação: ");
        scanf("%d", &books[*totalLivros].AnoPublicacao);
        printf("Digite Quantidade Disponivel: ");
        scanf("%d", &books[*totalLivros].QuantidadeDisponivel);
        printf("Digite 0(disponivel) ou 1(indisponivel): ");
        scanf("%d", &status);
        books[*totalLivros].StatusEmprestimo = status;




}
void GetFirstBook(struct Book books[], int *totalLivros)
{
    int currentCodigo = 0;
    printf("\n");
    system("clear");
    printf("|--------------------- Consultar Livro --------------------|\n");
    printf("Qual o Codigo do livro que deseja procurar: ");
    scanf("%d", &currentCodigo);

    if (currentCodigo <= *totalLivros)
    {
        printf("\n");
        printf("Codigo do Livro: %d\n", books[currentCodigo].Codigo);
        printf("Titulo: %s\n", books[currentCodigo].Titulo);
        printf("Autor: %s\n", books[currentCodigo].Autor);
        printf("Editora: %s\n", books[currentCodigo].Editora);
        printf("Ano de Publicação: %d\n", books[currentCodigo].AnoPublicacao);
        printf("Unidades: %d\n", books[currentCodigo].QuantidadeDisponivel);
        printf("Disponibilidade: %p\n", &books[currentCodigo].StatusEmprestimo);
        system("clear");
        printf("|------------------------------------------------------|\n");
    }
    else
    {
        printf("Livro Nao encontrado!!! \n");
    }

}
void GetAllBooks(struct Book books[], int *totalLivros)
{
    system("clear");
    printf("|--------------------- Relatorio de Livros --------------------|\n");
    if (*totalLivros != 0)
    {
        for (int i =0; i <= *totalLivros -1; i++) {
            printf("Codigo do livro:  %d\n", books[i].Codigo);
            printf("Titulo do Livro:  %s\n", books[i].Titulo);
            printf("Autor do Livro: %s\n", books[i].Autor);
            printf("A Editora: %s\n", books[i].Editora);
            printf("Ano de Publicação: %d\n", books[i].AnoPublicacao);
            printf("Unidades: %d\n", books[i].QuantidadeDisponivel);
            printf("Disponibilidade para Emprestimo: %p\n", &books[i].StatusEmprestimo);
            printf("|-----------------------------------------------------|\n");
        }
    }else
    {
        printf("Nao temos livros Cadastrados ainda.\n");
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


    MenuPrincipal();


}
