#include <stdio.h>
#include <stdlib.h>

typedef struct Vect Vect;
struct Vect
{
    int x;
    int y;
    int z;
    Vect *nextVect;
    //Vect *previousVect;
};

typedef struct gameObject gameObject;
struct gameObject
{
    int key;
    gameObject *nextObject;
    //gameObject *previousObject;
};

typedef struct List
{
    gameObject *firstObject;
    Vect *firstVect;
}List;

List *initialisation();
void insertion(List *list, int newX, int newY, int newZ, int newKey);
void suppression(List *list);
void afficherlist(List *list);

int main()
{
    List *asset = initialisation();

    insertion(asset, 1, 1, 1, 168);
    insertion(asset, 2, 2, 2, 403);
    insertion(asset, 3, 3, 3, 72);
    suppression(asset);

    afficherlist(asset);

    return 0;
}

List *initialisation()
{
    List *list = malloc(sizeof(*list));
    gameObject *gameobject = malloc(sizeof(*gameobject));
    Vect *vect = malloc(sizeof(*vect));

    if (list == NULL || gameobject == NULL || vect == NULL)
    {
        exit(EXIT_FAILURE);
    }

    vect->x = 0;
    vect->y = 0;
    vect->z = 0;

    gameobject->key = 0;

    vect->nextVect = NULL;
    gameobject->nextObject = NULL;

    list->firstVect = vect;
    list->firstObject = gameobject;

    return list;
}


void insertion(List *list, int newX, int newY, int newZ, int newKey)
{
    gameObject *newGameObject = malloc(sizeof(*newGameObject));
    Vect *newVect = malloc(sizeof(*newVect));
    if (list == NULL || newGameObject == NULL || newVect == NULL)
    {
        exit(EXIT_FAILURE);
    }

    newVect->x = newX;
    newVect->y = newY;
    newVect->z = newZ;

    newGameObject->key = newKey;

    newGameObject->nextObject = list->firstObject;
    list->firstObject = newGameObject;

    newVect->nextVect = list->firstVect;
    list->firstVect = newVect;
}


void suppression(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (list->firstObject != NULL && list->firstVect != NULL)
    {
        gameObject *ObjectToDel = list->firstObject;
        Vect *VectToDel = list->firstVect;

        list->firstObject = list->firstObject->nextObject;
        list->firstVect = list->firstVect->nextVect;
        free(ObjectToDel);
        free(VectToDel);
    }
}

void afficherlist(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    gameObject *currentObject = list->firstObject;
    Vect *currentVect = list->firstVect;

    printf("Game Object\n");
    while (currentObject != NULL)
    {
        printf("%d -> ", currentObject->key);
        currentObject = currentObject->nextObject;
    }
    printf("NULL\n\n");

    printf("Vector (X, Y, Z)\n");
    while (currentVect != NULL)
    {
        printf("%d, %d, %d -> ", currentVect->x, currentVect->y, currentVect->z);
        currentVect = currentVect->nextVect;
    }
    printf("NULL\n\n");
}
