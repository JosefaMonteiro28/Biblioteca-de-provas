#include<stdio.h>
#include<stdlib.h>
#include"numRacionais.h"

struct numRacional
{
    int num;
    int den;
};

Racional *criarRac()
{
    Racional *numRac;
    numRac = (Racional *)malloc(sizeof(Racional));
    return numRac;
}

Racional *liberaRac(Racional *numRac)
{
     free(numRac);
     return numRac;
}

int atribuiRac(Racional *numRac,int num,int den)
{
    numRac->num = num;
    numRac->den = den;
    
    return 1;
}

Racional *acessaRac(Racional *numRac,int *num,int *den)
{
    *num = numRac->num;
    *den = numRac->den;
    
    return numRac;        
}

int somaRac(Racional *num1,Racional *num2,Racional *Resultado)
{   
    if(num1->den != 0 && num2->den != 0)
    {
        Resultado->num = ((num1->num)*(num2->den) + (num2->num)*(num1->den));
        Resultado->den = ((num1->den)*(num2->den));
        
        return 1;
    }
    else
    {
        printf("Nao e possivel a operacao.\n");
        getch();
        return 0;        
    }   
}

int subtraiRac(Racional *num1,Racional *num2,Racional *Resultado)
{
    if(num1->den != 0 && num2->den != 0)
    {
        Resultado->num = ((num1->num)*(num2->den) - (num2->num)*(num1->den));
        Resultado->den = ((num1->den)*(num2->den));
        
        return 1;
    }
    else
    {
        printf("Nao e possivel a operacao.\n");
        getch();
        return 0;        
    }
}

int multiplicaRac(Racional *num1,Racional *num2,Racional *Resultado)
{
    if(num1->den != 0 && num2->den != 0)
    {        
        Resultado->num = ((num1->num)*(num2->num));
        Resultado->den = ((num1->den)*(num2->den));
   
        return 1;         
    }
    else
    {
        printf("Nao e possivel a operacao.\n");
        getch();
        return 0;
    }     
}

int divideRac(Racional *num1,Racional *num2,Racional *Resultado)
{
    if(num1->den != 0 && num2->den != 0)
    {        
        Resultado->num = ((num1->num)*(num2->den));
        Resultado->den = ((num1->den)*(num2->num));
   
        return 1;         
    }
    else
    {
        printf("Nao e possivel a operacao.\n");
        getch();
        return 0;
    }   
}

void simplificaRac(Racional *n)
{
    int num, den,resto,mdc;
    num = n->num;
    den = n->den;
    resto = num%den;
    while (resto!=0)
    {
       num = den;
       den = resto;
       resto = num%den;
    }
    mdc = den;
    n->num = (n->num)/mdc;
    n->den = (n->den)/mdc;
}
