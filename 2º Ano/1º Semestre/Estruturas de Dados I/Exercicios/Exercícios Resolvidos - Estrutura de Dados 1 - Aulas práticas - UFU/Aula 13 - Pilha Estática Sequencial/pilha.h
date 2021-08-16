//coloco o asterisco pra nao ter acesso direto a estrutura e sim somente ao seu endereco para o usuario nao poder modificar a estrutura
typedef struct pilha *Pilha;

int inicializa_pilha(Pilha *p);

int pilha_vazia(Pilha p);

int pilha_cheia(Pilha p);

int empilha(Pilha *p, int elem);

int desempilha(Pilha *p, int *elem);

int le_topo(Pilha p,int *elem);

int conv_dec_bin(Pilha p,int elem);

