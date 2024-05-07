#include <stdio.h>

int main() {
    // Abre un archivo llamado "archivo.txt" en modo de lectura y escritura
    FILE *archivo;
    archivo = fopen("archivo.txt", "r+");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1; // Sale del programa con un c�digo de error
    }

    // Obtiene la posici�n actual en el archivo
    long int posicion_actual = ftell(archivo);
    if (posicion_actual == -1L) {
        printf("Error al obtener la posici�n actual en el archivo.\n");
        fclose(archivo);
        return 1; // Sale del programa con un c�digo de error
    }

    // Mueve el puntero de archivo al principio del archivo
    fseek(archivo, 0, SEEK_SET);
    // Escribe la palabra "PRINCIPIO"
    fprintf(archivo, "PRINCIPIO ");

    // Mueve el puntero de archivo a la posici�n original
    fseek(archivo, posicion_actual, SEEK_SET);
    // Escribe la palabra "ACTUAL"
    fprintf(archivo, "ACTUAL ");

    // Mueve el puntero de archivo al final del archivo
    fseek(archivo, 0, SEEK_END);
    // Escribe la palabra "FINAL"
    fprintf(archivo, "FINAL");

    // Cierra el archivo
    fclose(archivo);

    printf("Se ha escrito en el archivo correctamente.\n");

    return 0; // Retorna 0 para indicar que el programa se ejecut� sin errores
}

