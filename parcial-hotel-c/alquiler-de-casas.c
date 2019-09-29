#include <stdio.h>

char** cargarHabitaciones(void);
const char* cargarCamas(int, char*);

int main() {

    char** casa;

    int hab, cam;

    casa = cargarHabitaciones();

    for (hab = 0; hab < 100; hab++) {
        printf("La Hab. Nº%d tiene las camas ", hab+1);
        for (cam = 0; cam < 100; cam++) {
            printf("%c ", casa[hab][cam]);
        }
        printf("\n");
    }

    return 0;
}

char** cargarHabitaciones(void) {
    char* habitaciones[5] = { "a","a","a","a","a" };
    int cantidadHabitaciones = 0, i;
    char aux[5];

    printf("Ingrese cantidad de habitaciones: ");
    scanf("%d", &cantidadHabitaciones);

    for (i = 0; i < cantidadHabitaciones; i++) {

        printf("cargo camas\n");
        cargarCamas(i+1, &aux);
        printf("cargue camas\n");

        printf("habitaciones[%d] = %s\n", i, habitaciones[i]);
        printf("aux = %s\n\n", aux);

    }

    return habitaciones;
}

const char* cargarCamas(int nroHabitacion, char* habitacion) {
    char camas[5];
    int cantidadCamas = 0, i;
    char tipoCama;

    printf("Ingrese cantidad de camas de la Hab. Nº%d: ", nroHabitacion);
    scanf("%d", &cantidadCamas);

    for (i = 0; i < cantidadCamas; i++) {

        printf("La cama %d es simple (S) o doble (D)? ", i+1);
        scanf(" %c", &tipoCama);

        if (!(tipoCama == 'S' || tipoCama == 'D' || tipoCama == 's' || tipoCama == 'd')) {
            printf("sos un nabo carga bien");
        } else {
            camas[i] = tipoCama;
        }

    }

    habitacion = camas;

    return &camas;
}
