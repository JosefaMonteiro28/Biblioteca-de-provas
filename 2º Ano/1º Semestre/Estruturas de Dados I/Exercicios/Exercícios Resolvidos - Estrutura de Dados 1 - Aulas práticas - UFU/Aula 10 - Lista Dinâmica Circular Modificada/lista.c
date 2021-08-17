#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

struct no
{
    //informacao onde ficara o elemento do no   
    char info;
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

int insere_elems(Lista *l,char elem)
{
    Lista no;
        
    //aloca um novo no para cada elemento
    no = (Lista)malloc(sizeof(struct no));
    
    //se nao foi possivel alocar o no
    if(!no)
    {
           return 0;
    }
    else
    {        
        //atribui o elemento inserido ao campo info do novo no
        no->info = elem;
                
        if(*l == NULL)
        {
             //a lista aponta para o novo no que e o  primeiro no e tambem e o ultimo no da lista
            *l = no;            
            //o novo no aponta para ele mesmo
            no->prox = no;               
        }
        else
        {                       
            //o novo no aponta para o ultimo no
            no->prox = (*l)->prox;
            //o ultimo no aponta para o novo no que passa a ser o ultimo no da lista 
            (*l)->prox = no;
            //a lista aponta para o novo no que passa a ser o ultimo no da lista
            *l = no;
        }
        return 1;                
    }      
}

int consulta_no(Lista l,int pos,char *elem)
{
    int i;
    //ponteiro que percorre a lista
    Lista atual;
            
    //se a lista for vazia
    if(l == NULL || pos <= 0)
    {
        return 0;  
    }    
    else
    {
        //recebe o endereco do primeiro no da lista 
        atual = l->prox;
            
        for(i = 1; i <= pos && atual != l; i++)
        {              
            if(i == pos)
            {
                 *elem = atual->info;
                 return 1;
            }            
            //atual recebe o endereco do proximo no                       
            atual = atual->prox;
        }
        //se for o ultimo no e nao for maior que o ultimo no
        if(atual == l && i == pos)
        {
            *elem = atual->info;
            return 1;    
        }        
    }
    return 0;
}

int remove_elem(Lista *l,char elem)
{
    Lista atual,ant;    
    
    //se a lista for vazia
    if(*l == NULL)
    {
       return 0;              
    }
    else
    {
        //se a lista so possuir um elemento
        if((*l)->info == elem && (*l)->prox == *l)
        {
            free(*l);
            *l = NULL;        
        }
        else
        {
            //atual aponta para o ultimo no da lista
            atual = *l;
            
            //enquanto nao for o final da lista e o info do no nao for igual o elemento
            while(atual->prox != *l && atual->prox->info != elem)
            {
                //atual aponta para o proximo no                    
                atual = atual->prox;
            }
            //se o elemento nao existir na lista
            if(atual->prox->info != elem && atual->prox == *l)
            {
                return 0;                 
            }            
            //se o elemento for o ultimo da lista em uma lista com mais de um elemento
            if(atual->prox->info == elem && atual->prox == *l)
            {
                //o penultimo no recebe o primeiro no da lista                         
                atual->prox = (*l)->prox;
                //apago o ultimo no da lista                                            
                free(*l);
                //o penultimo no passa a ser o ultimo no
                *l = atual;
                return 1;                
            }            
            else
            {
                //anterior recebe o no do proximo no que atual aponta                    
                ant = atual->prox;
                //atual recebe o endereco do proximo no que que anterior aponta
                atual->prox = ant->prox;
                free(ant);
                return 1;
            }
        }
    }
    return 0;            
}

Lista remove_lista(Lista l)
{
    Lista ant,atual;  
    if(l->prox == NULL)
    {
          return NULL;
    }
    //atual aponta para o primeiro no da lista
    atual = l;
    while(atual->prox != NULL)
    {
          //recebe o endereco de cada no da lista   
          ant = atual;
          //o no de cada percorrimento recebe o endereco do proximo no
          atual = atual->prox;
          //apaga cada no da lista
          free(ant);   
    }
    l->prox == NULL;
    return l;
}

int imprime_lista(Lista l)
{    
    Lista atual;
    
    if(l == NULL)
    {
         return 0;
    }    
    else
    {
        //recebe o primeiro no da lista;
        atual = l->prox;
                        
        while(atual != l)
        {
            printf("%c\n",atual->info);
            //atual recebe o endereco do proximo no 
            atual = atual->prox;        
        }
        if(atual == l)
        {
            printf("%c\n",atual->info);     
        }
    }
    return 1;
}

int tamanho_lista(Lista l)
{
    int cont = 1;
    Lista atual;
    if(l->prox == NULL)
    {
         return 0;
    }
    else
    {
        //atual recebe o endereco do primeiro no da lista
        atual = l->prox;
        while(atual != l)
        {
             atual = atual->prox;
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
