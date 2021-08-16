#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>
#define MAX 10
#define TAM 30


struct lista
{
      char vet[MAX][TAM];
      int fl; 
};

Lista cria_lista()
{
      Lista l;      
      l = (Lista)malloc(MAX*sizeof(struct lista));
      
      if(l== NULL)
      {
         return NULL;
      }
      l->fl = 0;
      
      return l;      
}

int verifica_vazia(Lista l)
{    
     //se a lista nao existir
     if(l == NULL)
     {
         return -1;
     }
     //se o final da lista for a primeira posicao do vetor,entao a lista e vazia
     if(l->fl == 0)
     {
         return 1;             
     }
     //se existir um elemento na lista
     if(l->fl > 0)
     {
        return 0;
     }     
}    

int verifica_cheia(Lista l)
{
     //se a lista nao existir
     if(l == NULL)
     {
         return -1;
     }
     //se a lista for cheia       
     if(l->fl == MAX-1)
     {
         return 1;     
     }
     //se a lista ainda nao for cheia
     if(l->fl >= 0 && l->fl < MAX-1)
     {
         return 0;
     }
     
}

int consulta_no(Lista l, char elem[])
{
    int i;
    // se a lista nao existir
    if(l == NULL)
    {
          return -1;
    }
    for(i = 0; i < MAX-1;i++)
    {
          //se o elemento existir na lista
          if(strcmp(l->vet[i],elem) == 0)
          {
              return 1;         
          }
    }
    // se o elemento nao existir na lista
    return 0;
}

int insere_elems(Lista *l, char elem[])
{
    int i,j;
    char temp[TAM];
    //se a lista nao existir       
    if((*l)==NULL)
    {
          return -1;
    }           
    //Se for a primeira insercao insiro no fim da lista pos o indice e zero e nao tem nenhum elemento na lista por ser vazia
    if((*l)->fl == 0)
    {
       strcpy((*l)->vet[0],elem);
       (*l)->fl++;
       return 1;                
    }
    //Se o fim da lista nao for igual ao seu limite de insercao continuo inserindo
    if((*l)->fl != MAX-1)
    {               
       //insiro o elemento no fim da lista         
       strcpy((*l)->vet[(*l)->fl],elem);
       //comparo elemento a elemento do vetor ordenando tudo na sua posicao correta         
       for(j = 0;j < MAX-1;j++)
       {                         
          for(i = 0;i < (*l)->fl;i++)
          { 
              //comparo o elemento inserido no fim da lista com os seus anteriores se o anterior for maior muda com o fim da lista que e uma posicao a frente    
              if(strcmp((*l)->vet[(*l)->fl],(*l)->vet[i]) < 0)              
              {    
                   //recebe o elemento do final da lista  em uma variavel que guarda o valor temporariamente               
                   strcpy(temp,(*l)->vet[i]);
                   //atribui no final da lista o elemento da posicao anterior que for maior que o ultimo inserido no fim da lista                 
                   strcpy((*l)->vet[i],(*l)->vet[(*l)->fl]);
                  //atribui o ultimo elemento que foi inserido no fim da lista na posicao ao qual ele foi de menor valor em relacao ao outro elemento comparado
                   strcpy((*l)->vet[(*l)->fl],temp);                                    
              }              
          }          
       }
       //incrementa o indice do final da lista para uma nova insercao
       (*l)->fl++;
      return 1;
    }
    //se nao for mais possivel inserir as strings    
    return 0;        
}

int remove_elem(Lista *l, char elem[])
{
    int i,j;
    //senao existir a lista
    if((*l) == NULL)
    {
          return -1;
    }   
    for(i = 0;i < (*l)->fl;i++)
    {
         if(strcmp((*l)->vet[i], elem) == 0)
         {
             for(j = i; j < (*l)->fl;j++)
             {
                   //desloca todos os elementos a direita posterior ao elemento removido para a esquerda da lista
                   strcpy((*l)->vet[j],(*l)->vet[j+1]);                   
             }
             (*l)->fl--;
             return 1;             
         }
          
    }
    //senao existir o elem
    return 0;
}

int remove_lista(Lista *l)
{      
      if((*l) != NULL)
      {         
         free(*l);  
         *l = NULL;                
         return 1;         
      }            
      return 0;                 
}

int imprime_lista(Lista l)
{
    int i;
    //se a lista nao existir
    if(l == NULL)
    {
         return -1;
    }
    if(l->fl > 0)
    {        
        for(i = 0; i < l->fl ;i++)
        {
           printf("%s\n",l->vet[i]);   
        }
        return 1;
    }    
    //se o fim da lista o indice for igual a zero quer dizer que a lista e vazia e nao tem elementos     
    return 0;                      
}

void sair()
{
     exit(1);
}
