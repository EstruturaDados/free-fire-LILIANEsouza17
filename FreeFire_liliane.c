#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10
//ESTRUTURA DO ITEM

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;
//ESTRUTURA LISTA ENCADEADA

typedef struct No {
    Item item;
    struct No *proximo;
} No;

//FUNÇÕES LISTA ESTÁTICA

void inicializarEstatica(Item mochila[], int *contador);
void inserirEstatica(Item mochila[], int *contador); 
void removerEstatica(Item mochila[], int *contador);
void listarEstatica(Item mochila[], int *contador);
void buscarEstatica(Item mochila[], int *contador);

//FUNÇÕES LISTA ENCADEADA
 No* inicializarEncadeada();
 No* inserirEncadeada(No *inicio);
 void listarEncadeada(No *inicio);
 void liberarEncadeada(No *inicio);

 // FUNÇÃO PRINCIPAL

 int main() {
    Item mochila [MAX_ITENS];
    int contador = 0; // INICIA O CONTADOR COM ZERO
    No *inicio = inicializarEncadeada();  //LISTA ENCADEADA VAZIA
    int opcao;

    inicializarEstatica(mochila, &contador);

    do {

printf("\n===========================================================================================\n");
       
         printf("                            MOCHILA DE SOBREVIVÊNCIA                                 \n");
         printf("                            CÓDIGO DA ILHA                                            \n");

printf("================================================================================================\n");

         printf(" [1] Inserir item (lista estatica)\n");
         printf(" [2] Remover item (lista estatica)\n");
         printf(" [3] Listar itens (lista estatica)\n");
         printf(" [4] Buscar item (lista estatica)\n");
         printf(" [5] Inserir item (lista encadeada)\n");
         printf(" [6] Listar itens (lista encadeada)\n");
         printf(" [0] Sair do sistema\n");

printf("===================================================================================================\n");
         printf(" Escolha uma opcao: ");
         scanf("%d", &opcao);
         getchar(); 

         switch (opcao) {
            case 1: inserirEstatica(mochila, &contador);
            break;
            case 2: removerEstatica(mochila, &contador);
            break;
            case 3: listarEstatica(mochila, &contador);
            break;
            case 4: buscarEstatica(mochila, contador);
            break;
            case 5: inicio = inserirEncadeada(inicio);
            break;
            case 6: listarEncadeada(inicio);
            break;
            case 0: printf("\n Saindo da ilha... Boa Sorte, sobrevivente!\n");
            break;
            default: printf("Opção Inválida!\n");
         }

        } while (opcao != 0);
        liberarEncadeada(inicio);
        return 0;
 }

 //LISTA ESTÁTICA

 void inicializarEstatica(Item mochila[], int *contador) {
    if (*contador >= MAX_ITENS) {
        printf("A MOCHILA ESTÁ CHEIA!\n");
        return;
    }
    printf("DIGITE O NOME DO ITEM: ");
    fgets(mochila[*contador]. nome, 30, stdin);
    mochila[*contador]. nome[strcpn(mochila[*contador]. nome, "\n")] = 0;

    printf("DIGITE O TIPO DO ITEM: ");
    fgets(mochila[*contador]. tipo, 20, stdin);
    mochila[*contador]. tipo[strcspn(mochila[*contador]. tipo, "\n")] = 0;

    printf("DIGITE A QUANTIDADE: ");
    scanf("%d", &mochila[*contador]. quantidade);
    getchar ();


    (*contador)++;
    printf("ITEM INSERIDO COM SUCESSO!\n");
    listarEstatica(mochila, *contador);
}
void removerEstatica(Item mochila[], int *contador) {

   if (*contador == 0) {
     
         printf("A MOCHILA ESTÁ VAZIA!\n");
         return;
     }
     char nome[30];
     printf("DIGITE O NOME O ITEM A REMOVER: ");
     fgets(nome, 30, stdin);
     nome[strcspn(nome, "\n")] = 0;

     int encontrado = 0;
     for (int i = 0; i < *contador; i++)
     {
         if (strcmp(mochila[i].nome, nome) == 0)
         {
             for (int j = i; j < *contador - 1; j++)
             {
                 mochila[j] = mochila[j + 1];
             }
             (*contador)--;
             encontrado = 1;
             printf("ITEM REMOVIDO COM SUCESSO!\n");
             break;
         }
     }
     if (!encontrado)
         printf("ITEM NÃO ENCONTRADO!\n");
     listarEstatica(mochila, *contador);
 }


 void listarEstatica(Item mochila[], int contador) {
    if (contador == 0) {
        printf("A MOCHILA ESTÁ VAZIA!\n");
        return;
    }

    printf("\n---ITENS NA MOCHILA(estatica)---\n");
    for (int i = 0; i < contador; i++) {
        printf("NOME: %s | TIPO: %s | QUANTIDADE: %d\n", mochila[i]. nome, mochila[i]. tipo, mochila[i].quantidade);
    }

 }

 void buscarEstatica(Item mochila[], int contador) {
      if (contador == 0) {
        printf("A MOCHILA ESTÁ VAZIA!\n");
        return;
      }
      char nome[30];
      printf("DIGITE O NOME DO ITEM A BUSCAR: ");
      fgets(nome, 30, stdin);
      nome[strcspn(nome, "\n")] = 0;
      int encontrado = 0;
      for (int i = 0; i < contador; i++) {
        if (strcmp(mochila[i]. nome, nome) == 0) {

            printf("ITEM ENCONTRADO: NOME: %s | TIPO: %s | QUANTIDADE: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            encontrado = 1; 
            break;
        }
      }
      if (!encontrado)
      printf("ITEM NÃO ENCONTRADO!\n");
    }

    //LISTA ENCADEADA

    void buscarEstatica(Item mochila[], int *contador)
    {
    }

    No inicializarEncadeada()
    {
        return NULL; // lista começa vazia
    }
    No* inserirEncadeada(No *inicio) {
        No *novo = (No*) malloc(sizeof(No));
        if (!novo) {
            printf("ERRO AO ALOCAR MEMÓRIA!\n");
            return inicio;
        }

        printf("DIGITE O NOME DO ITEM: ");
        fgets(novo->item.nome, 30, stdin);
        novo->item.nome[strcspn(novo->item.nome, "\n")] = 0;

        printf("DIGITE O TIPO DO ITEM: ");
        fgets(novo->item.tipo, 20, stdin);
        novo->item.tipo[strcspn(novo->item.tipo, "\n")] = 0;

        printf("DIGITE A QUANTIDADE: ");
        scanf("%d", &novo->item.quantidade);
        getchar();

        novo->proximo = inicio;
        inicio = novo;

        printf("ITEM ADICIONADO A LISTA ENCADEADA!\n");
        return inicio;
    }
    void listarEncadeada(No *inicio) {
        if (inicio == NULL) {
            printf("A LISTA ENCADEADA ESTÁ VAZIA!\n");
            return;
        }

        printf("\n---ITENS DA LISTA ENCADEADA---\n");
        No *atual = inicio;
        while (atual != NULL) {
            printf("NOME: %s | TIPO: %s | QUANTIDADE: %d\n", atual->item.nome, atual->item.tipo, atual->item.quantidade);
            atual = atual->proximo;

        }

    }
    void liberarEncadeada(No *inicio) {
        No *temp;
        while (inicio != NULL) {
            temp = inicio;
            inicio = inicio->proximo;
            free(temp);
        }
    }

 



