//Lista doblemente enlazada
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertarFront(struct Node** head, int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=data;

    if((*head)==NULL)//la lista está vacía
    {
        newNode->next=newNode;
        newNode->prev=newNode;
        (*head)=newNode;
        return;
    }

    newNode->prev=(*head)->prev;
    (*head)->prev->next=newNode;

    newNode->next=(*head);
    (*head)->prev=newNode;

    *head=newNode;
}

void insertarAfter(struct Node* prev_node, int data)
{
    if(prev_node==NULL)
    {
        printf("Nodo previo no puede ser null\n");
        printf("Es decir debe haber por lo menos un elemento en la lista para usar la función insertarAfter.");
        return;
    }

    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=data;

    newNode->next=prev_node->next;
   
    prev_node->next=newNode;

    newNode->prev=prev_node;

    newNode->next->prev=newNode;
}

void insertarEnd(struct Node** head, int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=data;

    if(*head == NULL)//significa que está vacía
    {
        (*head)=newNode;
        newNode->next=*head;//podía ser =newNode;
        newNode->prev=*head;//podía ser =newNode
        return;
    }

    //El resto del código es para cuando se quiere insertar en el final y hay nodos

    struct Node* temp;
    
    temp=(*head)->prev;

    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=*head;
    (*head)->prev=newNode; 
}

void deleteNode(struct Node** head, struct Node* del_node)//sirve para eliminar al incio al final y enter nodos
{
    if(*head == NULL || del_node == NULL)
    {
        printf("La lista está vacía o dirección de nodo inválida");
        return;
    }

    if(*head == del_node)//es la cabeza y cuando es el único
    {
        *head=del_node->next;
    }

        del_node->next->prev=del_node->prev;

        del_node->prev->next=del_node->next;

    //no modificamos los next y prev del nodo a eliminar. Solo modificamos los enlaces que llegaban a el nodo a eliminar
    free(del_node);
}

void displayList(struct Node* head)
{
    if(head!=NULL)
    {
        struct Node* temporal=head;
        do
        {
            printf("%d ⇄ ", temporal->data);
            temporal=temporal->next;
        }while(temporal!=head);
    }
    else
    {
        printf("Empty list.");
    }
    printf("\n");
}

int main() 
{
    int i;
    int opcion;
    int eliminar;
    int insertar;
    int dato;
    int position;
    struct Node* copia_head;
    struct Node* head=NULL;
    
    insertarFront(&head, 1);
    insertarEnd(&head, 5);//en este programa, se puede usar insertarEnd e insertarFront para insertar pro primera vez
    insertarFront(&head, 1);
    insertarFront(&head, 6);
    insertarEnd(&head, 9);

    insertarAfter(head, 11);

    insertarAfter(head->next, 15);

    //Se borra el penúltimo nodo
    deleteNode(&head, head->next->next->next->next->next);//6° nodo en la lista(incluyendo cabeza)

    deleteNode(&head, head->next->next);

    deleteNode(&head, head);

    printf("Bienvenido a realizar una operación en la lista doble circular enlazada.\n");
    printf("Esta es la lista actual: ");
    displayList(head);
    //while(8)
    {
        printf("Ingresa 1 para insertar\n");
        printf("Ingresa 2 para eliminar\n");
        //printf("Ingresa 3 para salir");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingresa 1 para insertar al final\n");
                printf("Ingresa 2 para insertar en el frente/inicio\n");
                printf("Ingresa 3 para insertar entre nodos\n");
                scanf("%d", &insertar);
                switch(insertar)
                {
                    case 1:
                        printf("Escribe el data del nodo a insertar: ");
                        scanf("%d", &dato);
                        insertarEnd(&head, dato);
                        printf("Así queda la lista después de la operación: ");
                        displayList(head);
                        break;
                    case 2:
                        printf("Escribe el data del nodo a insertar: ");
                        scanf("%d", &dato);
                        insertarFront(&head, dato);
                        printf("Así queda la lista después de la operación: ");
                        displayList(head);
                        break;
                    case 3:
                        printf("Escribe el data del nodo a insertar: ");
                        scanf("%d", &dato);
                        printf("Escribe la posición en número (sin contar al cero) en la que el nodo se va a insertar después: ");
                        scanf("%d", &position);
                        copia_head=head;
                        if((position<1)||(position>4))
                        {
                            printf("Posición inválida. Sólo del 1 al 4.");
                            return opcion;
                        }
                        for(i=1;i<=(position-1);i++)
                        {
                            copia_head=copia_head->next;
                        }
                        insertarAfter(copia_head, dato);
                        printf("Así queda la lista después de la operación: ");
                        displayList(head);
                        break;
                    default:
                        printf("Opción no válida");
                        break;
                }
                break;
            case 2:
                printf("Ingresa 1 para eliminar al final\n");
                printf("Ingresa 2 para eliminar en el frente/inicio\n");
                printf("Ingresa 3 para eliminar entre nodos\n");
                scanf("%d", &eliminar);
                switch(eliminar)
                {
                    case 1:
                        deleteNode(&head, head->prev);
                        printf("Así queda la lista después de la operación: ");
                        displayList(head);
                        break;
                    case 2:
                        deleteNode(&head, head);
                        printf("Así queda la lista después de la operación: ");
                        displayList(head);
                        break;
                    case 3:
                        //reutilizaré a i, position y copia_head
                        printf("Escribe la posición en número (sin contar al cero) del nodo a eliminar: ");
                        scanf("%d", &position);
                        copia_head=head;
                        if((position<1)||(position>4))
                        {
                            printf("Posición inválida. Sólo del 1 al 4.");
                            return opcion;
                        }
                        for(i=1;i<=(position-1);i++)//también podía ser ;i<position;
                        {
                            copia_head=copia_head->next;
                            printf("Esta es i %d\n", i);
                        }
                        deleteNode(&head, copia_head);
                        printf("Así queda la lista después de la operación: ");
                        displayList(head);
                        break;
                    default:
                        printf("Opción no válida");
                        break;
                }
                break;
            /*case 3://se supone que era opción salir, pero como no es ciclo
                return opcion;//jugando un poco
                break;*/
            default:
                printf("Opción no válida");
                break;
        }
    }
}
