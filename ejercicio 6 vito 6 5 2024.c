#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUGADORES 10
#define MAX_NOMBRE 50

typedef struct {
    char nombre[MAX_NOMBRE];
    int puntaje;
} Jugador;

void guardarJugador() {
    FILE *archivo;
    Jugador jugador;

    archivo = fopen("jugadores.dat", "ab");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    printf("Ingrese el nombre del jugador: ");
    scanf("%s", jugador.nombre);
    printf("Ingrese el puntaje del jugador: ");
    scanf("%d", &jugador.puntaje);

    fwrite(&jugador, sizeof(Jugador), 1, archivo);

    fclose(archivo);
}

void mostrarJugadores() {
    FILE *archivo;
    Jugador jugador;

    archivo = fopen("jugadores.dat", "rb");
    if (archivo == NULL) {
        printf("No hay jugadores registrados.\n");
        return;
    }

    printf("Los jugadores registrados son:\n");
    while (fread(&jugador, sizeof(Jugador), 1, archivo)) {
        printf("Nombre: %s, Puntaje: %d\n", jugador.nombre, jugador.puntaje);
    }

    fclose(archivo);
}

void buscarJugador(char nombreBuscado[MAX_NOMBRE]) {
    FILE *archivo;
    Jugador jugador;

    archivo = fopen("jugadores.dat", "rb");
    if (archivo == NULL) {
        printf("No hay jugadores registrados.\n");
        return;
    }

    while (fread(&jugador, sizeof(Jugador), 1, archivo)) {
        if (strcmp(jugador.nombre, nombreBuscado) == 0) {
            printf("Jugador encontrado - Nombre: %s, Puntaje: %d\n", jugador.nombre, jugador.puntaje);
            fclose(archivo);
            return;
        }
    }

    printf("Jugador no encontrado.\n");
    fclose(archivo);
}

int main() {
    int opcion;
    char nombreBuscado[MAX_NOMBRE];

    do {
        printf("\n1. Guardar jugador\n2. Mostrar jugadores\n3. Buscar jugador\n4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                guardarJugador();
                break;
            case 2:
                mostrarJugadores();
                break;
            case 3:
                printf("Ingrese el nombre del jugador a buscar: ");
                scanf("%s", nombreBuscado);
                buscarJugador(nombreBuscado);
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}
