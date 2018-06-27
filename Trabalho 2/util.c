/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   util.c
 * Author: ruan
 *
 * Created on 26 de Junho de 2018, 19:10
 */

#include <stdio.h>
#include <stdlib.h>

int validaPalavra(char* palavra) {
    char letras[] = "ABMIO";
    
    // Se a palavra e maior que 30 caracteres ele apresenta uma mensagem
    if (strlen(palavra) > 30) {
        printf("Valor maior que o requisitado...\n");
        return 0;
    }

    // Nesta parte ele verifica letra por letra da entrada com o banco
    // de caracteres possiveis de entrada ( A M B I O )
    for (int c_ent = 0; c_ent < strlen(palavra); c_ent++) {
        // Com o strchr verifica-se letra por letra
        // basicamente a funcao vai retornar NULL se a letra nao existir no banco
        if (strchr(letras, palavra[c_ent]) == NULL) {
            printf("Entrada nao contem um caracter valido...\n");
            return 0;
        }
    }
    
    return 1;
}

