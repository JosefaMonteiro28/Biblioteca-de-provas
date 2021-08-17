#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bebidas
{
      char nome[30];
      int volume;
      float preco;             
};

typedef struct bebidas Bebidas;

void inserirNovoReg(int *p,int n,Bebidas *bebidas);
void apagarUltimoReg(int *p,int n,Bebidas *bebidas);
void imprimirTabela(int n,Bebidas *bebidas);

int main()
{
    int *p;    
    int n = 0,op;
    p = &n;
      
    Bebidas *bebidas;
    
    bebidas = (Bebidas *)malloc(sizeof(Bebidas));
    
    //senao for possivel a alocacao de memoria    
    if(!bebidas)
    {
        printf("Memoria insuficiente");        
    }    
    
    do
    {
        printf("1 - Inserir novo registro.\n");
        printf("2 - Apagar ultimo registro.\n");
        printf("3 - Imprimir tabela.\n");
        printf("4 - Sair. \n \n");
                
        printf("Digite a opcao desejada:");
        scanf("%d",&op);
            
        switch(op)
        {
            case 1: inserirNovoReg(p,n,bebidas);break;
            case 2: apagarUltimoReg(p,n,bebidas);break;
            case 3: imprimirTabela(n,bebidas);break;
            case 4: getch();break;
            default: printf("Opcao nao valida.\n");getch();
        }
        system("cls");      
    }
    while(op != 4);
    return 0;   
}

void inserirNovoReg(int *p,int n,Bebidas *bebidas)
{     
     if(n < 20)
     {          
         if(n > 0)
         {
              //realoca mais espacos na memoria necessarios
              bebidas = (Bebidas *)realloc(bebidas, 19*sizeof(Bebidas));
         } 
         printf("Digite o nome da bebida:");
         fflush(stdin);
         gets(bebidas[n].nome);
         
         printf("Digite o volume da bebida:");   
         scanf("%d",&bebidas[n].volume);
         
         printf("Digite o preco da bebida:");   
         scanf("%f",&bebidas[n].preco);
         
         //altera o valor de n na funcao main incrementando
         (*p)++;                                   
     }     
     else
     {
         printf("Numero de registros excedidos.\n");
         getch();
     }          
}

void apagarUltimoReg(int *p,int n,Bebidas *bebidas)
{
    if(n > 0)
    {    
        free(&bebidas[n-1]);
        //altera o valor de n na funcao main decrementando
        (*p)--;
    }
    else
    {
        printf("Nenhum registro cadastrado.");
        getch();
    }     
}

void imprimirTabela(int n,Bebidas *bebidas)
{
     int i;
          
     if(n > 0)
     {
         printf("BEBIDA|VOLUME|PRECO:\n"); 
         for(i = 0;i < n;i++)
         {     
               printf("%s  %d ml  R$ %.2f. \n",bebidas[i].nome,bebidas[i].volume,bebidas[i].preco);                      
         }     
         getch();
     }
     else
     {
         printf("Nenhum registro cadastrado.");
         getch();
     }     
}
