#include <stdio.h>
#include <string.h>

//1 - CADASTRAR (IMPLEMENTADA)
void cadastrar(int codigo[], char nome [][15], int *total) {
    //Verificar se o cadastro esta cheio
    if (*total == 5){
        printf("\nCadastro cheio!\n");
        return;
    }
    //Ler o codigo
    printf("\nDigite o codigo: ");
    scanf("%d", &codigo[*total]);
    getchar();
    //Ler o nome
    printf("Digite o nome: ");
    fgets(nome[*total], 15, stdin);
     //(OPCIONAL) remover o \n que o fgets guarda no final do nome
      nome[*total][strcspn(nome[*total], "\n")] = '\0';
    // Atualizar o total de registros
    (*total)++;
    printf("\nCadastro realizado com sucesso!\n");
}

// 2 - CONSULTAR
void consultar(int codigo[], char nome[][15], int total) {
    int busca;
    int i;
    int encontrado = 0;

    // Solicitar o codigo para consulta
    printf("\nDigite o codigo para consulta: ");
    scanf("%d", &busca);

    // Percorrer o vetor procurando o codigo
    for (i = 0; i < total; i++) {
        if (codigo[i] == busca) {
            // Mostrar o codigo e o nome, se encontrado
            printf("\nCodigo: %d", codigo[i]);
            printf("\nNome: %s\n", nome[i]);
            encontrado = 1;
            break;
        }
    }

    // Informar se nao foi encontrado
    if (encontrado == 0) {
        printf("\nRegistro nao encontrado!\n");
    }
}

// 3 - LISTAR
void listar(int codigo[], char nome[][15], int total) {
    int i;

    if (total == 0) {
        printf("\nNenhum registro cadastrado.\n");
        return;
    }

    // Percorrer os registros cadastrados
    for (i = 0; i < total; i++) {
        // Mostrar o codigo e o nome de cada registro
        printf("\nCodigo: %d", codigo[i]);
        printf("\nNome: %s\n", nome[i]);
    }
}

// 4 - ALTERAR
void alterar(int codigo[], char nome[][15], int total) {
    int busca;
    int i;
    int encontrado = 0;

    // Solicitar o codigo que sera alterado
    printf("\nDigite o codigo que sera alterado: ");
    scanf("%d", &busca);

    // Procurar o codigo no vetor
    for (i = 0; i < total; i++) {
        if (codigo[i] == busca) {
            // Ler o novo codigo e o novo nome
            printf("Digite o novo codigo: ");
            scanf("%d", &codigo[i]);
            getchar();
            printf("Digite o novo nome: ");
            fgets(nome[i], 15, stdin);
            nome[i][strcspn(nome[i], "\n")] = '\0';

            printf("\nRegistro alterado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    // Informar se nao foi encontrado
    if (encontrado == 0) {
        printf("\nRegistro nao encontrado!\n");
    }
}

// 5 - EXCLUIR
void excluir(int codigo[], char nome[][15], int *total) {
    int busca;
    int i, j;
    int posicao = -1;

    // Solicitar o codigo que sera excluido
    printf("\nDigite o codigo que sera excluido: ");
    scanf("%d", &busca);

    // Procurar o registro no vetor
    for (i = 0; i < *total; i++) {
        if (codigo[i] == busca) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("\nNao foi possivel excluir: registro nao encontrado!\n");
        return;
    }

    // Deslocar os registros seguintes uma posicao para a esquerda
    for (j = posicao; j < *total - 1; j++) {
        codigo[j] = codigo[j + 1];
        strcpy(nome[j], nome[j + 1]);
    }

    // Diminuir o total de registros
    (*total)--;
    printf("\nRegistro excluido com sucesso!\n");
}

// PROGRAMA PRINCIPAL (sem alteracoes)
int main(void) {
    int codigo[5];
    char nome[5][15];
    int total = 0;
    int opcao;
    do{
        printf("\n\n== MENU ==");
        printf("\n1 - Cadastrar");
        printf("\n2 - Consultar");
        printf("\n3 - Listar");
        printf("\n4 - Alterar");
        printf("\n5 - Excluir");
        printf("\n0 - Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrar(codigo, nome, &total);
                break;
            case 2:
                consultar(codigo, nome, total);
                break;
            case 3:
                listar(codigo, nome, total);
                break;
            case 4:
                alterar(codigo, nome, total);
                break;
            case 5:
                excluir(codigo, nome, &total);
                break;
            case 0:
                printf("\nEncerrando...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
    return 0;
}