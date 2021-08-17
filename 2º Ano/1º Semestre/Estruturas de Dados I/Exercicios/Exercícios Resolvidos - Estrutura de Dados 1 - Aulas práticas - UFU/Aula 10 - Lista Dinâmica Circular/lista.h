typedef struct no *Lista;

Lista cria_lista();

int verifica_vazia(Lista l);

int insere_fim(Lista *l,char elem);

int insere_inicio(Lista *l,char elem);

int consulta_no(Lista l,int pos,char *elem);

int remove_inicio(Lista *l);

int remove_fim(Lista *l);

Lista remove_lista(Lista l);

int imprime_lista(Lista l);

int tamanho_lista(Lista l);

void sair();
