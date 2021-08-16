#include<"stdio.h">
#include<stdlib.h>
#include"lista.h"

struct lista
{
     int info;
     struct lista *prox; 
};

int inicializa_lista(Lista *l)
{
    *l = NULL;
    return 1;
}
