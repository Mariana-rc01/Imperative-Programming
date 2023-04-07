// Questoes 1ª Parte

// Nao saiem 39 a 41 e 47 a 50

#include <stdio.h>
#include <assert.h>
#include <string.h>

// Exercicio 1:
/*
int main() {
    int maior = -99999999999;
    while (1) {
        int n;
        assert(scanf("%d", &n) == 1);
        if (n == 0) break;
        if (n > maior) maior = n;
    }
    printf("Maior numero da sequencia: %d\n", maior);
    return 0;
}
*/

// Exercicio 2:
/*
int main() {
    float media = 0, soma = 0;
    int contador = 0;
    while (1) {
        int n;
        assert(scanf("%d",&n) == 1);
        if (n == 0) break;
        soma += n;
        contador++;
    }
    media = soma/contador;
    printf("%f\n", media);
    return 0;
}
*/

// Exercicio 3:
/*
int main() {
    int n1 = -99999999, n2 = -99999998;
    while (1) {
        int n;
        assert(scanf("%d",&n) == 1);
        if (n == 0) break;
        if (n > n1) {
            n2 = n1;
            n1 = n;
        }
        else if (n > n2) n2 = n;
    }
    printf("Segundo maior elemento: %d\n", n2);
    return 0;
}
*/

// Exercicio 4:

int bitsUm (unsigned int n) {
    int contador = 0;
    while (n) {
        contador += (n % 2);
        n /= 2;
    }
    return contador;
}

// Exercicio 5:

int trailingZ (unsigned int n) {
    if (n == 0) return 32;
    int contador =  0;
    while (n%2 == 0) {
        contador++;
        n /= 2;
    }
    return contador;
}

// Exercicio 6:

int qDig (int n) {
    int r = 0;
    while(n%10 > 0) {
        r++;
        n/=10;
    }
    return r;
}

// Exercicio 7:

char *mystrcat(char s1[], char s2[]) {
    int i, j;
    for (i = strlen(s1), j = 0; s2[j] != '\0'; i++, j++) {
        s1[i] = s2[j];
    }
    s1[i] = '\0';
    return s1;
}

// Exercicio 8:

char *mystrcpy(char s1[], const char s2[]) {
    int i;
    for (i = 0; s2[i] != '\0'; i++) {
        s1[i] = s2[i]; 
    }
    s1[i] = '\0';
    return s1;
}

// Exercicio 9:

int mystrcmp(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) i++;
    return s1[i] - s2[i];
}

// Exercicio 10:

char *mystrstr (char s1[], char s2[]) {
    int n1, n2, encontrou = 1;
    int tamanho1 = strlen(s1);
    int tamanho2 = strlen(s2);
    for (n1 = 0; n1 < tamanho1; n1++) {
        encontrou = 1;
        for (n2 = 0; n2 < tamanho2; n2++) {
            // necessario +n2 para continuar a ver a string n1
            if (s2[n2] != s1[n1+n2]) {encontrou = 0; break;}
        }
        if (encontrou == 1) break;
    }
    if (encontrou == 1) return s1+n1;
    return NULL;
}

// Exercicio 11:

void strrev (char s[]) {
    int tamanho = strlen(s);
    int i;
    for(i = 0; i < (tamanho/2); i++) {
        char aux = s[i];
        s[i] = s[tamanho - i -1];
        s[tamanho-i-1] = aux;
    }
}

// Exercicio 12:

void strnoV (char s[]){
    int j = 0, i;
    for(i = 0; s[i] != '\0'; i++) {
        int c = toupper(s[i]);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            continue;
        else s[j++] = s[i];
    }
    s[j] = '\0';
}

// Exercicio 13:
void mexe(char s[], int N) {
    int i;
    for(i = N; s[i]; i++)
        s[i] = s[i+1];
}

int isSpace(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

void truncW (char t[], int n) {
    int tamanho = 0, i = 0;
    while(t[i]) {
        if(isSpace(t[i])) {
            tamanho = 0;
            i++;
        }
        else {
            tamanho++;
            if(tamanho > n) mexe(t, i);
            else i++;
        }
    } 
}

// Exericico 14:

int conta (char c, char s[]) {
    int count = 0, i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) count++;
    }
    return count;
}

char charMaisfreq (char s[]) {
    char maisFreq = 0;
    int freqMax = 0, i;
    for(i = 0; s[i] != '\0'; i++) {
        if (conta(s[i],s) > freqMax) {
            freqMax = conta(s[i],s);
            maisFreq = s[i];
        }
    }
    return maisFreq;
}

// Exercicio 15:

int iguaisConsecutivos (char s[]) {
    int maximo = 0, count = 1, i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == s[i+1]) count ++;
        else {
            if (count > maximo) {
            maximo = count;
            count = 1;
            }
        }
    }
    return maximo;
}

// Exercicio 16:

// ver se os anteriores sao todos diferentes, falso caso nao sejam
int anteriores (char s[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (s[i] == s[n]) return 0;
    }
    
    return 1;
}

int difConsecutivos (char s[]) {
    int maximo = 0, count, i, j;
    for (i = 0; s[i] !='\0'; i++) {
        count = 0;
        for (j = 0; s[i+j] != '\0'; j++) {
            if (anteriores (s+i, j)) count++; // s+i, começa a ver apenas naquele valor
            else break;
        }
        if (count > maximo) maximo = count;
    }
    return maximo;
}


// Exercicio 17:

int maiorPrefixo(char s1[], char s2[]) {
    int count = 0, i;
    int minimo = strlen(s1) > strlen(s2) ? strlen(s2) : strlen(s1);
    for (i = 0; i < minimo; i++) {
        if (s1[i] == s2[i]) count++;
        else break;
    }
    return count;
}

// Exercicio 18:

int maiorSufixo (char s1 [], char s2 []) {
    int count = 0, i;
    int minimo = strlen(s1) > strlen(s2) ? strlen(s2) : strlen(s1);
    for (i = 1; i <= minimo ; i++) {
        if (s1[strlen(s1) - i] == s2[strlen(s2) - i]) count++;
        else break;
    }
    return count;
}

// Exercicios 19:

int sufPref (char s1[], char s2[]) {
    int j = 0, i;
    for (i = 0; s1[i]; i++) {
        if (s1[i] == s2[j]) j++;
        else j = 0;
    }
    return j;
}

// Exercicio 20:
      
int contaPal (char s[]) {
    int count = 0, anterior = 0, i; 
    for (i = 0; s[i]; i++) {
        if (isSpace(s[i]) && anterior) count++;
        else if (isSpace(s[i])) anterior = 0; // o anterior deixa de ser uma letra
        else anterior = 1;
    }
    return count + anterior;
}

// Exercicio 21:

int contaVogais (char s[]) {
    int count = 0, i;
    for (i = 0; s[i]; i++) {
        char c = toupper(s[i]);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') count++;
    }
    return count;
}

// Exercicio 22:

int search (char c, char s[]) {
    int i;
    for (i = 0; s[i]; i++) {
        if (s[i] == c) return 1;
    }
    return 0;
}

int contida (char a[], char b[]) {
    int i = 0;
    for (i = 0; a[i]; i++) {
        if (search (a[i],b)) continue;
        else return 0;
    }
    return 1;
}

// Exercicio 23:

int palindroma (char s[]) {
    int tamanho = strlen(s), i;
    for (i = 0; i < tamanho/2; i++) {
        if (s[i] == s[tamanho - i -1]) continue;
        else return 0;
    }
    return 1;
}

// Exercicio 24:

int remRep (char x[]) {
    int count = 0,i,j = 0;
    for (i = 0; x[i]; i++) {
        if (x[i] == x[i+1])
            continue;
        else {
            x[j++] = x[i];
            count++;
        }
    }
    x[j] = '\0';
    return count;
}

// Exercicio 25:

int limpaEspacos (char t[]) {
    int j=0, i;
    for (i = 0; t[i]; i++) {
        if (t[i] == ' ' && t[i+1] == ' ')
            continue;
        else t[j++] = t[i];
    }
    t[j] = '\0';
    return j;
}

// Exercicio 26:

void insere (int v[], int n, int x){
    while (n > 0 && v[n-1] >= x) {
        v[n] = v[n-1];
        n--;
    }
    v[n] = x;
}

// Exercicio 27:

void merge (int r [], int a[], int b[], int na, int nb){
    int ta = 0, tb = 0, i;
    for (i = 0; i < na+nb; i++) {
       if (ta == na && tb < nb) {
           r[i] = b[tb];
           tb++;
       }
       
       if (tb == nb && ta < na) {
           r[i] = a[ta];
           ta++;
       }
       
       if (ta < na && tb < nb) {
           if (a[ta] < b[tb]) {
               r[i] = a[ta];
               ta++;
           }
           else {
               r[i] = b[tb];
               tb++;
               }
        }
    }
}

// Exercicio 28:

int crescente (int a[], int i, int j){
   for(i; i < j; i++) {
       if (a[i] > a[i+1]) return 0;
    }
    return 1;
}

// Exercicio 29:

int retiraNeg (int v[], int N){
    int j = 0, i;
    for (i = 0; i < N; i++) {
        if (v[i] >= 0) v[j++] = v[i];
    }
    return j;
}

// Exercicio 30:

int menosFreq (int v[], int N){
    int count = 1, mfreq = N, posicao = v[0], i;
    for (i = 1; i < N; i++) {
        if (v[i] == v[i-1]) count++;
       else {
           if (count < mfreq) {
               mfreq = count;
               posicao = v[i-1];
           }
           count = 1;
       }
    }
    if(count < mfreq) {
        mfreq = count;
        posicao = v[i-1];
    }
   return posicao;
}

// Exercicio 31:

int maisFreq (int v[], int N){
    int count = 1, mfreq = 0, posicao = v[0], i;
    for (i = 1; i < N; i++) {
        if (v[i] == v[i-1]) count++;
       else {
           if (count > mfreq) {
               mfreq = count;
               posicao = v[i-1];
           }
           count = 1;
       }
    }
    if(count > mfreq) {
        mfreq = count;
        posicao = v[i-1];
    }
   return posicao;
}

// Exercicio 32:

int maxCresc (int v[], int N) {
    int i, count = 1, max = -1;
    for (i = 0; i < N; i++) {
        if (v[i] <= v[i+1]) count++;
        else {
            if (count > max) max = count;
            count = 1;
        }
    }
    if (count > max) max = count;
    return max;
}

// Exercicio 33:

int search1 (int v[], int x, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (v[i] == x) return 1;
    }
    return 0;
}

int elimRep (int v[], int n) {
    int j = 0, i;
    for (i = 0; i < n; i++) {
        if (search1(v+i+1, v[i], n-i-1))
            continue;
        else v[j++] = v[i];
    }
    return j;
}

// Exercicio 34:

int elimRepOrd (int v[], int n) {
    int j = 1, i;
    for (i = 1; i < n; i++) {
        if (v[i] == v[i-1]) continue;
        else v[j++] = v[i];
    }
    return j;
}

// Exercicio 35:

int comunsOrd (int a[], int na, int b[], int nb){
    int count = 0, i = 0, j = 0;
    while (i < na && j < nb) {
        if (a[i] == b[j]) {
            count++;
            i++;
            j++;
        }
        else if (a[i] < b[j]) i++;
        else j++;
    }
    return count;
}

// Exercicio 36:

int search3 (int x, int a[], int n) {
    int i = 0;
    for (i; i < n; i++) {
        if (x == a[i]) return 1;
    }
    return 0;
}

int comuns (int a[], int na, int b[], int nb){
    int count = 0, i;
    for (i = 0; i < na; i++) {
        if (search3(a[i],b, nb)) count++;
    }
    return count;
}

// Exercicio 37:

int minInd (int v[], int n) {
   int posicao = 0, menor = v[0], i;
   for (i = 1; i < n; i++) {
       if (v[i] < menor) {
           menor = v[i];
           posicao = i;
       }
   }
    return posicao;
}

// Exercicio 38:

void somasAc (int v[], int Ac [], int N){
    int soma = 0, i;
    for (i = 0; i < N; i++) {
        soma += v[i];
        Ac[i] = soma;
    }
}

// Exercicio 42:

int unionSet (int N, int v1[N], int v2[N], int r[N]) {
    int i;
    for(i = 0; i < N; i++) {
        r[i] = v1[i] || v2[i];
    }
    return 0;
}

// Exercicio 43:

int intersectSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i = 0; i < N; i++) {
        r[i] = v1[i] && v2[i];
    }
    return 0;
}

// Exercicio 44:

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i = 0; i < N; i++) {
        r[i] = v1[i] < v2[i] ? v1[i] : v2[i];
    }
    return 0;
}

// Exercicio 45:

int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i = 0; i < N; i++) {
        r[i] = v1[i] > v2[i] ? v1[i] : v2[i];
    }
    return 0;
}

// Exercicio 46:

int cardinalMSet (int N, int v[N]){
    int count = 0, i;
    for (i = 0; i < N; i++) 
        count += v[i];
   	return count;
}


int main() { // Para testar
    char dest[4] = "Olaa";
    char source[4] = "oola";
    mystrcpy(dest,source);
    for(int i = 0; dest[i] != '\0'; i++){
        printf("%c",dest[i]);
    }
    printf("\n");
}
