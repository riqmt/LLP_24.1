#include <stdio.h>
#include <stdlib.h>

#define MAX_LINHA 256

int main() {
    FILE *arquivo;
    char linha[MAX_LINHA];

    // 1) Criar um arquivo para armazenar linhas de texto
    arquivo = fopen("texto.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    // 2) Alimentar o arquivo com dados digitados no teclado
    printf("Digite linhas de texto (digite 'sair' para encerrar):\n");
    while (1) {
        fgets(linha, sizeof(linha), stdin);
        
        // 3) Verificar se o usuário deseja sair
        if (strncmp(linha, "sair", 4) == 0) {
            break;
        }

        // 4) Gravar a string lida do teclado no arquivo
        fprintf(arquivo, "%s", linha);
    }

    // 5) Fechar o arquivo
    fclose(arquivo);

    // 6) Abrir o arquivo no modo de leitura
    arquivo = fopen("texto.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return EXIT_FAILURE;
    }

    // 7) Ler cada linha do arquivo e mostrar no vídeo
    printf("\nConteúdo do arquivo:\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    // 8) Fechar o arquivo
    fclose(arquivo);

    return EXIT_SUCCESS;
}
