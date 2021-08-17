#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void menu();

int main()
{
    Lista lista = NULL;      
      
    int op,elem,compElem,i;
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
                         if(verifica_vazia(lista)==1)
                         {
                            printf("A lista e vazia.");
                            getch();                         
                         }
                         else
                         {
                            if(verifica_vazia(lista) == -1)
                            {
                                printf("A lista nao existe.");
                                getch();                            
                            }
                            else
                            { 
                                printf("A lista nao e vazia."); 
                                getch();
                            }
                         };break;
                    case 3:
                         if(verifica_cheia(lista) == 1)
                         {
                            printf("A lista e cheia.");
                            getch();                         
                         }
                         else
                         {
                            if(verifica_cheia(lista) == -1)
                            { 
                                printf("A lista nao existe.");
                                getch();                     
                                
                            }
                            else
                            {
                                printf("A lista nao e cheia.");
                                getch();
                            } 
                         };
                         break;
                    case 4:
                         if(lista == NULL)
                         {
                             printf("A lista nao existe.");
                             getch();
                             break;     
                         }
                         if(lista != NULL)
                         {
                             printf("Digite o elemento a ser inserido na lista:");
                             scanf("%d",&elem);   
                                                   
                             if(insere_elems(&lista,elem) == 1)
                             {
                                 printf("Elemento inserido com sucesso.");
                                 getch();                         
                             }
                         }
                         else
                         {
                              printf("Limite de insercoes excedidos.");
                              getch();
                             
                         };
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
                             if(remove_elem(&lista,elem) == -1)
                             {
                                 printf("A lista nao existe.");
                                 getch();                        
                             }
                             else
                             {
                                 printf("Elemento removido com sucesso.");
                                 getch();
                             }
                         }
                         break;
                    case 6:
                         if(remove_lista(&lista)== 1)
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
                         if(imprime_lista(lista) == 1)
                         {
                              getch();                   
                              break;                  
                         }
                         if(imprime_lista(lista) == -1)
                         {
                              printf("A lista nao existe.");
                              getch();
                         }
                         else
                         {
                              printf("A lista nao possui elementos.");
                              getch();
                         }
                         ;
                         break;
                    case 8:
                         printf("Digite o elemento desejado:");
                         scanf("%d",&compElem);
                         
                         if(consulta_no(lista,compElem) == 1)
                         {
                             printf("O elemento existe na lista.");
                             getch();
                         }
                         else
                         {
                             if(consulta_no(lista,compElem) == -1)
                             {
                                 printf("A lista nao existe.");
                                 getch();
                             }
                             else
                             {
                                 printf("O elemento nao existe na lista.");
                                 getch();
                             }                             
                         };                    
                         break;
                    case 9:
                         sair();
                         break;
                    default:
                         if(op <1 && op >9 )
                         {
                            printf("Opcao invalida.");
                            getch();
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


