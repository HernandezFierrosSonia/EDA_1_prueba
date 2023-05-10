//circular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* addToEmpty(struct Node* last, int data)
{
    if(last!=NULL) return last;
    
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=data;

    last=newNode;

    last->next=last;

    return last;
}


struct Node* addFront(struct Node* last, int data)
{
    if(last==NULL) return addToEmpty(last, data);

    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=data;

    newNode->next=last->next;

    last->next=newNode;

    return last;
}

struct Node* addEnd(struct Node* last, int data) 
{
    if(last==NULL) return addToEmpty(last, data);

    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=data;

    newNode->next=last->next;

    last->next=newNode;

    last=newNode;

    return last;
}

struct Node* addAfter(struct Node* last, int data, int item) 
{
    if(last==NULL) return NULL;

    struct Node *newNode, *p;

    p=last->next;

    do
    {
        if(p->data==item)
        {
            newNode=(struct Node*)malloc(sizeof(struct Node));

            newNode->data=data;

            newNode->next=p->next;
          
            p->next=newNode;

            if(p==last) last=newNode;
            return last;
        }
        p=p->next;
    } while(p!=last->next);

    printf("\nEl nodo dado no esta presente en la lista.");
    return last;
    
}

void deleteNode(struct Node** last, int key)
{
    if(*last==NULL) return;

    if((*last)->data==key && (*last)->next==(*last))
    {
        free(*last);
        *last=NULL;
        return;
    }

    struct Node* temp=*last;
    struct Node* d;

    if((*last)->data==key)
    {
        while(temp->next != *last) temp=temp->next;

        temp->next=(*last)->next;
        free(*last);
        *last=temp;//aquí tebpia un error el código del profesor
    }

    //Recorrido al nodo que va a ser eliminado
    while(temp->next!=(*last) && temp->next->data!=key) temp=temp->next;
    
    if(temp->next->data==key)
    {
        d=temp->next;
        temp->next=d->next;
        free(d);
    }
}

void traverse(struct Node* last)
{
    struct Node* p;

    if(last==NULL)
    {
        printf("La lista está vacía");
        return;
    }

    p=last->next;

    do
    {
        printf("%d ", p->data);
        p=p->next;

    } while(p!=last->next);
    printf("\n");
}

bool searchData(struct Node **last, int value)//esta función no modifica, es como peek
{
    struct Node* temp;//en lugar de llamarlo p lo llamé temp de temporal
    temp=(*last);

    do//aquí quise hacerle diferente al addAfter, en lugar de empezar por last->next empecé por last
    {
        if((temp->data)==value)
        {
            return true;
        }
        temp=temp->next;
    }while(temp!=(*last));
    return false;
}

int main() 
{
    int valor; 
    bool resultado1;
    struct Node* last;
    last=NULL;//hay que ponerlo a NULL, por que aun no va a guardar dirección pero necesitamos enviarlo para que eso ocurra

    printf("Bienvenido. Introduzca el valor a buscar en la lista ligada circular: ");
    scanf("%d", &valor);

    last=addToEmpty(last, 2);

    last=addEnd(last, 20);
    last=addEnd(last, 22);
    last=addEnd(last, 3);

    last=addFront(last, 19);
    last=addFront(last, 55);
    last=addFront(last, 56);

    last=addAfter(last, 10, 2);
    last=addAfter(last, 17, 3);
    last=addAfter(last, 1, 2);

    deleteNode(&last, 20);

    deleteNode(&last, 17);

    deleteNode(&last, 55);

    traverse(last);

    resultado1=searchData(&last, valor);
    
    if(resultado1==true)
    {
        printf("Tu valor ¡SI ESTÁ!\n");
    }
    else 
    {
        printf("Tu valor no está :c\n");
    }
    return 0;
}