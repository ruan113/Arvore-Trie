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

#include "tst.h"

no* criar_no(char letra) {
    //Aloca memoria
    no *novoNo = (no*) malloc(sizeof (no));

    novoNo->letra = letra; //letra que marca o no
    novoNo->fim = 0; //marca se o no e fim ou nao de string
    novoNo->dir = NULL; //marca o filho a direita
    novoNo->esq = NULL; //marca o filho a esquerda
    novoNo->meio = NULL; //marca o filho do meio

    return novoNo; //retorna o no alocado
}

void inserir_palavra(arvore *a, no* n, no* anterior, char *palavra, int noAtual) {

    //verifica se o local esta vazio, isso significa que podemos inserir a palavra por completo nele
    if (n == NULL) {
        n = criar_no(palavra[noAtual]);

        //Verifica se a raiz e null, caso seja, seta o novo no como raiz
        if (a->raiz == NULL)
            a->raiz = n;

        if (anterior != NULL) {
            //Aponta o ponteiro do no anterior para o novo no
            if (anterior->letra == palavra[noAtual - 1])
                anterior->meio = n;
            else if (anterior->letra > n->letra)
                anterior->esq = n;
            else if (anterior->letra < n->letra)
                anterior->dir = n;
        }
        //printf("%c\n", n->letra);
        //Se a ultima insercao tiver sido da ultima letra, seta esta letra como final de string
        //e para a recursao
        //printf("%zd\n",strlen(palavra));
        if (strlen(palavra) >= noAtual + 1) {
            n->fim = 1;
            return;
        } else {
            inserir_palavra(a, n->meio, n, palavra, noAtual + 1);
        }
    } else {
        //Se a arvore nao esta vazia, iremos fazer comparacoes para achar o local para melhor alocar cada letra
        //Se a letra analizada e menor que a que quer ser inserida, vamos para a direita
        if (palavra[noAtual] > n->letra) {
            inserir_palavra(a, n->dir, n, palavra, noAtual);
        } else {
            //Se a letra analizada e maior que a que quer ser inserida, vamos para a esquerda
            if (palavra[noAtual] < n->letra) {
                inserir_palavra(a, n->esq, n, palavra, noAtual);
            } else {
                //Se a letra analizada e igual que a que quer ser inserida, vamos para o meio
                //e acrescentamos um no contador do vetor, para indicar que a letra ja exista entao nao precisa inserir
                inserir_palavra(a, n->meio, n, palavra, noAtual + 1);
            }
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
        printarPalavras(n->meio, aux, contador + 1);

        //E por fim verificamos toda a direita
        printarPalavras(n->dir, aux, contador);

        /*
         * Obs: foi feita a ordem de chamadas: primeiro buscando todos da esquerda, depois do meio e por fim a direita.
         * Esta ordem garante que as palavras serao impressas em ordem crescente!
         */
    }
}

no* buscaUltimoNo(no* n, char* palavra, int contador) {

    //Trata erro de envio de no nulo
    if (n == NULL) {
        printf("No enviado e nulo!\n");
        return;
    }

    //Trata erro de envio de palavra vazia
    if (strlen(palavra) == 0) {
        printf("Digite uma palavra primeiro !\n");
        return;
    }

    //se a proxima letra for o marcador do fim da string, retorne o no que esta sendo analizado
    if (palavra[contador + 1] == '\0')
        return n;

    //Caso a palavra nao esteja no fim ainda, ande pela arvore seguindo as seguintes regras:
    if (n->letra > palavra[contador])//Se a letra da arvore for maior que a analizada, vamos para a esquerda 
        return buscaUltimoNo(n->esq, palavra, contador);
    else if (n->letra < palavra[contador])//Se a letra da arvore for menor que a analizada, vamos para a direita
        return buscaUltimoNo(n->dir, palavra, contador);
    else //Se a letra da arvore for igual que a analizada, verificamos se nao e o fim, caso nao... seguimos pelo meio, senao achamos a palavra completa
        return buscaUltimoNo(n->meio, palavra, contador + 1);
}
