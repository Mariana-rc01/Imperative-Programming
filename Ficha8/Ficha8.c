#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct slist {
	int valor;
	struct slist * prox;
} * LInt;

// Acrescenta um novo nodo à cabeça da lista
LInt newLInt (int x, LInt xs) {
	LInt r = malloc (sizeof(struct slist));
	if (r != NULL) {
		r->valor = x; r->prox = xs;
	}
	return r;
}

typedef LInt Stack;

// Exercícios sobre Stacks

void initStack (Stack *s) {
	*s = NULL;
}

int SisEmpty (Stack s) {
	return (s == NULL);
}

int push (Stack *s, int x) {
	Stack new = newLInt(x, *s);
	if (new == NULL) return 1;
	*s = new;
	return 0;
}

int pop (Stack *s, int *x) {
	if (SisEmpty(*s)) return 1;
	*x = (*s)->valor;
	Stack aux = (*s)->prox;
	free(*s);
	*s = aux;
	return 0;
}

int top (Stack s, int *x) {
	if (SisEmpty(s)) return 1;
	*x = s->valor;
	return 0;
}

// Exercícios sobre Queues

typedef struct {
	LInt inicio;
	LInt fim;
} Queue;

void initQueue (Queue *q) {
	q->inicio = NULL;
	q->fim = NULL;
}

int QisEmpty (Queue q) {
	return (q.inicio == NULL && q.fim == NULL);
}

int enqueue (Queue *q, int x) {
	LInt new = newLInt(x, NULL);
	if (new == NULL) return 1;
	if (QisEmpty(*q)) {q->fim = q->inicio = new;}
	else {
		q->fim->prox = new;
		q->fim = new;
	}
	return 0;
}

int dequeue (Queue *q, int *x) {
	if (QisEmpty(*q)) return 1;
	*x = q->inicio->valor;
	LInt aux = q->inicio->prox;
	free(q->inicio);
	q->inicio = aux;
	if (q->inicio == NULL) q->fim = NULL; // Caso haja apenas um elemento e ele tenha sido retirado
	return 0;
}

int front (Queue q, int *x) {
	if (QisEmpty(q)) return 1;
	*x = q.inicio->valor;
	return 0;
}

// Exercícios sobre Queues usando uma lista circular

typedef LInt QueueC;


int main() {
	Stack s1;
	initStack(&s1);
}