typedef struct no no;
typedef struct data data;

int quantidadeNos(no* n);
no* minValueNode(no* n);
no* removerNo(no *raiz, int x);
no* balancear(no *raiz);
no* rotacaoEsquerda(no *r);
no* rotacaoDireita(no *r);
no* inserir(no *raiz, int x,char* Marca,char* Modelo);
int fatorDeBalanceamento(no* n);
no* novoNo(int key,char* Marca,char* Modelo);
int alturaDoNo(no* n);
void imprime(no* n, int tab);