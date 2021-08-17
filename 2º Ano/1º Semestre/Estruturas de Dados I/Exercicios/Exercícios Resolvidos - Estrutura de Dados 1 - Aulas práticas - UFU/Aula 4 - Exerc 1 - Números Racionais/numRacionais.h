typedef struct numRacional Racional;

Racional *criarRac();

int atribuiRac(Racional *numRac,int num,int den);

Racional *liberaRac(Racional *numRac);

void simplificaRac(Racional *n);

Racional *acessaRac(Racional *numRac,int *num,int *den);

int somaRac(Racional *num1,Racional *num2,Racional *Resultado);

int subtraiRac(Racional *num1,Racional *num2,Racional *Resultado);

int multiplicaRac(Racional *num1,Racional *num2,Racional *Resultado);

int divideRac(Racional *num1,Racional *num2,Racional *Resultado);


