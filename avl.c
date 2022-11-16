#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct no{
   int valor;
   no* esquerda;
   no* direita;  
   int altura;
   int fb;
};
/*
   Função auxiliar
*/
int calculaFB(no* n);
int calculaFB(no* n){
   if(n == NULL)
      return -1;
   return (alturaDoNo(n->esquerda) - alturaDoNo(n->direita));
}
no* balancear(no* raiz);
/*

Funções para as rotações duplas

*/
no* rotacaoEsquerdaDireita(no* n){
    
}
no* rotacaoDireitaEsquerda(no* n);
/*

  funções para rotação simples
 
*/
no* rotacaoEsquerda(no* n){
  no* y = n->direita,*y2 = y->esquerda;
  
  y->esquerda = n;
  n->direita = y2;

  n->altura = max(alturaDoNo(n->esquerda), alturaDoNo(n->direita)) + 1;
  y->altura = max(alturaDoNo(y->esquerda), alturaDoNo(y->direita)) + 1;

  return y;
}
no* rotacaoDireita(no* n){
  no* x = n->esquerda,*x2 = n->direita;
  
  x->direita = n;
  n->esquerda = x2;

  n->altura = max(alturaDoNo(n->esquerda),alturaDoNo(n->direita)) + 1;
  x->altura = max(alturaDoNo(x->esquerda),alturaDoNo(x->direita)) + 1;

  return x;
}
no* inserir(no* raiz, int x){
    if(x > raiz->valor){
       if(raiz == NULL){
          raiz->direita = novoNo(x);
          return raiz->direita;
       }
       inserir(raiz->direita,x);
    }else if(x < raiz->valor){
       if(raiz == NULL){
          raiz->esquerda = novoNo(x);
          return raiz->esquerda;
       }
       inserir(raiz->esquerda,x);
    }else{
        printf("\nNão é permitido valor igual!\n\n");
        return NULL; 
    }     
}
void imprime(no* n, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (n != NULL) {
        printf("%c\n", n->valor);
        imprime(n->esquerda, tab + 2);
        printf("\n");
        imprime(n->direita, tab + 2);
    }else
        printf("vazio");
}
/*

Calcula e retorna o fator de balanceamento de um nó

*/
int getfatorDeBalanceamento(no* n){
    if(n == NULL)
       return -1;
    else
       return calculaFB(n);      
}
/*

Retorna a altura de um nó ou -1 caso ele seja null

*/
int alturaDoNo(no* n){
     if(n == NULL)
        return -1;
     return n->altura;
}
/*

Função que cria um novo nó

x -> valor a ser inserido no nó

Retorna: o endereço do nó criado

*/
no* novoNo(int key){
    no* novo = (no*)malloc(sizeof(no));
    novo->valor = key;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->altura = 1; 
    return novo;
}