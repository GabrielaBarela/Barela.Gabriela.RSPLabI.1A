#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int pedirOpcionMenu()
{
    int opcion;
    printf("                          Menu Principal                  \n\n");
    printf(" 1. Cargar archivo  \n 2. Listar   \n 3. Asignar datos \n 4. Posteos con mas de 3000 likes \n 5.   \n 6. Ordenar por followers  \n 7.  \n 8. Salir\n");
    scanf("%d", &opcion);

    return opcion;

}
int menuFiltrado()
{
    int choice;
    printf("                          Filtrado de Generos                  \n\n");
    printf(" 1. Filtrado ACCION  \n 2. Filtrado TERROR   \n 3. Filtrado DRAMA \n 4. Filtrado COMEDIA \n 5. Salir \n");
    scanf("%d", &choice);

    return choice;
}
