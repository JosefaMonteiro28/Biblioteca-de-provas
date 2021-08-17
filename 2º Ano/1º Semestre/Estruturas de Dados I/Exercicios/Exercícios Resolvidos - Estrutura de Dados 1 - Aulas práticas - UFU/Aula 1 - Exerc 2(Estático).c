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
        fflush(stdin);//limpa o buffer do teclado
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
}
