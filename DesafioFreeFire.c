#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Definição da struct Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

//Função para inserir um item na mochila
void inserirItem(Item mochila[], int *total) {
    if (*total >= 10) {
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }
    printf("Digite o nome do item: ");
    scanf("%s", mochila[*total].nome);
    printf("Digite o tipo do item (arma, municao, cura, etc): ");
    scanf("%s", mochila[*total].tipo);
    printf("Digite a quantidade: ");
    scanf("%d", &mochila[*total].quantidade);
    (*total)++;
    printf("Item cadastrado com sucesso!\n");
}

//Função para remover item da mochila
void removerItem(Item mochila[], int *total) {
    char nomeRemover[30];
    int encontrado = 0;
    printf("Digite o nome do item a ser removido: ");
    scanf("%s", nomeRemover);

    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            //Move os itens seguintes para "tapar o buraco"
            for (int j = i; j < *total - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*total)--;
            printf("Item removido com sucesso!\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Item não encontrado na mochila.\n");
    }
}

//Função para listar todos os itens da mochila
void listarItens(Item mochila[], int total) {
    printf("\n--- Itens na Mochila ---\n");
    if (total == 0) {
        printf("A mochila está vazia.\n");
    }
    for (int i = 0; i < total; i++) {
        printf("Item %d:\n", i + 1);
        printf("  Nome: %s\n", mochila[i].nome);
        printf("  Tipo: %s\n", mochila[i].tipo);
        printf("  Quantidade: %d\n", mochila[i].quantidade);
        printf("----------------------\n");
    }
}

//Função para buscar um item pelo nome
void buscarItem(Item mochila[], int total) {
    char nomeBusca[30];
    int encontrado = 0;
    printf("Digite o nome do item para buscar: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("Item encontrado!\n");
            printf("  Nome: %s\n", mochila[i].nome);
            printf("  Tipo: %s\n", mochila[i].tipo);
            printf("  Quantidade: %d\n", mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Item não encontrado na mochila.\n");
    }
}

int main() {
    Item mochila[10];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n=== Sistema de Inventário Free Fire ===\n");
        printf("1. Cadastrar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &totalItens);
                listarItens(mochila, totalItens);
                break;
            case 2:
                removerItem(mochila, &totalItens);
                listarItens(mochila, totalItens);
                break;
            case 3:
                listarItens(mochila, totalItens);
                break;
            case 4:
                buscarItem(mochila, totalItens);
                break;
            case 5:
                printf("Saindo do sistema. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
