#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"
#define MAX 10
#define TAM 30
 
struct bebidas
{       
      char nome[MAX][TAM];
      int volume[MAX];
      float preco[MAX];
      int fl;             
};

Bebidas cria_lista()
{
    Bebidas beb;
    
    beb =(Bebidas)malloc(MAX*sizeof(struct bebidas));
    
    if(!beb)
    {
          return NULL;  
    }
    beb->fl = 0;
    return beb;    
}

int verifica_vazia(Bebidas beb)
{    
     //se a lista nao existir
     if(beb == NULL)
     {
         return -1;
     }
     //se o final da lista for a primeira posicao do vetor,entao a lista e vazia
     if(beb->fl == 0)
     {
         return 1;             
     }
     //se existir um elemento na lista
     if(beb->fl > 0)
     {
        return 0;
     }     
}    

int verifica_cheia(Bebidas beb)
{
     //se a lista nao existir
     if(beb == NULL)
     {
         return -1;
     }
     //se a lista for cheia       
     if(beb->fl == MAX-1)
     {
         return 1;     
     }
     //se a lista ainda nao for cheia
     if(beb->fl >= 0 && beb->fl < MAX-1)
     {
         return 0;
     }
     
}

int consulta_no(Bebidas beb,char nome[])
{
    int i;
    // se a lista nao existir
    if(beb == NULL)
    {
          return -1;
    }
    for(i = 0; i < MAX-1;i++)
    {
          //se o elemento existir na lista
          if(strcmp(beb->nome[i],nome) == 0)
          {
              return 1;         
          }
    }
    // se o elemento nao existir na lista
    return 0;
}

int inserirNovoReg(Bebidas *beb,char nome[],int volume,float preco)
{     
    int i,j;
    float temp2,temp3;
    char temp[TAM];
               
    //Se for a primeira insercao insiro no fim da lista pos o indice e zero e nao tem nenhum elemento na lista por ser vazia
    if((*beb)->fl == 0)
    {
       strcpy((*beb)->nome[0],nome);
       (*beb)->volume[(*beb)->fl] = volume;
       (*beb)->preco[(*beb)->fl] = preco;     
       (*beb)->fl++;
       return 1;                
    }
    //Se o fim da lista nao for igual ao seu limite de insercao continuo inserindo
    if((*beb)->fl != MAX-1)
    {               
       //insiro o elemento no fim da lista
       strcpy((*beb)->nome[(*beb)->fl],nome);
       (*beb)->volume[(*beb)->fl] = volume;
       (*beb)->preco[(*beb)->fl] = preco;         
       
       //comparo elemento a elemento do vetor ordenando tudo na sua posicao correta         
       for(j = 0;j < MAX-1;j++)
       {                         
          for(i = 0;i < (*beb)->fl;i++)
          { 
              //comparo o elemento inserido no fim da lista com os seus anteriores se o anterior for maior muda com o fim da lista que e uma posicao a frente    
              if(strcmp((*beb)->nome[(*beb)->fl],(*beb)->nome[i]) < 0)              
              {    
                   //recebe o elemento do final da lista  em uma variavel que guarda o valor temporariamente               
                   strcpy(temp,(*beb)->nome[i]);
                   temp2 = (*beb)->volume[i];
                   temp3 = (*beb)->preco[i];
                   //atribui no final da lista o elemento da posicao anterior que for maior que o ultimo inserido no fim da lista                 
                   strcpy((*beb)->nome[i],(*beb)->nome[(*beb)->fl]);
                   (*beb)->volume[i] = (*beb)->volume[(*beb)->fl];
                   (*beb)->preco[i] = (*beb)->preco[(*beb)->fl];
                   //atribui o ultimo elemento que foi inserido no fim da lista na posicao ao qual ele foi de menor valor em relacao ao outro elemento comparado
                   strcpy((*beb)->nome[(*beb)->fl],temp);
                   (*beb)->volume[(*beb)->fl] = temp2;
                   (*beb)->preco[(*beb)->fl] = temp3;                                                       
              }              
          }          
       }
       //incrementa o indice do final da lista para uma nova insercao
       (*beb)->fl++;       
      return 1;
    }
    //se nao for possivel mais inserir as bebidas     
    return 0;               
}

int remove_beb(Bebidas *beb, char nome[])
{
    int i,j;
    //senao existir a lista
    if((*beb) == NULL)
    {
          return -1;
    }   
    for(i = 0;i < (*beb)->fl;i++)
    {
         if(strcmp((*beb)->nome[i], nome) == 0)
         {
             for(j = i; j < (*beb)->fl;j++)
             {
                   //desloca todos os elementos a direita posterior ao elemento removido para a esquerda da lista
                   strcpy((*beb)->nome[j],(*beb)->nome[j+1]);  
                   (*beb)->volume[j] = (*beb)->volume[j+1];
                   (*beb)->preco[j] = (*beb)->preco[j+1];                 
             }
             (*beb)->fl--;
             return 1;             
         }
          
    }
    //senao existir o elem
    return 0;
}

int remove_lista(Bebidas *beb)
{      
      if((*beb) != NULL)
      {         
         free(*beb);  
         *beb = NULL;                
         return 1;         
      }            
      return 0;                 
}

int imprimir_bebidas(Bebidas beb)
{
     int i;
     //se a lista nao existir
     if(beb == NULL)
     {
         return -1;   
     }     
     if(beb->fl > 0)
     {
         printf("BEBIDA|VOLUME|PRECO:\n"); 
         for(i = 0;i < beb->fl;i++)
         {     
               printf("%s  %d ml  R$ %.2f. \n",beb->nome[i],beb->volume[i],beb->preco[i]);                      
         }     
         return 1;
     }
     //se a lista nao possur elementos
     return 0;     
}

void sair()
{
     exit(1);     
}
