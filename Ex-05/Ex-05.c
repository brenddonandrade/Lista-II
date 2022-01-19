/*5) Escreva um programa que leia e imprima um vetor com n (lido via teclado) elementos inteiros. Em seguida, gere uma Lista Simplesmente Encadeada ordenada com os elementos do vetor. Imprima a lista gerada.*/

#include <stdio.h>
#include <malloc.h>

struct lista {
	int info;
	struct lista *prox;
};

struct lista *insereOrd(struct lista *p, int valor) 
{
 	struct lista *t, *q, *r;

	q=(struct lista*)malloc(sizeof(struct lista));
	q -> info=valor;

 	if(!p) {
 		q->prox=NULL;
		return q;
	}
 	else{
 		r=p;
  		while(p && valor > p->info) {
			t=p;
  			p=p->prox;
		}
  		if(!p)
		{ 
  			t->prox=q;
  			q -> prox=NULL;
			return r;
		}
		if(valor<p->info) 
		{
   			q->prox=p;
   			if(p!=r) {
    			t->prox=q;
   			return r;
 			 }
   		return q;
  		}
	}
}




void imprimirLista(struct lista *p){
	while(p){
		printf("%d\t", p->info);
		p = p->prox;
	}
}

int main(){
	struct lista *l1;
	int n, *v;

	printf("\nDigite o tamanho do vetor: ");
	scanf("%d", &n);

	v = (int*)malloc(n*sizeof(int));
	if(v==NULL){
		printf("\nERRO! Memoria indisponivel.\n");
		return 0;
	}

	puts("");
	printf("\nDigite os valores do vetor: \n");
	for(int i=0 ; i<n ; i++){
		printf("v[%d]: ",i);
		scanf("%d", &v[i]);
	}

	
	l1 = insereOrd(l1, v[0]);


	puts("");
	printf("\nLista l1: \n");
	imprimirLista(l1);
	puts("");
	for(int i=0 ; i<1 ; i++)
		printf("%d\t", v[i]);
	puts("");

	

	free(v);
	return 0;
}