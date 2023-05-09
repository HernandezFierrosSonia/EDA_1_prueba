//doble
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

    if(*head == NULL)//significa que está vacía//esto es lo que va en insetarToEmpty
    {
        (*head)=newNode;
        newNode->next=*head;//podía ser =newNode;
        newNode->prev=*head;//podía ser =newNode
        return;
    }

    //El resto del código es para cuando se quiere insertar en el final y hay nodos

    struct Node* temp;//al principio pensé que podiamos poner a last, pero con head podemos encontrar al último, esto es posible por que el pedazo de código original era doble, pero nos ayuda ahora que sea circular
    
    temp=(*head)->prev;//tenp es que hasta el momento temp es el último//su declaración e inicialización podiamos ponerlo en una sola línea
    //Nota como a temp no se le crea memoria dinámica, es como hermano de head o last, raritos, bichos. 
    //tengo una pregunta, lo que yo haga con temp, va a modificar al nodo al que soy igual? Por que según yo temp es una copia. BROTHER SIIIIII, poray si quieres ver el archivo ComportamientoDeTemporalesYHaed'sYLast's

    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=*head;
    (*head)->prev=newNode; 
}

void deleteNode(struct Node** head, struct Node* del_node)//¿sirve para eliminar al incio al final y enter nodos? El último nodo lo confirmo
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

    //no modificamos los next y prev del nodo a elminar. Solo modificamos los enlaces que llegaban a el nodo a eliminar
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

    //displayList(head);//nota display significa mostrar
    
    insertarAfter(head, 11);//insertAfter de lista doble y addAfter de lista circular añaden después de un nodo específico, en este caso añades después de head. Nota como en este add no enviamos &head, no lo necesitamos, no buscamos, por que ya debemos de enviar la dirección de un nodo específico, así como en deleteNode()
    //muy importante que se embía copia de head

    //Se inserta 15 después del segundo nodo
    insertarAfter(head->next, 15);//jeje, apenas descurbrí que el after es por que inserta después de un elemento, si insertara antes del nodo enviado se llamaría insertBefore. Decir entonces que la función insertaAfter a la derecha está sobreentendido, está demás.

    //displayList(head);

    //Se borra el penúltimo nodo
    deleteNode(&head, head->next->next->next->next->next);//6° nodo en la lista(incluyendo cabeza)

    //displayList(head);

    deleteNode(&head, head->next->next);
    //según yo hay otra forma de enviar nodos, y no es como que puedeas decir borrame el 1, entonces pienso que es más díficil para el usuario

    //displayList(head);

    deleteNode(&head, head);

    //displayList(head);

    printf("Bienvenido a realizar una operación en la lista doble circular enlazada.\n");
    printf("Esta es la lista actual: ");
    displayList(head);
    //while(8)
    {//funciona bien ntp
        printf("Ingresa 1 para insertar\n");
        printf("Ingresa 2 para eliminar\n");
        //printf("Ingresa 3 para salir");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingresa 1 para insertar al final\n");
                printf("Ingresa 2 para insertar en el frente/inicio\n");
                printf("Ingresa 3 para insertar entre nodos\n");//o lo que es lo mismo en medio o simplemente no en los extremos
                scanf("%d", &insertar);
                switch(insertar)
                {
                    case 1:
                        printf("Escribe el data del nodo a insertar: ");
                        scanf("%d", &dato);
                        insertarEnd(&head, dato);
                        printf("Así queda la lista después de la operación: ");//muy atareado sería poner qué operación
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
                        copia_head=head;//espero yo que así no se modifique head
                        //la verdad es que saber si una posición es inválida es muy díficil, no solo los números negativos y el cero, , sino que también puede ser que la posición rebace nuestro número de nodos
                        //confiamos en que el usuario nos dío una posición  válida
                        for(i=1;i<=(position-1);i++)
                        {
                            copia_head=copia_head->next;
                        }
                        insertarAfter(copia_head, dato);//que weno que se envíe copia mano
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
                printf("Ingresa 3 para eliminar entre nodos\n");//o lo que es lo mismo en medio o simplemente no en los extremos
                scanf("%d", &eliminar);
                switch(eliminar)
                {
                    case 1:
                        deleteNode(&head, head->prev);//aquí serpía muy útil el last si lo hubiera, una fucnión para contar elementos no hace falta, pues tenemos prev de head
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
                        copia_head=head;//espero yo que así no se modifique head
                        //la verdad es que saber si una posición es inválida es muy díficil, no solo los números negativos y el cero, , sino que también puede ser que la posición rebace nuestro número de nodos
                        //confiamos en que el usuario nos dío una posición  válida
                        for(i=1;i<(position-1);i++)//algo que te va a sorprender es que si fuera posición 1 si entra, es por ello que le quité 1 a la posición, por que no debería entrar en posición 1, sino copia_head cambiaría al nodo siguiente de head
                        {
                            copia_head=copia_head->next;
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
            /*case 3:
                return opcion;//jugando un poco
                break;*/
            default:
                printf("Opción no válida");
                break;
        }
    }
}
