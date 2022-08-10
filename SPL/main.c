#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "menu.h"
#include "peliculas.h"

int main()
{
    int option;
    int flag1=0;

    int flagMap1=0;
    int flagMap2=0;
    char auxCadenaGradado[50];

    LinkedList* listMovie = ll_newLinkedList();
    LinkedList* listMovieNULL= NULL;

    do
    {
        option= pedirOpcionMenu();
        switch(option)
        {
        case 1:
            if(flag1==0)
            {
                printf("\nIngrese el Nombre del Archivo que desea cargar, no se olvide de agregar ''.csv''(sino no se cargara el archivo)\n");
                scanf("%s",auxCadenaGradado);
                while(controller_loadFromText(auxCadenaGradado,listMovie)==0)
                {
                    printf("\n*** ERROR***\nIngrese el Nombre del Archivo que desea cargar, no se olvide de poner ''.csv'' al final(sino no se cargara el archivo)\n");
                    scanf("%s",auxCadenaGradado);
                }
                flag1=1;
            }
            else
            {
                printf("Ya ha cargado los datos\n");
                system("pause");
                system("cls");
            }
            break;
        case 2:
            if(flag1==1)
            {
                controller_ListMovie(listMovie);
            }
            else
            {
                printf("\nPrimero debe cargar el archivo");
            }

            break;
        case 3:
            if(flag1==1)
            {
                listMovieNULL = ll_map(listMovie,movie_mapRaiting);
                controller_ListMovie(listMovieNULL);
                flagMap1=1;
            }
            else
            {
                printf("\nPrimero debe cargar el archivo");
            }
            break;
        case 4:
            if(flag1==1)
            {
                 controller_mapRaiting(listMovieNULL);
                 controller_ListMovie(listMovieNULL);
                 flagMap2=1;
            }
            else
            {
                printf("\nPrimero debe cargar el archivo");
            }
            break;
        case 5:
            if(flag1==1 && flagMap1 ==1 && flagMap2 ==1)
            {
                controller_GenerosFiltrados(listMovieNULL);
            }
            else
            {
                printf("\nPrimero debe cargar el archivo");
            }
            break;
        case 6:
            if(flag1==1 && flagMap1 ==1 && flagMap2 ==1)
            {
                ll_sort(listMovieNULL,movie_sortGeneroxRaiting,0);
                controller_ListMovie(listMovieNULL);
            }
            else
            {
                printf("\nPrimero debe cargar el archivo");
            }
            break;
        case 7:
            controller_SaveAsText("ListaGuardada.csv",listMovieNULL);

            break;
        case 8:
            break;
        default:
            printf("Opcion Invalida\n");
            break;
        }
    }
    while(option!=8);
    return 0;
}
            /*printf("\nIngrese el Nombre del Archivo de Guardado, no se olvide de poner ''.csv'' al final, sino no se guardara el archivo");
            scanf("%s",auxCadenaGradado);
            controller_SaveAsText(auxCadenaGradado,listMovieNULL);*/
