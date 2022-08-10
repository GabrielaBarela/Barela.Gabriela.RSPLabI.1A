#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "controller.h"
#include "parser.h"
#include "menu.h"

int controller_loadFromText(char* path, LinkedList* pArrayListMovie)
{
    int retorno=-1;
    FILE* pFile=fopen(path, "r");

    if(pArrayListMovie!=NULL && path!=NULL)
    {
        printf("Invoco al controller texto\n");
        parser_MovieFromText(pFile, pArrayListMovie);
        retorno=1;
    }
    return retorno;
}

int controller_ListMovie(LinkedList* pArrayListMovie)
{
    eMovie* pMovieAux;
    int todoOk=0;
    int id_Aux;
    char titulo_Aux[50];
    char genero_Aux[50];
    float raiting_Aux;
    int lenList= ll_len(pArrayListMovie);
    int i;

    if(pArrayListMovie != NULL)
    {
        if(lenList>0)
        {
            printf("-Id-----------Pelicula--------------Genero----------Raiting-\n\n");

            for(i=0;i<lenList;i++)
            {
                pMovieAux = (eMovie*)ll_get(pArrayListMovie,i);

                movie_getId(pMovieAux,&id_Aux);
                movie_getTitulo(pMovieAux,titulo_Aux);
                movie_getGenero(pMovieAux,genero_Aux);
                movie_getRaiting(pMovieAux,&raiting_Aux);

                printf("%-2d    %-25s    %-15s    %-10.2f\n",id_Aux, titulo_Aux,genero_Aux,raiting_Aux);
            }
            todoOk=1;
        }
        else
        {
            printf("No se cargaron los Datos");
        }
    }
    return todoOk;
}

int controller_mapRaiting(LinkedList* pArrayMovie)
{
    int todoOk=-1;
    if(pArrayMovie != NULL)
    {
        ll_map(pArrayMovie,movie_mapGenero);
        todoOk=0;
    }
    return todoOk;
}

int controller_SaveAsText(char*path, LinkedList* pArrayListPeliculas)
{
    int todoOk=-1;
    int id;
    char titulo[30];
    char genero[20];
    float rating;
    eMovie* peliculaAux=NULL;
    FILE* pFile;

    if(path!=NULL && pArrayListPeliculas!=NULL)
    {
        pFile=fopen(path, "w");

        peliculaAux=movie_new();

        if(peliculaAux!=NULL)
        {
            fprintf(pFile, "id,titulo,genero,rating\n");
            for(int i=0;i<ll_len(pArrayListPeliculas);i++)
            {
                peliculaAux=(eMovie*) ll_get(pArrayListPeliculas, i);
                if(peliculaAux!=NULL)
                {
                    movie_getId(peliculaAux, &id);
                    movie_getTitulo(peliculaAux, titulo);
                    movie_getGenero(peliculaAux, genero);
                    movie_getRaiting(peliculaAux, &rating);

                    fprintf(pFile,"%d,%s,%s,%.2f\n",id,titulo,genero,rating);
                    todoOk=1;
                }
                else
                {
                    todoOk=0;
                    break;
                }
            }
        }
        fclose(pFile);

        if(todoOk)
        {
            printf("Se ha guardado correctamente el listado!\n");
        }
    }
    return todoOk;
}


int controller_GenerosFiltrados(LinkedList* pArrayListMovies)
{
    int todoOk=-1;
    int choice;
    LinkedList* auxTERROR =NULL;
    LinkedList* auxACCION =NULL;
    LinkedList* auxCOMEDIA =NULL;
    LinkedList* auxDRAMA =NULL;

    if (pArrayListMovies !=NULL)
    {
        do
        {
            choice=menuFiltradoGenero();
            switch(choice)
            {
                case 1:
                    auxACCION= ll_filter(pArrayListMovies,movie_filtraraACCION);
                    controller_ListMovie(auxACCION);
                    controller_SaveAsText("ACCION.csv",auxACCION);
                    break;
                case 2:
                    auxTERROR=ll_filter(pArrayListMovies,movie_filtrarTERROR);
                    controller_ListMovie(auxTERROR);
                    controller_SaveAsText("TERROR.csv",auxTERROR);
                    break;
                case 3:
                    auxDRAMA=ll_filter(pArrayListMovies,movie_filtrarDRAMA);
                    controller_ListMovie(auxDRAMA);
                    controller_SaveAsText("DRAMA.csv",auxDRAMA);
                    break;
                case 4:
                    auxCOMEDIA=ll_filter(pArrayListMovies,movie_filtrarCOMEDIA);
                    controller_ListMovie(auxCOMEDIA);
                    controller_SaveAsText("COMEDIA.csv", auxCOMEDIA);
                    break;
                case 5:
                    break;
                default:
                    printf("Opcion Invalida\n");
                break;
            }
        }
        while(choice!=5);
    }
    return todoOk;
}



