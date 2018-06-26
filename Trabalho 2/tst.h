/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tst.h
 * Author: ruan
 *
 * Created on 24 de Junho de 2018, 18:58
 */

#ifndef TST_H
#define TST_H

typedef struct NO{
    char letra;//Armazena a letra que o no vai representar
    struct NO *dir,*esq,*meio;//Caracteristica da arvore tst e ter 3 nos
    /*
     * Quando buscamos uma letra, se achamos ela o proximo no a ser explorado e o do meio,
     * quando a letra explorada nao e a desejada, buscamos por suas ramificacoes a esquerda ou direita.
     * se todos os nos a esquerda ou direta forem explorados sem completar a busca pela palavra,
     * significa que a mesma nao existe.
     * 
     * O no a esquerda tem que ser de uma letra menor que a letra do no analisado,
     * e o no a direta tem que ser maior.
     */
    int fim;
}no;

typedef struct TST_TREE{
    struct NO *raiz;//Armazena a raiz da arvore
}arvore;

no* criar_no(char letra);//Cria um no
void inserir_palavra(arvore *a, no* n, no* anterior, char* palavra, int noAtual);//Insere uma nova palavra na arvore
void printarPalavras(no* n, char* aux, int contador);//Printa todas as palavras da arvore
int buscarPalavra(no* n, char* palavra, int noAtual);//Busca palavra

#endif /* TST_H */

