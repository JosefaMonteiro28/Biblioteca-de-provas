#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct agenda
{
    char nome[10];
    int DDD;
    int telefone;
    char tipoTel[10];  
};

typedef struct agenda Cadastro;

void cadastro(int n);
void consulta(int n,Cadastro cadastro[]);
int main()
{       
    int n;    
    printf("Digite o numero de cadastros:");
    scanf("%d",&n);
    printf("\n");
    
    cadastro(n);
    
    getch();
}

void cadastro(int n)
{
    int i;
    
    Cadastro cadastro[n];
     
    for(i=0;i<n;i++)
    {
                                    
        printf("Digite o nome:");
        fflush(stdin);
        gets(cadastro[i].nome);
        printf("\n");
                
        if(strcmp(cadastro[i].nome,"ACABOU")==0)
        {
           exit(1);
        }         
        
        printf("Digite o DDD:");
        scanf("%d",&cadastro[i].DDD);
        printf("\n");
        
        printf("Digite o telefone:");
        scanf("%d",&cadastro[i].telefone);
        printf("\n");
        
        printf("Digite o tipo de telefone:");
        fflush(stdin);
        gets(cadastro[i].tipoTel);
        printf("\n");                        
    } 
    consulta(n,cadastro);
}

void consulta(int n,Cadastro cadastro[])
{
     int i;
     char nome[10]; 
     do
     {         
         printf("Digite o nome desejado para consulta:");
         fflush(stdin);
         gets(nome);
         printf("\n");
         for(i = 0;i < n;i++)
         {
             if(strcmp(nome,cadastro[i].nome)==0)
             {
                printf("O telefone da pessoa %s e %d. \n\n",cadastro[i].nome,cadastro[i].telefone);
             }
             else if(strcmp(nome,"FIM")== 0)
             { 
                 exit(1);                                  
             }
             else
             {
                 printf("O nome desejado nao existe.\n\n");             
             }
         }         
     }
     while(strcmp(nome,"FIM") != 0);//enquanto o nome nao for escrito FIM    
}
