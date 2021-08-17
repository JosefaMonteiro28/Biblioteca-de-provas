#include <stdio.h>
#include <stdlib.h>
#include"pilha.h"

void menu();
int main()
{
  int op,elem,ini = 0;
  Pilha p;
    
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
                  inicializa_pilha(&p);
                  ini = 1;
                  printf("Pilha criada com sucesso.");
                  getch();    
              }
              else
              {
                  printf("A pilha ja foi criada.");
                  getch();
              };
              break;
         case 2:
              if(ini == 0)
              {
                  printf("A pilha nao foi criada.");
                  getch();   
              }
              else
              {
                  if((pilha_vazia(p)) == 1)
                  {
                      printf("A pilha e vazia.");
                      getch();                
                  }
                  else
                  {
                      printf("A pilha nao e vazia.");
                      getch();
                  }
              };
              break;
         case 3:
              if(ini == 0)
              {
                  printf("A pilha nao foi criada.");
                  getch();   
              }
              else
              {
                  printf("Digite o elemento a ser empilhado:");
                  scanf("%d",&elem);
                  
                  //passo o e comercial para ter acesso direto ao endereco da estrutura pilha para ser modificado
                  if((empilha(&p,elem)) == 0)
                  {
                      printf("A pilha esta cheia.");
                      getch();                                       
                  }
                  else
                  {
                      printf("Elemento empilhado com sucesso.");
                      getch();
                  }
              };
              break;
         case 4:
              if(ini == 0)
              {
                  printf("A pilha nao foi criada.");
                  getch();   
              }
              else
              {
                  if((desempilha(&p,&elem)) == 0)
                  {
                      printf("Nao existem elementos para serem desempilhados.");
                      getch();                      
                  }
                  else
                  {
                      printf("O elemento desempilhado e %d.\n",elem);
                      printf("Elemento desempilhado com sucesso.");
                      getch();
                  }
              };
              break;
         case 5:
              if(ini == 0)
              {
                  printf("A pilha nao foi criada.");
                  getch();   
              }
              else
              {
                  if(le_topo(p,&elem) == 0)
                  {
                       printf("A pilha e vazia.");
                       getch();       
                  }
                  else
                  {
                      printf("O elemento do topo da pilha e o %d.",elem);
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
                  printf("Opcao invalida.");
                  getch();
              }    
              break;                                   
     }
     system("CLS");             
  }
  while(op != 6);
  return 0;
}

void menu()
{
     printf("1-Inicializa pilha.\n");
     printf("2-Verifica se a pilha e vazia.\n");
     printf("3-Empilha o elemento na pilha.\n");
     printf("4-Desempilha elemento da pilha.\n");
     printf("5-Le topo de uma pilha.\n");
     printf("6-Sair.\n");
}
