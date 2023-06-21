#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[50];
    int anoNascimento;
    char cpf[12];
} Pessoa;
//Lista de pessoas

void opcaoVender(Pessoa *pessoa, int * numPessoa);
void opcaoListar(Pessoa *pessoa, int numPessoa);
int validarCPF(char *cpf);

int main(void) {

    setlocale(LC_ALL, "Portuguese"); 

    int opcao;
    Pessoa pessoa[80];  // Limite de 80 pessoas 
    int numPessoa = 0;

    while (1) {
        system("cls");
        printf("===============================\n");
        printf("Bem-vindo ao Circo Maracutaia!\n");
        printf("===============================\n\n");

        printf("Selecionar Opcao\n ");
        printf("\n 1- Comprar Ingresso");
        printf("\n 2- Listar ingressos Vendidos");
        printf("\n 3- Validar ingresso");
        printf("\n 4- Sair\n");

        scanf("%d", &opcao);
        fflush(stdin); 

        switch (opcao) {
            case 1:
                opcaoComprar(pessoa, &numPessoa); // Opcao para comprar um ingresso.
                break;
            case 2:
                opcaoListar(pessoa, numPessoa); // Lista todos os ingressos que ja foram vendidos.
                break;
            case 3:
                opcaoValidar(pessoa, numPessoa); // Validar o ingresso pelo CPF.
                break;
            case 4:
                return 0;
            default:
                printf("Opcao Invalida!");
        }
    }
}

void opcaoComprar(Pessoa *pessoa, int *numPessoa){
    Pessoa novaPessoa;

    system("cls");
    printf("===============================\n");
    printf("Preencha com as suas informacoes: \n");

    printf("Nome: ");
    scanf("%s", novaPessoa.nome);

    fflush(stdin); 

    printf("Ano Nascimento: ");
    scanf("%d", &novaPessoa.anoNascimento);

    fflush(stdin); 

    printf("CPF: ");
    scanf("%s", novaPessoa.cpf);

    fflush(stdin);

    if (validarCPF(novaPessoa.cpf)) {
        pessoa[*numPessoa] = novaPessoa;
        (*numPessoa)++;

        printf("Venda realizada com sucesso!\n");
        system("pause"); 
    } else {
        printf("CPF invalido. Venda não realizada.\n");
        system("pause"); 
    }
}

void opcaoListar(Pessoa *pessoa, int numPessoa){
    printf("===============================\n");
    printf("Lista de Clientes:\n");

    for (int i = 0; i < numPessoa; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Nome: %s\n", pessoa[i].nome);
        printf("Ano de Nascimento: %d\n", pessoa[i].anoNascimento);

        // Formatar o CPF com os pontos adequados
        char cpfFormatado[15];
        strncpy(cpfFormatado, pessoa[i].cpf, 3);
        cpfFormatado[3] = '.';
        strncpy(cpfFormatado + 4, pessoa[i].cpf + 3, 3);
        cpfFormatado[7] = '.';
        strncpy(cpfFormatado + 8, pessoa[i].cpf + 6, 3);
        cpfFormatado[11] = '-';
        strncpy(cpfFormatado + 12, pessoa[i].cpf + 9, 2);
        cpfFormatado[14] = '\0';

        printf("CPF: %s\n", cpfFormatado);
        printf("===============================\n");
    }
    system("pause");
}

void opcaoValidar(Pessoa *pessoa, int numPessoa) {

    char cpf[12];
    printf("===============================\n");
    printf("Digite o CPF a ser validado: ");

    scanf("%s", cpf);
    fflush(stdin);

    // Busca o CPF na lista de pessoas
    int encontrado = 0;
    for (int i = 0; i < numPessoa; i++) {
        if (strcmp(cpf, pessoa[i].cpf) == 0) {
            printf("===============================\n");
            printf("Dados da Pessoa:\n");
            printf("Nome: %s\n", pessoa[i].nome);
            printf("Ano de Nascimento: %d\n", pessoa[i].anoNascimento);
            printf("CPF: %s\n", pessoa[i].cpf);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("===============================\n");
        printf("CPF não encontrado.\n");
    }

    printf("===============================\n");
    system("pause");
}

int validarCPF(char *cpf){
    int i, j, digito1 = 0, digito2 = 0;
    
    if (strlen(cpf) != 11)
        return 0;
    else if ((strcmp(cpf, "00000000000") == 0) || (strcmp(cpf, "11111111111") == 0) || (strcmp(cpf, "22222222222") == 0) ||
             (strcmp(cpf, "33333333333") == 0) || (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
             (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) || (strcmp(cpf, "88888888888") == 0) ||
             (strcmp(cpf, "99999999999") == 0))
        return 0; // se o CPF tiver todos os números iguais ele é inválido.
    else {
        // primeiro digito ======================================
        for (i = 0, j = 10; i < strlen(cpf) - 2; i++, j--) // multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i] - 48) * j;
        digito1 %= 11;
        if (digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if ((cpf[9] - 48) != digito1)
            return 0; // se o digito 1 não for o mesmo que o da validação CPF é inválido
        else{
        // segundo digito ======================================
            for (i = 0, j = 11; i < strlen(cpf) - 1; i++, j--) // multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                digito2 += (cpf[i] - 48) * j;
            digito2 %= 11;
            if (digito2 < 2)
                digito2 = 0;
            else
                digito2 = 11 - digito2;
            if ((cpf[10] - 48) != digito2)
                return 0; // se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}