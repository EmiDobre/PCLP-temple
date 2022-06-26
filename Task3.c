#include "utils.h"

void SolveTask3() {
    char sir[40][1000];
    int i, j;
    // citesc maxim 40 de linii  - daca dupa \n urmeaza alt \n ma opresc
    for ( i = 0; i < 40; i++ ) {
        fgets(sir[i], 1000, stdin);
        if ( sir[i][strlen(sir[i])] == '\n' ) {
            sir[i][strlen(sir[i])] = '\0';
        }
        if ( sir[i][0] == '\n' ) {
            if ( sir[i+1][0] == 'n' ) {
               break;
            } else {
                continue;
            }
        }
    }

    // aflu liniile care au cuvinte
    int nr_linii;
    for ( j = 0; j < i; j++ ) {
        if ( strlen(sir[j]) == 0 ) {
            nr_linii = j;
            break;
        }
    }

    // liniile citite le pun in stringul text cu spatiu doar:
    char* text = malloc(10000 * sizeof(char));
    for ( i = 0; i < nr_linii; i++ ) {
        strncat(text, sir[i], strlen(sir[i]));
        text[strlen(text)-1] = ' ';
    }

    // impart in cuvinte
    char sep[] = " ,.;!";
    char cuv[1000][50];
    int nr_cuv = 0;
    char* token = strtok(text, sep);
    while ( token != NULL ) {
        memcpy(cuv[nr_cuv], token, strlen(token));
        nr_cuv++;
        token = strtok(NULL, sep);
    }

    //  secventa: are nr_cuv_fara_spatiu-1 siruri
    char secventa[800][70], copie[800][70];
    char spatiu[1] = " ";
    int len1, len2;
    for ( i = 0; i < nr_cuv-1; i++ ) {
        len1 = strlen(cuv[i]);
        memcpy(secventa[i], cuv[i], len1);
        memcpy((char*)(secventa[i] + len1), spatiu, 1);
        len2 = strlen(cuv[i+1]);
        memcpy((char*)(secventa[i] + len1 + 1), cuv[i+1], len2);
        memcpy(copie[i], secventa[i], strlen(secventa[i]));
    }

    //  secventa fara duplicatii:
    char secventa_ofc[800][70];
    char duplicat[1] = "\0";
    int k = 0;
    for ( i = 0; i < nr_cuv-1; i++ ) {
        for ( j = 0; j < i; j++ ) {
            if ( strcmp(secventa[j], secventa[i]) == 0 ) {
                if ( strcmp(duplicat, secventa[i]) != 0 ) {
                    memcpy(secventa[i], duplicat, strlen(duplicat));
                    *(secventa[i] + strlen(duplicat)) = '\0';
                    break;
                }
            }
        }
        if ( strcmp(duplicat, secventa[i]) != 0 ) {
            memcpy(secventa_ofc[k], secventa[i], strlen(secventa[i]));
            k++;
        }
    }
    printf("%d\n", k);
    int* aparitii = calloc(k, sizeof(int));
    for ( i = 0; i < k; i++ ) {
        for ( j = 0; j < nr_cuv-1; j++ ) {
            if ( strcmp(secventa_ofc[i], copie[j]) == 0 ) {
                aparitii[i]++;
            }
        }
        printf("%s %d\n", secventa_ofc[i], aparitii[i]);
    }
}



