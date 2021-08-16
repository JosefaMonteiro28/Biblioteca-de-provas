#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

struct no
{
       //ponteiro para o no anterior
       struct no *ant;
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
    //se a lista for vazia
    if(*l == NULL)
    {                
        //o prox do novo no aponta NULL
        no->prox = NULL;
        //o ant do novo no aponta para NULL
        no->ant = NULL;
        //a lista aponta para o novo no, que vai ser o primeiro no da lista
        *l = no;   
        //se o elemento for inserido na lista
        return 1;  
    }
    else
    {
        //o prox novo no aponta para o primeiro no da lista
        no->prox = *l;
        //o primeiro no que passa a ser o segundo aponta o seu ponteiro ant para o novo no alocado
        (*l)->ant = no;
        //o ant do novo no aponta para NULL
        no->ant = NULL;
        //o ponteiro do tipo lista aponta para o novo no
        *l = no;        
    }       
}

int insere_elems_pos(Lista *l,int pos,int elem)
{
    int i;
    Lista no,aux;
    
    no = (Lista)malloc(sizeof(struct no));
    
    if(!no)
    {
        return 0;   
    }
    no->info = elem;
    //aux recebe o primeiro no da lista
    aux = *l;
    if(pos < 1)
    {
        return 0;  
    }
    //se a lista for vazia
    if(pos == 1 && aux == NULL)
    {
        //a lista aponta para o novo no que passa a ser o primeiro e unico no da lista   
        no->ant = NULL;
        no->prox = NULL;
        *l = no;
        return 1;   
    }
    //se for o primeiro no da lista e a lista possuir ja elemento
    if(pos == 1 && aux != NULL)
    {
       //o prox do novo no aponta para o primeiro no da lista  
       no->prox = *l;
       //o ponteiro ant do primeiro no aponta para o novo no que passa a ser o primeiro no
       (*l)->ant = no;
       //o ponteiro ant do novo no aponta para NULL
       no->ant = NULL;
       //a lista aponta para o novo no
       *l = no;
       return 1;
    }    
    else
    {       
        for(i = 1;i <= pos && aux != NULL;i++)
        {                
                //se for o ultimo no da lista
                if(i == pos && aux->prox == NULL)
                {
                    //o ant do novo no recebe no seu ponteiro o seu no anterior
                    no->ant = aux->ant;
                    //o ponteiro prox aponta para o no que esta na posicao ao qual o novo no sera inserido 
                    no->prox = aux->ant->prox;
                    //o ultimo no aponta para o novo no que passa a ser o ultimo no da lista 
                    aux->ant->prox = no;
                    //o ponteiro ant ultimo no aponta para o novo no
                    aux->ant = no;
                    
                    return 1; 
                }
                //se for uma posicao invalida que nao existe na lista
                if((pos > i) && (aux->prox == NULL))
                {
                    return 0;   
                }                
                else
                {
                    if(i == pos && aux->prox != NULL)
                    {
                        //o ponteiro ant do novo no aponta para o no anterior da posicao do no da lista escolhido que sera trocada pelo novo no
                        no->ant = aux->ant;
                        //o no anterior passa a apontar para o novo no 
                        aux->ant->prox = no;
                        //o ponteiro prox do novo no aponta para o no que ocupava a sua posicao que passa ser o proximo no da lista
                        no->prox = aux;
                        //o no que e da posicao escolhida passa a ser um no a frente do novo no que ocupa a sua posicao agora na lista
                        aux->ant = no;
                        return 1;
                    }                    
                }
                aux = aux->prox;                       
        }
        return 0;
    }
}

int consulta_no(Lista l,int pos,int *elem)
{
    int i;
    //ponteiro que percorre a lista
    Lista aux;
            
    //se a lista for vazia ou a posicao for invalida
    if(l == NULL || pos < 1)
    {
        return 0;  
    }
    else
    {
        //recebe o endereco do primeiro no    
        aux = l;
        
        for(i = 1; i <= pos && aux != NULL;i++)
        {                            
            if(i == pos)
            {
                 (*elem) = aux->info;
                 return 1;
            }
            //aux recebe o endereco do proximo no                       
            aux = aux->prox;                      
        }
        return 0;
    }
}

int remove_elem(Lista *l,int elem)
{
    Lista aux;
    
    //se a lista nao existir
    if(*l == NULL)
    {
        return 0;
    }
    //se a lista so possuir um elemento e for ele o elemento a ser removido
    if((*l)->info == elem && (*l)->prox == NULL)
    {
        free(*l);
        *l = NULL;
    }        
    else
    {
        //atual aponta para o primeiro no da lista  
        aux = *l;
        
        //se o elemento for o mesmo elemento do primeiro no da lista e a lista possuir mais de um no
        if(aux->info == elem)
        {           
            //o segundo no passa a ser o primeiro no e o ponterior ant do segundo no aponta para NULL
            aux->prox->ant = NULL;
            //a lista aponta para o segundo no que passa a ser o primeiro no
            *l = aux->prox;
            free(aux);
            return 1;         
        }
        else
        {
            //enquanto o info do ponteiro apontado por aux nao for o elemento
            while((aux->prox != NULL) && (aux->info != elem))
            {
                //aux aponta para o proximo no                    
                aux = aux->prox;
            }                    
            //se a lista for percorrida e o elemento nao existir na lista                    
            if(aux->prox == NULL && aux->info != elem)
            {
               return 0;              
            }
            //se for o ultimo elemento da lista
            if(aux->info == elem && aux->prox == NULL)
            {
                //o ponteiro prox do penultimo no passa a apontar para NULL e passa a ser o ultimo no         
                aux->ant->prox = NULL;
                free(aux);
                return 1;         
            }
            else
            {                    
                //o no anterior aponta para o proximo no do no que vai ser removido que e o sucessor do anterior                   
                aux->ant->prox = aux->prox;
                //o proximo no do no a ser removido aponta para o anterior do no que vai ser removido
                aux->prox->ant = aux->ant;
                free(aux);
                return 1;                                                  
            }                        
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
    l = NULL;
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
    int cont = 1;
    Lista aux;
    if(l == NULL)
    {
         return 0;
    }
    else
    {
        //aux recebe o endereco do primeiro no da lista
        aux = l;
        while(aux->prox != NULL)
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
