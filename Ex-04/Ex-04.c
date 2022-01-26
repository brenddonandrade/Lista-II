/*Dada uma estrutura livraria com código, título, autor, ano e editora. Faça um programa, usando Listas Simplesmente Encadeadas, com opções para: I- Inserir um livro na lista, BBuscar um livro na lista, R- Remover um livro da lista e E- Escrever todos os livros da lista. Na busca, leia um código qualquer e mostre título e autor, caso o código exista na lista. A lista deve conter n livros lidos via teclado.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 70

typedef struct livro livro;
typedef struct lista lista;

typedef struct livro{
    char autor[MAX];
    char titulo[MAX];
    char editora[MAX];
    char codigo[MAX];
    unsigned int ano;
};

typedef struct lista{
    livro info;
    lista *prox;
};


lista *cria(int n){
    unsigned int ano;
    livro lvr;
    lista *p, *ini, *ult;
    ini = ult = NULL;
    for(int i = 0; i < n; i++){
        printf("\nInforme o ano de lançamento do livro: ");
        scanf("%u", &lvr.ano);
        __fpurge(stdin);
        printf("\nInforme o autor desse livro: ");
        gets(lvr.autor);
        __fpurge(stdin);
        printf("\nInforme o título desse livro: ");
        gets(lvr.titulo);
        __fpurge(stdin);
        printf("\nInforme o código desse livro: ");
        gets(lvr.codigo);
        __fpurge(stdin);
        printf("\nInforme a editora desse livro: ");
        gets(lvr.editora);
        
        p = (lista *)malloc(sizeof(lista));
        p->info = lvr;
        p->prox = NULL;
        if(ult)
            ult->prox = p;
        else
            ini = p;
        ult = p;
    }
    return ini;
}

void impirmirLista(lista *p){
    if(!p){
        printf("\nLista vazia");
        return ;
    }
    lista *aux;
    aux = p;
    while(aux){
        livro lvr;
        __fpurge(stdin);
        lvr = aux->info;
        printf("\nTítulo do livro: %s", lvr.titulo);
        printf("\nAno de lançamento do livro: %u", lvr.ano);
        printf("\nAutor do livro: %s", lvr.autor);
        printf("\nCódigo do livro: %s", lvr.codigo);
        printf("\nEditora do livro: %s", lvr.editora);
        printf("\n\n");
        aux = aux->prox;
    }
}


int tam(lista *p){
    if(!p)
        return 0;
    int cont = 1;
    while(p->prox){
        cont++;
        p = p->prox;
    }
    return cont;
}

int naLista(lista *l, char *cod){
    lista *aux;
    aux = l;
    for(int i = 0; i < tam(l); i++){
        livro lvr;
        lvr = aux->info;
        if(strcmp(lvr.codigo, cod) == 0)
            return 1;
        aux = aux->prox;
    }
    return 0;
}

void busca(lista *l, char *cod){
    if(!naLista(l, cod))
        printf("\nO livro não foi encontrado");
    else{
        lista *aux;
        aux = l;
        for(int i = 0; i < tam(l); i++){
            livro lvr;
            lvr = aux->info;
            if(strcmp(lvr.codigo, cod) == 0){
                printf("\nTítulo: %s", lvr.titulo);
                printf("\nAutor: %s", lvr.autor);
                return ;
            }
            aux = aux->prox;
        }
    }
}


lista *remover(lista *l, char *cod){
    if(naLista(l, cod) == 0){
        printf("\nLivro ausente na lista");
        return l;
    }
    
    lista *aux1, *aux2;
    livro lvr;
    __fpurge(stdin);
    lvr = l->info;
    if(strcmp(lvr.codigo, cod) == 0){
        if(tam(l) == 1){
            free(l);
            return NULL;
        }
        else{
            aux1 = l;
            l = l->prox;
            free(aux1);
            return l;
        }
    }
    
    else{
        aux1 = l;
        while(strcmp(lvr.codigo, cod) != 0){
            aux2 = aux1;
            aux1 = aux1->prox;
            lvr = aux1->info;
        }
        aux2->prox = aux1->prox;
        free(aux1);
        return l;
    }
        
}

lista *insere(lista *p, livro lvr){
    lista *aux1, *aux2;
    aux1 = (lista *) malloc(sizeof(livro));
    aux1->info = lvr;
    aux1->prox = NULL;
    if(!p)
        return aux1;
    aux2 = p;
    while(aux2->prox)
        aux2 = aux2->prox;
    aux2->prox = aux1;
    return p;
}

int main(){
    int n;
    lista *l1;
    printf("\nInsira o número de livros que terá na lista: ");
    scanf("%d", &n);
    l1 = cria(n);
    printf("\nMENU: \n\nI- Inserir um livro na lista\nB- Buscar livro na lista\nR-Remover livro na lista\nE-Escrever os livros da lista\n");
    char escolha;
    printf("\n\nDigite uma opção: ");
    scanf("%c", &escolha);
    escolha = tolower(escolha);
    char cod[MAX];
    livro lvr;
    switch(escolha){
        case 'b':
            printf("\nDigite o código do livro que está buscando: ");
            __fpurge(stdin);
            gets(cod);
            busca(l1, cod);
            break;
        case 'r':
            printf("\nDigite o código do livro que deseja remover: ");
            __fpurge(stdin);
            gets(cod); 
            remover(l1, cod);
            impirmirLista(l1);
            break;
        case 'e':
            impirmirLista(l1);
            break;
        case 'i':
            printf("\nPreencha os dados do livro a ser inserido na lista: \n\n");
            printf("\nTítulo: ");
            __fpurge(stdin);
            gets(lvr.titulo);
            printf("\nAutor: ");
            __fpurge(stdin);
            gets(lvr.autor);
            printf("\nEditora: ");
            __fpurge(stdin);
            gets(lvr.editora);
            printf("\nCódigo: ");
            __fpurge(stdin);
            gets(lvr.codigo);
            printf("\nAno: ");
            scanf("%u", &lvr.ano);
            insere(l1, lvr);
            break;
        default:
            printf("\nOpção inválida");
    }
    return 0;
}


