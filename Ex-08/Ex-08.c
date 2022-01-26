/*Escreva um programa que leia duas Listas Simplesmente Encadeadas Circulares de números inteiros, que não apresentam repetição de dados em cada uma. Logo após, escreva funções para:
i) Criar uma outra lista com os elementos que apareçam na 1a. lista e também apareçam na 2a. lista (tipo interseção de conjuntos). Imprima a lista;
ii) Gerar uma terceira lista que represente a união das listas de entrada (tipo união de conjuntos). Imprima a lista.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista lista;

typedef struct lista{
    int info;
    lista *prox;
};

lista *criar(int n){
    lista *p, *ini, *ult;
    ini = ult = p = NULL;
    int valor;
    for(int i = 0; i < n; i++){
        scanf("%d", &valor);
        p = (lista*) malloc(sizeof(lista));
        p->info = valor;
        p->prox = ini;
        if(ult)
            ult->prox = p;
        else
            ini = p;
        ult = p;     
    }
    return ini;
}

int tamanho(lista *p){
    lista *aux;
    aux = p;
    int cont = 1;
    while(aux->prox != p){
        aux = aux->prox;
        cont++;
    }  
    return cont;
}

lista *intersecao(lista *l1, lista *l2){
    lista *aux1, *aux2, *ini, *p, *ult;
    aux1 = l1;
    aux2 = l2;
    for(int i = 0; i < tamanho(aux1); i++){
        for(int j = 0; j < tamanho(aux2); j++){
            if(aux1->info == aux2->info){
                int elem = aux1->info;
                p = (lista*) malloc(sizeof(lista));
                p->info = elem;
                p->prox = ini;
                if(ult)
                    ult->prox = p;
                else
                    ini = p;
                ult = p;   
            }
            aux2 = aux2->prox;
        }
        aux1 = aux1->prox;
    }
    return ini;
}

lista *uneLista(lista *l1, lista *l2){
    int t;
    lista *aux1, *aux2, *p, *ini, *ult;
    aux1 = l1;
    aux2 = l2;
    t = tamanho(l1)+tamanho(l2);
    for(int i = 1; i < t; i++){
        int elem;
        if(i <= tamanho(l1)){
            elem = l1->info;
            aux1 = aux1->prox;
        }
        else{
            elem = l2->info;
            aux2 = aux2->prox;
        }
        p = (lista*) malloc(sizeof(lista));
        p->info = elem;
        p->prox = ini;
        if(ult)
           ult->prox = p;
        else
           ini = p;
        ult = p;  
    }
    return ini;
}

void imprimeLista(lista *l){
    lista *aux;
    aux = l;
    printf("\n%d", aux->info);
    while(aux->prox != l){
        aux = aux->prox;
        printf("\n%d", aux->info);
    }  
}

int main(){
    lista *l1, *l2;
    int t1, t2;
    printf("\nInsira o tamanho para a primeira lista");
    scanf("%d", &t1);
    printf("\nInsira o tamanho para a segunda lista");
    scanf("%d", &t2);
    l1 = criar(t1);
    l2 = criar(t2);
    imprimeLista(intersecao(l1, l2));
    puts("");
    puts("");
    imprimeLista(uneLista(l1, l2));
    puts("");
    puts("");
    return 0;
}