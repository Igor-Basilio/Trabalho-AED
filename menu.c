#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "avl.h"
#define TRUE 0 

int main(void){
    setlocale(LC_ALL, "Portuguese");
    int O,v,temp; char nome[30];  
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
        printf("Digite 8 - Para sair.\n");
        scanf("%d",&O);
        fflush(stdin);
        switch(O){       
            case 0:

                break;
            case 1:    

                break;
            case 2:    

                break;
            case 3:    

                break;
            case 4:    

                break;
            case 5:      

                break;
            case 6:    

                break;
            case 7:    
 
                break; 
            case 8:
                 
                return EXIT_SUCCESS;
                break;             
        } 
        fflush(stdin);
    }while(TRUE == 0); 
}