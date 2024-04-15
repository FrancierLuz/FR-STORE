#ifndef CAMISAS_H
#define CAMISAS_H

typedef struct {
    int preco;
    char nome[15];
    char tamanho;
    struct produto* prox;
} produto;

/*Validar os emails*/
bool validarEmail(const char* email);

/*Cadastrar os emails*/
void CadastroEmail();

/*Cadastrar os Usuarios*/
void cadastrarUsuario();

/*Realizar login dos usuários*/
void fazerLogin();

/*Menu com opções*/
void menu();

/*Cadastrar Camisas*/
void cadastrar();

/*Buscar Camisas*/
void buscar(char *nome);

/*Mostrar camisas cadastradas*/
void listar();


/*Inserir tamanho da camisa*/
int tamanho();

/*Excluir camisa cadastrada*/
void excluir(char *nome);


/*Editar nome, tamnaho e precos da camisa*/
void editar(char *nome);


/*Principal*/
int main();


#endif