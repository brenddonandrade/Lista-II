/*19) Escreva um programa que insira (usando chamada de função) os dados de n (lido via teclado) alunos de uma turma numa Lista Duplamente Encadeada cujo tipo que representa um nó da lista é dado por:

struct aluno{
  int mat;
  char nome[80];
  float media;
  struct aluno *eprox;
  struct aluno *dprox;
};

Imprima a lista (usando chamada de função). Busque uma matricula lida via teclado na lista (usando chamada de função), mostre se achou ou não achou. Em seguida, implemente uma função que receba a lista criada e retorne uma nova lista dos alunos aprovados, ou seja, os alunos com média maior ou igual a 6.0. Imprima a nova lista. Crie uma outra função que recebe a lista e e retorne uma nova lista dos alunos que estão reprovados, ou seja, com média menor do que 4.0. Imprima a lista resultante.*/