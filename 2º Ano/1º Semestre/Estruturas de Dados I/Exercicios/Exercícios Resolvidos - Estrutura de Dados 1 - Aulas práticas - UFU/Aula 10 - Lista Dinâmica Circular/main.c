#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

void menu();

int main()
{
    Lista l;        
      
    int op,pos;
    
    char elem;
    
    //faz o controle de quando a lista nao existe quando zero e 1 quando for criada na funcao cria_lista
    int ini = 0;
    do
    {
          menu();               
          printf("\nDigite a opcao desejada:");
          scanf("%d",&op);          
          
          switch(op)
          {
                    case 1:
                         if((l = cria_lista()) == NULL)
                         {
                            printf("Lista criada com sucesso.");
                            ini = 1;
                            getch();
                         }
                         else
                         {
                            printf("Nao foi possivel criar a lista, memoria insuficiente."); 
                            getch();
                         };
                         break;
                    case 2:
                         if(ini == 0)
                         {
                            printf("A lista nao existe.");
                            getch();  
                         }
                         else
                         {
                            if(verifica_vazia(l) == 1)
                            {
                                printf("A lista e vazia.");
                                getch();                         
                            }
                            else
                            {                             
                                printf("A lista nao e vazia."); 
                                getch();                            
                            }
                         };
                         break;                    
                    case 3:
                         if(ini == 0)
                         {
                             printf("Nao e possivel inserir o elemento, a lista nao existe.");
                             getch();                         
                         }                         
                         else
                         {
                             printf("Digite o caractere a ser inserido na lista:");
                             fflush(stdin);
                             scanf("%c",&elem);
                             
                             insere_inicio(&l,elem);
                             printf("Elemento inserido com sucesso.");
                             getch();                            
                         };
                         break;
                    case 4:
                         if(ini == 0)
                         {
                             printf("Nao e possivel remover nenhum elemento, a lista nao existe.");
                             getch();
                         }                         
                         else
                         {
                             remove_inicio(&l);
                             printf("Elemento removido com sucesso.");
                             getch();
                         }
                         break;
                    case 5:
                         if(ini == 0)
                         {
                             printf("Nao e possivel inserir o elemento, a lista nao existe.");
                             getch();                         
                         }                         
                         else
                         {
                             printf("Digite o caractere a ser inserido na lista:");
                             fflush(stdin);
                             scanf("%c",&elem);
                             
                             insere_fim(&l,elem);
                             printf("Elemento inserido com sucesso.");
                             getch();                            
                         };
                         break;                         
                    case 6:
                         if(ini == 0)
                         {
                             printf("Nao e possivel remover nenhum elemento, a lista nao existe.");
                             getch();
                         }                         
                         else
                         {
                             remove_fim(&l);
                             printf("Elemento removido com sucesso.");
                             getch();
                         }
                         break;                                   
                    case 7:
                         if(ini == 0)
                         {
                             printf("A lista nao existe para ser removida.");
                             getch();                                  
                         }
                         else
                         {
                              remove_lista(l);                            
                              printf("Lista removida com sucesso.");
                              ini = 0;
                              getch();                                                                                
                         };
                         break;
                    case 8:
                         if(ini == 0)
                         {
                              printf("A lista nao existe.");
                              getch();  
                         }                         
                         else
                         {
                              if(l == NULL)
                              {
                                  printf("A lista nao possui nenhum elemento.");
                                  getch();                                  
                              }
                              else
                              {
                                  imprime_lista(l);
                                  getch();                                  
                              }
                         };
                         break;
                    case 9:
                         if(ini == 0)
                         {
                             printf("A lista nao existe.");
                             getch();  
                         }
                         else
                         {
                             printf("Digite a posicao do elemento desejado na lista:");
                             scanf("%d",&pos);
                             
                             if(consulta_no(l,pos,&elem) == 1)
                             {
                                 printf("O elemento e o %c na lista.",elem);
                                 getch();
                             }
                             else
                             {
                                 printf("O elemento nao existe na lista.");
                                 getch();
                             }
                         };                    
                         break;
                    case 10:
                        if(ini == 0)
                        {
                            printf("A lista nao existe.");
                            getch();  
                        }
                        else
                        {
                            if(tamanho_lista(l) == 0)
                            {
                                 printf("A lista e vazia.");
                                 getch();                
                            }
                            else
                            {
                                 printf("O tamanho da lista e de %d no(s).",tamanho_lista(l));
                                 getch();
                            }                            
                        };
                         break;     
                    case 11:
                         sair();
                         break;
                    default:
                         if(op <1 && op > 11)
                         {
                            printf("Opcao invalida.");
                            getch();
                         }     
          }
          system("cls");                    
    }
    while(op!=11); 
}

void menu()
{
     printf("1-Criar lista.\n");
     printf("2-Verifica se a lista e vazia.\n");     
     printf("3-Insere no inicio.\n");
     printf("4-Remove no Inicio.\n");
     printf("5-Insere o elemento no fim da lista.\n");
     printf("6-Remove o elemento no fim lista.\n");
     printf("7-Remove a lista.\n");
     printf("8-Imprime a lista.\n");     
     printf("9-Consulta o elemento na lista.\n");
     printf("10-Exibe o tamanho da lista.\n");
     printf("11-Sair.\n");
}
