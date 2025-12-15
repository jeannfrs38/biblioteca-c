# Manual do Usuário - Sistema de Biblioteca

Este manual tem como objetivo orientar o uso do sistema de biblioteca desenvolvido em C na IDE CLion . O sistema permite o gerenciamento de **livros**, **usuários** e **empréstimos**, com funcionalidades de cadastro, consulta, relatórios e devoluções.

---

## 📖 Estrutura do Sistema

O sistema é dividido em três módulos principais:

- **Livros**: cadastro, consulta e relatório.
    
- **Usuários**: cadastro, consulta e relatório.
    
- **Empréstimos**: cadastro, relatório de ativos e devolução.
    

---

## 🏠 Menu Principal

Ao iniciar o programa, o usuário verá o menu principal:

```
|-------------------- Biblioteca -------------------|
|1 - Livro
|2 - Usuários
|3 - Empréstimo
|4 - Sair
```

- **Opção 1**: abre o menu de livros.
    
- **Opção 2**: abre o menu de usuários.
    
- **Opção 3**: abre o menu de empréstimos.
    
- **Opção 4**: encerra o programa.
    

---

## 📚 Módulo Livros

### Funções disponíveis:

1. **Cadastrar Livro**
    
    - O sistema solicita título, autor, editora, ano de publicação, quantidade disponível e status (0 = Disponível, 1 = Emprestado).
        
    - O livro é salvo no arquivo [`livros.txt`](https://livros.txt).
        
2. **Consultar Livro**
    
    - Pesquisa por código, título ou autor.
        
    - Exibe os dados completos do livro encontrado.
        
3. **Relatório de Livros**
    
    - Lista todos os livros cadastrados com suas informações.
        

---

## 👤 Módulo Usuários

### Funções disponíveis:

1. **Cadastrar Usuário**
    
    - Solicita nome, curso, telefone e data de cadastro.
        
    - Usuário é salvo no arquivo [`usuarios.txt`](https://usuarios.txt).
        
2. **Consultar Usuário**
    
    - Pesquisa por matrícula ou nome.
        
    - Exibe os dados completos do usuário encontrado.
        
3. **Relatório de Usuários**
    
    - Lista todos os usuários cadastrados.
        

---

## 📑 Módulo Empréstimos

### Funções disponíveis:

1. **Cadastrar Empréstimo**
    
    - Solicita matrícula do usuário, código do livro e data do empréstimo.
        
    - Calcula automaticamente a data de devolução (7 dias após o empréstimo).
        
    - Salva no arquivo [`emprestimos.txt`](https://emprestimos.txt).
        
2. **Relatório de Empréstimos Ativos**
    
    - Lista todos os empréstimos com status ativo.
        
3. **Devolução de Empréstimo**
    
    - Solicita a data atual e o código do empréstimo.
        
    - Calcula se o prazo está dentro, vencendo ou atrasado.
        
    - Atualiza o status do empréstimo e devolve a unidade ao estoque do livro.
        

---

## 📂 Arquivos Utilizados

- **[livros.txt](https://livros.txt)** → armazena os dados dos livros.
    
- **[usuarios.txt](https://usuarios.txt)** → armazena os dados dos usuários.
    
- **[emprestimos.txt](https://emprestimos.txt)** → armazena os dados dos empréstimos.
    

Cada linha dos arquivos segue o formato:

- Livros: `Codigo;Titulo;Autor;Editora;Ano;Quantidade;Status`
    
- Usuários: `Matricula;Nome;Curso;Telefone;Dia;Mes;Ano`
    
- Empréstimos: `Codigo;MatriculaUser;CodigoLivro;Dia;Mes;Ano;DiaDevolucao;MesDevolucao;AnoDevolucao;Status`
    

---

## ⚙️ Regras de Uso

- Sempre utilize números inteiros para campos como código, ano, quantidade e status.
    
- Status dos livros: `0 = Disponível`, `1 = Emprestado`.
    
- Status dos empréstimos: `0 = Ativo`, `1 = Devolvido`.
    
- Datas devem ser informadas no formato **DD/MM/AAAA**.
    

---

## 🚨 Mensagens de Erro

- **Entrada inválida: string vazia** → quando o usuário não digita nada.
    
- **Entrada inválida: só números!** → quando o campo exige número e o usuário digita texto.
    
- **Código não encontrado** → quando o código informado não existe.
    
- **Sem unidades disponíveis** → quando não há exemplares do livro para empréstimo.
    

---

## ✅ Boas Práticas

- Sempre cadastre livros e usuários antes de realizar empréstimos.
    
- Mantenha os arquivos organizados e não edite manualmente fora do sistema.
    
- Faça backup dos arquivos regularmente.
    

---

## 🎯 Conclusão

Este sistema oferece uma solução simples e funcional para gerenciar uma biblioteca. Seguindo este manual, o usuário poderá cadastrar, consultar e controlar livros, usuários e empréstimos de forma prática.
