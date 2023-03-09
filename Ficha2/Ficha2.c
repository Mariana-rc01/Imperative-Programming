#include <stdio.h>
#include <stdlib.h>

// Exercicio 1:

float multInt1 (int n, float m) {
    float r = 0;
    for (int i = 0; i < n; i++) {
        r += m;
    }
    return r;
}

// Exercicio 2:

float multInt2 (int n, float m) {
    float r = 0;
    while (n >= 1) {
        if (n % 2 == 1) r += m;
        n /= 2;
        m *= 2;
    }
    return r;
}

// Conta quantas operaçoes (entre floats) sao feitas:

float multInt2M (int n, float m) {
    float r = 0;
    int i = 0;
    while (n >= 1) {
        if (n % 2 == 1) {
            r += m;
            i++;}
        n /= 2;
        m *= 2;
    }
    printf ("%d\n", i);
    return r;
}

// ou, com apontadores

float multInt2MExtra (int n, float m, int *i) {
    float r = 0;
    *i = 0;
    while (n >= 1) {
        if (n % 2 == 1) {
            r += m;
            (*i)++;}
        n /= 2;
        m *= 2;
    }
    printf ("%d\n", *i);
    return r;
}

// Exercicio 3:
// O maior vai ser sempre o a e o menor o b

int mdc1 (int a, int b) {
    int d;
    if (a < b) {
        d = a;
        a = b;
        b = d;
    }
    for (int i = 1; i <= b; i++) {
        if (a % i == 0 && b % i == 0) d = i;
    }
    return d;
}

// Exercicio 4:

int mdc2 (int a, int b) {
    while ((a != 0 || b != 0)) {
        if (a > b) a -= b;
        else if (a < b) b -= a;
        else return a;
    }
    if (a == 0) return b;
    else return a;
}

// Conta quantas iteraçoes foram feitas:

int mdc2M (int a, int b) {
    int i = 0;
    while ((a != 0 || b != 0)) {
        if (a > b) a -= b;
        else if (a < b) b -= a;
        else {printf("%d\n", i+1);return a;}
        i++;
    }
    printf("%d\n", i);
    if (a == 0) return b;
    else return a;
}

// Exercicio 5:

int mdc3 (int a, int b) {
    int i = 0;
    while ((a != 0 && b != 0)) {
        if (a > b) a %= b;
        else if (a < b) b %= a;
        else {printf("%d\n",i+1);return a;}
        i++;
    }
    printf("%d\n",i);
    if (a == 0) return b;  
    else return a;
}

// Exercicio 6:

// a)

int fib1 (int n) {
    if (n < 2) return 1;
    else return fib1 (n-1) + fib1 (n-2);
}

// b)

int fib2 (int n) {
    int a = 1, b = 1;
    int aux;
    if (n < 2) return 1;
    for (int i = 2; i <= n; i++) {
        aux = a;
        a += b;
        b = aux;
    }
    return a;
}

int main () {
    
    int n, i;
    float m;
    int count = 0;

    printf("Introduz o numero da pergunta: ");
    char opcao = getchar();

    switch(opcao) {

        case '1':{
        printf("Introduz dois numeros: ");
        scanf("%d %f", &n, &m);
        printf("O produto de %d por %f é %f.\n", n, m, multInt1(n,m));
        break;
        }

        case '2':{
        printf("Introduz dois numeros: ");
        scanf("%d %f", &n, &m);
        printf("O produto de %d por %f é %f.\n", n, m, multInt2MExtra(n,m,&count));
        break;
        }

        case '3':{
        printf("Introduz dois numeros: ");
        scanf("%d %d", &n, &i);
        printf("O máximo divisor comum entre %d e %d é %d.\n", n, i, mdc1(n,i));
        break;
        }

        case '4':{
        printf("Introduz dois numeros: ");
        scanf("%d %d", &n, &i);
        printf("O máximo divisor comum entre %d e %d é %d.\n", n, i, mdc2M(n,i));
        break;
        }

        case '5':{
        printf("Introduz dois numeros: ");
        scanf("%d %d", &n, &i);
        printf("O máximo divisor comum entre %d e %d é %d.\n", n, i, mdc3(n,i));
        break;
        }

        case '6':{
        printf("Introduz um numero: ");
        scanf("%d", &n);
        printf("O %d-ésimo número da sequência de Fibonacci é %d.\n", n, fib1(n));
        break;
        }
    }    
    return 0;
}