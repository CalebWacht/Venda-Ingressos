#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int qtdRuim, qtdRegular, qtdBom, qtdOtimo, opcao;
    
    qtdRuim = 0;
    qtdRegular = 0;
    qtdBom = 0;
    qtdOtimo = 0;
    
    do{ 
        printf("\nO que voce achou do antendimento? Digite uma opcao\n");
        printf("0 - RUIM\n");
        printf("1 - REGULAR\n");
        printf("2 - BOM\n");
        printf("3 - OTIMO\n");
        printf("4 - SAIR\n");
        
        scanf("%d", &opcao);
        
        switch (opcao){
               
           case 0:
                 qtdRuim = qtdRuim + 1;   
                 break;
           case 1:
                 qtdRegular = qtdRegular + 1;
                 break;
           case 2:
                 qtdBom = qtdBom + 1;
                 break;
           case 3:
                 qtdOtimo = qtdOtimo + 1;
                 break;
           case 4:
                break;
           default:
                 printf("Opcao invalida, por favor selecione novamente");   
                 break;
        }
        
    } while (opcao != 4);
      
      system("cls");
      printf("Quantidade de Votos no Ruim: %i\n", qtdRuim);
      printf("Quantidade de Votos no Regular: %i\n", qtdRegular);
      printf("Quantidade de Votos no Bom: %i\n", qtdBom);
      printf("Quantidade de Votos no Otimo: %i\n", qtdOtimo);
      
return 0;
}
