#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void menu();

int main()
{
    int ini = 0;
    Lista lista;      
      
    int op,elem,compElem;
    do
    {
          menu();               
          printf("\nDigite a opcao desejada:");
          scanf("%d",&op);          
          
          switch(op)
          {
                    case 1:
                         if(lista = cria_lista())
                         {
                            printf("Lista criada com sucesso.");
                            getch();
                         }
                         else
                         {
                            printf("Nao foi possivel criar a lista, memoria insuficiente."); 
                            getch();
                         };
                    break;
                    case 2:
                         if(verifica_vazia(lista))
                         {
                            printf("A lista e vazia.");
                            getch();                         
                         }
                         else
                         {
                            printf("A lista nao e vazia."); 
                            getch();
                         };break;
                    case 3:
                         if(verifica_cheia(lista))
                         {
                            printf("A lista e cheia.");
                            getch();                         
                         }
                         else
                         {
                            printf("A lista nao e cheia.");
                            getch(); 
                         };
                         break;
                    case 4:
                         printf("Digite o elemento a ser inserido na lista:");
                         scanf("%d",&elem);   
                                               
                         insere_elems(&lista,elem);
                         break;
                    case 5:
                         printf("Digite o elemento a ser removido da lista:");
                         scanf("%d",&elem);
                         
                         if(remove_elem(&lista,elem) == 0)
                         {
                             printf("O elemento nao existe na lista.");
                             getch();                      
                         }
                         else
                         {
                             printf("Elemento removido com sucesso.");
                             getch();
                         }
                         break;
                    case 6:
                         if(lista = remove_lista(lista))
                         {
                             printf("Lista removida com sucesso.");
                             getch();     
                         }
                         else
                         {
                             printf("A lista nao existe.");
                             getch();
                         };
                         break;
                    case 7:
                         imprime_lista(lista);break;
                    case 8:
                         printf("Digite o elemento desejado:");
                         scanf("%d",&compElem);
                         
                         if(consulta_no(lista,compElem))
                         {
                             printf("O elemento existe na lista.");
                             getch();
                         }
                         else
                         {
                             printf("O elemento nao existe na lista ou a lista nao existe.");
                             getch();
                         };                    
                         break;
                    case 9:
                         sair();
                         break;
                    default:
                         if(op <1 && op >9 )
                         {
                            printf("Opcao invalida.");
                         }     
          }
          system("cls");                    
    }
    while(op!=9); 
}

void menu()
{
     printf("1-Criar lista.\n");
     printf("2-Verifica se a lista é vazia.\n");
     printf("3-Verifica se a lista está cheia.\n");
     printf("4-Insere o elemento na lista.\n");
     printf("5-Remove o elemento da lista.\n");
     printf("6-Remove a lista.\n");
     printf("7-Imprime a lista.\n");
     printf("8-Consulta o elemento.\n");
     printf("9-Sair.\n");
}


