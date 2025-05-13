#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct time Time;
typedef struct tabela Tabela;
typedef struct hash_node Node;

struct time{
  char *nome;
  int pontos;
  int vitorias;
  int gols_marcados;
  int index;
  Time* anterior;
  Time* proximo;
};

struct tabela{
  Time *primeiro;
};

struct hash_node{
  Time *t;
  Node *proximo;
};

int hash_func(char c){
  if(c > 96 && c < 123){
	return c - 97;
  }

  return 27;
}

void iniciar_time(Time *time, int index){
  time->pontos = 0;
  time->vitorias = 0;
  time->gols_marcados = 0;
  time->index = index;
  time->anterior = NULL;
  time->proximo = NULL;
}

void add_time_hash_table(Node table[], Time *time){
  int index = hash_func(time->nome[0]);
  
  if((table[index]).t == NULL){
	(table[index]).t = time;
	return;
  }

  Node *current = &(table[index]);
  while(current->t != NULL){
	if(current->proximo == NULL){
	  current->proximo = malloc(sizeof(Node));
	  current->proximo->t = time;
	  return;
	}

	current = current->proximo;
  }
}

void atualizar_pontuacao_time(Tabela *tabela, Node table[], char *nome, int pontos, int gols_marcados){
  int index = hash_func(nome[0]);
  Time **time;

  Node *time_atual = &(table[index]);
  while(1){
	int cmp = strcmp(time_atual->t->nome, nome);

	if(cmp == 0){
	  time = &(time_atual->t);
	  break;
	}

	time_atual = time_atual->proximo;
  }

  (*time)->pontos += pontos;
  (*time)->gols_marcados += gols_marcados;
  if(pontos == 3){
	(*time)->vitorias++;
  }

  // atualizar classificação 
  while(1){
	Time *anterior = (*time)->anterior; // Pegar o endereço real do objeto
	if((*time)->anterior == NULL){
	  tabela->primeiro = *time;
	  return;
	}

	if(anterior->pontos > (*time)->pontos){
	  return;
	}else if(
			 (anterior->pontos < (*time)->pontos) ||
			 ((*time)->pontos==anterior->pontos && (*time)->vitorias > (anterior->vitorias)) ||
			 (anterior->pontos == (*time)->pontos && (*time)->vitorias == (anterior->vitorias) &&  anterior->gols_marcados < (*time)->gols_marcados) ||
			 (anterior->pontos == (*time)->pontos && (*time)->vitorias == (anterior->vitorias) && anterior->gols_marcados == (*time)->gols_marcados && anterior->index > (*time)->index)) {
	  Time *temp_anterior = anterior->anterior; // endereço do elemento anterior
	  Time *time_proximo = ((*time)->proximo);

	  if(temp_anterior == NULL){
		tabela->primeiro = *time;
		(*time)->anterior = NULL;
	  }else{
		temp_anterior->proximo = *time;
		(*time)->anterior = temp_anterior;
		temp_anterior->proximo = *time;
	  }

	  if(time_proximo !=NULL){
		anterior->proximo = time_proximo;
		time_proximo->anterior = anterior;
	  }else{
		anterior->proximo = NULL;
	  }

	  (*time)->proximo = anterior;
	  anterior->anterior = *time;
	  continue;
	}

	break;
  }
}

void free_tabela(Tabela *tabela){
  Time *atual = tabela->primeiro;
  while(atual != NULL){
	Time *temp = atual;
	atual = atual->proximo;
	free(temp);
	temp=NULL;
  }
  free(tabela);
  tabela = NULL;
}

int main(){
  int t;
  scanf("%d", &t);

  for(int i = 0; i < t; i++){
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	//Declarar a hash table
	Node table[27] = {0};
	Tabela *tabela = malloc(sizeof(Tabela)); 	
	//Ler os times e adicionar na hash table
	for(int j = 0; j < n; j++){
	  char nome[21];
	  scanf("%s", nome);
	  int len = strlen(nome);

	  Time *t = malloc(sizeof(Time));
	  t->nome = malloc(sizeof(char)*len);
	  strcpy(t->nome, nome);
	  iniciar_time(t, j);
	  add_time_hash_table(table, t);

	  Time *nAtual = tabela->primeiro;
	  if(j == 0){
		tabela->primeiro = t;
	  }else{
		while(1){
		  if(nAtual->proximo == NULL){
			nAtual->proximo = t;
			t->anterior = nAtual;
		  
			break;
		  }
		  nAtual = nAtual->proximo;
		}
	  }
	}
	// Ler os resultados e atualizar os pontos dos times
	for(int j = 0; j < m; j++){
	  int ga, gb;
	  char ta[21], tb[21];
	  scanf("%d", &ga);
	  scanf("%s", ta);
	  scanf("%d", &gb);
	  scanf("%s", tb);

	  if(ga > gb){
		atualizar_pontuacao_time(tabela, table, ta, 3, ga);
	  }else if(gb > ga){
		atualizar_pontuacao_time(tabela, table, tb, 3, gb);
	  }else{
		atualizar_pontuacao_time(tabela, table, tb, 1, gb);
		atualizar_pontuacao_time(tabela, table, ta, 1, ga);
	  }
	}

	Time *atual = tabela->primeiro;
	while(atual != NULL){
	  printf("%s\n", atual->nome);
	  atual = atual->proximo;
	}

	free_tabela(tabela);
  }
}
