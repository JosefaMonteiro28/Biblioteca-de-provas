#include "numRacionais.h"

void menu();

int main()
{
    int num1,den1,num2,den2,num,den,op;
    Racional *numRac1,*numRac2,*resultado;
    
    numRac1 = criarRac();    
    numRac2 = criarRac();
    resultado = criarRac();
    
    printf("Digite o numerador do numero racional 1:");
    scanf("%d",&num1);
    
    printf("Digite o denominador do numero racional 1:");
    scanf("%d",&den1);
    
    printf("Digite o numerador do numero racional 2:");
    scanf("%d",&num2);
    
    printf("Digite o denominador do numero racional 2:");
    scanf("%d",&den2);
    
    printf("\n\n");
    
    atribuiRac(numRac1,num1,den1);
    atribuiRac(numRac2,num2,den2);  
        
    do
    {         
        menu();
        
        printf("Digite a opcao desejada:");
        scanf("%d",&op);
        
        switch(op)
        {
            case 1:                 
                    somaRac(numRac1,numRac2,resultado);
                    simplificaRac(resultado);
                    resultado = acessaRac(resultado,&num,&den);
                    printf("A soma dos numeros racionais e: %d / %d",num,den);
                    getch();
                    break;                 
            case 2:        
                    subtraiRac(numRac1,numRac2,resultado);
                    simplificaRac(resultado);
                    resultado = acessaRac(resultado,&num,&den);
                    printf("A subtracao dos numeros racionais e: %d/%d",num,den);
                    getch();
                    break;
            case 3:
                    multiplicaRac(numRac1,numRac2,resultado);                     
                    simplificaRac(resultado);
                    resultado = acessaRac(resultado,&num,&den);
                    printf("A multiplicacao dos numeros racionais e: %d/%d",num,den);
                    getch();
                    break;
            case 4:
                    divideRac(numRac1,numRac2,resultado);
                    simplificaRac(resultado);
                    resultado = acessaRac(resultado,&num,&den);
                    printf("A divisao dos numeros racionais e: %d/%d",num,den);
                    getch();
                    break;
            case 5:
                    getch();
                    exit(1);
            default: 
                    printf("A opcao digitada e incorreta.\b");
                    getch();                                   
        }            
        system("cls");  
    }     
    while(op != 5 || op != 5);
    return 0;
}

void menu()
{
     printf("1 - Soma.\n");
     printf("2 - Subtracao.\n");
     printf("3 - Multiplicacao.\n");
     printf("4 - Divisao.\n");
     printf("5 - Sair.\n");
     printf("\n\n");
}
