#include <stdio.h>
#include <string.h>

int main(){

    char letras[] = "ABMIO";
    char entrada[9999] = "1";
    while(1){
        scanf("%s", entrada);
        if(strcmp("$", entrada) == 0) break;
        int valido = 1;
        // Verifica as regras propostas:
        // Se a palavra e maior que 30 caracteres ele apresenta uma mensagem
        if (strlen(entrada) > 30){
            printf("Valor maior que o requisitado...\n");
            valido = 0;
        } else {
        // Nesta parte ele verifica letra por letra da entrada com o banco
        // de caracteres possiveis de entrada ( A M B I O )
            for(int c_ent=0; c_ent<tam; c_ent++){
                // Com o strchr verifica-se letra por letra
                // basicamente a funcao vai retornar NULL se a letra nao existir no banco
                if(strchr(letras, entrada[c_ent]) == NULL){
                    printf("Entrada nao contem um caracter valido...\n");
                    valido = 0;
                    break;
                }
            }
        }
        // Apresentacao da entrada caso tenha passado pelos testes
        if(valido != 0)
            printf("Valor de entrada valido!\nEntrada = %s\n", entrada);
    }
    return 0;
}
