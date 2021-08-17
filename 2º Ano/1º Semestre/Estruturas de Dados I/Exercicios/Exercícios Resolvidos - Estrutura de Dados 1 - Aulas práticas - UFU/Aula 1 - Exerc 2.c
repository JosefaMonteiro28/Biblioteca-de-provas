#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct agenda
{
    char nome;
    int DDD;
    int telefone;
    char tipoTel;  
};
typedef struct agenda Cadastro;
int main()
{
    int i;
    Cadastro *cadastro;
    
    cadastro = (Cadastro *)malloc(sizeof(Cadastro));//cadastro e um ponteiro para o Cadastro
    
    if(!cadastro)
    {
       printf("Nao foi possivel a alocacao de memoria\n");   
    }
    
    
    for(i=0;strcmp(cadastro[i].nome,"ACABOU") != 0;i++)
    {           
        printf("Digite o nome:");
        gets((cadastro[i].nome);
        printf("\n");
        
        printf("Digite o DDD:");
        scanf("%d",&cadastro[i].DDD);
        printf("\n");
        
        printf("Digite o telefone:");
        scanf("%d",&cadastro[i].telefone);
        printf("\n");
        
        printf("Digite o tipo de telefone:");
        gets(cadastro[i].tipoTel);
        printf("\n");        
    }
    getch();
}
