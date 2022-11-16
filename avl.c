#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) (((a) > (b)) ? (a) : (b)) // Já esta na stdlib , mas em linux acho que não tem por isso defini novamente.
#include "avl.h"

struct no{
   data* data;
   int key;
   int altura;
   int fb;
   no* esquerda;
   no* direita;  
};
struct data{
   char Marca[1024],Modelo[1024];   
};

no* removerNo(no *raiz, int x){
   no* temp;
   if (raiz == NULL)
       return raiz;    
   if (x < raiz->key)
     raiz->esquerda = removerNo(raiz->esquerda, x);
   else if (x > raiz->key)
     raiz->direita = removerNo(raiz->direita, x);
   else{
     if(raiz->esquerda == NULL || raiz->direita == NULL){
        temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
        if(temp == NULL){
           temp = raiz;
           raiz = NULL;
        }else 
          *raiz = *temp;
        free(temp);
      }else{
        temp = minValueNode(raiz->direita);
        raiz->key = temp->key;
        raiz->direita = removerNo(raiz->direita,temp->key); 
      }
   }
   if(raiz == NULL)
      return raiz;  
  raiz->altura = 1 + max(alturaDoNo(raiz->esquerda),
                         alturaDoNo(raiz->direita));
  raiz->fb = fatorDeBalanceamento(raiz);
  if (raiz->fb > 1 && x < raiz->esquerda->key)
    return rotacaoDireita(raiz);
  if (raiz->fb < -1 && x > raiz->direita->key)
    return rotacaoEsquerda(raiz);
  if (raiz->fb > 1 && x > raiz->esquerda->key) {
    raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
    return rotacaoDireita(raiz);
  }
  if (raiz->fb < -1 && x < raiz->direita->key) {
    raiz->direita = rotacaoDireita(raiz->direita);
    return rotacaoEsquerda(raiz);
  }
  return raiz;  
}
/*
   Acha o nó mais a esquerda da arvore
   e o retorna;
*/
no* minValueNode(no* n) {
  no * current = n;

  while (current->esquerda != NULL)
    current = current->esquerda;
  return current;
}
/*

  funções para rotação simples
 
*/
no* rotacaoEsquerda(no* n){
  no* y = n->direita;
  no* y2 = y->esquerda;

  y->esquerda = n;  
  n->direita = y2;

  n->altura = max(alturaDoNo(n->esquerda), alturaDoNo(n->direita)) + 1;
  y->altura = max(alturaDoNo(y->esquerda), alturaDoNo(y->direita)) + 1;

  return y;
}
no* rotacaoDireita(no* n){
  no* x = n->esquerda;
  no* x2 = x->direita;

  x->direita = n;
  n->esquerda = x2;

  n->altura = max(alturaDoNo(n->esquerda), alturaDoNo(n->direita)) + 1;
  x->altura = max(alturaDoNo(x->esquerda), alturaDoNo(x->direita)) + 1;

  return x; 
}
/*
  Insere um novo nó
  em uma arvore com 
  ou sem cabeça

  Atualiza o fb
  e altura dos nodos;
*/
no* inserir(no* raiz, int x,char* Marca,char* Modelo){  
   if (raiz == NULL)
      return novoNo(x,Marca,Modelo);  
   if (x < raiz->key)
     raiz->esquerda = inserir(raiz->esquerda, x,Marca,Modelo);
   else if (x > raiz->key)
     raiz->direita = inserir(raiz->direita, x,Marca,Modelo);
   else
     return raiz; 
  raiz->altura = 1 + max(alturaDoNo(raiz->esquerda),
                         alturaDoNo(raiz->direita));
  raiz->fb = fatorDeBalanceamento(raiz);
  if (raiz->fb > 1 && x < raiz->esquerda->key)
    return rotacaoDireita(raiz);
  if (raiz->fb < -1 && x > raiz->direita->key)
    return rotacaoEsquerda(raiz);
  if (raiz->fb > 1 && x > raiz->esquerda->key) {
    raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
    return rotacaoDireita(raiz);
  }
  if (raiz->fb < -1 && x < raiz->direita->key) {
    raiz->direita = rotacaoDireita(raiz->direita);
    return rotacaoEsquerda(raiz);
  }
  return raiz;  
}
/* 
  Varre toda a arvore
  e retorna a quantidade
  de nós.
*/
int quantidadeNos(no* n){
    if(n == NULL)
       return -1;
    static int i = 0;
    if (n != NULL) {
      i++;
      quantidadeNos(n->esquerda);
      quantidadeNos(n->direita);
    }
    return i;
}
/*
  Imprime todos os nós da 
  arvore.

  tab = quanto espaço de
  diferença entre pai e filho
  dos nós.
*/
void imprime(no* n, int tab) {
    if(n == NULL)
       
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (n != NULL) {
        printf("%d | %s | %s\n",n->key,n->data->Marca,n->data->Modelo);
        imprime(n->esquerda, tab + 2);
        printf("\n");
        imprime(n->direita, tab + 2);
    }else
        printf("vazio");
}
/*
  Calcula e retorna o fator de balanceamento de um nó
*/
int fatorDeBalanceamento(no* n){
    if(n == NULL)
       return -1;
    else
       return alturaDoNo(n->esquerda) - alturaDoNo(n->direita);    
}
/*
  Retorna a altura de um nó ou -1 caso ele seja null
*/
int alturaDoNo(no* n){
     if(n == NULL)
        return -1;   
     else
        return n->altura;           
}
/*
  Função que cria um novo nó
  key -> chave de identificação do nó
  Retorna: o endereço do nó criado
*/
no* novoNo(int key,char* Marca,char* Modelo){
    no* novo = (no*)malloc(sizeof(no));
    data* nData = (data*)malloc(sizeof(data));    
    strncpy(nData->Marca,Marca,1024); strncpy(nData->Modelo,Modelo,1024);
    novo->data = nData;
    novo->key = key;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->altura = 0;
    novo->fb = 0;
    return novo;
}