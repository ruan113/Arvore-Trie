/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tst.c
 * Author: ruan
 *
 * Created on 24 de Junho de 2018, 18:57
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tst.h"

no* criar_no(char letra) {
    no *novoNo = (no*) malloc(sizeof (no));

    novoNo->letra = letra;
    novoNo->fim = 0;
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    novoNo->meio = NULL;

    return novoNo;
}

void inserir_palavra(no* n, no* anterior, char *palavra, int noAtual) {

    //verifica se o local esta vazio, isso significa que podemos inserir a palavra por completo nele
    if (n == NULL) {
        n = criar_no(palavra[noAtual]);

        if (anterior != NULL) {
            //Aponta o ponteiro do no anterior para o novo no
            if (anterior->letra > n->letra)
                anterior->esq = n;
            else if (anterior->letra < n->letra)
                anterior->dir = n;
            else if (anterior->letra == palavra[noAtual - 1])
                anterior->meio = n;
        }
        //printf("%c\n",n->letra);
        //Se a ultima insercao tiver sido da ultima letra, seta esta letra como final de string
        //e para a recursao
        if (strlen(palavra) == noAtual + 1)
            n->fim = 1;
        else
            inserir_palavra(n->meio, n, palavra, noAtual + 1);

        return;
    }

    //Se a arvore nao esta vazia, iremos fazer comparacoes para achar o local para melhor alocar cada letra
    //Se a letra analizada e menor que a que quer ser inserida, vamos para a direita
    if (palavra[noAtual] > n->letra) {
        inserir_palavra(n->dir, n, palavra, noAtual);
    } else {
        //Se a letra analizada e maior que a que quer ser inserida, vamos para a esquerda
        if (palavra[noAtual] < n->letra) {
            inserir_palavra(n->esq, n, palavra, noAtual);
        } else {
            //Se a letra analizada e igual que a que quer ser inserida, vamos para o meio
            //e acrescentamos um no contador do vetor, para indicar que a letra ja exista entao nao precisa inserir
            inserir_palavra(n->meio, n, palavra, noAtual + 1);
        }
    }
}

int buscarPalavra(no* n, char* palavra, int noAtual) {
    //Se o ponteiro chegar a algum ponto null, quer dizer que nao ha mais caminhos para vasculhar, 
    //portanto a palavra nao existe
    if (n == NULL)
        return 0;

    if (n->letra > palavra[noAtual])//Se a letra da arvore for maior que a analizada, vamos para a esquerda 
        return buscarPalavra(n->esq, palavra, noAtual);
    else if (n->letra < palavra[noAtual])//Se a letra da arvore for menor que a analizada, vamos para a direita
        return buscarPalavra(n->dir, palavra, noAtual);
    else if (n->fim != 1)//Se a letra da arvore for igual que a analizada, verificamos se nao e o fim, caso nao seguimos pelo meio, senao achamos a palavra completa
        return buscarPalavra(n->meio, palavra, noAtual + 1);
    else
        return 1;
}

void printarPalavras(no* n, char* aux, int contador) {
    //Verificamos se o no nao esta vazio
    if (n != NULL) {
        //Primeiro percorremos ate a arvore mais a esquerda
        printarPalavras(n->esq, aux, contador);

        //Setamos a letra que estamos analizando no buffer
        aux[contador] = n->letra;

        //Verificamos se nao estamos no fim de uma string
        //Caso estejamos, setamos o '\0' (indica final de uma string) para que o printf 
        //entenda ate onde ele deve imprimir a string e, assim, imprimos pela funcao printf
        if (n->fim == 1) {
            aux[contador + 1] = '\0';
            printf("%s\n", aux);
        }

        //verificamos todo o meio
        printarPalavras(n->meio, aux, contador);

        //E por fim verificamos toda a direita
        printarPalavras(n->dir, aux, contador);

        /*
         * Obs: foi feita a ordem de chamadas: primeiro buscando todos da esquerda, depois do meio e por fim a direita.
         * Esta ordem garante que as palavras serao impressas em ordem crescente!
         */
    }
}