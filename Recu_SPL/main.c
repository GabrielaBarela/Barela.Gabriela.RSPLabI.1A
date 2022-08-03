#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "menu.h"
#include "posts.h"
int main()
{
    int option;
    int flag1=0;

    int flagMap1=0;
    char auxCadenaGradado[50];

    LinkedList* listPost= ll_newLinkedList();
    LinkedList* listNull=NULL;

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
                while(controller_loadFromText(auxCadenaGradado,listPost)==0)
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
                controller_ListPost(listPost);
            }
            else
            {
                printf("\nPrimero debe cargar el archivo");
            }
            break;
        case 3:
            if(flag1==1)
            {
                listNull = ll_map(listPost,post_mapLikes);
                listNull = ll_map(listPost,post_mapDisLikes);
                listNull = ll_map(listPost,post_mapFollowers);
                controller_ListPost(listNull);
                flagMap1=1;
            }
            else
            {
                printf("\nPrimero debe cargar el archivo");
            }
            break;
        case 4:
            if(flag1==1 && flagMap1 ==1)
            {
                controller_BestPost(listNull);
                controller_SaveAsText("POSTEOS>3000.csv",listNull);
            }
            else
            {
                printf("\nPrimero debe cargar el archivo");
            }
            break;
        case 5:
            break;
        case 6:
            if(flag1==1 && flagMap1 ==1)
            {
                ll_sort(listNull,sortPost,0);
                controller_ListPost(listNull);
            }
            else
            {
                printf("\nPrimero debe cargar el archivo");
            }
            break;
        case 7:
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
