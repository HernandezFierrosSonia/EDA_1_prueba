//doble
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertarEnd(struct Node** head, int data)//¿este contiene a insertarToEmpty?SI
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
//te falta next y ver que pez con head=
    //El resto del código es para cuando se quiere insertar en el final y hay nodos
    struct Node* temp;//al principio pensé que podiamos poner a last, pero con head podemos encontrar al último, esto es posible por que el pedazo de código original era doble, pero nos ayuda ahora que sea circular
    
    temp=(*head)->prev;//°//tenp es que hasta el momento temp es el último//su declaración e inicialización podiamos ponerlo en una sola línea
    //Nota como a temp no se le crea memoria dinámica, es como hermano de head o last, raritos, bichos. 
    //tengo una pregunta, lo que yo haga con temp, va a modificar al nodo al que soy igual? Por que según yo temp es una copia. BROTHER SIIIIII, poray si quieres ver el archivo

    temp->next=newNode;

    newNode->prev=temp;

    (*head)->prev=newNode;
    
}

void displayList(struct Node* head)// es para imprimir los datos de todos los nodos en la lista
{//enviamos una copia así que si podemos modificar head
    if(head!=NULL)
    {
        /*do
        {
            printf("%d->", head->data);
            head=head->next;
        }while(head != head->prev);//si va a haber prev por que verificamos con el if de que no estuviera vacía. Funciona incluso con solo un elemento.
        */
        printf("Hola\n");
        printf("%d\n", head->data);
        printf("%p\n", head->next);
    }
}

int main() 
{
    struct Node* head=NULL;

    insertarEnd(&head, 5);
    displayList(head);
}