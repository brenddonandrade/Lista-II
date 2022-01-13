/* Considere uma estrutura do tipo Lista Simplesmente Encadeada que contém números inteiros. Escreva um programa que execute as seguintes funções:
a) Criar uma LSE com n nós (valor de n lido via teclado);
b) Imprimir os elementos da lista;
c) Contar os elementos da lista;
d) Remover o k-ésimo nó da lista, o nó k deve ser indicado pelo usuário (testar se talelemento existe);
e) Gerar uma cópia da lista;
f) Gerar uma lista com os elementos pares da lista criada;
g) Gerar uma lista com os elementos ímpares da lista criada.*/

#include <stdio.h>
#include <malloc.h>
struct lista{
  int valor;
  struct lista *prox;
};

struct lista *cria(int n){//cria lista com n nós
  int i, valor;
  struct lista *p, *ini, *ult;
  ini = ult = NULL;

  for(i=0 ; i<=n; i++){
    printf("\nInforme um valor: ");
    scanf("%d", &valor);
    p = (struct lista*)malloc(sizeof(struct lista));
    p->prox = NULL;
    if(ult)
      ult->prox=p;
    else  
      ini=p;
    ult=p;
  }
  return ini;
}

int contaNos(struct lista *p){
  int cont;
  if(!p)//se p==NULL(ou seja, um nó), o ! vai mudar o valor boolean e assim e executar o if
    return 0;
  else{
    cont = 0;
    while(p){//vai rodar enquanto p!=NULL
      p=p->prox;
      cont++;
    }
    return cont;
  }
}

void imprimirLista(struct lista *p){
  while(p){
    printf("%d\t", p->valor);
    p=p->prox;
  }
}

struct lista *inserirNoFinal(struct lista *p, int valor){
  struct lista *ini, *novo;
  novo=(struct lista*)malloc((sizeof(struct lista)));
  novo->valor=valor;
  novo->prox=NULL;
  if(!p)
    return novo;
  ini=p;
  while(p->prox)
    p=p->prox;
  p->prox=novo;
  return ini;
}

struct lista *removerNaLista(struct lista *p){
  struct lista *ini, *ult;
  if(!p)
    return NULL;
  if(!p->prox){
    free(p);
    return NULL;
  }
  ini=p;
  while(p->prox){
    ult=p;
    p=p->prox;
  }
  ult->prox=NULL;
  free(p);
  return ini;
}

struct lista *removeK(struct lista *p, int k){
  struct lista *t, *q;
  int cont;
  if(k==1)
    if(!p->prox){
      free(p);
      return NULL;
    }
    else{
      t=p->prox;
      p->prox=NULL;//!!!!!!!PERGUNTAR: pq colocar p->prox=NULL se vamos liberar o espaço da memória onde p aponta.
      free(p);
      return t;
    }
  else{
    cont = 1;
    t = p;
    while(cont!=k){
      q = p;
      p=p->prox;
      cont++;
    }
    q->prox=p->prox;
    free(p);
    return t;
  }
}
