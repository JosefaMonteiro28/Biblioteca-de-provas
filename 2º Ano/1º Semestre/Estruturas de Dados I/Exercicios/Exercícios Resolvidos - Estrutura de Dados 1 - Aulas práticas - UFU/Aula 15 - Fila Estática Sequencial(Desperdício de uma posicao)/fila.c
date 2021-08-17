#include <stdio.h>
#include <stdlib.h>
#include"fila.h"
#define MAX 10

struct fila
{
     int vet[MAX];
     int ini;
     int fim;  
};

int inicializa_fila(Fila *f)
{
    *f = (Fila)malloc(sizeof(struct fila));
    //se nao for possivel a alocacao
    if(!f)
    {
        return 0;  
    }
    else
    {
        //e igual a ultima posicao, pois nao existem pessoas na fila e a entrada de pessoas comeca no fim
        (*f)->ini = MAX-1;
        (*f)->fim = MAX-1;       
        return 1;
    }
}

int fila_vazia(Fila f)
{
    if(f->ini == f->fim)
    {
        return 1;      
    }
    else
    {         
        return 0;
    }
}

int fila_cheia(Fila f)
{
    //se for o limite da fila
    if(f->ini == ((f->fim + 1) % MAX))
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
    //se a fila estiver cheia
    if((*f)->ini == (((*f)->fim + 1) % MAX))
    {
        return 0;      
    }
    else
    {
       //incremento para a proxima posicao do final da fila
       (*f)->fim = (((*f)->fim + 1) % MAX);
       (*f)->vet[(*f)->fim] = elem;
        return 1;
    }
}

int remove_elem_fila(Fila *f, int *elem)
{
    //se a fila for vazia
    if((*f)->ini == (*f)->fim)
    {
        return 0;      
    }
    else
    {
        (*f)->ini = (((*f)->ini + 1) % MAX);
        //remove o primeiro elemento da fila
        *elem = (*f)->vet[(*f)->ini];
        return 1;    
    }    
}
