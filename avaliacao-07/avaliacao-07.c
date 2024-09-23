#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

// Definição da estrutura para produtos
typedef struct {
    int codigo;
    char descricao[50];
    float valor_unitario;
    int qtd_estoque;
} Produto;

// Função para mostrar o menu
void mostrar_menu() {
    printf("Sistema de Produtos:\n");
    printf("1) Cadastrar Produto\n");
    printf("2) Consultar Produto para Alteração\n");
    printf("3) Listar todos os produtos\n");
    printf("4) Exclusão do Produto\n");
    printf("5) Fim\n");
    printf("Opção: ");
}

// Função para cadastrar um produto
void cadastrar_produto(Produto *produtos, int *contador) {
    if (*contador >= MAX_PRODUTOS) {
        printf("Limite de produtos alcançado.\n");
        return;
    }

    Produto p;
    printf("Código: ");
    scanf("%d", &p.codigo);
    
    printf("Descrição: ");
    getchar(); // Limpa o buffer
    fgets(p.descricao, sizeof(p.descricao), stdin);
    p.descricao[strcspn(p.descricao, "\n")] = 0; // Remove a nova linha

    printf("Valor Unitário: ");
    scanf("%f", &p.valor_unitario);
    
    printf("Quantidade em Estoque: ");
    scanf("%d", &p.qtd_estoque);

    produtos[*contador] = p;
    (*contador)++;
    printf("Produto cadastrado com sucesso!\n");
}

// Função para consultar um produto para alteração
void consultar_produto(Produto *produtos, int contador) {
    int codigo;
    printf("Digite o código do produto para alteração: ");
    scanf("%d", &codigo);
    
    for (int i = 0; i < contador; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Código: %d\n", produtos[i].codigo);
            printf("Descrição: %s\n", produtos[i].descricao);
            printf("Valor Unitário: %.2f\n", produtos[i].valor_unitario);
            printf("Quantidade em Estoque: %d\n", produtos[i].qtd_estoque);

            printf("Digite a nova descrição: ");
            getchar(); // Limpa o buffer
            fgets(produtos[i].descricao, sizeof(produtos[i].descricao), stdin);
            produtos[i].descricao[strcspn(produtos[i].descricao, "\n")] = 0; // Remove a nova linha
            
            printf("Digite o novo valor unitário: ");
            scanf("%f", &produtos[i].valor_unitario);
            
            printf("Digite a nova quantidade em estoque: ");
            scanf("%d", &produtos[i].qtd_estoque);
            
            printf("Produto alterado com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

// Função para listar todos os produtos
void listar_produtos(Produto *produtos, int contador) {
    if (contador == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Lista de Produtos:\n");
    for (int i = 0; i < contador; i++) {
        float valor_estoque = produtos[i].valor_unitario * produtos[i].qtd_estoque;
        printf("Código: %d\n", produtos[i].codigo);
        printf("Descrição: %s\n", produtos[i].descricao);
        printf("Valor Unitário: %.2f\n", produtos[i].valor_unitario);
        printf("Quantidade em Estoque: %d\n", produtos[i].qtd_estoque);
        printf("Valor do Estoque: %.2f\n", valor_estoque);
        printf("--------------------------\n");
    }
}

// Função para excluir um produto
void excluir_produto(Produto *produtos, int *contador) {
    int codigo;
    printf("Digite o código do produto para exclusão: ");
    scanf("%d", &codigo);
    
    for (int i = 0; i < *contador; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Código: %d\n", produtos[i].codigo);
            printf("Descrição: %s\n", produtos[i].descricao);
            printf("Valor Unitário: %.2f\n", produtos[i].valor_unitario);
            printf("Quantidade em Estoque: %d\n", produtos[i].qtd_estoque);

            char confirmacao;
            printf("Deseja realmente excluir o produto? (s/n): ");
            getchar(); // Limpa o buffer
            scanf("%c", &confirmacao);
            
            if (confirmacao == 's' || confirmacao == 'S') {
                // Move todos os produtos para a esquerda
                for (int j = i; j < *contador - 1; j++) {
                    produtos[j] = produtos[j + 1];
                }
                (*contador)--;
                printf("Produto excluído com sucesso!\n");
            } else {
                printf("Exclusão cancelada.\n");
            }
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int contador = 0;
    int opcao;

    do {
        mostrar_menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_produto(produtos, &contador);
                break;
            case 2:
                consultar_produto(produtos, contador);
                break;
            case 3:
                listar_produtos(produtos, contador);
                break;
            case 4:
                excluir_produto(produtos, &contador);
                break;
            case 5:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
