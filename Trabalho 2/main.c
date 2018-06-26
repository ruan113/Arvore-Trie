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
    
    inserir_palavra(a,a->raiz,NULL,"GATO",0);
    inserir_palavra(a,a->raiz,NULL,"JOSE",0);
    inserir_palavra(a,a->raiz,NULL,"PIRANHA",0);
    inserir_palavra(a,a->raiz,NULL,"PEIXE",0);
    
    char *buffer = (char*) malloc(sizeof(char)*30);
    printarPalavras(a->raiz, buffer,0);
    
    buscarPalavra(a->raiz,"GATO",0) == 1 ? printf("Achou\n") : printf("Nao Achou\n");
    buscarPalavra(a->raiz,"PELADO",0) == 1 ? printf("Achou\n") : printf("Nao Achou\n");
    buscarPalavra(a->raiz,"IAN",0) == 1 ? printf("Achou\n") : printf("Nao Achou\n");
    buscarPalavra(a->raiz,"JOSE",0) == 1 ? printf("Achou\n") : printf("Nao Achou\n");
    
    return (EXIT_SUCCESS);
}

