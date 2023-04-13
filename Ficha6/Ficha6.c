#include <stdlib.h>

// Exercicio 1:
#define Max 3

// sp aponta para o valor seguinte

typedef struct staticStack {
    int sp;
    int values [Max];
} STACK, *SStack;

// a)

void SinitStack (SStack s) {
    s->sp = 0; //(*s).sp = 0;
}

// b)

int SisEmpty (SStack s) {
    return (s->sp == 0);
}

// c)

int Spush (SStack s, int x) {
    if (s->sp == Max) return 1;
    s->values[s->sp] = x;
    s->sp++;
    return 0;
}

// d)

int Spop (SStack s, int *x) {
    if (s->sp == 0) return 1;
    *x = s->values[--s->sp];
    return 0;
}

// e)

int Stop (SStack s, int *x) {
    if (s->sp == 0) return 1;
    *x = s->values[s->sp-1];
    return 0;
}

// Exercicio 2:

typedef struct staticQueue {
    int front; // primeiro elemento a entrar
    int length;
    int values [Max];
} QUEUE, *SQueue;

// a)

void SinitQueue (SQueue q) {
    q->front = 0;
    q->length = 0;
}

// b)

int SisEmptyQ (SQueue q) {
    return (q->length == 0);
}

// c)

int Senqueue (SQueue q, int x) {
    if (q->length == Max) return 1;
    int nextFree = (q->length + q->front) % Max;
    q->values[nextFree] = x;
    q->length++;
    return 0;
}

// d)

int Sdequeue (SQueue q, int *x) {
    if (SisEmptyQ(q)) return 1;
    *x = q->values[q->front];
    q->front = q->front + 1;
    if (q->front == Max) q->front = 0;
    q->length--;
    return 0;
}

// e)

int Sfront (SQueue q, int *x) {
    if (SisEmptyQ(q)) return 1;
    *x = q->values[q->front];
    return 0;
}

// Exercicio 3:

typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;

// a)

void DinitStack(DStack s) {
    s->sp = 0;
    s->size = Max;
    s->values = malloc(sizeof(int)*(s->size));
}

// b)

int DisEmpty (DStack s) {
    return (s->sp == 0);
}

// c)

int dupStack (DStack s) {
    int *new = malloc(sizeof(int)*(s->size)*2);
    if (new == NULL) return 1;
    int i;
    for (i = 0; i < s->sp; i++) {
        new[i] = s->values[i];
    }
    free(s->values);
    s->values = new;
    s->size *= 2;
    return 0;
}

int Dpush (DStack s, int x) {
    if (s->sp == s->size) {
        if (dupStack(s)) return 1;
    }
    s->values[s->sp++] = x;
    return 0;
}

// Com realloc

int Dpush1 (DStack s, int x) {
    if (s->sp == s->size) {
        int *new = realloc(s->values, sizeof(int)*s->size*2);
        s->size *= 2;
        s->values = new;
    }
    s->values[s->sp++] = x;
    return 0;
}


// d)

int Dpop (DStack s, int *x) {
    if (s->sp == 0) return 1;
    *x = s->values[--s->sp];
    return 0;
}

// e)

int Dtop (DStack s, int *x) {
    if (s->sp == 0) return 1;
    *x = s->values[s->sp-1];
    return 0;
}

typedef struct dinQueue {
    int size; // guarda o tamanho do array values
    int front;
    int length;
    int *values;
} *DQueue;

// a)

void DinitQueue (DQueue q) {
    q->front = 0;
    q->length = 0;
    q->size = 0;
}

// b)

int DisEmptyQ (DQueue q) {
    if (q->length == 0) return 1;
    else return 0;
}

// c)

int dupQueue (DQueue q) {
    int *new = malloc(sizeof(int)*(q->size)*2);
    if (new == NULL) return 1;
    int i, j;
    for (i = 0; i < q->length; i++) {
        for (j = q->front; j < q->length + q->front; j++) {
            new[i] = q->values[j];
        }
    }
    free(q->values);
    q->values = new;
    q->size *= 2;
    q->front = 0;
    return 0;
}

int Denqueue (DQueue q, int x) {
    if (q->length == q->size) {
        if (dupQueue(q)) return 1;
        q->size *= 2;
    }
    int nextFree = q->length + q->front;
    q->values[nextFree] = x;
    q->length++;
    return 0;
}

// d)

int Ddequeue (DQueue q, int *x) {
    if (DisEmptyQ(q)) return 1;
    *x = q->values[q->front];
    q->front = q->front + 1;
    if (q->front == q->size) {
        int save = q->front;
        if (dupQueue(q)) return 1;
        q->size *= 2;
        q->front = save;
    }
    else q->front = q->front + 1;
    q->length--;
    return 0;
}

// e)

int Dfront (DQueue q, int *x) {
    if (DisEmptyQ(q)) return 1;
    *x = q->values[q->front];
    return 0;
}

int main() {
    STACK s1;
    SStack sp1 = &s1;
    SinitStack(sp1);
}