#ifndef POSTS_H_INCLUDED
#define POSTS_H_INCLUDED

typedef struct
{
    int id;
    char user[30];
    int likes;
    int dislikes;
    int followers;
}ePosts;

#endif // POSTS_H_INCLUDED
ePosts* post_new();
void  post_delete(ePosts* this);
void* post_mapLikes(void* pPost);
void* post_mapDisLikes(void* pPost);
void* post_mapFollowers(void* pPost);

///stters
int post_setId(ePosts* this, int id);
int post_setUser(ePosts* this, char* user);
int post_setLikes(ePosts* this, int likes);
int post_setDisLikes(ePosts* this, int dislikes);
int post_setFollowage(ePosts* this, int followers);
///gtters
int post_getId(ePosts* this, int* id);
int post_getUser(ePosts* this, char* user);
int post_getLikes(ePosts* this, int* likes);
int post_getDisLikes(ePosts* this, int* dislikes);
int post_getFollowage(ePosts* this, int* followers);


int post_filtrarMejoresPosts(void*pBestPost);
int sortPost(void* tipo1,void* tipo2);
