#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

struct fila
{
    int info;
    struct no *prox;   
};

Fila inicializa_fila(Fila *f)
{
    return NULL;
}

int fila_vazia(Fila f)
{
    if(f == NULL)
    {
        return 1; 
    }
    else
    {
        return 0;
    }
}

int insere_elem_fila(Fila *f, int elem)
{
    Fila no;
    no = (Fila)malloc(sizeof(struct fila));
    
    
    if(!no)
    {
        return 0;   
    }
    else
    {
        //o campo info do no recebe o elemento
        no->info = elem;
        //se a fila for vazia
        if(*f == NULL)
        {
            //o prox do primeiro no aponta para ele mesmo
            no->prox = no;
            //a fila aponta para o primeiro no da lista
            *f = no;
            return 1;              
        }
        else
        {
            //o ponteiro prox do novo no aponta para para o primeiro no
            no->prox = (*f)->prox;
            //o ponteiro prox do ultimo no apontado pelo ponteiro do tipo fila aponta para o novo no que passa agora a ser o ultimo no
            (*f)->prox = no;
            //o ponteiro do tipo fila aponta para o novo no que passa a ser o ultimo no
            *f = no;
            return 1;
        }        
    }
    
}

int remove_elem_fila(Fila *f, int *elem)
{
    Fila aux;
    //aux recebe o primeiro no
    aux = (*f)->prox;
    if(*f == NULL)
    {
        return 0;
    }
    else
    {
        //o ponteiro do tipo fila que aponta para o ultimo no aponta para o segundo no que passa agora ser o primeiro no pois aux aponta para o primeiro no
        (*f)->prox = aux->prox;
        free(aux);
        return 1;
    }
}
