/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ruan
 *
 * Created on 24 de Junho de 2018, 18:17
 */

#include <stdio.h>
#include <stdlib.h>

#include "tst.h"

/*
 * 
 */
int main(int argc, char** argv) {

    arvore* a = (arvore*) malloc(sizeof(arvore));
    a->raiz = NULL;
    
    inserir_palavra(a->raiz,NULL,"GATO",0);
    //inserir_palavra(a->raiz,NULL,"JOSE",0);
    //inserir_palavra(a->raiz,NULL,"PIRANHA",0);
    //inserir_palavra(a->raiz,NULL,"PEIXE",0);
    
    printf("%c\n",a->raiz->letra);/*
    printarPalavras(a, malloc(sizeof(char)*30),0);
    
    buscarPalavra(a,"GATINHO",0) == 1 ? printf("Achou\n") : printf("Nao Achou\n");
    buscarPalavra(a,"PELADO",0) == 1 ? printf("Achou\n") : printf("Nao Achou\n");
    buscarPalavra(a,"IAN",0) == 1 ? printf("Achou\n") : printf("Nao Achou\n");
    buscarPalavra(a,"JOSE",0) == 1 ? printf("Achou\n") : printf("Nao Achou\n");
    */
    return (EXIT_SUCCESS);
}

