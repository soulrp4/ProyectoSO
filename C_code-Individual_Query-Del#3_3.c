// Programa en C per consultar els punts totals d'un jugador

#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *resultado;
    MYSQL_ROW row;
    int err;
    
    char nom[50];
    char consulta[256];

    // Crear la connexió amb MySQL
    conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("Error al crear la connexió: %u %s\n", mysql_errno(conn), mysql_error(conn));
        return 1;
    }

    // Connectar-se a MySQL
    if (!mysql_real_connect(conn, "localhost", "root", "mysql", "rummikub", 0, NULL, 0)) {
        printf("Error en connectar-se a MySQL: %u %s\n", mysql_errno(conn), mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    // Demanar a l'usuari el nom del jugador
    printf("Introdueix el nom del jugador: ");
    scanf("%49s", nom);  // Limita a 49 caràcters per evitar desbordament de buffer

    // Construir la consulta SQL de manera segura
    snprintf(consulta, sizeof(consulta), 
             "SELECT nom, punts_totals FROM jugadors WHERE nom = '%s'", nom);

    // Executar la consulta
    err = mysql_query(conn, consulta);
    if (err) {
        printf("Error en la consulta: %u %s\n", mysql_errno(conn), mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    // Recollir el resultat de la consulta
    resultado = mysql_store_result(conn);
    if (resultado == NULL) {
        printf("Error en obtenir resultats: %u %s\n", mysql_errno(conn), mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    // Mostrar els resultats
    row = mysql_fetch_row(resultado);
    if (row == NULL) {
        printf("No s'ha trobat cap jugador amb aquest nom.\n");
    } else {
        printf("\nJugador: %s - Punts totals: %s\n", row[0], row[1]);
    }

    // Alliberar memòria i tancar connexió
    mysql_free_result(resultado);
    mysql_close(conn);

    return 0;
}
