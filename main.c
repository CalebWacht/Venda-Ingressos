#include <stdio.h>
#include <stdlib.h>

struct  lista
{
      char nome[20];
      int anoNascimento;
      struct lista *proximo;
};

      struct lista m1, m2, m3;
      struct lista *gancho = &m1;
      

int main(void)
{     

      int opcao;

      system("cls");
      printf("===============================\n");
      printf("Bem vindo ao Circo Maracutaia!\n");
      printf("===============================\n\n");

      printf("Selecionar Opcao\n ");
      printf("\n 1- Vender Ingresso");
      printf("\n 2- Listar ingressos Vendidos");
      printf("\n 3- Validar ingresso");
      printf("\n 4- Sair\n");
      scanf("%d", &opcao);

      switch (opcao)
      {
      case 1:
            opcaoVender();
            break;
      case 2:
            opcaoListar();
            break;

      case 3:
            opcaoValidar();
            break;

      case 4:
            break;

      default:
            printf("Opcao Invalida");
      }
      return 0;
}

void opcaoVender(){
      printf("===============================\n");
      printf("Preencha com as suas informações: \n");
      
      printf("Nome: \n");
            
      printf("Ano Nascimento: \n");

      printf("CPF: \n");

//    validarCPF(cpf);    
}

void opcaoListar(){

}

void opcaoValidar(){
      
}

//Retorno: [1] - Se for válido | [0] - Se for inválido
int validarCPF(char *cpf)
{
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}