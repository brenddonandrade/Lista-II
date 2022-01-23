/*Escreva um programa, que contém uma estrutura do tipo Lista Duplamente Encadeada Ordenada que armazena números reais e execute as seguintes seguintes opções de: 1- Inserção, 2-Busca, 3-Remoção, 4-Imprimir lista e 5-Sair, através de chamadas às funções
para:
- Inserir um elemento na LDE; ------
- Buscar um elemento (lido via teclado) na LDE;
- Remover o k-ésimo (lido via teclado) nó da LDE;------
- Imprimir os elementos da LDE. --------
*/

#include <stdio.h>
#include <malloc.h>

struct dupla {
	struct dupla *eprox;
	float info;
	struct dupla *dprox;
};

struct dupla *cria(int n){
	struct dupla *p, *ini, *ult;
	float valor;
	int i;

	ult = NULL;

	for(i=0 ; i<=n ; i++){
		printf("\nInforme um valor: ");
		scanf("%f", &valor);
		p = (struct dupla*)malloc(sizeof(struct dupla));
		p->info = valor;
		p->eprox = NULL;
		p->dprox = NULL;
		if(ult){
			ult->dprox = p;
			p->eprox = ult;
		}else 
			ini = p;
		ult = p;
	}
	return ini;
}

void imprime(struct dupla *p){
	while(p){
		printf("%f.2\t", p->info);
		p = p->dprox;
	}
}

struct dupla *insereFinal(struct dupla *p, int valor) {
	struct dupla *q, *t;
	
	q=(struct dupla*)malloc(sizeof(struct dupla));
	q -> info = valor;
	if(!p){
		q->eprox = q->dprox = NULL;
		return q;
	}else {
		t=p;
		while(t -> dprox)
		t= t->dprox;
 		t->dprox = q;
 		q->eprox = t;
		q->dprox = NULL;
		return p;
	}
} 

struct dupla *removeK(struct dupla *p, int k){
	struct dupla *q, *r, *t;
	int cont;
	if(k==1){
		if(!p-dprox){
			free(p);
			return NULL;
		}else {
			q = p;
			p = p->dprox
			p->eprox = NULL;
			free(q);
			return p;
		}
	}
	else {
		cont =1;
		q=p; 
		while(cont!=k){
			q = q->dprox;
			cont++;
		}
		t=q->dprox;
		r=q->eprox;
		r->dprox = t;
		if(t!=NULL)
			t->eprox = r;
		free(q);
	}
	return(p);
}