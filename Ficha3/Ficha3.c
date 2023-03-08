#include <stdio.h>
#include <string.h>

/*
Exercicio 1:

a)

Passos:
1º define-se um array com 15 elementos e os elementos estao apresentados
2º y é um apontador para a posiçao 0 do array de x
3º z é um apontador para a posiçao 3 do array de x
4º faz um ciclo for imprimindo os seguintes numeros:

1 1 4  (i=0), y aponta para a posiçao 1 de x, z aponta para a posiçao 6 de x
2 2 6  (i=1), y aponta para a posiçao 2 de x, z aponta para a posiçao 8 de x
3 3 8  (i=2), y aponta para a posiçao 3 de x, z aponta para a posiçao 10 de x
4 4 10 (i=3), y aponta para a posiçao 4 de x, z aponta para a posiçao 12 de x
5 5 12 (i=4), y aponta para a posiçao 5 de x, z aponta para a posiçao 14 de x

b)

Passos:
1º i = 3, j = 5, a e b apontadores para int
2º a aponta para 3, b aponta para 5
3º i = 4 e a continua a apontar para o i, ou seja, a aponta para 4
4º j = 4 + 5 = 9 e b aponta para 9
5º b passa a apontar para o i que é 4
6º j = 9 + 4 = 13
7º imprime o numero: 13
*/

// Exercicio 2:

void swapM (int *x, int *y) {
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

// Exercicio 3:

void swap (int v[], int i, int j) {
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

// Exercicio 4:

int soma (int v[], int N) {
    int soma = 0;
    for (int i = 0; i < N; i++) {
        soma += v[i];
    }
    return soma;
}

// Exercicio 5:

// Usando o Exercicio 2:
void inverteArray2 (int v[], int N) {  
    for (int i = 0; i < N/2; i++) {
        swapM(&v[i],&v[N-1-i]);
    }
}

// Usando o Exercicio 3:
void inverteArray3 (int v[], int N) {
    for (int i = 0; i < N/2; i++) {
        swap(v,i,N-1-i);
    }
}

// Exercicio 6:

int maximum (int v[], int N, int *m) {
    if (N < 0) return 1;
    else {
        for (int i = 0; i < N; i++) {
            if (i == 0) *m = v[i];
            else if (v[i] > *m) *m = v[i];
        }
        return 0;
    }
}

// Exercicio 7:

void quadrados (int q[],int N) {
    for (int i = 0; i < N; i++) {
        q[i] = (i-1)*(i-1) + 2 * (i-1) + 1;
    }
}

// Exercicio 8:

// a)

void pascal (int v[], int N) {
    if (N == 1) v[0] = 1;
    else {
        int linhaAnterior[N-1];
        pascal(linhaAnterior,N-1);
        for (int i = 0; i < N; i++) {
            if (i == 0 || i == N-1) v[i] = 1;
            else v[i] = linhaAnterior[i] + linhaAnterior[i-1];
        }
    }
}

//b)

void pascalB (int v[], int N) {
    if (N == 1) {v[0] = 1; printf("%d\n",v[0]);}
    else {
        int linhaAnterior[N-1];
        pascalB(linhaAnterior,N-1);
        for (int i = 0; i < N; i++) {
            if (i == 0 || i == N-1) v[i] = 1;
            else v[i] = linhaAnterior[i] + linhaAnterior[i-1];
            printf("%d ",v[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    int v[50], tamanho;
    printf("Introduz o numero da pergunta: ");
    char opcao = getchar();

    switch(opcao) {

        case '2':{
        printf("Introduz dois numeros: ");
        scanf("%d %d", &n, &m);
        swapM(&n,&m);
        printf("%d %d\n", n, m);
        break;
        }

        case '3':{

        printf("Introduz o tamanho do array: ");
        scanf("%d", &tamanho);
        printf("Introduz um array com espaços: ");
        for (int i = 0; i < tamanho; i++) {
            scanf("%d", &v[i]);
        }
        printf("Introduz as posiçoes a serem trocadas: ");
        scanf("%d %d", &n, &m);
        swap(v,n,m);
        for(int j = 0; j < tamanho; j++) {
            printf("%d", v[j]);
        }
        printf("\n");
        break;
        }

        case '4':{
        
        printf("Introduz o tamanho do array: ");
        scanf("%d", &tamanho);
        printf("Introduz um array com espaços: ");
        for (int i = 0; i < tamanho; i++) {
            scanf("%d", &v[i]);
        }
        printf("A soma dos elementos do array é: %d\n", soma(v,tamanho));
        break;
        }

        case '5':{
        
        printf("Introduz o tamanho do array: ");
        scanf("%d", &tamanho);
        printf("Introduz um array com espaços: ");
        for (int i = 0; i < tamanho; i++) {
            scanf("%d", &v[i]);
        }
        //Das duas formas:
        //inverteArray2(v,tamanho);
        inverteArray3(v,tamanho);
        for(int j = 0; j < tamanho; j++) {
            printf("%d", v[j]);
        }
        printf("\n");
        break;
        }

        case '6':{
        
        printf("Introduz o tamanho do array: ");
        scanf("%d", &tamanho);
        printf("Introduz um array com espaços: ");
        for (int i = 0; i < tamanho; i++) {
            scanf("%d", &v[i]);
        }
        int max;
        int maximo = maximum (v,tamanho,&max);
        if (maximo) printf("Tamanho do aray menor que 0\n");
        else printf("A maior elemento do array é: %d\n",max);
        break;
        }

        case '7':{
        
        printf("Introduz o tamanho do array: ");
        scanf("%d", &tamanho);
        quadrados(v,tamanho);
        printf("O quadrado dos primeiros %d numeros naturais e 0 sao: ", tamanho);
        for(int j = 0; j < tamanho; j++) {
            printf("%d ", v[j]);
        }
        printf("\n");
        break;
        }

        case '8':{
        
        printf("Introduz a linha: ");
        scanf("%d", &tamanho);

        //alinea a:
        pascal(v,tamanho);
        printf("O %d-ésima linha do triângulo de Pascal tem como valores: ", tamanho);
        for(int j = 0; j < tamanho; j++) {
            printf("%d ", v[j]);
        }
        printf("\n");

        //alinea b:
        pascalB(v,tamanho);
        printf("\n");
        break;
        }

        default:
        printf("Nao inseriste um numero valido :)\n");
        
    }
    return 0;
}