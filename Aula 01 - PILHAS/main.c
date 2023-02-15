#include <stdio.h>

// Constantes
#define TAMANHO 5
const int FALSE = 0;
const int TRUE = 1;
const int VAZIA = 0;

// Variáveis
int pilha[TAMANHO];
int posicao = 0;

// Protótipos
int push(int dado);
int pop(int *valor);

int menu();

int main() {
    int opcao;
    int numero;
    int resultado;

    opcao = 0;

    while(opcao != 3)
    {
        opcao = menu();
        switch(opcao)
        {
            case 1:
                printf("Digite um numero: ");
                scanf("%d", &numero);
                resultado = push(numero);
                if(!resultado)
                {
                    printf("Estouro de pilha!\n");
                }
                break;
            case 2:
                resultado = pop(&numero);
                if(!resultado)
                {
                    printf("Pilha vazia!\n");
                }
                else
                {
                    printf("Retirado %d da pilha\n", numero);
                }
                break;
            case 3:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}

int push(int dado)
{
    if(posicao == TAMANHO)  // Se a pilha estiver cheia
    {
        return FALSE;
    }

    pilha[posicao] = dado;
    posicao++;

    return TRUE;
}

int pop(int *valor)
{
    if(posicao == VAZIA)
    {
        return FALSE;
    }

    posicao--;
    *valor = pilha[posicao];

    return TRUE;
}

int menu()
{
    int retorno = 0;

    printf("1 - Push\n");
    printf("2 - Pop\n");
    printf("3 - Sair\n");
    printf("\nDigite a sua opcao: ");
    scanf("%d", &retorno);

    return retorno;
}
