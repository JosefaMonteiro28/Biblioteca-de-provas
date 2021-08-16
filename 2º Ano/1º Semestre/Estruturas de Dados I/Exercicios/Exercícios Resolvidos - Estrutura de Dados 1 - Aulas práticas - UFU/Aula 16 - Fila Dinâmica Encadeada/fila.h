typedef struct fila *Fila;

Fila inicializa_fila(Fila *f);

int fila_vazia(Fila f);

int insere_elem_fila(Fila *f, int elem);

int remove_elem_fila(Fila *f, int *elem);
