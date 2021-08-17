#include <stdio.h>
#include <stdlib.h>
#include"fila.h"

void menu();

int main()
{
  Fila f;
  int op,elem,ini = 0;
  do
  {
      menu();
      
      printf("Digite a opcao desejada:");
      scanf("%d",&op);
      
      switch(op)
      {
          case 1:
               if(ini == 0)
               {
                   inicializa_fila(&f);
                   ini = 1;
                   printf("Fila criada com sucesso.");  
                   getch(); 
               }
               else
               {
                   printf("A fila ja foi criada.");
                   getch();
               };
               break;
           case 2:
                if(ini == 0)
                {
                    printf("A fila nao foi criada.");
                    getch();   
                }
                else
                {
                    if(fila_vazia(f) == NULL)
                    {
                        printf("A fila e vazia.");
                        getch();             
                    }
                    else
                    {
                        printf("A fila nao e vazia.");
                        getch();
                    }
                };
                break;           
           case 3:
                if(ini == 0)
                {
                    printf("A fila nao foi criada.");
                    getch();   
                }
                else
                {
                    printf("\nDigite o elemento a ser inserido:");
                    scanf("%d",&elem);
                    
                    if(insere_elem_fila(&f,elem) == 1)
                    {
                        printf("Elemento inserido com sucesso.");
                        getch();                         
                    }
                    else
                    {
                        printf("Nao e possivel novas insercoes, fila cheia.");
                        getch();
                    }
                };
                break;
           case 4:
                if(ini == 0)
                {
                    printf("A fila nao foi criada.");
                    getch();   
                }
                else
                {
                    if(remove_elem_fila(&f,&elem) == 1)
                    {
                        printf("\nO elemento removido foi %d.",elem);                           
                        printf("Elemento removido com sucesso.");
                        getch();                         
                    }
                    else
                    {
                        printf("Fila vazia.");
                        getch();
                    }
                };
                break;
           case 5:
                exit(1);
                break;
           default:
                if(op < 1 && op > 5)
                {
                    printf("opcao invalida.");
                    getch();  
                }   
                break;                               
      }
      system("CLS");
  }
  while(op != 5);
  
}

void menu()
{
    printf("1-Inicializa fila.\n");
    printf("2-Verifica se a fila e vazia.\n");
    printf("3-Insere na fila.\n");
    printf("4-Remove da fila.\n");
    printf("5-Sair.\n"); 
}
