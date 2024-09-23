#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUTOS 100

// Definição da estrutura para produtos
typedef struct {
    int codigo;
    char descricao[50];
    float valor_unitario;
    int qtd_estoque;
    float valor_estoque;
} Produto;

// Função para mostrar o menu
void mostrar_menu() {
    printf("Sistema de Estoque:\n");
    printf("1) Entrada de Produtos:\n");
    printf("2) Listar os Produtos:\n");
    printf("3) Valor Total do Estoque:\n");
    printf("4) Fim:\n");
    printf("Opção: ");
}

// Função para entrada de produtos
void entrada_produtos(Produto *produtos, int *contador) {
    if (*contador >= MAX_PRODUTOS) {
        printf("Limite de produtos alcançado.\n");
        return;
    }

    Produto p;
    printf("----------------------------------------------------------------------\n");
    printf("Entrada de Cadastro de Produtos\n");
    printf("----------------------------------------------------------------------\n");

    printf("Código: ");
    scanf("%d", &p.codigo);
    
    printf("Descrição: ");
    getchar(); // Limpa o buffer
    fgets(p.descricao, sizeof(p.descricao), stdin);
    
    printf("Valor Unitário: ");
    scanf("%f", &p.valor_unitario);
    
    printf("Qtd Estoque: ");
    scanf("%d", &p.qtd_estoque);
    
    // Calcula o valor do estoque
    p.valor_estoque = p.valor_unitario * p.qtd_estoque;
    printf("Valor Estoque: %.2f\n", p.valor_estoque);

    int opcao;
    printf("Digite (1-Para Gravar, 2-Voltar a tela inicial): ");
    scanf("%d", &opcao);
    
    if (opcao == 1) {
        produtos[*contador] = p;
        (*contador)++;
        printf("Produto gravado com sucesso!\n");
    } else {
        printf("Voltando à tela inicial.\n");
    }
}

// Função para listar os produtos
void listar_produtos(Produto *produtos, int contador) {
    printf("Lista de Produtos:\n");
    if (contador == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    for (int i = 0; i < contador; i++) {
        printf("Código: %d\n", produtos[i].codigo);
        printf("Descrição: %s", produtos[i].descricao);
        printf("Valor Unitário: %.2f\n", produtos[i].valor_unitario);
        printf("Qtd Estoque: %d\n", produtos[i].qtd_estoque);
        printf("Valor Estoque: %.2f\n", produtos[i].valor_estoque);
        printf("--------------------------\n");
    }
}

// Função para calcular o valor total do estoque
void valor_total_estoque(Produto *produtos, int contador) {
    float total = 0.0;
    for (int i = 0; i < contador; i++) {
        total += produtos[i].valor_estoque;
    }
    printf("Valor Total do Estoque: %.2f\n", total);
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
                entrada_produtos(produtos, &contador);
                break;
            case 2:
                listar_produtos(produtos, contador);
                break;
            case 3:
                valor_total_estoque(produtos, contador);
                break;
            case 4:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
