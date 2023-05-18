#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} * ABin;

// Exercício 1:

// a)

ABin removeMenor (ABin *a) {
	ABin aux = *a;
	if (*a != NULL) {
		while ((*a)->esq != NULL)
			a = &((*a)->esq);
		aux = *a;
		*a = (*a)->dir;
	}
	return aux;
}

// b)

void removeRaiz (ABin *a) {
	ABin menor = removeMenor(&((*a)->dir));
	ABin aux_e = (*a)->esq;
	ABin aux_d = (*a)->dir;
	free(*a);
	if (menor == NULL) *a = aux_e;
	else {
		*a = menor;
		(*a)->esq = aux_e;
		(*a)->dir = aux_d;
	}
}

// c)

int main() {
	return 0;
}