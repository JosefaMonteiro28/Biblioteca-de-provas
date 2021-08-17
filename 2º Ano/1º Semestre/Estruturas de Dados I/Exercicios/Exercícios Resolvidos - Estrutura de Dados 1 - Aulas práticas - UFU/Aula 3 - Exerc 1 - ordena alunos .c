#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno
{
    char nome[30];
    float media;
    int faltas;   
};

typedef struct aluno Aluno;

void ordenaAlunos(int num);
void imprimeAlunos(int num,Aluno *alunos);

int main()
{
    int num;
    printf("Digite o numero de alunos:");
    scanf("%d",&num);
    ordenaAlunos(num);
    getch();    
}

void ordenaAlunos(int num)
{
    int i,j,temp2;
    char temp[30];
    float temp3; 
    Aluno *alunos;
    
    alunos = (Aluno *)malloc(sizeof(Aluno)*num);
    
    if(!alunos)
    {
       printf("Memoria insuficiente.\n");
    }
    
    else
    {
        //insere os dados de cada aluno
        for(i = 0;i < num;i++)
        {
              printf("Digite o nome do aluno:");
              fflush(stdin);
              gets(alunos[i].nome);              
              
              printf("Digite a media do aluno:");
              fflush(stdin);
              scanf("%f",&alunos[i].media);
                            
              printf("Digite o numero de faltas:");
              fflush(stdin);
              scanf("%d",&alunos[i].faltas);              
        }
        //ordena os alunos segundo a media de cada um
        for(i = 0;i < num;i++)
        {
              for(j = 0;j < num;j++)
              {
                    //se o aluno anterior a sua ordenacao for depois do proximo aluno da lista de alunos, troca colocando na ordem alfabetica certa
                    if(alunos[i].media > alunos[j].media)
                    {
                         strcpy(temp,alunos[j].nome);              
                         temp2 = alunos[j].media;
                         temp3 = alunos[j].faltas;
                         
                         strcpy(alunos[j].nome,alunos[i].nome);
                         alunos[j].media = alunos[i].media;
                         alunos[j].faltas = alunos[i].faltas;
                         
                         strcpy(alunos[i].nome,temp);
                         alunos[i].media= temp2;
                         alunos[i].faltas= temp3;
                    }
              }
        }        
    }
    imprimeAlunos(num,alunos);
}

void imprimeAlunos(int num,Aluno *alunos)
{
     int i;
     for(i = 0;i < num;i++)
     {
           printf("O aluno %s com media %.1f obteve %d falta(s).\n",alunos[i].nome,alunos[i].media,alunos[i].faltas);
     }
     //libera a memoria alocada para alunos
     free(alunos);
}
