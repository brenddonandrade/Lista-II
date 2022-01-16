/*2) Considere uma estrutura do tipo Lista Simplesmente Encadeada que contém números reais. Escreva um programa que gere e imprima duas listas L1 e L2 de tamanhos lidos via teclado. Logo após, crie uma função que recebe as duas listas e concatena a lista L2 no final da lista
L1. A função deve retornar ponteiro para o início da lista concatenada Imprima a lista concatenada.*/

#include <stdio.h>
#include <malloc.h>

struct lista {
	float valor;
	struct lista *prox;
};

struct lista *cria(int n){
	int i;
	float valor;
	struct lista *p, *ini, *ult;
	ini = ult = NULL;

	puts("");
	for(i=0 ; i<n ; i++){
		printf("Informe um valor: ");
		scanf("%f", &valor);
		p = (struct lista*)malloc(sizeof(struct lista));
		p->valor = valor;
		p->prox = NULL;
		if(ult)
			ult->prox=p;
		else
			ini=p;
		ult = p;
	}
	return ini;
}

void imprimirLista(struct lista *p) {
	while(p){
		printf("%.2f\t", p->valor);
		p = p->prox;
	}
}

struct lista *concatena(struct lista *p1, struct lista *p2) {
	int i;
	struct lista *ini, *ult;
	if(!p1 || !p2)
		return NULL;

	ini = p1;
	while(p1->prox)
		p1 = p1->prox;

	p1->prox = p2;
	return ini;
}

int main() {
	struct lista *l1, *l2;
	int n;
	float valor;

	printf("\nNumero de termos de L1: ");
	scanf("%d", &n);
	l1 = cria(n);
	puts("");

	printf("\nLista L1:\n");
	imprimirLista(l1);
	puts("");
	puts("");

	printf("\nNumero de termos de L2: ");
	scanf("%d", &n);
	l2 = cria(n);
	puts("");

	printf("\nLista L2:\n");
	imprimirLista(l2);
	puts("");

	l1 = concatena(l1, l2);

	puts("");
	printf("\nLista L1 concatenada: \n");
	imprimirLista(l1);
	puts("");
	puts("");
	return 0;
}