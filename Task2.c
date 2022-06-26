#include "utils.h"
char* decriptare_caesar(char* cod, int cheie);
void decriptare_vigenere(char* cod, char* cheie);
char* addition(char* cod1, char* cod2);
char* reversed(char* sir);
char* lungime_noua(char* sir, int len_nou);

void SolveTask2() {
    char tip_cod[20];                   // tipul de cod ales la input
    fgets(tip_cod, 20, stdin);
    if ( tip_cod[strlen(tip_cod)-1] == '\n' ) {
        tip_cod[strlen(tip_cod)-1] = '\0';
    }
    // 2.1 CAESAR
    if ( strcmp(tip_cod, "caesar") == 0 ) {
        int cheie;
        scanf("%d", &cheie);
        scanf("\n");

        char cod[1000];
        fgets(cod, 1000, stdin);
        if ( cod[strlen(cod)-1] == '\n' ) {
        cod[strlen(cod)-1] = '\0';
        }
        int len = strlen(cod)+1;
        char cod_nou[1000];
        memcpy(cod_nou, decriptare_caesar(cod, cheie), len);
        printf("%s", cod_nou);
    }
    // 2.2 VIGENERE
    if ( strcmp(tip_cod, "vigenere") == 0 ) {
        char cheie[10];
        fgets(cheie, 10, stdin);
        if ( cheie[strlen(cheie)-1] == '\n' ) {
            cheie[strlen(cheie)-1] = '\0';
        }

        char cod[1000];
        fgets(cod, 1000, stdin);
        if ( cod[strlen(cod)-1] == '\n' ) {
            cod[strlen(cod)-1] = '\0';
        }

        decriptare_vigenere(cod, cheie);
        printf("%s", cod);
    }

    // 2.3 ADDITION
    if ( strcmp(tip_cod, "addition") == 0 ) {
        int cheie;
        scanf("%d", &cheie);
        scanf("\n");

        char cod1[1000];
        fgets(cod1, 1000, stdin);
        if ( cod1[strlen(cod1)-1] == '\n' ) {
            cod1[strlen(cod1)-1] = '\0';
        }

        char cod2[1000];
        fgets(cod2, 1000, stdin);
        if ( cod2[strlen(cod2)-1] == '\n' ) {
            cod2[strlen(cod2)-1] = '\0';
        }

        char* nr1 = malloc( (strlen(cod1) + 1) * sizeof(char) );
        char* nr2 = malloc( (strlen(cod2) + 1) * sizeof(char) );
        int len1 = strlen(cod1) + 1;
        int len2 = strlen(cod2) + 1;
        memcpy(nr1, decriptare_caesar(cod1, cheie), len1);
        memcpy(nr2, decriptare_caesar(cod2, cheie), len2);

        char* suma = malloc(1000 * sizeof(char) );
        char* aux = addition(nr1, nr2);
        memcpy(suma, aux, strlen(aux));
        printf("%s ", suma);
    }
}

char* decriptare_caesar(char* cod, int cheie) {
    int i, j, min, max;
    // pt vall in ascii=> 3 cazuri:
    for ( i = 0; i < strlen(cod); i++ ) {
        if ( (int)cod[i] >= 97 && (int)cod[i] <= 122 ) {    // literele mici
            min = 97;
            max = 122;
        }
        if ( (int)cod[i] >= 65 && (int)cod[i] <= 90 ) {    // literele mari
            min = 65;
            max = 90;
        }
        if ( (int)cod[i] >= 48 && (int)cod[i] <= 57 ) {   // cifrele
            min = 48;
            max = 57;
        }

        for ( j=0; j < cheie; j++ ) {
            if ( cod[i] != min ) {
                cod[i] = cod[i] - 1;
            } else {
                cod[i] = (char)max;
            }
        }
    }

    char* cod_decriptat = malloc( (strlen(cod) + 1) * sizeof(char) );
    int len = strlen(cod);
    memcpy(cod_decriptat, cod, len);

    return cod_decriptat;
}



void decriptare_vigenere(char* cod, char* cheie) {
    int i, k, rotire[strlen(cheie)];

    // in vectorul rotire stochez pozitiile cu care se roteste codul
    for ( i = 0; i < strlen(cheie); i++ ) {
        rotire[i] = cheie[i] - 65;
    }

    // pt ABA rotire este 010 => decriptez codul cu ajutorul vect rotire
    // char cod_mic[strlen(cheie)];
    int min, max, j;

    for ( i = 0; i < strlen(cod); i++ ) {
        if ( (int)cod[i] >= 97 && (int)cod[i] <= 122 ) {    // literele mici
            min = 97;
            max = 122;
            }
        if ( (int)cod[i] >= 65 && (int)cod[i] <= 90 ) {    // literele mari
            min = 65;
            max = 90;
        }
        if ( (int)cod[i] >= 48 && (int)cod[i] <= 57 ) {   // cifrele
            min = 48;
            max = 57;
        }

        for ( j = 0; j < rotire[i % (strlen(cheie))]; j++ ) {
            if ( cod[i] != min ) {
                cod[i] = cod[i] - 1;
            } else {
                cod[i] = (char)max;
            }
        }
    }
}



char* addition(char* nr1, char* nr2) {
    int len1 = strlen(nr1);
    int len2 = strlen(nr2);
    int i;

    char* nr1_nou = malloc( (len1+1) * sizeof(char) );
    char* nr2_nou = malloc( (len2+1) * sizeof(char) );

    // ambele noi siruri vor avea acc lungime
    // se autocompleteaza pana la 0 pt sirul mai mic
    if ( len1 > len2 ) {
        char* sir = lungime_noua(nr2, len1);
        memcpy(nr2_nou, sir, len1);
        memcpy(nr1_nou, nr1, len1);
    } else if ( len1 < len2 ) {
        char* sir = lungime_noua(nr1, len2);
        memcpy(nr1_nou, sir, len2);
        memcpy(nr2_nou, nr2, len2);
    } else {
        memcpy(nr1_nou, nr1, len1);
        memcpy(nr2_nou, nr2, len2);
    }

    // inversez ambele siruri de cifre=> fct reversed def mai jos
    int len_nou = strlen(nr1_nou);
    char* rev1 = malloc( (len_nou + 1) * sizeof(char));
    char* rev2 = malloc( (len_nou + 1) * sizeof(char));

    memcpy(rev1, reversed(nr1_nou), len_nou);
    memcpy(rev2, reversed(nr2_nou), len_nou);

    // suma pe bucati dintre rev1 si rev2=>
    char* suma = malloc( (len_nou+2+1) * sizeof(char));    // maxim
    char plus = '0' - 48;

    for ( i = 0; i < len_nou; i++ ) {
        suma[i]= rev1[i] + rev2[i] + plus - 48;
        // 931+009=> suma[3]=10=> suma[3]=0, plus=1 care se audauga la suma[3+1]

        if ( suma[i] > 57 ) {     // reprezetare numerica cod ascii => 57 pt 9
            suma[i] = rev1[i]+ rev2[i] + plus - 58;   // 10<=>58, 11<=>59
            plus = '1' - 48;
        } else {
            plus = '0' - 48;
        }
    }
    // caracterul 1; 989+032=>9121, pe poz len_nou apare 1=> intors corect 1219
    if ( plus == '1'-48 ) {
        suma[len_nou] = 49;
        suma[len_nou+1] = '\0';
        len_nou++;
    } else {
        suma[len_nou] = '\0';
    }

    char* suma_adv = malloc( (len_nou+1) * sizeof(char));
    memcpy(suma_adv, reversed(suma), len_nou);

    //  daca suma incepe cu 0:
    char* suma_fara_0 = malloc( (len_nou+1) * sizeof(char));
    while ( suma_adv[0] == '0' ) {
        suma_fara_0 = suma_adv+1;
        suma_adv = suma_fara_0;
    }

    return suma_adv;
}


char* reversed(char* sir) {
    int len = strlen(sir);
    char* reversed = malloc( (len + 1) * sizeof(char) );
    int i;
    for ( i = 0; i < len; i++ ) {
        reversed[i] = sir[len-1-i];
    }
    reversed[len] = '\0';
    return reversed;
}


char* lungime_noua(char* sir, int len_nou) {
    // am sirul 2 dar am nev de 002 pt lungimea noua 3=> creez sirul zero: 00
    int len = strlen(sir);
    char zero[1000];

    char* sir_nou = malloc(len_nou * sizeof(char));
    int i;
    for ( i = 0; i < (len_nou-len); i++ ) {
        zero[i] = '0';
    }
    zero[len_nou-len] = '\0';

    memcpy(sir_nou, zero, strlen(zero));
    memcpy(sir_nou+len_nou-len, sir, strlen(sir));

    return sir_nou;
}

