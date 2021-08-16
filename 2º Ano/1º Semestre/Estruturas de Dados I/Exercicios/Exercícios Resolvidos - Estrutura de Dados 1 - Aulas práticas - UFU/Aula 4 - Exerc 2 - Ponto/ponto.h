typedef struct ponto Ponto;

Ponto *criaPonto();

int atribuiPonto(Ponto *p,float x, float y);

float distanciaPontos(Ponto *p1,Ponto *p2);

void liberaPonto(Ponto *p);
