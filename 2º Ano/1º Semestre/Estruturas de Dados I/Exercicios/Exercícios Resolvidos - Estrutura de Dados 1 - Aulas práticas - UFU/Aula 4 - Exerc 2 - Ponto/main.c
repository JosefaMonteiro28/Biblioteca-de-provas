#include<stdio.h>
#include<stdlib.h>
#include "ponto.h"

int main()
{
    Ponto *p1,*p2;
    float x,y,x1,y1,distancia;
    
    printf("Digite o valor da coordenada x do ponto 1:");
    scanf("%f",&x);
    
    printf("Digite o valor da coordenada y do ponto 1:");
    scanf("%f",&y);
    
    printf("Digite o valor da coordenada x do ponto 2:");
    scanf("%f",&x1);
    
    printf("Digite o valor da coordenada y do ponto 2:");
    scanf("%f",&y1);
    
    p1 = criaPonto();    
    p2 = criaPonto();
    
    atribuiPonto(p1,x,y);
    atribuiPonto(p2,x1,y1);       
    
    distancia = distanciaPontos(p1,p2);
        
    printf("A distancia entre os dois pontos e %.2f.\n",distancia);
  
  system("PAUSE");	
  return 0;
}
