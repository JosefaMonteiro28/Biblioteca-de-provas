#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"

void menu();

int main()
{
    Bebidas beb = NULL;
        
    int volume,op;
    char nome[30],compBeb[30];
    float preco;
    
    do
    {
        menu();
                
        printf("Digite a opcao desejada:");
        scanf("%d",&op);
            
        switch(op)
        {
            case 1:
                 if((beb = cria_lista()) != NULL)
                 {
                    printf("Lista criada com sucesso.");
                    getch();     
                 };
                 break;      
            case 2:
                 if(verifica_vazia(beb)==1)
                 {
                    printf("A lista e vazia.");
                    getch();                         
                 }
                 else
                 {
                    if(verifica_vazia(beb) == -1)
                    {
                        printf("A lista nao existe.");
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
                 if(verifica_cheia(beb) == 1)
                 {
                    printf("A lista e cheia.");
                    getch();                         
                 }
                 else
                 {
                    if(verifica_cheia(beb) == -1)
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
                 if(beb == NULL)
                 {
                     printf("A lista nao existe.");
                     getch();
                     break;   
                 }                 
                 //se a lista nao for nula
                 if(beb != NULL)
                 {
                     printf("Digite o nome da bebida:");
                     fflush(stdin);
                     gets(nome);
                     
                     printf("Digite o volume da bebida:");   
                     scanf("%d",&volume);
                     
                     printf("Digite o preco da bebida:");   
                     scanf("%f",&preco);
                     if((inserirNovoReg(&beb,nome,volume,preco)) == 1)
                     {
                         printf("Registro inserido com sucesso.");
                         getch(); 
                     }                     
                 }
                 else
                 {
                     printf("Numero de registros excedidos.\n");
                     getch();
                 }
                 break;
            case 5:
                 printf("Digite a bebida desejada:");
                 fflush(stdin);
                 gets(compBeb);
                         
                 if(consulta_no(beb,compBeb) == 1)
                 {
                     printf("A bebida existe na lista.");
                     getch();
                 }
                 else
                 {
                     if(consulta_no(beb,compBeb) == -1)
                     {
                         printf("A lista nao existe.");
                         getch();
                     }
                     else
                     {
                         printf("A bebida nao existe na lista.");
                         getch();
                     }                             
                 };                    
                 break;
            case 6:
                 printf("Digite a bebida a ser removida da lista:");
                 fflush(stdin);
                 gets(nome);
                 
                 if(remove_beb(&beb,nome) == 0)
                 {
                     printf("A bebida nao existe na lista.");
                     getch();                      
                 }
                 else
                 {
                     if(remove_beb(&beb,nome) == -1)
                     {
                         printf("A lista nao existe.");
                         getch();                        
                     }
                     else
                     {
                         printf("Bebida removida com sucesso.");
                         getch();
                     }
                 }
                 break;
            case 7:
                 if(remove_lista(&beb)== 1)
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
            case 8:
                 if(imprimir_bebidas(beb) == 1)
                 {
                      getch();
                      break;
                 }
                 if(imprimir_bebidas(beb) == -1)
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
            case 9:
                 sair();
                 break;     
            default: printf("Opcao nao valida.\n");getch();
        }
        system("cls");      
    }
    while(op != 9);
    return 0;    
}

void menu()
{
     printf("1 - Criar lista de bebidas.\n");
     printf("2 - Verifica se a lista e vazia.\n");
     printf("3 - Verifica se a lista e cheia.\n");
     printf("4 - Inserir novo registro de bebida.\n");
     printf("5 - Consultar tipo de bebida.\n");
     printf("6 - Apagar tipo de bebida.\n");
     printf("7 - Apagar lista de bebidas.\n");
     printf("8 - Imprimir tabela.\n");
     printf("9 - Sair. \n \n");
}
