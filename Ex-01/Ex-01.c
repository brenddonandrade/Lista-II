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

  puts("");
  for(i=0 ; i<n; i++){
    printf("Informe um valor: ");
    scanf("%d", &valor);
    p = (struct lista*)malloc(sizeof(struct lista));
    p->valor = valor;
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
      p->prox=NULL;
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

struct lista *copia(struct lista *p, int n){
  struct lista *ini, *copia, *final;
  ini = final = NULL;
  
  if(!p)
      return 0;
  
  if(!p->prox){
    copia = (struct lista*)malloc(sizeof(struct lista));
    copia->valor = p->valor;
    copia->prox = NULL;
  }

    for(int i = 0; i < n ; i++ ){
    copia = (struct lista*)malloc(sizeof(struct lista));
    if(i==0)
      ini = copia;
    copia->valor = p->valor;
    p = p->prox;
    copia->prox = NULL;
    if(final)
      final->prox=copia;
    else  
      ini=copia;
    final=copia;
  }
  return ini;
}

struct lista *descobrePar(struct lista *p){
  struct lista *par, *iniPar, *finalPar;
  iniPar = finalPar = NULL;

  if(!p) {
    return NULL;
  }

  while(p){
    if((p->valor%2) == 0){
        par = (struct lista*)malloc(sizeof(struct lista));
        par->valor = p->valor;
        par->prox= NULL;
        if(finalPar)
          finalPar->prox=par;
        else  
          iniPar=par;
        finalPar=par;
      }
      p = p->prox;
  }
  return iniPar;
}

struct lista *descobreImpar(struct lista *p){
  struct lista *impar, *iniImpar, *finalImpar;
  iniImpar = finalImpar = NULL;

  if(!p) {
    return NULL;
  }

  while(p){
    if((p->valor%2) == 1){
        impar = (struct lista*)malloc(sizeof(struct lista));
        impar->valor = p->valor;
        impar->prox= NULL;
        if(finalImpar)
          finalImpar->prox=impar;
        else  
          iniImpar=impar;
        finalImpar=impar;
      }
      p = p->prox;
  }
  return iniImpar;
}


int main() {
  struct lista *l1, *l2, *par, *impar;
  int n;

  printf("\nDigite o numero de nos: ");
  scanf("%d", &n);

  l1 = cria(n);

  l2 = copia(l1, n);

  puts("");
  printf("l1: \n");
  imprimirLista(l1);
  puts("");

  printf("\nl2:\n");
  imprimirLista(l2);
  puts("");

  par = descobrePar(l2);
  printf("\nPar:\n");
  imprimirLista(par);
  puts("");

  impar = descobreImpar(l2);
  printf("\nImpar:\n");
  imprimirLista(impar);
  puts("");
  puts("");
  

  return 0;
}
