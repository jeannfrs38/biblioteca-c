#include <stdbool.h>
#include <stdio.h>
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

int main(void) {
    struct Book books[100];
    struct User users[100];
    struct Loan loans[100];




}