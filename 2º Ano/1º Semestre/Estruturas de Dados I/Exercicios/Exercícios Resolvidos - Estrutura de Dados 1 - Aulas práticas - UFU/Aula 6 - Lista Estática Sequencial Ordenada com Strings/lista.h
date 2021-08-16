typedef struct lista *Lista;

Lista cria_lista();

int verifica_vazia(Lista l);

int verifica_cheia(Lista l);

int consulta_no(Lista l,char elem[]);

int insere_elems(Lista *l,char elem[]);

int remove_elem(Lista *l,char elem[]);

int remove_lista(Lista *l);

int imprime_lista(Lista l);

void sair();
