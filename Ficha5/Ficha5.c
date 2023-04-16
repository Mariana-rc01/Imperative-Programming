#include <stdio.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [5];
    float teste;
} Aluno;

// Exercicio 1:

int nota (Aluno a) {
    int i;
    float miniTestes = 0;
    for (i = 0; i < 5; i++) {
        miniTestes += a.miniT[i];
    }
    miniTestes /= 5;
    if (miniTestes < 0.25) return 0;
    float media = miniTestes * 10 * 0.2 + a.teste * 0.8;
    if (media < 9.5) return 0;
    else return media;
}

// Exercicio 2:

// 1ª versao

int procuraNum (int num, Aluno t[], int N) {
    int encontrou = -1;
    for (int i = 0; i < N; i++) {
        if (t[i].numero == num) {
            encontrou = i;
            break;
        }
    }
    return encontrou;
}

// 2ª versao

int procuraNum2 (int num, Aluno t[], int N) {
    int encontrou = -1, i;
    for (i = 0; i < N && t[i].numero < num; i++);
    if (i < N && t[i].numero == num) encontrou = i;
    return encontrou;
}

// 3ª versao

int procuraNum3 (int num, Aluno t[], int N) {
    int encontrou = -1, m;
    int l = 0, u = N-1;
    while (l <= u) {
        m = (l+u)/2;
        if (t[m].numero == num) {
            encontrou = m;
            break;
        }
        else if (t[m].numero < num) l = m+1;
        else u = m-1;
    }
    return encontrou;
}

// Exercicio 3:

void ordenaPorNum (Aluno t[], int N) {
    int i, j;
    Aluno aux;
    for (i = 0; i < N; i++) {
        aux = t[i];
        for (j = i; j > 0 && t[j-1].numero > aux.numero; j--) {
            t[j] = t[j-1];
        }
        t[j] = aux;
    }
}

// Exercicio 4:

void atribuiInd (Aluno t[], int N, int ind[]) {
	int i, j;
	Aluno aux;
	for (i = 0; i < N; i++) {
		aux = t[i];
		int auxInd = ind[i];
		for (j = i; j > 0 && t[j-1].numero > aux.numero; j--) {
			t[j] = t[j-1];
			ind[j] = ind[j-1];
		}
		t[j] = aux;
		ind[j] = auxInd;
	}
}

void criaIndPorNum (Aluno t[], int N, int ind[]) {
    int i, j;
    for (i = 0; i < N; i++) {
        ind[i] = i;
    }
		atribuiInd(t,N,ind);
}

// Exercicio 5:

void imprimeTurma (int ind[], Aluno t[], int N) {
    int i = 0;
    while (i < N) {
        int posicao = ind[i];
        int n = nota(t[posicao]);
        printf("%d %s %d\n",t[posicao].numero, t[posicao].nome, n);
        i++;
    }
}

// Exercicio 6:

int procuraNum6 (int num, Aluno t[], int N, int ind[]) {
    for (int i = 0; i < N; i++) {
        if (t[ind[i]].numero == num) return ind[i];
    }
    return -1;
}

// Exercicio 7:

void criaIndPorNome (Aluno t [], int N, int ind[]) {
    int i, j;
    for (i = 0; i < N; i++) {
        ind[i] = i;
    }
    for (i = 0; i < N; i++) {
        int id = ind[i];
        Aluno aux = t[id];
        for (j = i-1; j >= 0 && strcmp(t[ind[j]].nome,aux.nome) > 0; j--) {
            ind[j+1] = ind[j];
        }
        ind[j+1] = id;
    }
}

int main() {
    Aluno M = {90817,
              "Mariana", 
              {2,2,2,1.5,2},
              19
    };

    Aluno t[4] = {
        {90817,
        "Mariana", 
        {2,2,2,1.5,2},
        19},

        {95151,
        "Hugo", 
        {2,2,2,2,2},
        19},

        {104612,
        "Joana", 
        {2,2,0,0,2},
        12},

        {67923,
        "Antonio", 
        {0,0,2,0,2},
        9}
    };

    // Exercicio 1:
    //printf("%d\n",nota(M));

    // Exercicio 2:
    //procuraNum(90817,t,4);

    // Exercicio 3:
    //ordenaPorNum(t,4);

    // Exercicio 4:
    
    int ind[4] = {0};
    criaIndPorNum(t,4,ind);
    for (int i = 0; i < 4; i++) {
        printf("%d\n",ind[i]);
    }
    

    // Exercicio 5:
    /*
    int ind[4] = {0};
    criaIndPorNum(t,4,ind);
    imprimeTurma(ind,t,4);
    */
    
    // Exercicio 6:
    /*
    int ind[4] = {0};
    criaIndPorNum(t,4,ind);
    int r = procuraNum6(90817,t,4,ind);
    printf("%d\n",r);
    */

   // Exercicio 7:
   /*
   int ind[4] =  {0};
   criaIndPorNome(t,4,ind);
   for (int i = 0; i < 4; i++) {
        printf("%d\n",ind[i]);
    }
    */

    return 0;
}