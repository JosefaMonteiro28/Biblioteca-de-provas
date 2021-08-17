#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"
#define MAX 10

struct pilha
{
    //vetor do tipo pilha   
    int vet[MAX];
    //ultima posicao do vetor e o topo da pilha
    int topo;   
};

int inicializa_pilha(Pilha *p)
{
    //aloca um espaco na memoria para a pilha
    *p = (Pilha)malloc(sizeof(struct pilha));
    //posicao invalida do vetor
    (*p)->topo = -1;
    return 1;
}

int pilha_vazia(Pilha p)
{
    //se for uma posicao invalida, entao a pilha nao tem nenhum elemento
    if(p->topo == -1)
    {
        return 1;      
    }
    else
    {
        return 0;
    }
}

int pilha_cheia(Pilha p)
{
    //se a ultima posicao da pilha for igual a ultima posicao do vetor
    if(p->topo == MAX-1)
    {
        return 1;      
    }
    else
    {
        return 0;
    }
}

int empilha(Pilha *p, int elem)
{
    //se a pilha estiver cheia
    if((*p)->topo == MAX-1)
    {
        return 0;       
    }
    else
    {
        //incremento a pilha do novo vetor para a proxima insercao do novo elemento
        (*p)->topo++;
        //atribuo o elemento ao final da pilha do vetor
        (*p)->vet[(*p)->topo] = elem;
        return 1;
    }
}

int desempilha(Pilha *p, int *elem)
{
    if((*p)->topo == -1)
    {
        return 0;          
    }
    else
    {
        //atribui o valor a variavel elem, o elemento do topo da pilha a ser desempilhado
        *elem = (*p)->vet[(*p)->topo];
        //decrementa a pilha
        (*p)->topo--;
        return 1;
    }
}

int le_topo(Pilha p,int *elem)
{
    if(p->topo == -1)
    {
        return 0;       
    }
    else
    {
        //recebe o elemento do topo da pilha
        *elem = p->vet[p->topo];
        return 1;
    }
}
    
int conv_dec_bin(Pilha p,int num)
{
    while(num > 0)
    {
        p->topo++;      
        //salvo cada bit do numero binario em um vetor      
        p->vet[p->topo] = (num % 2);
        //divido o numero decimal ate nao ser mais possivel por 2     
        num = (num/2);        
    }
    printf("O numero decimal convertido para binario e: ");
    //desempilha cada bit da pilha formando o numero binario desejado
    while(p->topo > -1)
    {
         //imprime cada bit do numero binario                     
         printf("%d",p->vet[p->topo]);
         p->topo--;
    }
    getch();    
    return 1;
}
