/*Escreva um programa, que contém uma estrutura do tipo Lista Simplesmente Encadeada Circular que armazena números inteiros e execute as seguintes funções:
a) Criar uma LSEC com n nós; ------
b) Imprimir os elementos da lista; -------
c) Contar os elementos da lista; ------
d) Remover o k-ésimo nó da lista, o nó k deve ser indicado pelo usuário (testar se tal elemento existe); ------
e) Criar e imprimir uma cópia da lista;  
f) Inserir um nó antes do k-ésimo nó da lista, o nó k deve ser indicado pelo usuário.*/
#include <stdio.h>
#include <malloc.h>

struct lista {
	int info; 
	struct lista *prox;
};

struct lista *cria(int n){
	int i, valor;
	struct lista *p, *ini, *ult;

	ini = NULL;

	puts("");
	for(i=0 ; i<n ; i++){
		printf("Informe um valor: ");
		scanf("%d", &valor);
		p=(struct lista*) malloc(sizeof(struct lista));
		p->info = valor;
		if(!ini){
			p->prox=p;
			ini = p;
		}
		else {
			p->prox = ini;
			ult->prox = p;
		}
		ult = p;
	}
	return p;
}

void imprimirLista(struct lista *p){
	struct lista *aux;
	aux = p;

	do{
		printf("%d\t", p->info);
		p = p->prox;
	}while(p!=aux);
}

int contaNos(struct lista *p){
	struct lista *q;
	int cont = 1;
	if(!p)
		return 0;
	q = p;
	while(p->prox!=q){
		cont++;
		p=p->prox;
	}
	return cont;
}

struct lista *removeK(struct lista *p, int k){
	struct lista *q, *t;
	int cont, n;
	n = contaNos(p);

	if(k > n ){
		printf("\nERRO! A lista nao possui esse numero de nos.\n");
		return p;
	}

	if(k==1){
		if(p->prox == p){
			free(p);
			return NULL;
		}
		else{
			q=p->prox;
			p->prox = q->prox;
			free(q);
		}
	}
	else{
		cont = 1;
		q=p->prox;
		while(k=!cont){
			t=q;
			q=q->prox;
			cont++;
		}
		t->prox = q->prox;
		if(p==q){
			free(q);
			return t;
		}
		free(q);
		return p;
	}

}


struct lista *copia(struct lista *p){
	struct lista *copia, *ini, *ult, *aux;

	ini = NULL;

	if(!p){
		printf("\nLista vazia.\n");
		return NULL;
	}

	aux = p;
	do {
		copia = (struct lista *)malloc(sizeof(struct lista));
		copia->info = p->info;
		if(!ini){
			copia->prox = copia;
			ini = copia;
		}else{
			copia->prox = ini;
			ult->prox = copia; 
		}
		ult = copia;
		p = p->prox;

	}while(p!=aux);

	return copia;
}


struct lista *insereAntesK(struct lista *p, int k){
	struct lista *aux, *q, *t,  *r;
	int cont = 1; int valor;
	
	printf("\nDigite o valor a ser inserido: ");
	scanf("%d", &valor);

	r = (struct lista*)malloc(sizeof(struct lista*));
	r->info = valor;

	aux = p;
	t = p->prox;
	if(p->prox == p){
		p->prox = r;
		r->prox = p; 
	}else {
		while(!(t->prox == aux)){
			t = t->prox;
			q = t;
		}
		q->prox = r;
		r->prox = p;
	}
	return p;
}


int main() {
	struct lista *l1, *l2;
	int i, n, cont;

	printf("\nDigite o numero de nos:");
	scanf("%d", &n);

	l1 = cria(n);

	cont = contaNos(l1);

	printf("\nNumero de nos: %d", cont);
	puts("");
	puts("");
	puts("");
	imprimirLista(l1);
	puts("");

	removeK(l1, 1);
	
	printf("\nLista L1(%p) apos remover o primeiro no: \n", l1);
	imprimirLista(l1);

	l2 = copia(l1);
	puts("");
	puts("");

	printf("\nLista l2: %p", l2);
	puts("");
	imprimirLista(l2);
	puts("");
	puts("");
	l2 = insereAntesK(l2, 3);
	printf("\nLista l2: %p\n", l2);
	imprimirLista(l2);
	puts("");
	puts("");

	return 0;
}