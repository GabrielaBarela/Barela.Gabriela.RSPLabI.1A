
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "peliculas.h"
#include "LinkedList.h"

eMovie* movie_new()
{
    return (eMovie*)calloc(1,sizeof(eMovie));
}

eMovie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr,char* raitingStr)
{
    eMovie* auxMovie = movie_new();

    if(auxMovie != NULL)
    {
        movie_setId(auxMovie,atoi(idStr));
        movie_setTitulo(auxMovie,tituloStr);
        movie_setGenero(auxMovie,generoStr);
        movie_setRaiting(auxMovie,atof(raitingStr));
    }
    return auxMovie;
}

void  movie_delete(eMovie* this)
{
    if(this!=NULL)
    free(this);
}


void* movie_mapRaiting(void* pMovie)
{
    float aleatorio;
    int min = 1;
    int max=100;

    eMovie* movie= NULL;

    movie = (eMovie*) pMovie;

    aleatorio = (float)((rand()%(max-min +1))+min)/10;

    movie_setRaiting(movie,aleatorio);

    return movie;
}

void* movie_mapGenero(void* pMovie)
{
    eMovie* auxMovie=NULL;
    int aleatorio;
    int min = 1;
    int max=4;
    char genero[50];

    if(pMovie!=NULL)
    {
        auxMovie=(eMovie*)pMovie;

        if(auxMovie!=NULL)
        {
            aleatorio=rand()%(max-min+1)+min;
            movie_Genero(aleatorio,genero);
            movie_setGenero(auxMovie,genero);
        }
    }
    return auxMovie;
}

int movie_Genero(int num1, char* pGenero)
{
    int ret=0;
    if(num1<=4 && num1>=1 && pGenero!=NULL)
    {
        if(num1==1)
        {
            strcpy(pGenero,"DRAMA");
        }
        else if(num1==2)
        {
            strcpy(pGenero,"COMEDIA");
        }
        else if(num1==3)
        {
            strcpy(pGenero,"ACCION");
        }
        else if(num1==4)
        {
            strcpy(pGenero,"TERROR");
        }
        ret=1;
    }
    return ret;
}


//SETTERS

int movie_setId(eMovie* this, int id)
{
    int todoOk = 0;
    if(this!=NULL)
    {
        if(id>0)
        {
            this->id_Movie=id;
            todoOk=1;
        }
    }
    return todoOk;
}

int movie_setTitulo(eMovie* this, char* titulo)
{
    int todoOk = 0;
    if(this!=NULL && strlen(titulo)!=0)
    {
        strcpy(this->titulo,titulo);
        todoOk=1;
    }
    return todoOk;
}

int movie_setGenero(eMovie* this, char* genero)
{
        int todoOk = 0;
    if(this!=NULL && strlen(genero)!=0)
    {
        strcpy(this->genero,genero);
        todoOk=1;
    }
    return todoOk;
}

int movie_setRaiting(eMovie* this, float raiting)
{
    int todoOk=0;
    if(this!=NULL)
    {
        if(raiting >= 0)
        {
            this->raiting = raiting;
            todoOk=1;
        }
    }
    return todoOk;
}

//GETTERS

int movie_getId(eMovie* this, int* id)
{
    int todoOk=0;
    if(this!=NULL)
    {
        *id = this->id_Movie;
        todoOk=1;
    }
    return todoOk;
}

int movie_getTitulo(eMovie* this, char* titulo)
{
    int todoOk;
    if(this!=NULL)
    {
        strcpy(titulo,this->titulo);
        todoOk=1;
    }
    return todoOk;
}

int movie_getGenero(eMovie* this, char* genero)
{
    int todoOk;
    if(this!=NULL)
    {
        strcpy(genero,this->genero);
        todoOk=1;
    }
    return todoOk;
}

int movie_getRaiting(eMovie* this, float* raiting)
{
    int todoOk=0;
    if(this!=NULL)
    {
        *raiting= this->raiting;
        todoOk=1;
    }
    return todoOk;
}

void mostrarMovie(eMovie* movie)
{
    printf("\n%5d  %10s  %10s  %.2f",movie->id_Movie,movie->titulo,movie->genero,movie->raiting);
}



int movie_sortGeneroxRaiting(void* tipo1,void* tipo2)
{
    char peli1[50];
    char peli2[50];

    float movie1;
    float movie2;

    int ret = 0;

    int comparacion;

    if(tipo1 != NULL && tipo2 != NULL)
    {
        movie_getGenero(tipo1,peli1);
        movie_getGenero(tipo2,peli2);

        comparacion = strcmp(peli1,peli2);
        if  (comparacion>0)
        {
            ret =1;
        }
        else if(comparacion<0)
        {
            ret= -1;
        }
        else if(comparacion==0)
        {
            if(tipo1 != NULL && tipo2 != NULL)
            {
                movie_getRaiting(tipo1,&movie1);
                movie_getRaiting(tipo2,&movie2);

                if(movie1>movie2)
                {
                    ret=1;
                }
                else if(movie1<movie2)
                {
                    ret=-1;
                }
            }
        }

    }
    return ret;
}


int movie_filtrarTERROR(void*pGenero)
{
    int todoOk=-1;
    eMovie* auxMovie;
    char auxGenero[50]={"TERROR"};

    if(pGenero != NULL)
    {
        auxMovie=(eMovie*) pGenero;

        if(strcmp(auxMovie->genero,auxGenero)==0)
        {
            todoOk=1;
        }
        else
        {
            todoOk=0;
        }
    }
    return todoOk;
}



int movie_filtrarCOMEDIA(void*pGenero)
{
    int todoOk=-1;
    eMovie* auxMovie;
    char auxGenero[50]={"COMEDIA"};

    if(pGenero != NULL)
    {
        auxMovie=(eMovie*) pGenero;

        if(strcmp(auxMovie->genero,auxGenero)==0)
        {
            todoOk=1;
        }
        else
        {
            todoOk=0;
        }
    }
    return todoOk;
}


int movie_filtrarDRAMA(void*pGenero)
{
    int todoOk=-1;
    eMovie* auxMovie;
    char auxGenero[50]={"DRAMA"};
    if(pGenero != NULL)
    {
        auxMovie=(eMovie*) pGenero;
        if(strcmp(auxMovie->genero,auxGenero)==0)
        {
            todoOk=1;
        }
        else
        {
            todoOk=0;
        }
    }
    return todoOk;
}


int movie_filtraraACCION(void*pGenero)
{
    int todoOk=-1;
    eMovie* auxMovie;
    char auxGenero[50]={"ACCION"};

    if(pGenero != NULL)
    {
        auxMovie=(eMovie*) pGenero;

        if(strcmp(auxMovie->genero,auxGenero)==0)
        {
            todoOk=1;
        }
        else
        {
            todoOk=0;
        }
    }
    return todoOk;
}




