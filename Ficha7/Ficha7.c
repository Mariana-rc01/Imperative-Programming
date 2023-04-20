#include <stdlib.h>
#include <string.h>

typedef struct celula {
	char *palavra;
	int ocorr;
	struct celula * prox;
} * Palavras;

// Exercício 1:

void libertaLista (Palavras p) {
	while(p) {
		free(p);
		p = p->prox;
	}
}

// Exercício 2:

int quantasP (Palavras l) {
	int count = 0;
	while (l) {
		count++;
		l = l->prox;
	}
	return count;
}

// Para retornar quantas palavras existem

int quantasPI (Palavras l) {
	int count = 0;
	while (l) {
		count+=l->ocorr;
		l = l->prox;
	}
	return count;
}

// Exercício 3:

void listaPal (Palavras l) {
	while (l) {
		printf("%s %d\n", l->palavra, l->ocorr);
		l = l->prox;
	}
}

// Exercício 4:

char* ultima (Palavras l) {
  char* ult;
	while (l) {
		if (l->prox == NULL) {
		  ult = malloc(strlen(l->palavra));
		  strcpy(ult, l->palavra);
		}
		l = l->prox;
	}
	return ult;
}

// Exercicio 5:

Palavras acrescentaInicio (Palavras l, char *p) {
	Palavras new = malloc (sizeof(struct celula));
	new->palavra = malloc (strlen(p)+1);
	strcpy(new->palavra, p);
	new->ocorr = 1;
	new->prox = l;
	return new;
}

// Exercicio 6:

Palavras acrescentaFim (Palavras l, char *p) {
	Palavras new = malloc (sizeof(struct celula));
	new->palavra = malloc (strlen(p)+1);
	new->ocorr = 1;
	new->prox = NULL;
	strcpy(new->palavra,p);

	if (l == NULL) return new;

	Palavras atual = l;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = new;

    return l;
}

// Exercicio 7:

// acrescentar no início

Palavras acrescenta (Palavras l, char *p) {
	Palavras atual = l;
	while (atual) {
		if (strcmp(atual->palavra, p) == 0) {
			atual->ocorr++;
			break;
		}
		atual = atual->prox;
	}
	if (atual->prox == NULL) acrescentaInicio (l,p);
	return l;
}

// Exercicio 8:

struct celula * maisFreq (Palavras l){
    int maior = -1;
    Palavras atual = l;
    while(atual != NULL){
        if(atual->ocorr > maior) maior = atual->ocorr;
        atual = atual->prox;
    }
    while(l != NULL){
        if(l->ocorr == maior) return l; 
        l = l->prox;
    }
}
