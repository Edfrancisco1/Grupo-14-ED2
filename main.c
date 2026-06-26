#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Node* root = NULL;
    int option, num;
    Data data;

    do {
        printf("\n========== AGENDA TELEFONICA (ABB) ==========\n");
        printf("1. Inserir contato\n");
        printf("2. Buscar contato\n");
        printf("3. Remover contato\n");
        printf("4. Listar contatos (In-Order)\n");
        printf("5. Listar contatos (Pre-Order)\n");
        printf("6. Listar contatos (Pos-Order)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        clearBuffer();

        switch (option) {
            case 1:
                /* num gerado automaticamente */
                data.num = getNextNum();

                printf("Nome: ");
                fgets(data.name, sizeof(data.name), stdin);
                data.name[strcspn(data.name, "\n")] = '\0';

                printf("Telefone: ");
                fgets(data.phone, sizeof(data.phone), stdin);
                data.phone[strcspn(data.phone, "\n")] = '\0';

                root = insert(root, data);
                printf("Contato inserido com sucesso (num: %d).\n", data.num);
                break;

            case 2:
                printf("Digite o codigo (num) para buscar: ");
                scanf("%d", &num);
                clearBuffer();

                Node* found = search(root, num);
                if (found)
                    printf("Encontrado -> num: %d | nome: %s | telefone: %s\n",
                           found->data.num, found->data.name, found->data.phone);
                else
                    printf("Contato nao encontrado.\n");
                break;

            case 3:
                printf("Digite o codigo (num) para remover: ");
                scanf("%d", &num);
                clearBuffer();

                root = removeNode(root, num);
                printf("Contato removido (se existia).\n");
                break;

            case 4:
                printf("\n--- Listagem In-Order ---\n");
                inOrder(root);
                break;

            case 5:
                printf("\n--- Listagem Pre-Order ---\n");
                preOrder(root);
                break;

            case 6:
                printf("\n--- Listagem Pos-Order ---\n");
                posOrder(root);
                break;

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (option != 0);

    freeTree(root);
    return 0;
}