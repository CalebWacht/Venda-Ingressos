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

      printf("Selecionar Opção ");
      printf("\n 1- Vender Ingresso");
      printf("\n 2- Listar ingressos Vendidos\n");
      printf("\n 3- Validar ingresso\n");
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
}

void opcaoVender(){
      printf("===============================\n");
      printf("Preencha com as suas informações: \n");
      
      printf("Nome: \n");
            
      printf("Ano Nascimento: \n");
               
}

void opcaoListar(){

}