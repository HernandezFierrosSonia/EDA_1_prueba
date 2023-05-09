//doble
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
};


void insertFront(struct Node** head, int data) 
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=data;

    newNode->next=(*head);

    newNode->prev=NULL;

    if((*head) != NULL)
        (*head)->prev=newNode;

    (*head)=newNode;
}

void insertAfter(struct Node* prev_node, int data)
{
    if(prev_node==NULL)
    {
        printf("Nodo previo no puede ser null");
        return;
    }

    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=data;

    newNode->next=prev_node->next;
   
    prev_node->next=newNode;

    newNode->prev=prev_node;

    if(newNode->next != NULL)
        newNode->next->prev=newNode;
}

void insertEnd(struct Node** head, int data)//este contiene a insertToEmpty
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=data;

    newNode->next=NULL;

    if(*head == NULL) 
    {
        newNode->prev=NULL;
        *head=newNode;
        return;
    }

    struct Node* temp=*head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;

    newNode->prev=temp;
}

void deleteNode(struct Node** head, struct Node* del_node)
{
    if(*head == NULL || del_node == NULL)
        return;

    if(*head == del_node)
    {
        printf("2° if\n");
        *head=del_node->next;
    }

    if (del_node->next != NULL)
    {
        printf("3° if\n");
        del_node->next->prev=del_node->prev;
    }

    if (del_node->prev != NULL)
    {
        printf("4° if\n");

        del_node->prev->next=del_node->next;
    }

    free(del_node);
}

void displayList(struct Node* node) 
{
    while (node != NULL) 
    {
        printf("%d->", node->data);
        node=node->next;
    }

    if (node == NULL)
        printf("NULL\n");
}

int main() 
{
    struct Node* head=NULL;

    insertEnd(&head, 5);/*que curioso, nuestras funciones son void, enviamos &head y no lo recibimos
    la diferencia es esta:
    void()
    {

    }
    void()
    {

    }
    */
    insertFront(&head, 1);
    insertFront(&head, 6);
    insertEnd(&head, 9);

    //Se inserta 11 después de cabeza
    insertAfter(head, 11);//insertAfter de lista doble y addAfter de lista circular añaden después de un nodo específico, en este caso añades después de head. Nota como en este add no enviamos &head, no lo necesitamos, no buscamos, por que ya debemos de enviar la dirección de un nodo específico, así como en deleteNode()

    //Se inserta 15 después del segundo nodo
    insertAfter(head->next, 15);

    displayList(head);

    //Se borra el último nodo
    printf("S\n");          // 6  -> 11 -> 15 -> 1 ->  5 -> 9
    deleteNode(&head, head->next->next->next->next->next);//entra en el 4° if

    displayList(head);//¿por qué enviamos head y no &head?

    printf("O\n");
    deleteNode(&head, head->next->next);//aquí entra a 3° y 4° if de delete node
    //según yo hay otra forma de enviar nodos, y no es como que puedeas decir borrame el 1, entonces pienso que es más díficil para el usuario

    displayList(head);

    printf("N\n");
    deleteNode(&head, head);//aquí entra al 2° y 3° if de delete node

    displayList(head);
}

/*menú
int opcion;
printf("Bienvenido a realizar una operación\n");
printf("Ingresa 1 para insertar");
printf("Ingresa 2 para eliminar");
scanf("%d", &opcion);

switch(opcion)
    case 1:
        printf("");
        break;
    case2:
        printf("");
        break;
*/