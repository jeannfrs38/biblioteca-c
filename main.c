#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    int StatusEmprestimo;
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
        printf("%d", totalLivros);
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
                break;
        };
    }while (opcao != 4);

};

// Iniciando Funcoes do sub-menu Livros.
void CadastraLivro(struct Book books[],  int *totalLivros);
void PesquisarLivros(struct Book books[], int *totalLivros);
void RelatorioLivros(struct Book books[], int *totalLivros);
// Funcoes MenuLivro
void MenuLivro(struct Book books[], int *totalLivros)
{
    int opcao;
        system("clear");
        printf("\n|--------------------- Livros --------------------|\n\n");
        printf("|1 - Cadastra Livro\n");
        printf("|2 - Consultar Livro\n");
        printf("|3 - Relatorio de Livros\n");
        printf("|4 - Sair/Voltar\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                CadastraLivro(books, totalLivros);
                break;
            case 2:
                PesquisarLivros(books, totalLivros);
                break;
            case 3:
                RelatorioLivros(books, totalLivros);
                break;
            case 4:
            default:
                break;
        }


}
//funcao para verificar Entrada do tipo string
bool VerificaString(const char *mensagem, char *destino, size_t tamanho)
{
    printf("%s", mensagem);
    if (fgets(destino, tamanho, stdin) == NULL)
    {
        printf("Erro na leitura\n");
        return false;

    }

    destino[strcspn(destino,"\n")] = '\0';

    if (strlen(destino) == 0)
    {
        printf("Entrada Invalida: string vazia\n");
        return false;
    }

    return true;
}
bool VerificaInteiro(const char *mensagem, int *valor)
{

    char texto[50];
    char *endptr;

    printf("%s", mensagem);
    if (fgets(texto, sizeof(texto), stdin) == NULL)
        return false;
    texto[strcspn(texto, "\n")] = '\0';
    *valor = strtol(texto, &endptr,10);
    if (strlen(texto) == 0)
    {
        printf("Entrada Invalida: string vazia\n");
        return false;
    }
    if (*endptr != '\0')
    {
        printf("Entrada Invalida:só numeros!\n");
        return false;
    }
    return true;
}
void CadastraLivro(struct Book books[],  int *totalLivros)
{
    int quantidade = 0;
    int status;
    system("clear");
    printf("\n|--------------------- Cadastro de Livros --------------------|\n");
    printf("Quantos livros deseja cadastra: ");
    scanf("%d", &quantidade);
    getchar();
    for (int i = 0; i < quantidade; i++) {

        printf("%d", *totalLivros);
        books[*totalLivros].Codigo = *totalLivros;
        printf("\n|--------------------- Codigo do Livro: %d --------------------|\n", books[*totalLivros].Codigo);
        while(!VerificaString("\nDigite o Titulo do Livro:" , books[*totalLivros].Titulo,sizeof(books[*totalLivros].Titulo)));
        while(!VerificaString("Nome do Autor: ", books[*totalLivros].Autor, sizeof(books[*totalLivros].Autor)));
        while(!VerificaString("Qual Editora: ", books[*totalLivros].Editora, sizeof(books[*totalLivros].Editora)));
        while(!VerificaInteiro("Ano de Publicacão: ", &books[*totalLivros].AnoPublicacao));
        while(!VerificaInteiro("Quantas unidades: ", &books[*totalLivros].QuantidadeDisponivel));
        while(!VerificaInteiro("Digite 0(Disponivel) e 1 (Emprestado): ", &books[*totalLivros].StatusEmprestimo));

        printf("Livro Cadastrado com Sucesso!!\n");

        printf("Titulo: %s\n", books[*totalLivros].Titulo);
        printf("Autor: %s\n", books[*totalLivros].Autor);
        printf("Editora: %s\n", books[*totalLivros].Editora);
        printf("Ano de Publicacao: %d\n", books[*totalLivros].AnoPublicacao);
        printf("Unidades em Estoque: %d\n", books[*totalLivros].QuantidadeDisponivel);
        printf("Status: %d\n", books[*totalLivros].StatusEmprestimo);
        printf("\n|-----------------------------------------|\n");
        (*totalLivros)++;

    }


}
void strToLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}
void PesquisarLivros(struct Book books[], int *totalLivros)
{
    int CodigoAtual = 0;
    int indice = 0;
    int opcao = 0;
    char buscaTexto[80];
    printf("\n");
    printf("|--------------------- Consultar Livro --------------------|\n");
    printf("Como voce desejar Pesquisar: ");
    printf("1 - Codigo do livro \n");
    printf("2 - Titulo do Livro \n");
    printf("3 - Nome do Autor \n");
    printf("4 - Sair\n");
    printf("Escolha um tipo de pesquisa: ");
    scanf("%d", &opcao);
    getchar();
    switch (opcao)
    {
        case 1:
            while (!VerificaInteiro("Digite o Codigo do livro: ", &CodigoAtual))
            for (int i = 0; i <= *totalLivros -1; i++) {
                if (CodigoAtual == books[i].Codigo) {

                }
                else
                {
                    indice = -1;
                    printf("Codigo Nao Encontrado! ");
                }
            }
            break;
        case 2:
            while (!VerificaString("Digito o Titulo do livro: ", buscaTexto, sizeof(buscaTexto)));
            strToLower(buscaTexto);
                for (int i = 0; i < *totalLivros; i++) {
                    strToLower(books[i].Titulo);
                    if (strcmp(buscaTexto, books[i].Titulo) == 0)
                    {
                        indice = i;
                    }
                    else
                    {
                        indice = -1;

                    }
                }
            break;
        case 3:
            while (!VerificaString("Digito o Autor do livro: ", buscaTexto, sizeof(buscaTexto)));
            strToLower(buscaTexto);
            for (int i = 0; i < *totalLivros ; i++) {
                strToLower(books[i].Autor);
                if (strcmp(buscaTexto, books[i].Autor) == 0)
                {
                    indice = i;
                }
                else
                {
                    indice = -1;

                }
            }
            break;
        default:
            break;

    }
    if ( *totalLivros > 0)
    {
        printf("\nLivro Encontrado ----------------|\n");
        printf("Titulo: %s\n", books[indice].Titulo);
        printf("Autor: %s\n", books[indice].Autor);
        printf("Editora: %s\n", books[indice].Editora);
        printf("Ano de Publicacao: %d\n", books[indice].AnoPublicacao);
        printf("Unidades em Estoque: %d\n", books[indice].QuantidadeDisponivel);
        printf("Status: %d\n", books[indice].StatusEmprestimo);
        printf("\n|--------------------------------|\n");
    }
    else
    {
        printf("Livro Nao encontrado!!! \n");
    }

}
void RelatorioLivros(struct Book books[], int *totalLivros)
{
    system("clear");
    printf("|--------------------- Relatorio de Livros --------------------|\n");
    printf("%d", *totalLivros);
    if (*totalLivros >= 0)
    {
        for (int i = 0; i < *totalLivros; i++) {
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
