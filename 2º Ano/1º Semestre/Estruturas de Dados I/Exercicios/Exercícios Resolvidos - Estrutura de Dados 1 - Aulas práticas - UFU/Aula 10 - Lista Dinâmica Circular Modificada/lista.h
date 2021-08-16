typedef struct no *Lista;

Lista cria_lista();

int verifica_vazia(Lista l);

int insere_elems(Lista *l,char elem);

int consulta_no(Lista l,int pos,char *elem);

int remove_elem(Lista *l,char elem);

Lista remove_lista(Lista l);

int imprime_lista(Lista l);

int tamanho_lista(Lista l);

void sair();
