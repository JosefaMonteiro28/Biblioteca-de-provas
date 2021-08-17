typedef struct no *Lista;

Lista cria_lista();

int verifica_vazia(Lista l);

int insere_elems(Lista *l,int elem);

int insere_elems_pos(Lista *l,int pos,int elem);

int consulta_no(Lista l,int pos,int *elem);

int remove_elem(Lista *l,int elem);

Lista remove_lista(Lista l);

int imprime_lista(Lista l);

int tamanho_lista(Lista l);

void sair();
