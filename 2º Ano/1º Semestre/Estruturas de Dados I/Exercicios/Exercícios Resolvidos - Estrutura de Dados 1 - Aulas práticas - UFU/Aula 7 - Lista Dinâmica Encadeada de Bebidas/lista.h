typedef struct bebidas *Lista;

Lista cria_lista();

int verifica_vazia(Lista l);

int insere_elems(Lista *l,char elem[],int vol,float preco);

int consulta_no(Lista l,int pos,char nome[],int *vol,float *preco);

int remove_elem(Lista *l,char elem[]);

Lista remove_lista(Lista l);

int imprime_lista(Lista l);

int tamanho_lista(Lista l);

void sair();
