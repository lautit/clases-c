#include <stdio.h>
#include <stdlib.h>

char ***asignarMemoriaCasa(const unsigned int cuartos, const unsigned int *camas);
void cargarCuartos (char *** casa, const unsigned int cuartos, const unsigned int *camas);
void cargarCamas (char ** cuarto, const unsigned int nroCuarto, const unsigned int cantCamas);
void imprimirCasa (char **casa);

int main() {

    /***
     * Matriz esencial para el ejercicio: 
     *
     *  casa -----┐
     *            |
     *            V
     *          ┌---┐      [0][0]
     *          |   |      ┌---┬---┬---┬---┐
     *      [0] | ●------> |'S'|'S'|'S'|'ø'|
     *          |   |      └---┴---┴---┴---┘
     *          ├---┤      [1][0]
     *          |   |      ┌---┬---┐
     *      [1] | ●------> |'D'|'ø'|
     *          |   |      └---┴---┘
     *          ├---┤      [2][0]
     *          |   |      ┌---┬---┬---┐
     *      [2] | ●------> |'D'|'S'|'ø'|
     *          |   |      └---┴---┴---┘
     *          ├---┤
     *          |   |
     *        ═════════
     *          |   |
     *          ├---┤                            ║
     *          |   |      ┌---┬---┬---┬---┬---┬-║-┬---┐
     *  casa[x] | ●------> |   |   |   |   |   | ║ | ● | casa[x][y]
     *          |   |      └---┴---┴---┴---┴---┴-║-┴---┘
     *          └---┘                            ║
     *
     */
    char** casa = NULL;

    //const unsigned int cuartos = 3u; //, nroCuarto;
    //const unsigned int camas[] = { 1u, 2u, 3u }; //NULL;
    unsigned int cuartos, nroCuarto;
    unsigned int *camas = NULL;

    printf("Ingrese cantidad de habitaciones: ");
    scanf("%u", &cuartos);
    fflush(NULL);

    camas = (unsigned int *) calloc(cuartos, sizeof(unsigned int));

    for (nroCuarto = 0; nroCuarto < cuartos; nroCuarto++) {
        printf("Ingrese cantidad de camas de la Hab. Nº%u: ", nroCuarto + 1);
        scanf("%u", &camas[nroCuarto]);
        fflush(NULL);
    }

    casa = *asignarMemoriaCasa(cuartos, camas);

    cargarCuartos(&casa, cuartos, camas);

    imprimirCasa(casa);

    return 0;
}

void cargarCuartos (char *** casa, const unsigned int cuartos, const unsigned int *camas) {
    unsigned int nroCuarto;
    char *cuarto = NULL;

    for (nroCuarto = 0; nroCuarto < cuartos; nroCuarto++) {
        cuarto = (*casa)[nroCuarto];

        printf(">> Cargando Hab. Nº%u:\n", nroCuarto + 1);
        fflush(NULL);
        cargarCamas(&cuarto, (const unsigned int)nroCuarto, camas[nroCuarto]);
    }

    return;
}

void cargarCamas(char ** cuarto, const unsigned int nroCuarto, const unsigned int cantCamas) {
    unsigned int nroCama;
    char tipoCama;
    //void *tipoCama[] = {"D", "DS", "SSS"};

    for (nroCama = 0; nroCama < cantCamas; nroCama++) {

        printf("La cama %u de %u, ¿es simple (S) o doble (D)? ", nroCama + 1, cantCamas);
        scanf(" %c", &tipoCama);
        fflush(NULL);

        if (!(tipoCama == 'S' || tipoCama == 'D' || tipoCama == 's' || tipoCama == 'd')) {
            printf("\nIngrese sólo S o D: ");
            scanf(" %c", &tipoCama);
            fflush(NULL);
        } else {
            cuarto[0][nroCama] = tipoCama;
        }

    }

    printf("\n\n");

    return;
}

char*** asignarMemoriaCasa(const unsigned int cuartos, const unsigned int *camas) {
    unsigned int i;
    char **auxCasa = NULL;

    printf("\n\n");

    printf("> Alocando %lu bytes para %u punteros que representan habitaciones\n", sizeof(char *) * cuartos, cuartos);
    auxCasa = (char **) calloc(cuartos, sizeof(char *));

    for (i = 0; i < cuartos; i++) {
        printf("> Alocando %lu bytes para %u caracteres que representan las camas de la habitación %u\n", sizeof(char) * camas[i], camas[i], i);
        auxCasa[i] = (char*) calloc(camas[i], sizeof(char));
    }

    printf("\n\n");

    return &auxCasa;
}

void imprimirCasa(char **casa) {
    printf("¿Que iría acá?");
}