//coloco o asterisco em fila pra nao ter acesso direto a estrutura para modifica-la
typedef struct fila *Fila;

typedef struct nodesc *noDesc;

int inicializa_noDesc(noDesc *no);

int fila_vazia(noDesc no);

int insere_elem_fila(noDesc *n, int elem);

int remove_elem_fila(noDesc *no, int *elem);

int imprime_elems(noDesc no);
