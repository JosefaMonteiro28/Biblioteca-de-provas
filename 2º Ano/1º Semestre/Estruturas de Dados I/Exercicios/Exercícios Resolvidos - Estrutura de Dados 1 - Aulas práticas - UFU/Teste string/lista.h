typedef struct lista  *Lista;
Lista cria_lista();
Lista libera_lista(Lista ptl);
int e_vazio(Lista *ptl);
int e_cheio(Lista *ptl);
int insere_ele(Lista *ptl,char a[]);
int remove_ele(Lista *ptl,char a[]);
int consulta_nodo(Lista ptl,int b, char *ele);
int tamanho_lista(Lista ptl);



