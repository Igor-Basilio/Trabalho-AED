#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "avl.h"
#define TRUE 0 

int main(void){
    setlocale(LC_ALL,"");  // Usa padrão do OS.
    int O,v,temp; char nome[1024],nome_[1024]; no* n = NULL,*m = NULL;
    do{    
        fflush(stdin);
        printf("Digite 0 - Incluir Elemento na Árvore AVL\n");
        printf("Digite 1 - Buscar e Imprimir (Todos os campos de um elemento)\n");
        printf("Digite 2 - Editar o valor de um elemento (Buscar por uma chave e permitir alterar o valor correspondente)\n");
        printf("Digite 3 - Excluir Elemento da Árvore AVL\n");
        printf("Digite 4 - Imprimir todos elementos (De forma ordenada)\n");
        printf("Digite 5 - Imprimir quantidade de elementos\n");
        printf("Digite 6 - Informar altura da árvore\n");
        printf("Digite 7 - Imprimir com estrutura de arvore (apresentando a forma que as chaves estão armazenadas).\n");
        printf("Digite 8 - Para sair.\n\n");
        scanf("%d",&O);
        fflush(stdin);
        switch(O){       
            case 0:                
                printf("Digite a chave , a marca e o modelo!\n");
                scanf("%d",&temp);            
                fflush(stdin);
                fgets(nome,1024,stdin);
                fflush(stdin);
                fgets(nome_,1024,stdin);
                if(v = 0){
                   n = novoNo(temp,nome,nome_);
                }else{
                   inserir(n,temp,nome,nome_);
                }           
                v = 1;   
                break;
            case 1:    
                printf("Digite a chave do elemento!\n");
                scanf("%d",&temp);
                fflush(stdin);
                m = buscaNo_Chave(n,temp);
                printf("\nInformações do elemento!\n");
                imprime(m,2);
                break;
            case 2:    
                printf("Digite a chave do elemento!\n");
                scanf("%d",&temp);
                fflush(stdin);
                m = buscaNo_Chave(n,temp);
                int chave = getChave(m);               
                printf("Digite os novos valores do elemento! Marca - Modelo , Respectivamente\n");
                fgets(nome,1024,stdin);
                fflush(stdin);
                fgets(nome_,1024,stdin);
                removerNo(n,chave);
                if(v == 0)
                   n = novoNo(chave,nome,nome_);
                else
                   inserir(n,chave,nome,nome_);
                v = 1;   
                break;
            case 3:    
                printf("Digite a chave do elemento!\n");
                scanf("%d",&temp);
                fflush(stdin);
                removerNo(n,temp);
                printf("\n Elemento Removido! \n");
                break;
            case 4:    
                printf("\n Árvore AVL : \n");
                imprime(n,2);
                break;
            case 5:      
                printf("A Quantidade de elementos é :\n");
                temp = quantidadeNos(n);
                printf("%d\n\n",temp);
                break;
            case 6:    
                printf("Altura da arvore :\n");
                printf("| %d |\n\n",alturaDoNo(n));
                break;
            case 7:    
                imprime(n,2);
                printf("\n\n");
                break; 
            case 8:
                finalizaArvore(n); finalizaArvore(m);
                printf("Obrigado!\n"); 
                return EXIT_SUCCESS;
                break;             
        } 
        fflush(stdin);
    }while(TRUE == 0); 
}