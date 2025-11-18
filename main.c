#include <stdio.h>
struct Books
{
    char Titulo[100];
    char 
};
int main(void) {
    struct Books livros;

    printf("Cadastro de Livros: \n");
    fgets(livros.Titulo, sizeof(livros.Titulo), stdin);

    printf("o Titulo do Livros e: %s", livros.Titulo);


}