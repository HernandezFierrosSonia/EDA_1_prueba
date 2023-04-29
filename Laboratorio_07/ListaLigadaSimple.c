//Código para implementar operaciones en una lista ligada circular

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* addToEmpty(struct Node* last, int data) 
{
    if(last!=NULL) return last;
    
    //asignar memoria al nuevo nodo
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    //se asigna dato al nuevo modo
    newNode->data=data;

    //se asigna como last al nuevo modo
    last=newNode;

    //se crea enlace para si mismo
    last->next=last;

    return last;
}

//Agregar nodo por el frente
struct Node* addFront(struct Node* last, int data)
{
    //Se revisa si la lista está vacía
    if(last==NULL) return addToEmpty(last, data);

    //Se asigna memoria al nuevo nodo
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    //Se agrega dato al nuevo nodo
    newNode->data=data;

    //Se guarda la dirección del primer nodo actual en el nuevo nodo
    newNode->next=last->next;

    //Se hace el nuevo nodo como la cabeza
    last->next=newNode;

    return last;
}

//Agregar nodo al final
struct Node* addEnd(struct Node* last, int data) 
{
    //Se revisa si el nodo está vacío
    if(last==NULL) return addToEmpty(last, data); 

    //Se asigna memoria al nuevo nodo
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    //Se agrega dato al nuevo nodo
    newNode->data=data;

    //Se almacena la direción del nodo cabeza al siguiente del nuevo nodo
    newNode->next=last->next;

    //Se apunta al actual último nodo al nuevo nodo
    last->next=newNode;

    //Se hace al nuevo nodo como el último nodo
    last=newNode;

    return last;
}

//Insertar nodo después de un nodo específico
struct Node* addAfter(struct Node* last, int data, int item) 
{
    //Se revisa si la lista está vacía
    if(last==NULL) return NULL;

    struct Node *newNode, *p;
    p=last->next;

    do{
    //Si se encontró el elemento, se coloca el nuevo nodo después de él
        if(p->data==item) 
        {
            //Se asigna memoria al nuevo nodo
            newNode=(struct Node*)malloc(sizeof(struct Node));

            //Se agrega dato al nodo
            newNode->data=data;

            //Se hace como siguiente el nodo actual siguiente del nuevo nodo
            newNode->next=p->next;
            
            //Se pone al nuevo nodo como el siguiente de p
            p->next=newNode;

            //Si p es el último nodo, se hace al nuevo nodo como el último nodo
            if(p==last) last=newNode;
            return last;
        }

        p=p->next;
    } while(p!=last->next);

    printf("\nEl nodo dado no esta presente en la lista.");
    return last;
    
}

//Borrar un nodo
void deleteNode(struct Node** last, int key) 
{
    //Si la lista ligada está vacía
    if(*last==NULL) return;

    //Si la lista contiene solo un nodo
    if((*last)->data==key &&(*last)->next==*last) 
    {
        free(*last);
        *last=NULL;
        return;//por que no puede devolver algo
    }

    struct Node *temp=*last, *d;

    //Si se va a eliminar el último
    if((*last)->data==key)
    {
        //Encontrar el nodo antes del último nodo
        while(temp->next != *last) temp=temp->next;

        //Apuntar un nodo temporal al siguiente del último es decir el primer nodo
        temp->next=(*last)->next;
        free(*last);
        *last=temp->next;
    }

    //Recorrido al nodo que va a ser eliminado
    while(temp->next!=*last && temp->next->data !=key)
    {
        temp=temp->next;
    }

    //Si el nodo a eliminar se encuentra
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
        return;//por que no puede devolver algo
    }

    p=last->next;

    do{
        printf("%d", p->data);
        p=p->next;

    } while(p!=last->next);
}

int main() 
{
    struct Node* last=NULL;

    last=addToEmpty(last, 6);
    last=addEnd(last, 8);
    last=addFront(last, 2);

    last=addAfter(last, 10, 2);

    traverse(last);

    deleteNode(&last, 8);

    printf("\n");

    traverse(last);

    return 0;
}