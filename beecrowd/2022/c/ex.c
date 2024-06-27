#include <stdio.h>
#include <stdlib.h>
// comprar string
//  criar lista encadeada
typedef struct _Presente
{
    char *nome;
    float preco;
    int preferencia;
    struct _Presente *anterior;
    struct _Presente *proximo;
} Presente;

typedef struct
{
    Presente *head;
} LinkedList;

void aqui(){
    printf("aqui\n");
}

void inserir(LinkedList *lista, Presente *novoPresente)
{

    if (!lista->head)
    {
        aqui();
        lista->head = novoPresente;
        return;
    }

    Presente *presenteAtual = lista->head;
    while (presenteAtual)
    {
        if ((presenteAtual->preferencia < novoPresente->preferencia) || (presenteAtual->preferencia == novoPresente->preferencia && presenteAtual->preco > novoPresente->preco))
        {
            Presente *temp = presenteAtual;
            presenteAtual = novoPresente;
            if (temp->anterior != NULL)
            {
                presenteAtual->anterior = temp->anterior;
            }
            presenteAtual->proximo = temp;
            temp->anterior = presenteAtual;

            return;
        }

        if (presenteAtual->proximo == NULL)
        {
            presenteAtual->proximo = novoPresente;
            return;
        }

        presenteAtual = presenteAtual->proximo;
    }

    aqui();

}

void printPresente(Presente *presente)
{
    printf("Presente: %s\n", presente->nome);
    printf("Presente: %f\n", presente->preco);
    printf("Presente: %d\n", presente->preferencia);
}

void printLista(LinkedList *lista)
{
    Presente *presenteAtual = lista->head;
    while (presenteAtual)
    {
        printPresente(presenteAtual);
        presenteAtual = presenteAtual->proximo;
        // proximo(presenteAtual);
    }
}

void proximo(Presente *presente)
{
    presente = presente->proximo;
}

int main()
{
    // while (scanf("%d", &n) != EOF)
    char nome[50];
    int numeroPresentes;

    scanf("%s", nome);
    scanf("%d", &numeroPresentes);

    while (*nome != EOF)
    {
        LinkedList listaPresentes;

        for (int i = 0; i < numeroPresentes; i++)
        {
            char presenteNome[50]; // um array é um ponteiro
            int preferencia;
            float preco;

            scanf(" %[^\n]%*c", presenteNome);

            scanf("%f", &preco);
            scanf("%d", &preferencia);

            Presente *novoPresente = malloc(sizeof(Presente));
            novoPresente->nome = presenteNome;
            novoPresente->preco = preco;
            novoPresente->preferencia = preferencia;

            printPresente(novoPresente);
            inserir(&listaPresentes, novoPresente);
        }
        printLista(&listaPresentes);

        scanf("%[^\n]%*c", nome);
        scanf("%d", &numeroPresentes);
    }

    return 0;
}