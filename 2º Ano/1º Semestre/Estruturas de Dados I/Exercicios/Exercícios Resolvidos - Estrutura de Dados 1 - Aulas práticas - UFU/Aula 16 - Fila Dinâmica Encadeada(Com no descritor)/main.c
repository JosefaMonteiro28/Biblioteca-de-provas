#include <stdio.h>
#include <stdlib.h>
#include"fila.h"

void menu();

int main()
{
  noDesc no = NULL;
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
                   inicializa_noDesc(&no);
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
                    if(fila_vazia(no) == 1)
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
                    
                    if(insere_elem_fila(&no,elem) == 1)
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
                    if(remove_elem_fila(&no,&elem) == 1)
                    {
                        printf("\nO elemento removido foi o %d.\n",elem);                           
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
                if(ini == 0)
                {
                    printf("A fila nao foi criada.");
                    getch();   
                }
                else
                {
                    if(imprime_elems(no) == 0)
                    {
                        printf("A fila e vazia.");
                        getch();                
                    }
                    else
                    {
                        getch();
                    }
                };
                break;     
           case 6:
                exit(1);
                break;
           default:
                if(op < 1 && op > 6)
                {
                    printf("opcao invalida.");
                    getch();  
                }   
                break;                               
      }
      system("CLS");
  }
  while(op != 6);
  
}

void menu()
{
    printf("1-Inicializa fila.\n");
    printf("2-Verifica se a fila e vazia.\n");
    printf("3-Insere na fila.\n");
    printf("4-Remove da fila.\n");
    printf("5-Imprime os elementos da fila do inicio para o final.\n");
    printf("6-Sair.\n"); 
}
