#include "utils.h"
int CodA(char* cod_mic);
int CodB(char* cod_mic);
int CodC(char* cod_mic);


void SolveTask1() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    scanf("\n");

    char cod[1000];
    fgets(cod, 1000, stdin);
    if ( cod[strlen(cod)-1] == '\n' ) {
        cod[strlen(cod)-1] = '\0';
    }

    // printf("%d %d %s \n", n, m, cod);

    int lungime = strlen(cod);
    char* cod_mic;
    char sep[]=" ";

    cod_mic = strtok(cod, sep);
    // salvez in vectorul drum iesirile de la coduri care corespund
    // unei directii dreapta stanga sus jos
    // pasi reprezinta nr de pasi adica dimensiunea vectorului
    // in fct de vectorul drum creez matricea
    int pasi = 0;
    int drum[100];


    while ( cod_mic != NULL ) {    // separ toate cuv si vf ce tip de cod sunt
        if ( *(cod_mic) == 'a' ) {
            drum[pasi] = CodA(cod_mic);
        }

        if ( *(cod_mic) == 'b' ) {
            drum[pasi] = CodB(cod_mic);
        }

        if ( *(cod_mic) == 'c' ) {
            drum[pasi] = CodC(cod_mic);
        }

        cod_mic = strtok(NULL, sep);
        pasi++;
    }

    // matricea- o aloc dinamic pt a avea toate elemetele 0
    int** matrix = (int**)calloc( n, sizeof(int*));
    int i, j, nr;
    for ( i = 0; i < m; i++ ) {
        matrix[i] = (int*)calloc( m, sizeof(int));
    }
    matrix[0][0] = 1;

    i = 0; j = 0;
    for ( nr = 2; nr <= pasi+1; nr++ ) {
        if ( drum[nr-2] == -1 ) {        // jos
            i = i + 1;
            matrix[i][j] = nr;
        }

        if ( drum[nr-2] == 0 ) {        // sus
            i = i - 1;
            matrix[i][j] = nr;
        }

        if ( drum[nr-2] == 2 ) {        // dreapta
            j = j + 1;
            matrix[i][j] = nr;
        }

        if ( drum[nr-2] == 1 ) {        // stanga
            j = j - 1;
            matrix[i][j] = nr;
        }
    }

    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < m; j++ ) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int CodA(char* cod_mic) {
    char maxim = cod_mic[1], pozitie = 1;
    for ( int i = 1; i <= 4; i++ ) {
        if ( maxim < cod_mic[i] ) {
            maxim = cod_mic[i];
            pozitie = i;
        }
    }

    switch (pozitie) {
        case 1:
            return 2;    // dreapta=2
            break;

        case 2:
            return 0;   // sus
            break;

        case 3:
            return 1;   // stanga
            break;

        case 4:
            return -1;  // jos
            break;
    }
}

  int CodB(char* cod_mic) {
    int lungime = strlen(cod_mic);
    char i, palindrom = 1, prim = 1;
    // vf palindrom:
     for ( i = 1; i < lungime; i++ ) {
        if ( cod_mic[i] != cod_mic[lungime-i] ) {
            palindrom = 0;
            break;
        }
    }
    // vf X prim
    int X;
    // codul ascii=nr decimal+48, 1=49 etc
    unsigned int a = (unsigned int)cod_mic[lungime-2]-48;
    unsigned int b = (unsigned int)cod_mic[lungime-1] - 48;
    X = 10 * a + b;
    for ( i = 2; i <= X/2; i++ ) {
        if ( X % i == 0 ) {
            prim = 0;
            break;
        }
    }

    if ( palindrom == 1 ) {
        if ( prim == 1 ) {
            return 1;
        } else {
            return 2;
        }
    } else {
        if ( prim == 1 ) {
            return 0;
        } else {
            return -1;
        }
    }
}

int CodC(char* cod_mic) {
    int lungime = strlen(cod_mic);
    int n, k, i, suma = 0;
    int x[10];         // codul ascii= nr+48
    n = cod_mic[1]-48;
    k = cod_mic[2]-48;

    for ( i = 3; i < lungime; i++ ) {
        x[i-3] = cod_mic[i] - 48;
    }

    for ( int repetitii = 0; repetitii < k; repetitii++ ) {
        if ( (k*repetitii) < n ) {
            suma = suma + x[k*repetitii];
        } else {
            suma = suma + x[(k*repetitii)%n];
        }
    }

    switch (suma%4) {
        case 0:
            return 1;         // stanga=1
            break;

        case 1:
            return 0;       // sus
            break;

        case 2:
            return 2;      // dreapta
            break;

        case 3:
            return -1;    // jos
            break;
    }
}
