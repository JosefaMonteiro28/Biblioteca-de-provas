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

int insere_inicio(Lista *l,char elem)
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
        
        //se a lista for fazia        
        if(*l == NULL)
        {
            //a lista aponta para o novo no que e o  primeiro no e tambem e o ultimo no da lista
            *l = no;            
            //o novo no aponta para ele mesmo
            no->prox = no;               
        }
        else
        {
            //o prox do novo no aponta pra o primeiro no
            no->prox = (*l)->prox;
            //o prox do primeiro no aponta para o novo no
            (*l)->prox = no;
        }
    }
}

int insere_fim(Lista *l,char elem)
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
        
        //se a lista for fazia        
        if(*l == NULL)
        {
             //a lista aponta para o novo no que e o  primeiro no e tambem e o ultimo no da lista
            *l = no;            
            //o novo no aponta para ele mesmo
            no->prox = no;               
        }
        else
        { 
            //o novo no aponta para o primeiro no
            no->prox = (*l)->prox;
            //o prox do ultimo no aponta para o novo no que sera o ultimo no
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

int remove_inicio(Lista *l)
{
    Lista atual;
    //se a lista for vazia
    if(*l == NULL)
    {
       return 0;              
    }
    else
    {
        //se a lista so possuir um elemento
        if((*l)->prox == *l)
        {
            free(*l);
            *l = NULL;
            return 1;        
        }
        else
        {
            //atual recebe o primeiro no da lista
            atual = (*l)->prox;
            //o prox do ultimo no passa a apontar para o segundo no
            (*l)->prox = atual->prox;
            free(atual);            
        }
        return 1;
    }
}

int remove_fim(Lista *l )
{
    Lista atual;    
    
    //se a lista for vazia
    if(*l == NULL)
    {
       return 0;              
    }
    else
    {
        //se a lista so possuir um elemento
        if((*l)->prox == *l)
        {
            free(*l);
            *l = NULL;        
        }
        else
        {
            //atual aponta para o ultimo no da lista                         
            atual = (*l)->prox;
            //percorro a lista desde o comeco ate chegar no ultimo no
            while(atual->prox != *l)
            {
                //atual recebe o proximo no              
                atual = atual->prox;        
            }
            //o penultimo no recebe o primeiro no 
            atual->prox = (*l)->prox;
            //apago o ultimo no da lista                                            
            free(*l);
            //o ultimo no passa a ser o penultimo no que se torna agora o ultimo no
            *l = atual;
            return 1;                       
        }
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
    atual = l->prox;
    while(atual != l)
    {
          //recebe o endereco de cada no da lista   
          ant = atual;
          //o no de cada percorrimento recebe o endereco do proximo no
          atual = atual->prox;
          //apaga cada no da lista
          free(ant);   
    }
    l = NULL;
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
    if(l == NULL)
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
