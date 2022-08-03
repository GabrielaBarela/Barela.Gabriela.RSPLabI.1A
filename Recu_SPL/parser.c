#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "posts.h"
#include "parser.h"
int parser_PostFromText(FILE* pFile, LinkedList* pArrayListPost)
{
    ePosts* auxPost = post_new();
    int auxCantidad;
    int CantidadArgumentos;
    int i=0;
    int todoOk=0;

    char id_Aux[50], user_Aux[50], likes_Aux[50], dislikes_Aux[50],followers_Aux[50];
    if (pFile != NULL && pArrayListPost != NULL)
    {
        while(!feof(pFile))
        {
            CantidadArgumentos= fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id_Aux,user_Aux,likes_Aux,dislikes_Aux,followers_Aux);
            if(CantidadArgumentos==5)
            {
                auxPost = post_newParam(id_Aux,user_Aux,likes_Aux,dislikes_Aux,followers_Aux);
                auxCantidad = ll_add(pArrayListPost,auxPost);
                i++;
                if(auxCantidad!=0)
                {
                    post_delete(auxPost);
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
        printf("Se cargaron %d Users a la lista (modo texto)\n",i);
    }
    return todoOk;
}
