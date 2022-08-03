#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "posts.h"
#include "LinkedList.h"

ePosts* post_new()
{
    return (ePosts*) calloc(1,sizeof(ePosts));
}

ePosts* post_newParam(char* idStr,char* userStr,char* likStr,char* dislikeStr,char* followage)
{
    ePosts* auxPost = post_new();
    if (auxPost!= NULL)
    {
        post_setId(auxPost,atoi(idStr));
        post_setUser(auxPost,userStr);
        post_setLikes(auxPost,atoi(likStr));
        post_setDisLikes(auxPost,atoi(dislikeStr));
        post_setFollowage(auxPost,atoi(followage));
    }
    return auxPost;
}

void* post_mapLikes(void* pPost)
{
    int aleatorio;
    int min=5000;
    int max=50000;
    ePosts* post=NULL;

    post=(ePosts*) pPost;

    aleatorio=((rand()%(max-min +1))+min)/10;

    post_setLikes(post,aleatorio);

    return post;
}
void* post_mapDisLikes(void* pPost)
{
    int aleatorio;
    int min=3000;
    int max=35000;
    ePosts* post=NULL;

    post=(ePosts*) pPost;

    aleatorio=((rand()%(max-min +1))+min)/10;

    post_setDisLikes(post,aleatorio);

    return post;
}

void* post_mapFollowers(void* pPost)
{
    int aleatorio;
    int min=100000;
    int max=200000;
    ePosts* post=NULL;

    post=(ePosts*) pPost;

    aleatorio=((rand()%(max-min +1))+min)/10;

    post_setFollowage(post,aleatorio);

    return post;
}
void  post_delete(ePosts* this)
{
    if(this!=NULL)
    free(this);
}
///SETTERS


int post_setId(ePosts* this, int id)
{
    int todoOk = 0;
    if(this!=NULL)
    {
        if(id>0)
        {
            this->id=id;
            todoOk=1;
        }
    }
    return todoOk;
}

int post_setUser(ePosts* this, char* user)
{
    int todoOk = 0;
    if(this!=NULL && strlen(user)!=0)
    {
        strcpy(this->user,user);
        todoOk=1;
    }
    return todoOk;
}
int post_setLikes(ePosts* this, int likes)
{
    int todoOk = 0;
    if(this!=NULL)
    {
        if(likes>0)
        {
            this->likes=likes;
            todoOk=1;
        }
    }
    return todoOk;
}
int post_setDisLikes(ePosts* this, int dislikes)
{
    int todoOk = 0;
    if(this!=NULL)
    {
        if(dislikes>0)
        {
            this->dislikes=dislikes;
            todoOk=1;
        }
    }
    return todoOk;
}
int post_setFollowage(ePosts* this, int followers)
{
    int todoOk = 0;
    if(this!=NULL)
    {
        if(followers>0)
        {
            this->followers=followers;
            todoOk=1;
        }
    }
    return todoOk;
}

///getters


int post_getId(ePosts* this, int* id)
{
    int todoOk=0;
    if(this!=NULL)
    {
        *id = this->id;
        todoOk=1;
    }
    return todoOk;
}

int post_getUser(ePosts* this, char* user)
{
    int todoOk;
    if(this!=NULL)
    {
        strcpy(user,this->user);
        todoOk=1;
    }
    return todoOk;
}
int post_getLikes(ePosts* this, int* likes)
{
    int todoOk=0;
    if(this!=NULL)
    {
        *likes = this->likes;
        todoOk=1;
    }
    return todoOk;
}
int post_getDisLikes(ePosts* this, int* dislikes)
{
    int todoOk=0;
    if(this!=NULL)
    {
        *dislikes = this->dislikes;
        todoOk=1;
    }
    return todoOk;
}
int post_getFollowage(ePosts* this, int* followers)
{
    int todoOk=0;
    if(this!=NULL)
    {
        *followers = this->followers;
        todoOk=1;
    }
    return todoOk;
}

int post_filtrarMejoresPosts(void*pBestPost)
{
    int todoOk=-1;
    ePosts* auxPost;

    if(pBestPost !=NULL)
    {
        auxPost=(ePosts*) pBestPost;

        if(auxPost->likes>3000)
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


int sortPost(void* tipo1,void* tipo2)
{
    int post1;
    int post2;
    int todoOk=0;
    int comparacion;

    if(post1!=NULL && post2 !=NULL)
    {
        post_getFollowage(tipo1,&post1);
        post_getFollowage(tipo2,&post2);

        if(post1>post2)
        {
            todoOk=1;
        }
        else if(post1<post2)
        {
            todoOk=-1;
        }
    }
    return todoOk;
}


