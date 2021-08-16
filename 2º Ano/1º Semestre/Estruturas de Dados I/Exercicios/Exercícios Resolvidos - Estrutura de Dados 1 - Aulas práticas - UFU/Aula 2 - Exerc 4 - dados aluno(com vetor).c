#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct aluno
{
      char nome[10];
      int matricula;
      float nota;
};
typedef struct aluno Aluno;

void cadAlunos(int num);
void imprimeMatAluno(int matricula,Aluno alunos[],int num);

int main()
{
    int i, num;
    
    printf("Digite o numero de alunos que deseja cadastrar:");
    scanf("%d",&num);
    
    cadAlunos(num);   
                        
    getch();
    return 0;
}
void cadAlunos(int num)
{
    int i,matricula;            
    Aluno alunos[num];
    
    for(i = 0; i < num;i++)
    {
          printf("Digite o nome do aluno:");
          fflush(stdin);
          gets(alunos[i].nome);
          printf("\n");
                    
          printf("Digite a matricula:");
          fflush(stdin);
          scanf("%d",&alunos[i].matricula);
          printf("\n");
          
          
          printf("Digite a nota final:");
          fflush(stdin);
          scanf("%f",&alunos[i].nota);
          printf("\n");          
     }
     
     printf("Digite o numero de matricula desejado:");
     scanf("%d",&matricula);
     printf("\n");
     
     imprimeMatAluno(matricula,alunos,num);                    
}

void imprimeMatAluno(int matricula,Aluno alunos[],int num)
{
     int i;
     for(i = 0; i < num;i++)
     {
          if(matricula == alunos[i].matricula)
          {
             printf("O aluno(a) %s com matricula %d obteve nota %.1f. \n\n",alunos[i].nome,alunos[i].matricula,alunos[i].nota);
          }
          else
          {
             if(i == num-1)
             { 
                printf("Registro nao encontrado.\n");
             }
          } 
     }
}
