//doble
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertarFront(struct Node** head, int data)/*El código para doble(que es del cual nos basamos) no tiene insertToEmpty,
así que en el cirular tanto en insertFront como insertEnd tiene  código por si la lista no está vacía, por lo que aquí
tenemos que hacer lo mismo*/
//modifiqué esta función de la doble(de la cual nos basamos) que nos dío el profesor, para que se pareciera a insetarEnd, aquí no nos gusta excentricidades y complejidad, weno a mi se me hace más fácil entender la de End
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=data;

    if((*head)==NULL)//la lista está vacía
    {
        newNode->next=newNode;//si hubieras puesto esta línea del if como última, podría ser =*head;
        newNode->prev=newNode;
        (*head)=newNode;//mira según yo no importa si los cambios los hagas en head(ya habiendo hecho previamente *head=newNode) o en newNode antes de *head=newNode
        return;
    }

    //a partir de aquí comprobamos que si hay elementos en la lista, ya sea para uno o para varios, aunque si es para uno que perdida de código, pero ni modo que hacer.

    //struct Node* temp=NULL;
    //temp=(*head)->prev;

    newNode->prev=(*head)->prev;//importa este orden//=[(*head)->prev];lo que esta en corchetes hubiera sido representado por temp
    (*head)->prev->next=newNode;//[(*head)->prev]->next la parte que ves en corchetes hubiera sido representada por temp

    newNode->next=(*head);
    (*head)->prev=newNode;

    *head=newNode;//SONIA insertarEnd e insertarFront son exactamente las mismas instrucciones, a excepción de está.
}

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

    //El resto del código es para cuando se quiere insertar en el final y hay nodos

    struct Node* temp;//al principio pensé que podiamos poner a last, pero con head podemos encontrar al último, esto es posible por que el pedazo de código original era doble, pero nos ayuda ahora que sea circular
    
    temp=(*head)->prev;//°//tenp es que hasta el momento temp es el último//su declaración e inicialización podiamos ponerlo en una sola línea
    //Nota como a temp no se le crea memoria dinámica, es como hermano de head o last, raritos, bichos. 
    //tengo una pregunta, lo que yo haga con temp, va a modificar al nodo al que soy igual? Por que según yo temp es una copia. BROTHER SIIIIII, poray si quieres ver el archivo

    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=*head;
    (*head)->prev=newNode;    
}

void displayList(struct Node* head)// es para imprimir los datos de todos los nodos en la lista
{//enviamos una copia así que si podemos modificar head
    if(head!=NULL)
    {
        struct Node* temporal=head;//head es una copia, no le va a apasar nada si modificaramos al tenporal
        /*pero algo que debes de tener en cuenta es que si modificas temporal, modificas la copia de head
        Y si modifico head también modifico el temporal?*/
        
        /*
        //printf("Holis%d\n", head->next->data);
        printf("1° %d\n", head->data);
        //printf("Hola%d\n", head->prev->data);
        if(head==head->next) printf("Que onda\n");//Si solo tiene un elemento no debe imprimir que onda, no queremos que entre, no queremos que sea verdadea, queremos que se romap el ciclo 
        //lo que tu quieres es que no volvamos al incio, que nos demos cuenta cuando regresamos al inicio, necesitamos un temporal a fuerzas según yo, a fuerzitas, por que head lo utilizas para desplazarte

        head=head->next;
        printf("2° %d\n", head->data);//debe imprimir lo mismo que holis
        if(head==head->next) printf("Que onda\n");
        
        head=head->next;
        printf("3° %d\n", head->data);
        if(head==head->next) printf("Que onda\n");

        head=head->next;
        printf("4° %d\n", head->data);
        if(head==head->next) printf("Que onda\n");

        head=head->next;
        printf("5° %d\n", head->data);
        if(head==head->next) printf("Que onda\n");

        head=head->next;
        printf("6° %d\n", head->data);
        if(head==head->next) printf("Que onda\n");

        head=head->next;
        printf("7° %d\n", head->data);
        if(head==head->next) printf("Que onda\n");//queremos que imprima que onda//brother, nunca lo va a imprimir, nunca va a salir del ciclo, por que un nodo nunca va a ser igual(en cuanto a dirección) a su siguiente, mala lógica, a menos que solo haya un nodo en la lista

        head=head->next;
        printf("8° %d\n", head->data);
        if(head==head->next) printf("Que onda\n");*/

        /*do
        {
            printf("%d->", head->data);
            head=head->next;
        }while(head != head->next);*/ //si va a haber un siguiente nodo(aunque sea el mismo nodo al ser el único) por que verificamos con el if de que no estuviera vacía. Funciona incluso con solo un elemento.
        //si te confunde, un if y un while funcionan igual
        //sabes en lugar de comparar direcciones (heads ,y nodos en general), también prodriamos poner en condición la comparación de sus datas, pero más díficil y sería nadamás para presumir
        
        /*
        printf("%p\n", head->next);
        printf("%p\n", head);//imprime lo mismo que la línea anterior
        */

        /*do
        {
            printf("%d ⇄ ", head->data);//en lugar de usar temp, podías usar data para todo, funcionaba igual, solo tenías que escoger cual querías que fuera estático y cual querías que se desplazara
            head=head->next;
            //printf("#%d#", temporal->data);lo que más me sorprende es que el temporal nunca cambió (lo comprobé imprimiendo su valor)
        }while(head!=temporal);//cuando se sale del while head termina en el primer número/nodo
        */

        do
        {
            printf("%d ⇄ ", temporal->data);//en lugar de usar temp, podías usar data para todo, funcionaba igual, solo tenías que escoger cual querías que fuera estático y cual querías que se desplazara
            temporal=temporal->next;
            //printf("#%d#", head->data);
        }while(temporal!=head);//cuando se sale del while temporal termina en el primer número/nodo
        //utilicé este do por que me parece más razonable que temp se desplazara y head se quedara teniendo la dirección del primer nodo
    }
}

int main() 
{
    struct Node* head=NULL;

    insertarEnd(&head, 5);//en este programa, se puede usar insertarEnd e insertarFront para insertar pro primera vez
    insertarFront(&head, 1);
    insertarFront(&head, 6);
    insertarEnd(&head, 9);

    //Se inserta 11 después de cabeza
    insertarFront(&head, 11);
    insertarFront(&head, 15);//a insetarFront siempre debes de enviarle la dirección de la cabeza

    displayList(head);
}