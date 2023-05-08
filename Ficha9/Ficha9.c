#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) {
	ABin a = malloc (sizeof(struct nodo));
	if (a != NULL) {
		a->valor = r; a->esq = e; a->dir = d;
	}
	return a;
}

// Exercício 1:

// a)

int max (int a, int b) {
	return a > b ? a : b;
}

int altura (ABin a) {
	if (a == NULL) return 0;
	else return (1 + max(altura (a->esq), altura (a->dir)));
}

// b)

int nFolhas (ABin a) {
	if (a == NULL) return 0;
	if (a->esq == NULL && a->dir == NULL) return 1;
	else return (nFolhas(a->esq) + nFolhas(a->dir));
}

// c)

ABin maisEsquerda (ABin a) {
	if (a == NULL) return NULL;
	if (a->esq == NULL) return a;
	else return (maisEsquerda(a->esq));
}

// sem usar recursiva

ABin maisEsquerda1 (ABin a) {
	if (a == NULL) return NULL;
	while (a->esq != NULL) a = a->esq;
	return a;
}


// d)

void imprimeNivel (ABin a, int l) {
	if (a != NULL) {
		if (l == 0) printf("%d\n", a->valor);
		else {
			imprimeNivel(a->esq, l-1);
			imprimeNivel(a->dir, l-1);
		}
	}
}

// e)

int procuraE (ABin a, int x) {
	if (a == NULL) return 0;
	if (a->valor == x) return 1;
	else return (procuraE(a->esq,x) || procuraE(a->dir,x));
}

// Exercício 2:

// f)

struct nodo *procura (ABin a, int x) { // ABin procura(ABin a, int x)
	if (a == NULL) return NULL;
	if (a->valor == x) return a;
	else {
		if (a->valor > x) return (procura(a->esq,x));
		else return (procura(a->dir,x));
	}
}

// g)

int nivel (ABin a, int x) {
	if (a == NULL) return -1;
	if (a->valor == x) return 0;
	else {
		if (x < a->valor) return (1 + nivel(a->esq,x));
		else return(1 + nivel(a->dir,x));
	}
}

// h)

void imprimeAte (ABin a, int x) {
	if (a == NULL) return;
	if (x > a->valor) {
		imprimeAte(a->esq,x);
		printf("%d\n", a->valor);
		imprimeAte(a->dir,x);
	}
	else imprimeAte(a->esq,x);
}

int main() {

	ABin a = newABin(7,newABin(3,NULL,newABin(5,NULL,NULL)),newABin(10,NULL,NULL));
	imprimeAte(a,6);
	return 0;
}