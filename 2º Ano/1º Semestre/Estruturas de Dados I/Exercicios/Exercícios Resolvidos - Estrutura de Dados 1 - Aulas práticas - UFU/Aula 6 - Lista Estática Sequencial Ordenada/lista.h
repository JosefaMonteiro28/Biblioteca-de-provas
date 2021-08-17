typedef struct lista *Lista;

Lista cria_lista();

int verifica_vazia(Lista lista);

int verifica_cheia(Lista lista);

int consulta_no(Lista lista,int elem);

int insere_elems(Lista *lista,int elem);

int remove_elem(Lista *lista,int elem);

int remove_lista(Lista *lista);

int imprime_lista(Lista lista);

void sair();
