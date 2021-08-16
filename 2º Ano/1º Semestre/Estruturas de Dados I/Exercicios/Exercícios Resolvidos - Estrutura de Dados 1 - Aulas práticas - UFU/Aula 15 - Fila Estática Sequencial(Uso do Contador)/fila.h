typedef struct fila *Fila;

int inicializa_fila(Fila *f);

int fila_vazia(Fila f);

int fila_cheia(Fila f);

int insere_elem_fila(Fila *f, int elem);

int remove_elem_fila(Fila *f, int *elem);
