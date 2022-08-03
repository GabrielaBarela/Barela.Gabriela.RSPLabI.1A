#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "posts.h"
#include "controller.h"
#include "parser.h"
#include "menu.h"


int controller_loadFromText(char* path, LinkedList* pArrayListPost)
{
    int retorno=-1;
    FILE* pFile=fopen(path, "r");

    if(pArrayListPost!=NULL && path!=NULL)
    {
        printf("Invoco al controller texto\n");
        parser_PostFromText(pFile, pArrayListPost);
        retorno=1;
    }
    return retorno;
}

int controller_ListPost(LinkedList* pArrayListPost)
{
    ePosts* pPosts;
    int todoOk=0;
    int id_Aux;
    char user_Aux[30];
    int like_Aux;
    int dislike_Aux;
    int followers_Aux;
    int lenList = ll_len(pArrayListPost);
    int i;
    if(pArrayListPost !=NULL)
    {
        if(lenList>0)
        {
            printf("-Id-----------Users--------------Likes----------Dislikes-------Followers\n\n");
            for(i=0;i<lenList;i++)
            {
                pPosts = (ePosts*)ll_get(pArrayListPost,i);

                 post_getId(pPosts, &id_Aux);
                 post_getUser(pPosts,user_Aux);
                 post_getLikes(pPosts, &like_Aux);
                 post_getDisLikes(pPosts, &dislike_Aux);
                 post_getFollowage(pPosts, &followers_Aux);

                printf("%-2d    %-25s    %-15d    %-10d    %-10d\n",id_Aux, user_Aux,like_Aux,dislike_Aux,followers_Aux);
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

int controller_SaveAsText(char*path, LinkedList* pArrayListPost)
{
    int todoOk=-1;
    int id_Aux;
    char user_Aux[30];
    int like_Aux;
    int dislike_Aux;
    int followers_Aux;
    ePosts* postAUX=NULL;
    FILE* pFile;

    if(path!=NULL && pArrayListPost!=NULL)
    {
        pFile=fopen(path, "w");

        postAUX=post_new();

        if(postAUX!=NULL)
        {
            fprintf(pFile, "id,titulo,genero,rating\n");
            for(int i=0;i<ll_len(pArrayListPost);i++)
            {
                postAUX=(ePosts*) ll_get(pArrayListPost, i);
                if(postAUX!=NULL)
                {
                    post_getId(postAUX, &id_Aux);
                    post_getUser(postAUX,user_Aux );
                    post_getLikes(postAUX,&like_Aux );
                    post_getDisLikes(postAUX, &dislike_Aux);
                    post_getFollowage(postAUX,&followers_Aux);

                    fprintf(pFile,"%d,%s,%d,%d,%d\n",id_Aux,user_Aux,like_Aux,dislike_Aux,followers_Aux);
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

int controller_BestPost(LinkedList* pArrayListPost)
{
    int todoOk=-1;
    int choice;

    LinkedList* auxPost=NULL;
    if(pArrayListPost !=NULL)
    {
        auxPost=ll_filter(pArrayListPost,post_filtrarMejoresPosts);
        controller_ListPost(auxPost);
    }
    return todoOk;
}






