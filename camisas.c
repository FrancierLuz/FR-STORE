#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50



bool validarEmail(const char* email) {
    int i, atCount = 0;
    int length = strlen(email);

    // Verificar se o e-mail contém pelo menos um "@" e um ponto após o "@"
    for (i = 0; i < length; i++) {
        if (email[i] == '@') {
            atCount++;
        }
        if (email[i] == '.' && atCount == 1 && i < length - 1) {
            return true;
        }
    }

    return false;
}

void CadastroEmail() {
    char email[100];

    while (1) {
        printf("==================\n ");
        printf("Digite seu e-mail:\n ");
         printf("==================\n ");
        scanf("%s", email);

        if (validarEmail(email)) {
            printf("E-mail valido.\n");
            break; // Sai do loop se o e-mail for válido
        } else {
            printf("E-mail invalido. Tente novamente.\n");
        }
    }
    system ("pause");
    system ("cls");
}

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];
int numUsers = 0;


void cadastrarUsuario() {
   
    if (numUsers >= MAX_USERS) {
        printf("Limite maximo de usuarios atingido.\n");
        return;
    }

    struct User newUser;
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("        BEM VINDO A FR STORE :)\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("\n");
    printf("\n");
    printf("==================\n");
    printf("Realize o Cadastro\n");
    printf("==================\n");
    printf("\n");
    printf ("Digite o nome de usuario: ");
    scanf("%s", newUser.username);
    printf("Digite a senha: ");
    scanf("%s", newUser.password);

    users[numUsers++] = newUser;
    printf("Usuario cadastrado com sucesso!\n");
    system ("pause");
    system ("cls");
}


void fazerLogin() {
    while (1) {
        char username[MAX_USERNAME_LENGTH];
        char password[MAX_PASSWORD_LENGTH];

        printf("===============\n");
        printf("REALIZE O LOGIN\n");
        printf("===============\n");
        printf("Digite o nome de usuario: ");
        scanf("%s", username);
        printf("Digite a senha: ");
        scanf("%s", password);

        for (int i = 0; i < numUsers; i++) {
            if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
                printf("Login bem-sucedido!\n");
                system("pause");
                system("cls");
                return;
            }
        }

        printf("Nome de usuario ou senha incorretos. Tente novamente.\n");

        printf("Deseja tentar novamente? (1 - Sim / 0 - Sair): ");
        int tentarNovamente;
        scanf("%d", &tentarNovamente);

        if (tentarNovamente == 0) {
            printf("================================\n");
            printf("Encerrando o programa. Ate logo!\n");
            printf("================================\n");
            exit(0);  
        }
    }
}

typedef struct {
    int preco;
    char nome[15];
    char tamanho;
} produto;



void menu() {
    printf("Escolha uma opcao:\n");
    printf("1 - cadastar camisas\n");
    printf("2 - listar camisas\n");
    printf("3 - buscar camisa\n");
    printf("4 - quantidade de camisas\n");
    printf("5 - excluir camisa\n");
    printf("6 - editar  camisa\n");
    printf("0 - sair\n");
    printf("===================\n");
}

void cadastrar() {
    FILE* file = fopen("camisas.b", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    produto a;
    printf("Cadastre uma camisa:\n");
    printf("Informe o nome, preco e tamanho da camisa:\n");
    scanf("%s %d %c", a.nome, &a.preco, &a.tamanho);

    fwrite(&a, sizeof(produto), 1, file);
    fclose(file);

    printf("Camisa cadastrada com sucesso!\n");
}
void buscar(char *nome) {
    FILE* file = fopen("camisas.b", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    produto a;
    int entrou = 0;
    while (fread(&a, sizeof(produto), 1, file)) {
        if (strcmp(a.nome, nome) == 0) {
            printf("%s: R$ %d %c\n", a.nome, a.preco, a.tamanho);
            entrou = 1;
            break;
        }
    }
    if (entrou == 0) {
        printf("Camisa não encontrada\n");
    }
    fclose(file);
}

void listar() {
    FILE* file = fopen("camisas.b", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    produto a;
    while (fread(&a, sizeof(produto), 1, file)) {
        printf("%s: R$ %d %c\n", a.nome, a.preco, a.tamanho);
    }
    fclose(file);
}
int tamanho() {
    FILE* file = fopen("camisas.b", "rb");
    produto a;
    int cont = 0;
    while (fread(&a, sizeof(produto), 1, file)) {
        cont++;
    }
    fclose(file);
    return cont;
}

void excluir(char *nome) {
    int n = tamanho();
    produto v[n];
    FILE *file = fopen("camisas.b", "rb");
    int i = 0;
    while (fread(&v[i], sizeof(produto), 1, file)) {
        i++;
    }
    fclose(file);
    file = fopen("camisas.b", "wb");
    for (i = 0; i < n; i++) {
        if (v[i].nome != nome) {
            fwrite(&v[i], sizeof(produto), 1, file);
        }
    }
    fclose(file);
}

void editar(char nome) {
    int n = tamanho();
    produto v[n];
    FILE *file = fopen("camisas.b", "rb");
    int i = 0;
    while (fread(&v[i], sizeof(produto), 1, file)) {
        i++;
    }
    fclose(file);
    file = fopen("camisas.b", "wb");
    for (i = 0; i < n; i++) {
        if (v[i].nome == nome) {
            int preco;
            printf("Informe  o preco\n");
            scanf("%i", &preco);
            v[i].preco = preco;
            printf("preco: %i", preco);
        }
        printf("preco: %f", v[i].preco);
        fwrite(&v[i], sizeof(produto), 1, file);
    }
    fclose(file);
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    cadastrarUsuario();
    CadastroEmail();
    fazerLogin();
    
    int op;

    menu();
    scanf("%d", &op);
    while (op != 0) {
        if (op == 1) {
           cadastrar();
        } else if (op == 2) {
            listar();
        } else if (op == 3) {
            char nome[10];
            printf("Informe o nome da camisa:\n");
            scanf("%s", nome);
            buscar(nome);
        } else if (op == 4) {
            int n = tamanho();
            printf("Quantidade de camisas: %d\n", n);
        } else if (op == 5) {
            int nome[10];
            printf("Informe o nome para exclusao:\n");
            scanf("%s", nome);
            excluir('nome');
        } else if (op == 6) {
            char nome[10];
            printf("Informe o nome da camisa para edicao:\n");
            scanf("%s", nome);
            editar(nome);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}