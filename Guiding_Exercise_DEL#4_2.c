#include <stdio.h>
#include <string.h>
#include <stdlib.h> // necesario para atof

int main(int argc, char *argv[]) {

    char peticion[100];
    char respuesta[100] = ""; // Inicializar la cadena

    strcpy(peticion, "Miguel/47/Juan/12/Maria/22/Marcos/19");
    // Resultado esperado: "Miguel*47-Maria*22-Marcos*19"

    char nombre[20];
    int edad;
    char *p = strtok(peticion, "/");

    while (p != NULL) {

        strcpy(nombre, p);
        p = strtok(NULL, "/");
        if (p == NULL) break; // Evita acceder a puntero NULL
        edad = atoi(p);

        if (edad > 18)
            sprintf(respuesta, "%s%s*%d-", respuesta, nombre, edad);

        p = strtok(NULL, "/"); // Continuar con el siguiente token
    }
	respuesta[strlen (respuesta) -1] = '\0';

    printf("Resultado: %s\n", respuesta);
}
