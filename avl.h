typedef struct no no;

no* balancear(no *raiz);
no* rotacaoEsquerdaDireita(no *n);
no* rotacaoDireitaEsquerda(no *n);
no* rotacaoEsquerda(no *r);
no* rotacaoDireita(no *r);
no* inserir(no *raiz, int x);
int getfatorDeBalanceamento(no *n);
no* novoNo(int x);
int alturaDoNo(no* n);
void imprime(no* n, int tab);