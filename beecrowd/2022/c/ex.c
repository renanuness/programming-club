#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// comprar string
//  criar lista encadeada
typedef struct Presente Presente;

struct Presente
{
    char *nome;
    float preco;
    int preferencia;
    struct Presente *anterior;
    struct Presente *proximo;
};

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
	    temp->anterior->proximo = presenteAtual;
    	  }
          presenteAtual->proximo = temp;
          temp->anterior = presenteAtual;

	  if(temp == lista->head){
	    lista->head = presenteAtual;
	  }
	  
            return;
        }

        if (presenteAtual->proximo == NULL)
        {
	  presenteAtual->proximo = novoPresente;
	  novoPresente->anterior = presenteAtual;
            return;
        }

        presenteAtual = presenteAtual->proximo;
    }

}

void printPresente(Presente *presente)
{
  printf("%s - R$ %.2f\n", presente->nome, presente->preco);
}

void printDebug(Presente *presente)
{
    printf("Presente: %s\n", presente->nome);
    printf("Preco: %f\n", presente->preco);
    printf("Preferencia: %d\n", presente->preferencia);
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

void freeLista(LinkedList *lista){
  Presente *atual = lista->head;
  while(atual){
    Presente *temp = atual;
    atual = atual->proximo;
    free(temp);
  }
  free(lista);
}

int main()
{
    // while (scanf("%d", &n) != EOF)
    char nome[50];
    int numeroPresentes;

    while (scanf("%s", nome) != EOF && scanf("%d", &numeroPresentes) != EOF)
    {
      LinkedList *listaPresentes = malloc(sizeof(LinkedList));
      listaPresentes->head = NULL;
      char g;
      for (int i = 0; i < numeroPresentes; i++)
      {
	char presenteNome[50]; // um array é um ponteiro
        int preferencia;
        float preco;
	    
        scanf("%c%[^\n]\n", &g, presenteNome);
	scanf("%f", &preco);
        scanf("%d", &preferencia);

        Presente *novoPresente = malloc(sizeof(Presente));
	novoPresente->nome = malloc(sizeof(char)*(strlen(presenteNome)+1));
        strcpy(novoPresente->nome, presenteNome);
        novoPresente->preco = preco;
	novoPresente->preferencia = preferencia;
	    
        inserir(listaPresentes, novoPresente);
      }

	printf("Lista de %s\n", nome);
        printLista(listaPresentes);
	printf("\n");
	
        //scanf("%c%[^\n]%*c", &g,nome);
        //scanf("%d", &numeroPresentes);
        freeLista(listaPresentes);
    }

    return 0;
}
