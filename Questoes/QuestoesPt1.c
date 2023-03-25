// Questoes 1ª Parte
#include <stdio.h>

// Exercicio 1:

// Exercicio 5:

int trailingZ (unsigned int n) {
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
    while(*s1) s1++;
    while((*s1 = *s2)) {s1++; s2++;}
    *s1 = '\0';
    return s1;
}

// Exercicio 8:

char *mystrcpy(char *dest, char source[]) {
    char *dest_inicial = dest;
    while (*source != '\0') {
        *dest = *source;
        source++;
        dest++;
    }
    *dest = '\0';
    dest = dest_inicial;
    return dest;
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
            if (count > maximo) maximo = count;
            count = 1;
        }
    }
    return maximo;
}
int main() {
    char dest[4] = "Olaa";
    char source[4] = "oola";
    mystrcpy(dest,source);
    for(int i = 0; dest[i] != '\0'; i++){
        printf("%c",dest[i]);
    }
    printf("\n");
}