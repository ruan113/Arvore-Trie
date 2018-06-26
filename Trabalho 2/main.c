
#include "tst.h"

/*
 * 
 */
int main(int argc, char** argv) {

    char str[31];
    arvore* a = (arvore*) malloc(sizeof (arvore));
    a->raiz = NULL;
    int opcao_menu = 0;

    criaArquivo();
   
    lerArquivo(a);

    do {
        printf("+          ARVORE TRIE            +\n\n");
        printf("O que voce deseja fazer?\n");
        printf("     (1) Inserir palavra na arvore\n");
        printf("     (2) Buscar palavra na arvore\n");
        printf("     (3) Imprimir toda a arvore TRIE\n");
        printf("     (4) Iniciar o Autocorretor\n");
        printf("     (5) Sair\n");

        scanf("%d", &opcao_menu);

        switch (opcao_menu) {
            case 1:
                printf("\n\nDigite a palavra a ser inserida:\n");
                scanf("%s", &str);
                inserir_palavra(a, a->raiz, NULL, str, 0);
                printf("\nPalavra inserida com sucesso!\n");
                break;
            case 2:
                printf("\n\nDigite a palavra a ser buscada:\n");
                scanf("%s", &str);\
                buscarPalavra(a->raiz, str, 0) == 1 ? printf("A palavra foi achada!\n\n") : printf("A palavra nao foi achada!\n");
                break;
            case 3:
                printarPalavras(a->raiz, &str, 0);
                break;
            case 4:
                printf("\n\nDigite uma palavra:\n");
                scanf("%s", &str);
                printf("Voce quis dizer:\n");
                printarPalavras(buscaUltimoNo(a->raiz, str, 0), str, strlen(str) - 1);
                break;
            case 5:
                printf("\n\nSaindo do programa...\n\n");
                return (EXIT_SUCCESS);
            default:
                printf("\n\nOpcao invalida!\n\n");
                break;
        }

        printf("-------------------------------------------------------\n");

    } while (getchar() != 5);

    return (EXIT_SUCCESS);
}

