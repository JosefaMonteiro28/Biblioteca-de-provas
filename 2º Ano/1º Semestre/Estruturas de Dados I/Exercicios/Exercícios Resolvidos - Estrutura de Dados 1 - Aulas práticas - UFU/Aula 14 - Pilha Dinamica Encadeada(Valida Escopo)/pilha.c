#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pilha.h"
struct pilha
{
    int info;   
    struct pilha *prox;   
};

int inicializa_pilha(Pilha *p)
{
    *p = NULL;
    //coloca a pilha no estado de vazia  
    return 1;
}

int pilha_vazia(Pilha p)
{
    //se for vazia
    if(p == NULL)
    {
        return 1; 
    }
    else
    {
        return 0;
    }
}

int empilha(Pilha *p,int elem)
{
    Pilha no;
    no = (Pilha)malloc(sizeof(struct pilha));
    //senao foi possivel a alocacao do novo no
    if(!no)
    {
         return 0;
    }
    
    if(*p == NULL)
    {
         //se a pilha for vazia e for o primeiro no, o campo info recebe o elemento do primeiro no
         no->info = elem;
         //o ponteiro do tipo pilha aponta para o primeiro no, com isso tem acesso a todo o seu conteudo
         *p = no;
         //o prox do no aponta para NULL
         (*p)->prox = NULL;
         return 1;
    }
    else
    {
        //o novo no recebe o elemento para ser empilhado na pilha
        no->info = elem;
        //o ponteiro prox do novo no aponta para o ultimo no da pilha que passa a ser o penultimo no
        no->prox = *p;
        //o ponteiro do tipo pilha que aponta para o ultimo no, passa a apontar para o novo no que passa a ser agora o ultimo no da pilha
        *p = no;
        return 1;
    }
}

int desempilha(Pilha *p,int *elem)
{
    Pilha aux;
    //se nao houver nenhum elemento na pilha
    if(*p == NULL)
    {
        return 0;          
    }
    else
    {
        //aux recebe o no apontado por p
        aux = *p;
        if(aux->prox == NULL)
        {
            //elem recebe o unico elemento a ser desempilhado         
            *elem = aux->info;         
            //coloca o ponteiro do tipo pilha no estado de nulo          
            *p = NULL;          
            //remove o unico no que tiver na pilha          
            free(aux);
            return 1;          
        }
        else
        {
            //elem recebe o elemento do no removido
            *elem = aux->info;
            //o ponteiro do tipo pilha aponta para o penultimo no
            *p = aux->prox;
            //libera o no apontado pelo ponteiro do tipo pilha
            free(aux);
            return 1;
        }
    }
}

int le_topo(Pilha p,int *elem)
{
    if(p == NULL)
    {
         return 0;
    }
    else
    {
        //elem recebe o elemento do topo da pilha
        *elem = p->info;
        return 1;
    }
}

int valida_escopo(char vet[])
{
    int i = 0,elem;
    Pilha p2;
    //inicializa a pilha onde serao empilhados os delimitadores da expressao matematica
    inicializa_pilha(&p2);
    
    //enquanto nao for o final do vetor
    while(vet[i] != '\0')
    {
         if(vet[i] == '(')
         {
             //empilho a abertura do delimitador da expressao matematica       
             empilha(&p2,vet[i]);       
         }
         else
         {
             if(vet[i] == ')')
             {
                 //se tentar desempilhar a abertura de parenteses e nao existir nada para desempilhar entao quer dizer que a pilha e vazia      
                 if(desempilha(&p2,&elem) == 0)
                 {
                     return 0;                     
                 }       
             }
         }
         i++;   
    }
    //se o mesmo numero de fechamentos de parenteses for igual o mesmo numero de parentes abertos e desempilhados entao a expressao e valida pois todos os parentes abertos foram desempilhados e a pilha ficou vazia
    if(p2 == NULL)
    {
        return 1;  
    }
    //se o numero de aberturas de parentes for diferente do numero de fechamentos
    return 0;    
}
