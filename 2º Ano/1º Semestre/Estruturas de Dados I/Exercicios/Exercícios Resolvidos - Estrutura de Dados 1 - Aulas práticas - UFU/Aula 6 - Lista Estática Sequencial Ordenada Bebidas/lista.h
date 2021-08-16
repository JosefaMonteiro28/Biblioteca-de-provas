typedef struct bebidas *Bebidas;

Bebidas cria_lista();

int verifica_vazia(Bebidas beb);

int verifica_cheia(Bebidas beb);

int consulta_no(Bebidas beb,char nome[]);

int inserirNovoReg(Bebidas *beb,char nome[],int volume,float preco);

int remove_beb(Bebidas *beb,char nome[]);

int remove_lista(Bebidas *beb);

int imprimir_bebidas(Bebidas beb);

void sair();
