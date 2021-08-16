#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno
{
      char nome[30];
      int matricula;
      float nota;
};

typedef struct aluno Aluno;

int main(int argc, char *argv[])
{
    int comparaMat,i=0,j=0,encontrado = 0;    
    
    if(argc != 3)
    {
            printf("Dados incorretos.\n");
    }
    
    //pega a matricula da linha de comando
    comparaMat = atoi(argv[2]);
                   
    FILE *leAluno;
    
    Aluno *alunos;
    
    alunos = (Aluno *)malloc(sizeof(Aluno));
    
    if(!alunos)
    {
        printf("Memoria insuficiente");                
    }    
    else
    {
       leAluno = fopen(strcat(argv[1],".txt"),"r+");//r+ para leitura e gravacao
       
       //enquanto nao for a leitura ate o final do arquivo faca os comandos abaixo
       while(!feof(leAluno))
       {
          //pega o numero da matricula do arquivo e coloca dentro da estrutura alunos no campo matricula                  
          fscanf(leAluno,"%d",&alunos[i].matricula);
          
          //pega a virgula depois da matricula sem imprimir na tela
          getc(leAluno);
              
          //pega a primeira letra do nome do aluno
          fscanf(leAluno,"%c",&alunos[i].nome[j]);
          
          //pega cada caracter do nome do aluno e coloca na estrutura aluno no campo nome
          while(alunos[i].nome[j] != ',')
          {
              //indice para cada caracter do vetor nome da estrutura aluno                     
              j++;                     
              fscanf(leAluno,"%c",&alunos[i].nome[j]);                            
          }
          
          //finaliza o vetor do nome na estrutura aluno, para mostrar ate onde vai ser a leitura do nome
          alunos[i].nome[j] = '\0';
          
          //volta a salvar no inicio do vetor o nome do aluno
          j = 0;          
           
          //pega a nota do aluno do arquivo e coloca em nota da estrutura aluno    
          fscanf(leAluno,"%f",&alunos[i].nota);
          
          //pega o ponto final sem imprimir na tela
          getc(leAluno);
          
          //compara se a matricula digitada esta no arquivo e imprime os dados do aluno              
          if(alunos[i].matricula == comparaMat)
          {
               printf("O Aluno %s de matricula %d obteve nota: %.1f.\n",alunos[i].nome,alunos[i].matricula,alunos[i].nota);
               getch();
               return 1;                    
          }
          //incremento para guardar cada dado de um aluno diferente na estrutura
          i++;                    
       }       
       fclose(leAluno);
       
       //muda o valor de encontrado para 1 caso a matricula digitada nao exista no arquivo
       encontrado = 1;
       if(encontrado == 1)
       {
           printf("Registro nao encontrado.\n");
       }       
    }
    getch();
    return 0;
}
