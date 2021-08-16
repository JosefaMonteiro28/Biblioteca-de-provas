#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

struct no
{
    //informacao onde ficara o elemento do no   
    int info;
    //ponteiro para o proximo no
    struct no *prox;   
};

Lista cria_lista()
{
    return NULL;
}

int verifica_vazia(Lista l)
{
    //se for uma lista vazia
    if(l == NULL)
    {
        return 1;  
    }
    //se for uma lista sem ser vazia    
    return 0;
}

int insere_elems(Lista *l,int elem)
{
    Lista no;
    
    //aloca um novo no para cada elemento
    no = (Lista)malloc(sizeof(struct no));
    
    //se nao foi possivel alocar o no
    if(!no)
    {
           return 0;
    }
    //insere o elemento no campo info do no
    no->info = elem;
    //o novo no aponta para o primeiro no da lista
    no->prox = *l;
    
    //a lista aponta para o novo no, que vai ser o primeiro no da lista
    *l = no;    
    
    //se o elemento for inserido na lista
    return 1;   
}

int consulta_no(Lista l,int pos,int *elem)
{
    int i;
    //ponteiro que percorre a lista
    Lista aux;
    
    //recebe o endereco do primeiro no    
    aux = l;    
        
    //se a lista for vazia
    if(l == NULL || pos <= 0)
    {
        return 0;  
    }
    else
    {
        for(i = 1; i <= pos;i++)
        {
            if(i == pos)
            {
                 (*elem) = aux->info;
            }
            //aux recebe o endereco do proximo no                       
            aux = aux->prox;                      
        }
    }
    return 1;
}

int remove_elem(Lista *l,int elem)
{
    Lista ant,atual;
    
    //se a lista nao existir
    if(*l == NULL)
    {
        return 0;
    }        
    else
    {
        //atual aponta para o primeiro elemento da lista  
        atual = *l;
        
        //se o elemento for o mesmo elemento do primeiro no da lista 
        if(atual->info == elem)
        {           
            //a lista aponta para o proximo no da lista
            *l = (*l)->prox;
            
            //remove o primeiro no da lista
            free(atual);
            return 1;         
        }
        else
        {
            //enquanto o info do proximo no apontado pelo prox do atual nao for o elemento
            while((atual->prox != NULL) && (atual->prox->info != elem))
            {
                //atual aponta para o proximo no                    
                atual = atual->prox;
            }                    
            //se a lista for percorrida e o no de atual for nulo, quer dizer que o elemento nao existe na lista                    
            if(atual->prox == NULL)
            {
               return 0;              
            }
            else
            {                    
                //anterior recebe o no do proximo no que atual aponta                    
                ant = atual->prox;
                //atual recebe o endereco do proximo no que que anterior aponta
                atual->prox = ant->prox;
                free(ant);                                   
            }            
        }
        return 1;
    }    
}

Lista remove_lista(Lista l)
{
    Lista ant,atual;  
    if(l == NULL)
    {
          return NULL;
    }
    //atual aponta para o primeiro no da lista
    atual = l;
    while(atual != NULL)
    {
          //recebe o endereco de cada no da lista   
          ant = atual;
          //o no de cada percorrimento recebe o endereco do proximo no
          atual = atual->prox;
          //apaga cada no da lista
          free(ant);   
    }
    l == NULL;
    return l;
}

int imprime_lista(Lista l)
{    
    Lista aux;
    
    if(l == NULL)
    {
         return 0;
    }
    
    else
    {        
        //recebe o primeiro no da lista;
        aux = l;
        while(aux != NULL)
        {
             printf("%d\n",aux->info);
             aux = aux->prox;
        }
        return 1;        
    }
    
}

int tamanho_lista(Lista l)
{
    int cont = 0;
    Lista aux;
    if(l == NULL)
    {
         return 0;
    }
    else
    {
        //aux recebe o endereco do primeiro no da lista
        aux = l;
        while(aux != NULL)
        {
             aux = aux->prox;
             //faz a contagem de cada no da lista
             cont++;     
        }
    }    
    return cont;
}

void sair()
{
     exit(1);
}




