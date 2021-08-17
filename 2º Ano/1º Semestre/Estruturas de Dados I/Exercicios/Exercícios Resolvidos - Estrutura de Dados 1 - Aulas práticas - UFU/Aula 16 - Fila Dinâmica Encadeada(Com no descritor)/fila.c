#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila
{
    int info;
    struct fila *prox;
};

struct nodesc
{
    struct fila *ini;
    struct fila *fim;  
};

int inicializa_noDesc(noDesc *no)
{
    *no = (noDesc)malloc(sizeof(struct nodesc));
    //coloca a fila no estado de vazia
     if(!(*no))
     {
          return 0;
     }
     else
     {
         (*no)->ini = NULL;
         (*no)->fim = NULL;
          return 1;          
     }
}

int fila_vazia(noDesc no)
{
    //verifica se a fila e vazia
    if(no->ini == NULL)
    {
        return 1;     
    }
    else
    {
        return 0;
    }
}

int insere_elem_fila(noDesc *n, int elem)
{
    Fila no;
    no = (Fila)malloc(sizeof(struct fila));
    //senao for possivel a alocacao do no
    if(!no)
    {
        return 0;   
    }
    else
    {
        //o novo no recebe o elemento
        no->info = elem;
        no->prox = NULL;
        //se for o primeiro no
        if((*n)->ini == NULL)
        {
            (*n)->ini = no;
            (*n)->fim = no;
            return 1;
        }
        else
        {
            //o ponteiro prox do no descritor fim que aponta para o ultimo no aponta para o novo no que passa ser o ultimo agora
            (*n)->fim->prox = no;
            //o ponteiro fim do no descritor aponta para o novo no 
            (*n)->fim = no;
        }
        return 1;        
    }
}

int remove_elem_fila(noDesc *n, int *elem)
{
    noDesc aux;
    //se a fila for vazia
    if((*n)->ini == NULL)
    {
        return 0;        
    }
    else
    {
        //elem recebe o elemento do no a ser removido da fila
        *elem = (*n)->ini->info;
        //aux recebe o primeiro no da fila
        aux->ini = (*n)->ini;
        //o inicio da fila aponta para o proximo no sucessor ao inicio que passa agora a ser o novo inicio da fila
        (*n)->ini = (*n)->ini->prox;
        //se a fila possuir somente um no
        if((*n)->ini == (*n)->fim)
        {
            free(aux);         
            (*n)->ini = NULL;
            (*n)->fim = NULL;
            return 1;
        }
        //apaga o no da memoria
        free(aux);
        return 1;
    }
}

int imprime_elems(noDesc f)
{
    noDesc aux;
    if(f->ini == NULL)
    {
        return 0; 
    }
    else
    {
        aux->ini = f->ini;
        while(aux->ini != NULL)
        {
            printf("O elemento e o %d.\n",aux->ini->info);
            //aux->ini recebe o proximo no
            aux->ini = aux->ini->prox;      
        }                      
        return 1;
    }
}

