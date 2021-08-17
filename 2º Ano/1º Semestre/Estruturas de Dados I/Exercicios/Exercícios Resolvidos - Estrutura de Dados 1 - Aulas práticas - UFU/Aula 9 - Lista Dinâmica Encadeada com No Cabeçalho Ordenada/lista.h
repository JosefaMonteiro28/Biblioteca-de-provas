typedef struct no *Lista;

int cria_lista(Lista *l);

int verifica_vazia(Lista l);

int insere_elems(Lista *l,float elem);

int consulta_no(Lista l,int pos,float *elem);

int remove_elem(Lista *l,float elem);

Lista remove_lista(Lista l);

int imprime_lista(Lista l);

int tamanho_lista(Lista l);

void sair();
