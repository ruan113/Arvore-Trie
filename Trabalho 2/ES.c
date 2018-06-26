
#include "ES.h"

void criaArquivo() {
    FILE *arquivo; //ponteiro para indicar arquivo de entrada
    int i, y, tam, qtd = 30; //variaveis de controle
    char alfabeto[5]; //vetor para armazenar o alfabeto permitido

    alfabeto[0] = 'A'; //Inserindo as letras do alfabeto permitido no vetor
    alfabeto[1] = 'B'; //Inserindo as letras do alfabeto permitido no vetor
    alfabeto[2] = 'M'; //Inserindo as letras do alfabeto permitido no vetor
    alfabeto[3] = 'I'; //Inserindo as letras do alfabeto permitido no vetor
    alfabeto[4] = 'O'; //Inserindo as letras do alfabeto permitido no vetor

    srand(time(NULL)); //Define semente do rand

    arquivo = fopen("entrada.txt", "w"); //inicializa arquivo

    if (arquivo == NULL) { //Testa se foi possivel abrir o arquivo
        printf("Impossivel Criar Arquivo\n"); //Informa a impossibilidade de abrir o arquivo
        fclose(arquivo); //fecha o arquivo
        exit(1); //sai do programa

    } else {
        printf("Arquivo de Entrada Criado com Sucesso\n"); //informa que arquivo foi criado com sucesso
    }

    for (i = 0; i < qtd; i++) { //Loop para popular o arquivo com as palavras
        tam = rand() % 30 + 1; //Define randomicamente o tamanho que a palavra terá

        for (y = 0; y < tam; y++) { // Loop para gerar as palavras 
            //para gerar uma palavra é escrito letras do alfabeto aleatoriamente no arquivo até atingir o tamanho da palavra
            fprintf(arquivo, "%c", alfabeto[rand() % 5]);
           
        }

        fprintf(arquivo, "\n"); //Então se printa uma quebra de linha para marcar o fim da palavra
    }
    fclose(arquivo); //após as iterações dos loops fecha o arquivo
}

void lerArquivo(arvore *a) {
    FILE *entrada;
    char palavra[31];
    entrada = fopen("entrada.txt", "r"); //Abre arquivo no modo de leitura
    if (entrada == NULL) { //trata se arquivo não existir
        printf("Arquivo Vazio \n");
    }
    while (!feof(entrada)) {//le arquivo até o final
        fscanf(entrada, "%s\n", &palavra); //le palavra e armazena em variável auxiliar palavra
        printf("%zd\n",strlen(palavra));
        inserir_palavra(a, a->raiz, NULL, palavra, 0); //Insere uma nova palavra na arvore
    }
}

