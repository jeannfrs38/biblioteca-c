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
struct Livro
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
struct Usuario
{
    int  Matricula;
    char Nome[100];
    char Curso[100];
    char Telefone[15];
    struct Data DataCadastro;
};
//Struct do tipo emprestimo para facilitar o emprestimo de um livro
struct  Emprestimo
{
    int Codigo;
    int MatriculaUser;
    int CodigoLivro;
    struct Data DataEmprestimo;
    struct Data DataDevolucao;
    int Status;
};
const char caminho[11] = "./data";

void strToLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}
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

// Livros
void SalvarLivros(const char *filename, struct Livro livros);
void CarregarDadosLivros(const char *filename, struct Livro livros[], int *totalLivros);

//Users
void SalvarUsers(const char *caminho, struct Usuario users);
void CarregarDadosUsers(const char *filename, struct Usuario users[], int *totalUsers);

// Emprestimos
void SalvarEmprestimos(const char *caminho, struct Usuario users);
void CarregarDadosEmprestimos(const char *filename, struct Emprestimo emprestimos[], int *totalEmprestimos);


// Iniciando Funcoes dos sub-menus
void MenuLivro(struct Livro books[], int *totalLivros);
void MenuUsuario(struct Usuario users[], int *totalUsers);
void MenuEmprestimo(struct Emprestimo emprestimos[],  struct Usuario users[], struct Livro livros[], int *totalEmprestimos, int *totalUsers, int *totalLivros);
// Funcao Menu principal
void MenuPrincipal(void){
    struct Livro livros[100];
    struct Usuario users[100];
    struct Emprestimo emprestimos [100];
    int totalLivros = 0;
    int totalUsers = 0;
    int totalEmprestimos = 0;
    int opcao;
    CarregarDadosLivros("livros.txt", livros, &totalLivros);
    CarregarDadosUsers("usuarios.txt", users, &totalUsers);
    do {

        printf("|-------------------- Biblioteca -------------------|\n");
        printf("\n");
        printf("|1 - Livro\n");
        printf("|2 - Usuarios\n");
        printf("|3 - Emprestimo\n");
        printf("|4 - Sair\n");
        printf("\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:

                MenuLivro(livros, &totalLivros);
                break;
            case 2:
                MenuUsuario(users, &totalUsers);
                break;
            case 3:
                MenuEmprestimo(emprestimos, users, livros ,&totalEmprestimos, &totalUsers, &totalLivros);
                break;
            case 4:
            default:

                break;
        };
    }while (opcao != 4);

};

// Iniciando Funcoes do sub-menu Livros.
void CadastrarLivro(struct Livro livros[],  int *totalLivros);
void PesquisarLivros(struct Livro livros[], int *totalLivros);
void RelatorioLivros(struct Livro livros[], int *totalLivros);
const char* VerificaStatus( int valor, const char *mensagem, const char *mensagem2);

// Funcoes MenuLivro
void MenuLivro(struct Livro books[], int *totalLivros)
{
    int opcao;
    do {
        printf("\n|--------------------- Livros --------------------|\n\n");
        printf("|1 - Cadastrar Livro\n");
        printf("|2 - Consultar Livro\n");
        printf("|3 - Relatorio de Livros\n");
        printf("|4 - Sair/Voltar\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                CadastrarLivro(books, totalLivros);
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
    }while (opcao != 4);

}
//funcao para verificar Entrada do tipo string
void CadastrarLivro(struct Livro livros[],  int *totalLivros)
{

    char status[50];
    int quantidade = 0;
    printf("\n|--------------------- Cadastro de Livros --------------------|\n");
    printf("Quantos livros deseja Cadastra?");
    scanf("%d", &quantidade);
    getchar();
    for (int i = 0; i < quantidade; i++) {

        printf("%d", *totalLivros);
        livros[*totalLivros].Codigo = *totalLivros + 1;
        printf("\n|--------------------- Codigo do Livro: %d --------------------|\n", livros[*totalLivros].Codigo);
        while(!VerificaString("\nDigite o Titulo do Livro:" , livros[*totalLivros].Titulo,sizeof(livros[*totalLivros].Titulo)));
        while(!VerificaString("Nome do Autor: ", livros[*totalLivros].Autor, sizeof(livros[*totalLivros].Autor)));
        while(!VerificaString("Qual Editora: ", livros[*totalLivros].Editora, sizeof(livros[*totalLivros].Editora)));
        while(!VerificaInteiro("Ano de Publicacão: ", &livros[*totalLivros].AnoPublicacao));
        while(!VerificaInteiro("Quantas unidades: ", &livros[*totalLivros].QuantidadeDisponivel));
        while(!VerificaInteiro("Digite 0(Disponivel) e 1 (Emprestado): ", &livros[*totalLivros].StatusEmprestimo));


        printf("\n|--------Livro Cadastrado com Sucesso!!----------|\n");
        printf("Codigo do Livro: %d", livros[*totalLivros].Codigo);
        printf("Titulo: %s\n", livros[*totalLivros].Titulo);
        printf("Autor: %s\n", livros[*totalLivros].Autor);
        printf("Editora: %s\n", livros[*totalLivros].Editora);
        printf("Ano de Publicacao: %d\n", livros[*totalLivros].AnoPublicacao);
        printf("Unidades em Estoque: %d\n", livros[*totalLivros].QuantidadeDisponivel);
        printf("Status: %s\n", VerificaStatus(livros[*totalLivros].StatusEmprestimo, "Disponivel", "Emprestado"));
        printf("\n|-----------------------------------------|\n");
        SalvarLivros("livros.txt", livros[*totalLivros]);
        (*totalLivros)++;


    }


}
void PesquisarLivros(struct Livro livros[], int *totalLivros)
{
    int CodigoAtual = 0;
    int indice = 0;
    int opcao = 0;
    char buscaTexto[80];
    printf("\n");
    printf("|--------------------- Consultar Livro --------------------|\n");
    printf("Como voce desejar Pesquisar:\n ");
    printf("1 - Codigo do livro \n");
    printf("2 - Titulo do Livro \n");
    printf("3 - Nome do Autor \n");
    printf("4 - Sair\n");
    printf("\nEscolha um tipo de pesquisa: ");
    scanf("%d", &opcao);
    getchar();
    switch (opcao)
    {
        case 1:
            while (!VerificaInteiro("Digite o Codigo do livro: ", &CodigoAtual))
            for (int i = 0; i <= *totalLivros -1; i++) {
                if (CodigoAtual == livros[i].Codigo) {

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
                    strToLower(livros[i].Titulo);
                    if (strcmp(buscaTexto, livros[i].Titulo) == 0)
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
                strToLower(livros[i].Autor);
                if (strcmp(buscaTexto, livros[i].Autor) == 0)
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
        printf("Titulo: %s\n", livros[indice].Titulo);
        printf("Autor: %s\n", livros[indice].Autor);
        printf("Editora: %s\n", livros[indice].Editora);
        printf("Ano de Publicacao: %d\n", livros[indice].AnoPublicacao);
        printf("Unidades em Estoque: %d\n", livros[indice].QuantidadeDisponivel);
        printf("Status: %s\n", VerificaStatus(livros[indice].StatusEmprestimo, "Disponivel","Emprestado"));
        printf("\n|--------------------------------|\n");
    }
    else
    {
        printf("Livro Nao encontrado!!! \n");
    }

}
void RelatorioLivros(struct Livro livros[], int *totalLivros)
{

    printf("|--------------------- Relatorio de Livros --------------------|\n");
    printf("%d", *totalLivros);
    if (*totalLivros >= 0)
    {
        for (int i = 0; i < *totalLivros; i++) {
            printf("Codigo do livro:  %d\n", livros[i].Codigo);
            printf("Titulo do Livro:  %s\n", livros[i].Titulo);
            printf("Autor do Livro: %s\n", livros[i].Autor);
            printf("A Editora: %s\n", livros[i].Editora);
            printf("Ano de Publicação: %d\n", livros[i].AnoPublicacao);
            printf("Unidades: %d\n", livros[i].QuantidadeDisponivel);
            printf("Status para Emprestimo: %s\n", VerificaStatus(livros[i].StatusEmprestimo, "Disponivel", "Emprestado"));
            printf("|-----------------------------------------------------|\n");
        }
    }else
    {
        printf("Nao temos livros Cadastrados ainda.\n");
    }

}
const char* VerificaStatus(int valor, const char *disponivel, const char  *emprestado)
{
    char texto[50];
    if (valor == 1) {

        return emprestado;
    }

    return disponivel;

}

//Iniciando Funcoes do sub-menu Usuario
void CadastrarUser(struct Usuario users[], int *totalUsers);
void PesquisarUser(struct Usuario users[], int *totalUsers);
void RelatorioUser(struct Usuario users[], int *totalUsers);
//Menu Usuario
void MenuUsuario(struct Usuario users[], int *totalUsers)
{
    int opcao;
    do{
        printf("|--------------------- Usuarios ----------------------|\n");
        printf("\n");
        printf("|1 - Cadastra Usuario\n");
        printf("|2 - Consultar Usuario\n");
        printf("|3 - Relatorio de Usuario\n");
        printf("|4 - Sair/Voltar\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                CadastrarUser(users, totalUsers);
                break;
            case 2:
                PesquisarUser(users, totalUsers);
                break;
            case 3:
                RelatorioUser(users, totalUsers);
                break;
            case 4:
            default:
                break;
        }
    }while (opcao != 4);
}
//funcoes Usuario
void CadastrarUser(struct Usuario users[], int *totalUsers)
{
    int quantidade = 0;
    int status;
    printf("\n|--------------------- Cadastro de Usuarios --------------------|\n");
    printf("Quantos Usuarios deseja Cadastra: ");
    scanf("%d", &quantidade);
    getchar();
    for (int i = 0; i < quantidade; i++) {


        users[*totalUsers].Matricula = *totalUsers;
        printf("\n|--------------------- Usuario : %d --------------------|\n", users[*totalUsers].Matricula);
        while(!VerificaString("\nDigite o Nome do Usuario: " , users[*totalUsers].Nome,sizeof(users[*totalUsers].Nome)));

        while(!VerificaString("Qual o Curso: ", users[*totalUsers].Curso, sizeof(users[*totalUsers].Curso)));
        while(!VerificaString("Qual  o Telefone(55999999999): ", users[*totalUsers].Telefone, sizeof(users[*totalUsers].Telefone)));
        while(!VerificaInteiro("Dia Do Cadastro: ", &users[*totalUsers].DataCadastro.dia));
        while(!VerificaInteiro("Mes Do Cadastro: ", &users[*totalUsers].DataCadastro.mes));
        while(!VerificaInteiro("Ano Do Cadastro: ", &users[*totalUsers].DataCadastro.ano));

        printf("\nUsuario Cadastrado com Sucesso!!\n");
        printf("Nome: %s\n", users[*totalUsers].Nome);
        printf("Curso: %s\n", users[*totalUsers].Curso);
        printf("Telefone: %s\n", users[*totalUsers].Telefone);
        printf("Data de Cadastro: %d/%d/%d\n", users[*totalUsers].DataCadastro.dia, users[*totalUsers].DataCadastro.mes,users[*totalUsers].DataCadastro.ano);

        printf("\n|-----------------------------------------|\n");
        SalvarUsers("usuarios.txt", users[*totalUsers]);
        (*totalUsers)++;

    }


}
void PesquisarUser(struct Usuario users[], int *totalUsers)
{
    int MatriculaAtual = 0;
    int indice = 0;
    int opcao = 0;
    char buscaTexto[80];
    printf("\n");
    printf("|--------------------- Consultar Usuario --------------------|\n\n");
    printf("1 - Matricula do Usuario \n");
    printf("2 - Nome do Usuario \n");
    printf("3 - Sair\n\n");
    printf("Escolha um tipo de pesquisa: ");
    scanf("%d", &opcao);
    getchar();
    switch (opcao)
    {
        case 1:
            while (!VerificaInteiro("Digite a Matricula do Usuario: ", &MatriculaAtual))
            for (int i = 0; i <= *totalUsers ; i++) {
                if (MatriculaAtual == users[i].Matricula) {

                }
                else
                {
                    indice = -1;
                }
            }
            break;
        case 2:
            while (!VerificaString("Digite o Nome do Usuario: ", buscaTexto, sizeof(buscaTexto)));
            strToLower(buscaTexto);
                for (int i = 0; i < *totalUsers; i++) {
                    strToLower(users[i].Nome);
                    if (strcmp(buscaTexto, users[i].Nome) == 0)
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
    if ( *totalUsers >= 0 && opcao != 3 && indice != -1)
    {
        printf("\n|---------------- Usuario Encontrado ----------------|\n\n");
        printf("Matricula: %d\n", users[indice].Matricula);
        printf("Nome: %s\n", users[indice].Nome);
        printf("Curso: %s\n", users[indice].Curso);
        printf("Telefone: %s\n", users[indice].Telefone);
        printf("Data de Cadastro: %d/%d/%d\n", users[indice].DataCadastro.dia,users[indice].DataCadastro.mes, users[indice].DataCadastro.ano);
        printf("\n|----------------------------------------------------|\n");
    }
    else
    {
        printf("Usuario nao encontrado!!! \n");
    }

}
void RelatorioUser(struct Usuario users[],  int *totalUsers)
{

    printf("|--------------------- Relatorio de Usuarios --------------------|\n");
    if (*totalUsers >= 0)
    {
        for (int i = 0; i < *totalUsers; i++) {
            printf("Matricula:  %d\n", users[i].Matricula);
            printf("Nome:  %s\n", users[i].Nome);
            printf("Curso: %s\n", users[i].Curso);
            printf("Telefone: %s\n", users[i].Telefone);
            printf("Data de Cadastro: %d/%d/%d\n", users[i].DataCadastro.dia, users[i].DataCadastro.mes, users[i].DataCadastro.ano);
            printf("|--------------------------------------------------------|\n");
        }
    }else
    {
        printf("Nao temos livros Cadastrados ainda.\n");
    }

}

//Iniciando Funcoes  sub-menu Emprestimos
void CadastrarEmprestimo(struct Emprestimo emprestimos[],  struct Usuario users[], struct Livro livros[], int *totalEmprestimos, int *totalUsers, int *totalLivros);
void RelatorioEmprestimoAtivo(struct Emprestimo emprestimos[], int *totalEmprestimos);
void DevolucaoEmprestimo(struct Emprestimo emprestimos[], int *totalEmprestimos, struct Livro livros[], int *totalLivros);
bool VerificaInteiroUser(const char *mensagem, int *valor, int *totalUsers, struct Usuario users[]);
bool VerificaInteiroLivro(const char *mensagem, int *valor, int *totalLivros, struct Livro livros[]);
bool VerificaInteiroEmprestimo(const char *mensagem, int *valor, int *totalEmprestimos, struct Emprestimo emprestimos[]);
int DiasNoMes(int mes, int ano);
long DataParaDias(struct Data data);
int diferencaDias(struct Data d1, struct Data d2);
void DiaDevolucao(struct Data *d, int dias);

void MenuEmprestimo(struct Emprestimo emprestimos[],  struct Usuario users[], struct Livro livros[], int *totalEmprestimos, int *totalUsers, int *totalLivros)
{
    int opcao;
    do {
    printf("|--------------------- Emprestimo --------------------|\n");
    printf("\n");
    printf("|1 - Cadastra Emprestimo\n");
    printf("|2 - Relatorio de Emprestimo\n");
    printf("|3 - Devolucao\n");
    printf("|4 - Sair/Voltar\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                CadastrarEmprestimo(emprestimos,users, livros, totalEmprestimos, totalUsers, totalLivros);
                break;
            case 2:
                RelatorioEmprestimoAtivo(emprestimos, totalEmprestimos);
                break;
            case 3:
                DevolucaoEmprestimo(emprestimos, totalEmprestimos, livros, totalLivros);
                break;
            case 4:
            default:
                break;
        }
    }while (opcao != 4);

}

void CadastrarEmprestimo(struct Emprestimo emprestimos[],  struct Usuario users[], struct Livro livros[], int *totalEmprestimos, int *totalUsers, int *totalLivros)
{
    int quantidade = 0;
    int status;
    printf("\n|--------------------- Realizar Emprestimo --------------------|\n");
    printf("Quantos Emprestimos deseja Cadastra? ");
    scanf("%d", &quantidade);
    getchar();
    for (int i = 0; i < quantidade; i++) {


        emprestimos[*totalEmprestimos].Codigo = *totalEmprestimos;
        printf("\n|--------------------- Emprestimo : %d --------------------|\n", emprestimos[*totalEmprestimos].Codigo);
        while (!VerificaInteiroUser("Digite a Matricula do Usuario: ", &emprestimos[*totalEmprestimos].MatriculaUser ,totalUsers, users));
        while (!VerificaInteiroLivro("Digite o Codigo do Livro: ", &emprestimos[*totalEmprestimos].CodigoLivro, totalLivros, livros));
        while (!VerificaInteiro("Digite o Dia do Emprestimo: ", &emprestimos[*totalEmprestimos].DataEmprestimo.dia));
        while (!VerificaInteiro("Digite o Mes do Emprestimo: ", &emprestimos[*totalEmprestimos].DataEmprestimo.mes));
        while (!VerificaInteiro("Digite o Ano do Emprestimo: ", &emprestimos[*totalEmprestimos].DataEmprestimo.ano));
        emprestimos[*totalEmprestimos].DataDevolucao = emprestimos[*totalEmprestimos].DataEmprestimo;
        DiaDevolucao(&emprestimos[*totalEmprestimos].DataDevolucao, 7);
        while(!VerificaInteiro("Digite o Status do emprestimo (0)Ativo e (1)Devolvido:", &emprestimos[*totalEmprestimos].Status));


        printf("\nEmprestimo Cadastrado com Sucesso!!\n");
        printf("Matricula do Usuario: %d\n", emprestimos[*totalEmprestimos].MatriculaUser);
        printf("Codigo do Livro: %d\n", emprestimos[*totalEmprestimos].CodigoLivro);
        printf("Data do Emprestimo: %d/%d/%d\n", emprestimos[*totalEmprestimos].DataEmprestimo.dia, emprestimos[*totalEmprestimos].DataEmprestimo.mes, emprestimos[*totalEmprestimos].DataEmprestimo.ano);
        printf("Data da Devolucao: %d/%d/%d", emprestimos[*totalEmprestimos].DataDevolucao.dia, emprestimos[*totalEmprestimos].DataDevolucao.mes, emprestimos[*totalEmprestimos].DataDevolucao.ano);
        printf("Status: %s\n", VerificaStatus(emprestimos[*totalEmprestimos].Status, "Ativo", "Devolvido"));
        printf("\n|-----------------------------------------|\n");
        (*totalEmprestimos)++;

    }


}
void RelatorioEmprestimoAtivo(struct Emprestimo emprestimos[], int *totalEmprestimos)
{

    printf("|--------------------- Relatorio de Emprestimos Ativos --------------------|\n");
    if (*totalEmprestimos >= 0)
    {
        for (int i = 0; i < *totalEmprestimos; i++) {
            if (emprestimos[i].Status == 0) {
                printf("Codigo:  %d\n", emprestimos[i].Codigo);
                printf("Matricula do Usuario:  %d\n", emprestimos[i].MatriculaUser);
                printf("Codigo do Livro: %d\n", emprestimos[i].CodigoLivro);
                printf("Data do Emprestimo: %d/%d/%d\n", emprestimos[i].DataEmprestimo.dia,emprestimos[i].DataEmprestimo.mes,emprestimos[i].DataEmprestimo.ano);
                printf("Data de Devolucao: %d/%d/%d\n", emprestimos[i].DataDevolucao.dia, emprestimos[i].DataDevolucao.mes, emprestimos[i].DataDevolucao.ano);
                printf("Status: %s\n", VerificaStatus(emprestimos[i].Status, "Ativo", "Devolvido"));
                printf("|--------------------------------------------------------|\n");
            }

        }
    }else
    {
        printf("Nao temos livros Cadastrados ainda.\n");
    }

}
void DevolucaoEmprestimo(struct Emprestimo emprestimos[], int *totalEmprestimos, struct Livro livros[], int *totalLivros)
{
    int CodigoAtual, diff, indiceLivro = 0;
    struct Data data;
    char opcao[10];

    printf("|--------------------- Devolucao Emprestimo --------------------|\n");
    printf("Qual a data de Hoje: ");
    while (!VerificaInteiro("Dia: ", &data.dia));
    while (!VerificaInteiro("Mes: ", &data.mes));
    while (!VerificaInteiro("Ano: ", &data.ano));
    while (!VerificaInteiroEmprestimo("Qual o Codigo do Emprestimo: ",&CodigoAtual, totalEmprestimos, emprestimos));
    printf("O Emprestimo que voce deseja realizar a devolucao e esse? \n");
    printf("Codigo do Emprestimo: %d\n", emprestimos[CodigoAtual].Codigo);
    printf("Matricula do Usuario: %d\n", emprestimos[CodigoAtual].MatriculaUser);
    printf("Codigo do Livro: %d\n", emprestimos[CodigoAtual].CodigoLivro );
    printf("Data Emprestimo: %d/%d/%d\n", emprestimos[CodigoAtual].DataEmprestimo.dia,emprestimos[CodigoAtual].DataEmprestimo.mes, emprestimos[CodigoAtual].DataEmprestimo.ano);
    printf("Data Devolucao: %d/%d/%d\n", emprestimos[CodigoAtual].DataDevolucao.dia, emprestimos[CodigoAtual].DataDevolucao.mes,emprestimos[CodigoAtual].DataDevolucao.ano);
    printf("|---------------------------------------------------------------|\n");
    for (int i =0; i < *totalLivros; i++) {
        if (livros[i].Codigo == emprestimos[CodigoAtual].CodigoLivro) {
            indiceLivro = i;
        }
    }
    diff = diferencaDias(data, emprestimos[CodigoAtual].DataDevolucao);
    if (diff > 0) {
        printf("Faltam %d dias para a devolução.\n", diff);
        while (!VerificaString("Voce Deseja Devolver agora ? ainda tem tempo! digite s para (sim) ou n (nao)?", opcao, sizeof(opcao)));
        if (strcmp(opcao, "s") == 0) {
            emprestimos[CodigoAtual].Status = 1;
            livros[indiceLivro].QuantidadeDisponivel += 1;
            livros[indiceLivro].StatusEmprestimo = 0;
            printf("Livro devolvido com sucesso!!!\n");
        }else {
            return;
        }
    } else if (diff == 0) {
        printf("A devolução é hoje!\n");
        printf("Certo, Voce esta dentro do prazo!\n");
        emprestimos[CodigoAtual].Status = 1;
        livros[indiceLivro].QuantidadeDisponivel += 1;
        livros[indiceLivro].StatusEmprestimo = 0;
        printf("Livro devolvido\n");
    } else {
        printf("O prazo já passou há %d dias.\n", -diff);
        printf("Voce esta atrasado!!\n");
        emprestimos[CodigoAtual].Status = 1;
        livros[indiceLivro].QuantidadeDisponivel += 1;
        livros[indiceLivro].StatusEmprestimo = 0;
    }


}

int DiasNoMes(int mes, int ano) {
    if (mes == 2) {
        //fevereiro
        return(ano % 400 ==0 || (ano % 4 == 0 && ano % 100 != 0))? 29 : 28;
    }

    if (mes == 4 || mes == 6|| mes == 9 || mes == 11 ) return 30;
    return 31;
}
long DataParaDias(struct Data d) {
    long total = d.dia;
    // soma dias dos meses anteriores
    for (int m = 1; m < d.mes; m++) {
        total += DiasNoMes(m, d.ano);
    }
    // soma dias dos anos anteriores
    for (int a = 1; a < d.ano; a++) {
        total += (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0)) ? 366 : 365;
    }
    return total;
}
int diferencaDias(struct Data d1, struct Data d2) {
    long dias1 = DataParaDias(d1);
    long dias2 = DataParaDias(d2);
    return (int)(dias2 - dias1);
}
void DiaDevolucao(struct Data *d, int dias) {
    d->dia += dias;
    while (d->dia > DiasNoMes(d->mes, d->ano)) {
        d->dia -= DiasNoMes(d->mes, d->ano);
        d->mes++;
        if (d->mes > 12) {
            d->mes = 1;
            d->ano++;
        }
    }
}
bool VerificaInteiroUser(const char *mensagem, int *valor, int *totalUsers, struct Usuario users[])
{

    char texto[50];
    char *endptr;
    int indice;
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
    for (int i = 0; i < *totalUsers; i++)
    {
        if(*valor != users[i].Matricula)
        {
            indice = -1;
        }
        else {
            indice = i;
        }

    }
    if (indice == -1) {
        printf("Matricula Nao encontrada");
        return false;
    }
    return true;
}
bool VerificaInteiroLivro(const char *mensagem, int *valor, int *totalLivros, struct Livro livros[])
{

    char texto[50];
    char *endptr;
    int indice;
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
    for (int i = 0; i < *totalLivros; i++)
    {
        if(*valor != livros[i].Codigo)
        {
            indice = -1;
        }
        else {
            livros[i].StatusEmprestimo = 1;
            livros[i].QuantidadeDisponivel -= 1;
            indice = i;
        }

    }
    if (indice == -1) {
        printf("Codigo do livro nao encontrado ");
        return false;
    }
    return true;
}
bool VerificaInteiroEmprestimo(const char *mensagem, int *valor, int *totalEmprestimos, struct Emprestimo emprestimos[])
{

    char texto[50];
    char *endptr;
    int indice;
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
    for (int i = 0; i < *totalEmprestimos; i++)
    {
        if(*valor != emprestimos[i].Codigo)
        {
            indice = -1;
        }
        else {
            indice = i;
        }

    }
    if (indice == -1) {
        printf("Codigo do livro nao encontrado ");
        return false;
    }
    return true;
}

//Funcoes Salvar em Arquivo
void SalvarLivros(const char *filename, struct Livro livros)
{
    FILE* arquivo = fopen( filename,"a");;



    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo");
        return;
    }


        fprintf(arquivo, "%d;%s;%s;%s;%d;%d;%d", livros.Codigo, livros.Titulo, livros.Autor, livros.Editora, livros.AnoPublicacao, livros.QuantidadeDisponivel, livros.StatusEmprestimo);
        fclose(arquivo);
        printf("Arquivo salvo com sucesso");

}
void CarregarDadosLivros(const char *filename, struct Livro livros[], int *totalLivros)
{
        FILE *arquivo = fopen(filename, "r");
        if (arquivo == NULL) {
            printf("Arquivo nao criado\n");
            printf("Salva informacoes para criar o arquivo\n");
            return;
        }
        while (fscanf(arquivo, " %d;%101[^;];%101[^;];%101[^;];%d;%d;%d", &livros[*totalLivros].Codigo, livros[*totalLivros].Titulo, livros[*totalLivros].Autor,
livros[*totalLivros].Editora, &livros[*totalLivros].AnoPublicacao, &livros[*totalLivros].QuantidadeDisponivel, &livros[*totalLivros].StatusEmprestimo) == 7) {
            (*totalLivros)++;
        }

    printf("total Arquivos carregados %d\n", *totalLivros);

}
void SalvarUsers(const char *filename, struct Usuario user)
{
    FILE* arquivo = fopen( filename,"a");;



    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }


    fprintf(arquivo, "%d;%s;%s;%s;%d;%d;%d", user.Matricula, user.Nome, user.Curso, user.Telefone, user.DataCadastro.dia, user.DataCadastro.mes, user.DataCadastro.ano);
    fclose(arquivo);
    printf("Arquivo salvo com sucesso\n");

}
void CarregarDadosUsers(const char *filename, struct Usuario users[], int *totalUsers)
{
    FILE *arquivo = fopen(filename, "r");
    if (arquivo == NULL) {
        printf("Arquivo nao criado");
        printf("Salva informacoes para criar o arquivo");
        return;
    }
    while (fscanf(arquivo, " %d;%101[^;];%101[^;];%101[^;];%d;%d;%d", &users[*totalUsers].Matricula, users[*totalUsers].Nome, users[*totalUsers].Curso,
users[*totalUsers].Telefone, &users[*totalUsers].DataCadastro.dia, &users[*totalUsers].DataCadastro.mes, &users[*totalUsers].DataCadastro.ano) == 7) {
        (*totalUsers)++;
}

    printf("total Arquivos carregados %d\n", *totalUsers);

}
void SalvarEmprestimos(const char *filename, struct Emprestimo emprestimos)
{
    FILE* arquivo = fopen( filename,"a");;



    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }


    fprintf(arquivo, "%d;%d;%d;%d;%d;%d;%d;%d;%d", emprestimos.Codigo, emprestimos.MatriculaUser, emprestimos.CodigoLivro, emprestimos.DataEmprestimo.dia,
        emprestimos.DataEmprestimo.mes, emprestimos.DataEmprestimo.ano, emprestimos.DataDevolucao.dia, emprestimos.DataDevolucao.mes, emprestimos.DataDevolucao.ano);
    fclose(arquivo);
    printf("Arquivo salvo com sucesso\n");

}
void CarregarDadosEmprestimos(const char *filename, struct Emprestimo emprestimos[], int *totalEmprestimos)
{
    FILE *arquivo = fopen(filename, "r");
    if (arquivo == NULL) {
        printf("Arquivo nao criado\n");
        printf("Salva informacoes para criar o arquivo\n");
        return;
    }
    while (fscanf(arquivo, " %d;%d;%d;%d;%d;%d;%d;%d;%d", &emprestimos[*totalEmprestimos].Codigo, &emprestimos[*totalEmprestimos].MatriculaUser,
        &emprestimos[*totalEmprestimos].CodigoLivro, &emprestimos[*totalEmprestimos].DataEmprestimo.dia, &emprestimos[*totalEmprestimos].DataEmprestimo.mes,
        &emprestimos[*totalEmprestimos].DataEmprestimo.ano, &emprestimos[*totalEmprestimos].DataDevolucao.dia, &emprestimos[*totalEmprestimos].DataDevolucao.mes, &emprestimos[*totalEmprestimos].DataDevolucao.ano) == 7) {
        (*totalEmprestimos)++;
}

    printf("total Arquivos carregados %d\n", *totalEmprestimos);

}
int main(void)
{
    MenuPrincipal();
}
