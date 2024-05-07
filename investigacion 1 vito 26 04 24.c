#include <stdio.h>

int main() {
    // Abre un archivo llamado "archivo.txt" en modo de escritura (sobrescribe si ya existe)
    FILE *archivo;
    archivo = fopen("archivo.txt", "w");

    // Verifica si se abrió correctamente el archivo
    if (archivo != NULL) {
        // Escribe contenido en el archivo
        fprintf(archivo, "Hola, este es un archivo de ejemplo creado en C.\n");
        fprintf(archivo, "Puedes escribir cualquier cosa que desees aquí.\n");
        
        // Cierra el archivo
        fclose(archivo);
        printf("Se ha creado el archivo correctamente.\n");
    } else {
        printf("Error al crear el archivo.\n");
    }

    return 0;
}

