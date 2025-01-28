#include <stdio.h>
#include <locale.h>
#define MAX_PRODUTOS 100

typedef struct {
    int codigo;
    char nome[50];
    float quantidade;
} Produto;

Produto estoque[MAX_PRODUTOS];
int total_produtos = 0;

void adicionar_produto() {
    if (total_produtos >= MAX_PRODUTOS) {
        printf("Estoque cheio! Não é possível adicionar mais produtos.\n");
        return;
    }

    Produto novo_produto;
    printf("Digite o código do produto: ");
    scanf("%d", &novo_produto.codigo);
    printf("Digite o nome do produto: ");
    scanf("%s", novo_produto.nome);
    printf("Digite a quantidade do produto em KG: ");
    scanf("%f", &novo_produto.quantidade);

    estoque[total_produtos] = novo_produto;
    total_produtos++;
    printf("Produto adicionado com sucesso!\n");
}

void remover_produto() {
    int codigo, i, encontrado = 0;
    printf("Digite o código do produto a ser removido: ");
    scanf("%d", &codigo);

    for (i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        for (int j = i; j < total_produtos - 1; j++) {
            estoque[j] = estoque[j + 1];
        }
        total_produtos--;
        printf("Produto removido com sucesso!\n");
    } else {
        printf("Produto não encontrado.\n");
    }
}

void lista_de_produtos() {
    if (total_produtos == 0) {
        printf("Estoque vazio.\n");
        return;
    }

    printf("\nLista de Produtos no Estoque:\n");
    for (int i = 0; i < total_produtos; i++) {
        printf("Código: %d | Nome: %s | Quantidade: %.2f KG\n", estoque[i].codigo, estoque[i].nome, estoque[i].quantidade);
    }
}

//Menu de Operações
int main() {
    int opcao;
    setlocale (LC_ALL,"portuguese");

    do {
        printf("\nMenu de Operações:\n");
        printf("1 - Adicionar Produto\n");
        printf("2 - Remover Produto\n");
        printf("3 - Lista de Produtos\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_produto();
                break;
            case 2:
                remover_produto();
                break;
            case 3:
                lista_de_produtos();
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
