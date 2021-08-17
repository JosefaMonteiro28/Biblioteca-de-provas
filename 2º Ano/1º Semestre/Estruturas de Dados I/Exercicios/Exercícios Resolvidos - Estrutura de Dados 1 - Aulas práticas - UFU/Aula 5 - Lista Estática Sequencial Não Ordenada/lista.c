#include<stdlib.h>
#include "lista.h"
#define max 10

struct lista
{
       int fim;
       int vet[max];
};

Lista cria_lista()
{
    Lista lista;
    lista = (Lista)malloc(sizeof(struct lista));
    
    if(!lista)
    {
       return lista;
    }
    //recebe o primeiro indice do vetor, como o fim esta no inicio, logo a lista e vazia
    lista->fim = 0;
        
    return lista;        
}

int verifica_vazia(Lista lista)
{     
     if(lista->fim == 0)
     {
         return 1;     
     }
     else
     {
         return 0;
     }                         
}

int verifica_cheia(Lista lista)
{
     if(lista->fim == max-1)
     {
         return 1;                     
     }
     else
     {
         return 0;
     }           
}

int consulta_no(Lista lista,int elem)
{
    int i;
    for(i = 0;i < lista->fim;i++)
    {
         if(lista->vet[i] == elem)
         {
             return 1;        
         } 
    }
    return 0;        
}

int insere_elems(Lista *lista,int elem)
{
     if(lista == NULL)
     {
         return 0;     
     }
     (*lista)->vet[(*lista)->fim] = elem;
     (*lista)->fim++;
     
     return 1;             
}

int remove_elem(Lista *lista,int elem)
{
      int i,j;
      for(i = 0;i < (*lista)->fim;i++)
      {
            j = i;
            if((*lista)->vet[i] == elem)
            {
                free(&(*lista)->vet[i]);
                while(j < (*lista)->fim)
                {
                     //desloca todos os elementos do vetor da direita para a esquerda onde o elemento foi removido   
                    (*lista)->vet[i] = (*lista)->vet[i+1];
                    j++;    
                }
                return 1;
            }            
      }
      return 0;       
}

Lista remove_lista(Lista lista)
{
      free(lista);
      
      return lista;
}

void imprime_lista(Lista lista)
{
    int i;
    
    for(i = 0; i < lista->fim ;i++)
    {
       printf("%d\n",lista->vet[i]);   
    }
    getch();               
}

void sair()
{
     exit(1); 
}



