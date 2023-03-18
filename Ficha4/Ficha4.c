#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 1) Funções sobre strings

// Exercicio 1:

int isVogal(char l) {
    char c = toupper(l);
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;
    else return 0;
}

int contaVogais(char *s) {
    int contador = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if (isVogal(s[i])) contador++;
    }
    return contador;
}

// Exercicio 2:

// Usando um array auxiliar:
int retiraVogaisRep(char *s) {
    int tamanho = strlen(s);
    char sAux[tamanho+1];
    int contador = 0;
    int j = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if (s[i] == s[i+1] && isVogal(s[i])) {
            contador++;}
        else {
            sAux[j] = s[i]; // sAux[j++] = s[i]
            j++;
        }
    }
    sAux[j] = '\0';
    strcpy(s,sAux); // copia a string sAux para a string s
    return contador;
}

// Sem usar um array auxiliar:

int retiraVogaisRep1(char *s) {
    int tamanho = strlen(s);
    int contador = 0;
    int j = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if (s[i] == s[i+1] && isVogal(s[i])) {
            contador++;}
        else {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
    return contador;
}

// Exercicio 3:

int duplicaVogais (char *s) {
    char aux[1001];
    int j = 0;
    int contador = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isVogal(s[i])) {
            contador++;
            aux[j] = s[i];
            aux[j+1] = s[i];
            j+=2;
        }
        else {
            aux[j] = s[i];
            j++;
        }
    }
    aux[j] = '\0';
    strcpy(s,aux);
    return contador;
}

// Sem usar um array auxiliar:

int duplicaVogais1 (char *s) {
    int tamanho = strlen(s);
    int j = 2*tamanho + 1;
    int contador = 0;
    for (int i = tamanho; i >= 0; i--) {
        if (isVogal(s[i])) {
            contador++;
            s[--j] = s[i];
            s[--j] = s[i];
        }
        else {
            s[--j] = s[i];
        }
    }
    return contador;
}

// 2) Arrays ordenados

// Exercicio 1: (opçao 4)

int ordenado (int v[], int N) {
    for (int i = 0; i < N; i++) {
        if (v[i] > v[i+1]) return 0;
    }
    return 1;
}

// Exercicio 2: (opçao 5)

void merge (int a[], int na, int b[], int nb, int r[]) {
    int j = 0, l = 0;
    for (int i = 0; i < na+nb; i++) {

        if (j == na && l < nb) {
            r[i] = b[l]; l++;
        }        

        if (l == nb && l < nb) {
            r[i] = a[j]; j++;
        }

        if (j < na && l < nb) {
            if (a[j] >= b[l]) {r[i] = b[l]; l++;}
            else {r[i] = a[j]; j++;}
        }
    }
}

// Exercicio 3: (opçao 6)

int partition (int v[], int N, int x) {
    int aux[N];
    int j = 0, contador = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] <= x) {
            aux[j] = v[i];
            j++;
            contador++;}
    }

    for (int i = 0; i < N; i++) {
        if (v[i] > x) {aux[j] = v[i]; j++;}
    }
    
    for(int i = 0; i < N; i++) {
        v[i] = aux[i];
    }

    return contador;
}

// Sem usar um array auxiliar:

// 1ª forma:

int partition1 (int v[], int N, int x) {
    int j = 0, contador = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] <= x) {
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            j++;
            contador++;
        }
    }
    return contador;
}

// 2ª forma:

int partition2 (int v[], int N, int x) {
    int a = 0, b = 0;
    for(b = 0; b < N; b++) {
        if (v[b] <= x) {
            int aux = v[b];
            v[b] = v[a];
            v[a] = aux;
            a++;
        }
    }
    return a;
}

// Main

int main() {
    int n, m;
    int v[50], v1[50], r[1001], tamanho, tamanho1;
    char s[1001];
    printf("Introduza o numero da pergunta: ");
    char opcao = getchar();
    getchar();

    switch(opcao) {

        case '1':{
        printf("Introduza uma frase: ");
        fgets(s,1001,stdin);
        printf("A frase introduzida tem %d vogais.\n", contaVogais(s));
        break;
        }

        case '2':{
        printf("Introduza uma frase: ");
        fgets(s,1001,stdin);
        n = retiraVogaisRep1(s);
        printf("Da frase introduzida foram retiradas %d vogais repetidas.\n Frase sem vogais repetidas: ", n);
        for(int i = 0; s[i] != '\0'; i++) {
            printf("%c",s[i]);
        }
        break;
        }

        case '3':{
        printf("Introduza uma frase: ");
        fgets(s,1001,stdin);
        n = duplicaVogais1(s);
        printf("Da frase introduzida foram acrescentadas %d vogais repetidas.\n Frase com vogais duplicadas: ", n);
        for(int i = 0; s[i] != '\0'; i++) {
            printf("%c",s[i]);
        }
        break;
        }

        case '4':{
        printf("Introduza o tamanho do array: ");
        scanf("%d", &tamanho);
        printf("Introduza um array com espaços: ");
        for (int i = 0; i < tamanho; i++) {
            scanf("%d", &v[i]);
        }
        if (ordenado(v,tamanho)) printf("Os elementos do array estao por ordem crescente.\n");
        else printf("Os elementos do array nao estao por ordem crescente.\n");
        break;
        }

        case '5':{
        printf("Introduza o tamanho do 1º array: ");
        scanf("%d", &tamanho);
        printf("Introduza o 1º array com espaços: ");
        for (int i = 0; i < tamanho; i++) {
            scanf("%d", &v[i]);
        }

        printf("Introduza o tamanho do 2º array: ");
        scanf("%d", &tamanho1);
        printf("Introduza o 2º array com espaços: ");
        for (int i = 0; i < tamanho1; i++) {
            scanf("%d", &v1[i]);
        }

        merge(v,tamanho,v1,tamanho1,r);

        printf("Array ordenado dos dois arrays anteriores: ");
        for(int i = 0; i < tamanho+tamanho1; i++) {
            printf("%d ",r[i]);
        }
        printf("\n");
        break;
        }

        case '6':{
        printf("Introduza um numero inteiro: ");
        scanf("%d", &m);
        printf("Introduza o tamanho do array: ");
        scanf("%d", &tamanho);
        printf("Introduza um array com espaços: ");
        for (int i = 0; i < tamanho; i++) {
            scanf("%d", &v[i]);
        }
        n = partition2(v,tamanho,m);
        printf("%d elementos ficaram na primeira parte do array.\n Array reorganizado: \n",n);
        for(int i = 0; i < tamanho; i++) {
            printf("%d ",v[i]);
        }
        printf("\n");
        break;
        }

        default:
        printf("Nao inseriu um numero valido :)\n");
    }

    return 0;
}