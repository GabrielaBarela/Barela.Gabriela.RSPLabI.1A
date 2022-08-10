#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "parser.h"

int parser_MovieFromText(FILE* pFile, LinkedList* pArrayListMovie)
{
    eMovie* auxMovie = movie_new();
    int auxCantidad;
    int CantidadArgumentos;
    int i=0;
    int todoOk=0;

    char id_Aux[50], titulo_Aux[50], genero_Aux[50], raiting_Aux[50];
    if (pFile != NULL && pArrayListMovie != NULL)
    {
        while(!feof(pFile))
        {
            CantidadArgumentos= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id_Aux,titulo_Aux,genero_Aux,raiting_Aux);
            if(CantidadArgumentos==4)
            {
                auxMovie = movie_newParametros(id_Aux,titulo_Aux,genero_Aux,raiting_Aux);
                auxCantidad = ll_add(pArrayListMovie,auxMovie);
                i++;
                if(auxCantidad!=0)
                {
                    movie_delete(auxMovie);
                    break;
                }
                else
                {
                    todoOk=1;
                }
            }
            else
            {
                break;
            }
        }
        printf("Se cargaron %d Peliculas a la lista (modo texto)\n", i);
    }
    return todoOk;
}
