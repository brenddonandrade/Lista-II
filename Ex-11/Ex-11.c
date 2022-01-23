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

void imprima(struct dupla *p){
	struct dupla *q;
	
	q = p;
	puts("");
	printf("Lista:\n");
	while(q){

		printf("%.2f\t", q->info);
		q = q->dprox;
	}
	printf("\n");
}


struct dupla *insereFinal(struct dupla *p, float valor)
{
	struct dupla *q, *t;
	q=(struct dupla*)malloc(sizeof(struct dupla));
 	q->info = valor;
	if(!p){
		q->eprox = q->dprox = NULL;
		return q;
	}
	else{
		t=p;
		while(t->dprox)
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

	if(!p){
		printf("\nLista vazia.\n");
		return NULL;
	}
	if(k==1){
		if(!p->dprox){
			free(p);
			return NULL;
		}else {
			q = p;
			p = p->dprox;
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

int busca(struct dupla *p, int valor){
	struct dupla *aux;

	aux = p;
	while(aux){
		if(aux->info == valor)
			return 1;
		aux = aux->dprox;
	}
	return 0;
}


int main() {
	struct dupla *l1;
	int  k, n, op, aux, cont=0;
	float valor;

	l1 = NULL;

	

		do{
			puts("");
			printf("\nDigite o que deseja fazer:\n1-Inserção \n2-Busca \n3-Remoção \n4-Imprimir lista \n5-Sair\n\n");
			scanf("%d", &op);	
			
			switch(op){
			case 1: 
				printf("\nDigite o valor a ser incluido: ");
				scanf("%f", &valor);
				l1 = insereFinal(l1, valor);
				cont++;
				break;
			
			case 2:
				if(!l1){
					printf("\nLista vazia.\n\n");
					break;
				}

				printf("\nDigite o valor buscado: ");
				scanf("%f", &valor);
				aux = busca(l1, valor);
				if(aux==0)
					printf("\nValor nao encontrado na lista.\n");
				if(aux==1)
					printf("\nValor encontrado.\n");
				break;

			case 3:
				if(!l1){
					printf("\nLista vazia.\n\n");
					break;
				}
				printf("\nDigite qual no deseja remover: ");
				scanf("%d", &n);
				if(n<=cont){
					l1 = removeK(l1, n);
					printf("\nRemovido com sucesso.\n");
				}else {
					printf("\nLista nao possui tantos nos.\n");
				}
				break;

			case 4:
				imprima(l1);
				break;

			case 5:
				printf("\nExit.\n");
				break;

			default:
				printf("\nOpcao Invalida.\n");
		}
	}while(op!=5);

	return 0;

}