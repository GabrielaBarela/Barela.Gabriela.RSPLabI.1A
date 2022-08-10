#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id_Movie;
    char titulo[50];
    char genero[50];
    float raiting;
}eMovie;




eMovie* movie_new();

eMovie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr,char* raitingStr);

void  movie_delete(eMovie* this);

void mostrarMovie(eMovie* movie);

void* movie_mapRaiting(void* pMovie);

int movie_Genero(int num1, char* pGenero);

void* movie_mapGenero(void* pMovie);

int movie_sortGeneroxRaiting(void* tipo1,void* tipo2);

//int movie_mapeoRaitig(eMovie* pMovie);
int movie_filtraraACCION(void*pGenero);

int movie_filtrarTERROR(void*pGenero);

int movie_filtrarCOMEDIA(void*pGenero);

int movie_filtrarDRAMA(void*pGenero);

//SETTERS

int movie_setId(eMovie* this, int id);
int movie_setTitulo(eMovie* this, char* titulo);
int movie_setGenero(eMovie* this, char* genero);
int movie_setRaiting(eMovie* this, float raiting);

//GETTERS

int movie_getId(eMovie* this, int* id);
int movie_getTitulo(eMovie* this, char* titulo);
int movie_getGenero(eMovie* this, char* genero);
int movie_getRaiting(eMovie* this, float* raiting);
#endif // PELICULAS_H_INCLUDED
