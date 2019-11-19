#include <stdio.h>
#include <stdlib.h>
#include <new>
#include <iostream>
#include <string.h>

typedef struct Lista{
	int info; // Váriavel que irá marcar o valor na lista
	struct Lista *prox; // Ponteiro que irá apontar para o próximo item da lista
}Lista;

Lista *criaLista();
Lista *inserir(int n, Lista *ref);
void remover(int n, Lista *ref);
void imprimir(Lista *ref);
void buscar(int n, Lista *ref);
void RemoverInicio(Lista *ref);
void Remover(int n, Lista *ref);
//Lista *separa(Lista = l, int n)





int main(int argc, char const *argv[]){
	int x = 0, y = 0, caso = 0, z = 0, r = 0;
  //ponteiro cursor da lista
	Lista *ponteiroInicio;
  //menuzinho padrão
	while(caso < 7){
		printf("\n1 - Criar Lista\n2 - Inserir Item na Lista\n3 - Remover Item da Lista\n4 - Remover Início da Lista\n5 - Imprimir Lista\n6 - Buscar Item na Lista\n");
		printf("7 - Sair\n\nEscolha a opção: ");
		scanf("%d", &caso);
		system("clear || cls");
		switch(caso){
			case 1:
				system("clear || cls");
				ponteiroInicio = criaLista();
				printf("Lista Criada!!!\n\n");
			break;
			case 2:
				do{
					system("clear || cls");
					printf("Digite o valor a ser inserido na lista: \n");
					scanf("%d", &x);
					ponteiroInicio = inserir(x, ponteiroInicio);
					printf("Deseja adicionar mais um número? (1 - SIM  2 - NÃO): ");
					scanf("%d", &r);
				}while(r == 1);
			break;
			case 3:
				system("clear || cls");
				printf("Digite o valor a ser retirado da lista: ");
				scanf("%d", &y);
				Remover(y, ponteiroInicio);
			break;
			case 4:
				system("clear || cls");
				RemoverInicio(ponteiroInicio);
			break;
			case 5:
				system("clear || cls");
				imprimir(ponteiroInicio);
			break;
			case 6:
				printf("Digite o valor a ser encontrado: ");
				scanf("%d", &z);
				buscar(z, ponteiroInicio);
			break;
			default: system(EXIT_SUCCESS);
		}
	}
	return 0;
}


Lista *criaLista(){ // Criando uma lista vázia
	return NULL;
}

Lista* inserir(int n, Lista *ref){
	 Lista *novo = new Lista; // Alocação dinâmica para o novo nó da lista
	 novo->prox = ref; // o novo nó passa a ter o proximo como o item anterior, tornando-se o novo primeiro elemento
	 novo->info = n; // Novo que acessa info, onde info recebe n(valor que ira ser inserido na lista)
	 ref = novo; // o novo nó passa a ser o primeiro da lista
	 return ref;//retorna o valor do primeiro item da lista
}

void imprimir(Lista *ref){
	Lista *aux = ref; // Ponteiro aux da struct lista recebe ref, cabeça da lista
	if(ref == NULL){ // Se a referência for NULL, ou seja, nenhum valor
		printf("LISTA VÁZIA!!\n");
		return;
	}
	while(aux != NULL){ // Enquanto esse ponteiro auxiliar for diferente de null, a lista irá conter valores
		printf("%d -> ", aux->info); // Imprimir a cabeça da lista
		aux = aux->prox; // Auxiliar irá agora receber próxima posição da lista;
	}
  printf("NULL\n");
}

void buscar(int n, Lista *ref){
	Lista *aux = ref; // Ponteiro aux da struct lista recebe ref, cabeça da lista
	while(aux != NULL){ // Enquanto aux for diferente de NULL(fim da lista)
		if(aux->info == n){ //
			printf("%d\n", aux->info);
			break;
		}
		aux = aux->prox;
	}
	if(aux == NULL){
		printf("\nO ELEMENTO NÃO SE ENCONTRA NA LISTA!!\n" );
	}
}

void Remover(int n, Lista *ref){
	Lista *aux = ref, *aux2; // Ponteiro aux da struct lista recebe ref, cabeça da lista
	while(aux != NULL){
		if(aux->info == n){ // Se o conteúdo do nó na lista for igual a n(valor desejado pelo usuário)
			aux2->prox = aux->prox; // aux2 que aponta para o próximo agora ira receber a posição que aux aponta
			free(aux); // Liberar ó nó (Remover)
			break;
		}
			aux2 = aux; // Aux2 recebe aux(nó).
			aux = aux->prox; // aux aponta para o próximo
	}
}

void RemoverInicio(Lista *ref){
  Lista *aux;
  if(ref == NULL){ // Se a referência for NULL, ou seja, nenhum valor
    printf("LIXTA VÁZIA!!\n");
    return;
  }
  aux = ref->prox;// aux começa a apontar pro segundo valor da lista
  ref-> prox = aux->prox;//agora o ponteiro cursor começa a apontar pro segunda (novo primeiro) valor da lista

}
