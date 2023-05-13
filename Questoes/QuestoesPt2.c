#include <stdlib.h>
#include <stdio.h>

// Listas Ligadas

typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt;


// Exercício 1:

int length (LInt l){
	int count = 0;
	while (l) {
		count++;
		l = l->prox;
	}
	return count;
}

// Exercício 2:

void freeL (LInt l) {
	LInt aux;
	while (l) {
		aux = l->prox;
		free(l);
		l = aux;
	}
}

// Exercício 3:

void imprimeL (LInt l) {
	while (l) {
		printf("%d\n", l->valor);
		l = l->prox;
	}
}

// Exercício 4:

LInt reverseL(LInt l) {
	LInt prev = NULL, next = NULL;
	while (l != NULL) { // enquanto não chegarmos ao fim da lista
		next = l->prox; // guarda o endereço do próximo nó
		l->prox = prev; // faz o nó atual apontar para o anterior
		prev = l; // atualiza o ponteiro para apontar para o atual
		l = next; // atualiza o ponteiro para apontar para o próximo nó
	}
	return prev; // retorna o novo início da lista (o último nó original)
}

// Exercício 5:

void insertOrd(LInt* l, int valor) {
	LInt new = malloc(sizeof(struct lligada));
	new->valor = valor;

	if (*l == NULL || valor < (*l)->valor) {
		new->prox = *l;
		*l = new;
	}
	else {
		LInt atual = *l;
		while (atual->prox != NULL && atual->prox->valor <= valor) {
			atual = atual->prox;
		}
		new->prox = atual->prox;
		atual->prox = new;
	}
}

// Exercício 6:

int removeOneOrd (LInt *l, int x){
	LInt ant = NULL, aux = *l;
	while (aux != NULL && aux->valor < x) {
		ant = aux;
		aux = aux->prox;
	}
	if (aux == NULL || aux->valor != x) return 1;
	if (ant == NULL) *l = aux->prox;
	else ant->prox = aux->prox;
	free(aux);
	return 0;
}

// Exercício 7:

void merge(LInt* r, LInt l1, LInt l2) {
	while (l1 != NULL || l2 != NULL) {
		if(l2 == NULL || l1 != NULL && l1->valor < l2->valor) {
			(*r) = l1;
			r = &((*r)->prox);
			l1 = l1->prox;
		}
		else {
			(*r) = l2;
			r = &((*r)->prox);
			l2= l2->prox;
		}
	}
}

// Exercício 8:

void splitQS(LInt l, int x, LInt *mx, LInt *Mx) {
	while (l != NULL) {
		if(l->valor < x) {
			(*mx) = l;
			(*Mx) = NULL;
			l = l->prox;
			mx = &((*mx)->prox);
		}
		else {
			(*Mx) = l;
			(*mx) = NULL;
			l = l->prox;
			Mx = &((*Mx)->prox);
		}
	}
}

// Exercício 9:

LInt parteAmeio (LInt *l){
	int divide = length(*l)/2;
	if (divide == 0) return NULL;
	LInt y = *l, ant = NULL;
	int i;
	for (i = 0; i < divide; i++) {
		ant = *l;
		*l = (*l)->prox;
	}
	ant->prox = NULL; // para que seja "cortada" a metade, l já só está a apontar para a sua metade
		// e o ponteiro de y tem que se manter no início de l, então temos o ant para "cortar"
	return y;
}

// Exercício 10:

int removeAll (LInt *l, int x){
	int count = 0;
	LInt aux = *l, ant = NULL;
	while (aux != NULL) {
		if (aux->valor == x) {
			if (ant == NULL) *l = (*l)->prox;
			else ant->prox = aux->prox;
			aux = aux->prox;
			count++;
		}
		else {
			ant = aux;
			aux = aux->prox;
		}
	}
	return count;
}

// Exercício 11: percorrer a lista duas vezes

int removeDups(LInt *l) {
	int count = 0;
	for(l; *l != NULL; l = &((*l)->prox)) {
		LInt prev = (*l), aux = (*l)->prox;
		for(aux; aux; aux = prev->prox) {
			if(aux->valor == (*l)->valor) {
				prev->prox = aux->prox;
				count++;
				free(aux);
			}
			else prev = aux;
		}
	}
	return count;
}

// Exercício 12:

int removeMaiorL (LInt *l){
	int maior = (*l)->valor;
	LInt ant = NULL, maxAnt = NULL, maxL = *l, lista = *l;
	while (lista != NULL) {
		if (lista->valor > maior) {
			maxAnt = ant;
			maxL = lista;
			maior = lista->valor;
		}
		ant = lista;
		lista = lista->prox;
	}
	if (maxAnt == NULL) (*l) = (*l)->prox;
	else maxAnt->prox = maxL->prox;
	return maior;
}

// Exercício 13:

void init (LInt *l) {
	if ((*l)->prox == NULL) {
		free(*l);
		*l = NULL;
		return;
	}
	LInt aux = *l, ant = NULL;
	while (aux->prox != NULL) {
		ant = aux;
		aux = aux->prox;
	}
	free(aux);
	ant->prox = NULL;
}

// Exercício 14:

void appendL (LInt *l, int x){
	if ((*l) == NULL) {
		(*l) = malloc(sizeof(struct lligada));
		(*l)->valor = x;
		(*l)->prox = NULL;
		return;
	}
	LInt aux = *l;
	while (aux->prox != NULL) aux = aux->prox;
	aux->prox = malloc(sizeof(struct lligada));
	aux->prox->valor = x;
	aux->prox->prox = NULL;
}

// Exercício 15:

void concatL (LInt *a, LInt b){
	if ((*a) == NULL) {
		(*a) = malloc(sizeof(b));
		(*a) = b;
		return;
	}
	LInt aux = *a;
	while (aux->prox != NULL) aux = aux->prox;
	aux->prox = malloc(sizeof(b));
	aux->prox = b;
}

// Exercício 16:

LInt cloneL (LInt l) {
	LInt r;
	LInt *sitio;
	sitio = &r;
	while (l != NULL) {
		*sitio = malloc(sizeof(struct lligada));
		(*sitio)->valor = l->valor;
		sitio = &((*sitio)->prox);
		l = l->prox;
	}
	*sitio = NULL;
	return r;
}

// Exercício 17:

LInt cloneRev (LInt l) {
	LInt r = NULL;
	while(l) {
		LInt aux = malloc(sizeof(struct lligada));
		aux->valor = l->valor;
		aux->prox = r;
		r = aux;
		l = l->prox;
	}
	return r;
}

// Exercício 18:

int maximo (LInt l){
	int max = l->valor;
	while (l != NULL) {
		if (l->valor > max) max = l->valor;
		l = l->prox;
	}
	return max;
}

// Exercício 19:

int take (int n, LInt *l){
	int i;
	for (i = 0; i < n && *l != NULL; i++, l = &((*l)->prox));
	if (*l == NULL) return i;
	while (*l != NULL) {
		LInt next = (*l)->prox;
		free(*l);
		*l = next;
	}
	return n;
}

// Exercício 20:

int drop (int n, LInt *l){
	int i;
	for (i = 0; i < n && *l != NULL; i++) {
		LInt aux = (*l)->prox;
		free(*l);
		*l = aux;
	}
	return i;
}

// Exercício 21:

LInt NForward (LInt l, int N){
	int i;
	for (i = 0; i < N; i++) l = l->prox;
	return l;
}

// Exercício 22:

int listToArray (LInt l, int v[], int N){
	int i;
	for (i = 0; i < N && l != NULL; i++, l = l->prox)
		v[i] = l->valor;
	return i;
}

// Exercício 23:

LInt arrayToList(int v[], int N) {
	if (N == 0) return NULL;

	LInt l = malloc(sizeof(struct lligada));
	l->valor = v[0];
	l->prox = NULL;

	LInt aux = l;
	int i;

	for (i = 1; i < N; i++) {
		aux->prox = malloc(sizeof(struct lligada));
		aux = aux->prox;
		aux->valor = v[i];
		aux->prox = NULL;
	}

	return l;
}


// Exercício 24:

LInt somasAcL (LInt l) {
	int sum = 0;
	LInt r = NULL, ult = NULL;
	while (l != NULL) {
		sum += l->valor;
		LInt new = malloc(sizeof(struct lligada));
		new->valor = sum;
		new->prox = NULL;
		if(r == NULL) r = ult = new;
		else ult = ult->prox = new;
		l = l->prox;
	}
	return r;
}

// Exercício 25:

void remreps(LInt l) {
	if (l != NULL) {
		while(l->prox) {
			if(l->prox->valor == l->valor) {
				LInt temp = l->prox;
				l->prox = temp->prox;
				free(temp);
			}
			else l = l->prox;
		}
	}
}

// Exercício 26:

LInt rotateL (LInt l){
	if (l == NULL || l->prox == NULL) return l;
	int first = l->valor;
	LInt aux = l;
	while (aux->prox != NULL) {
		aux->valor = aux->prox->valor;
		aux = aux->prox;
	}
	aux->valor = first;
	return l;
}

// Exercício 27:

LInt parte (LInt l) {
	LInt y = NULL, aux = NULL;
	while(l && l->prox) {
		if(y == NULL) y = aux = l->prox;
		else aux = aux->prox = l->prox;
		l = l->prox = l->prox->prox;
		aux->prox = NULL;
	}
	return y;
}

// Exercício 28:



// Exercício 29:



int main() {
	return 0;
}
