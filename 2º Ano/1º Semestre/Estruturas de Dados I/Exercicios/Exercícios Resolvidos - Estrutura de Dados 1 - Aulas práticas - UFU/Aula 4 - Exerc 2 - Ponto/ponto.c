#include<math.h>
#include "ponto.h"

struct ponto
{
       float x;
       float y;
};

Ponto *criaPonto()
{        
      Ponto *p;
          
      p = (Ponto *)malloc(sizeof(Ponto));
            
      return p;
}

int atribuiPonto(Ponto *p, float x, float y)
{
      p->x = x;
      p->y = y;
      
      return 1;
}

float distanciaPontos(Ponto *p1,Ponto *p2)
{
      float distancia;
      
      distancia = sqrt(pow(((p2->x) - (p1->x)),2) + pow(((p2->y) - (p1->y)),2));
       
      return distancia;
}

void liberaPonto(Ponto *p)
{
     free(p);
}
