#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

int main(){
    char nome[200],line[100],*token,marcaBuff[100],modeloBuff[100]; 
    int O=0,v=0,i=0,read=0; no* n;

    FILE* ptr = fopen("carros.csv","r");
    while(fgets(line,100,ptr) != NULL){
       token = strtok(line,",");
       read = atoi(token);
       token = strtok(NULL,",");
       strncpy(marcaBuff,token,100);
       token = strtok(NULL,",");
       strncpy(modeloBuff,token,100);
       if(v == 0){
          v = 1;
          n = novoNo(read,marcaBuff,modeloBuff);
       }else{
          inserir(n,read,marcaBuff,modeloBuff);
       }     
    }
    fclose(ptr);
    while(O != 1){
      printf("\n\n"); 
      imprime(n,2);
      printf("\nDigite o nome do carro a procurar!\n\n");
      fgets(nome,200,stdin);
      
     


      printf("Deseja sair ou procurar outro carro? * - Procurar | 1 - Sair\n\n");
      scanf("%d",&O);
      fflush(stdin);
    }
    printf("Obrigado !\n");
    return EXIT_SUCCESS;
}