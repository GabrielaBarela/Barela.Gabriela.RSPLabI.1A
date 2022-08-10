#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_ListMovie(LinkedList* pArrayListMovie);

int controller_loadFromText(char* path, LinkedList* pArrayListMovie);

int controller_mapRaiting(LinkedList* pArrayMovie);

int controller_SaveAsText(char*path, LinkedList* list);

int controller_GenerosFiltrados(LinkedList* pArrayListMovies);


#endif // CONTROLLER_H_INCLUDED
