//Código para implementar operaciones en una lista ligada circular

#include <stdio.h>
#include <stdlib.h>

struct Node//verás que se vuelve a llamar a sí misma
{//bro nunca terminare de entender estructuras, me acuerdo que en ajedrez ni podía usarlas normal
    int data;
    struct Node* next;//esto es una referencia(enlace)/apuntador al siguiente nodo de la lista
    /*por qué no se hace infinito? 
    Pienso que no es como una función dentro de una función, no creo que esto sea recursividad
    , pero weno es una acción que crea más acciones infinitas*/
};

struct Node* addToEmpty(struct Node* last, int data)//es una función muy importante
{
    if(last!=NULL) return last;//por qué es tan importante que esté igualada a NULL?
    
    //asignar memoria al nuevo nodo
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));//nunca me voy a aprender la sintaxis de malloc

    //se asigna dato al nuevo modo
    newNode->data=data;//curioso es que no hay problema si una variable se llama igual que el miembro

    //se asigna como last al nuevo modo
    last=newNode;//tanto last como newNode son nodos, es como que last guarda una copia

    //se crea enlace para si mismo
    last->next=last;//ah caray, newNode no es el protagonista, pero...¿por qué crear a newNode entonces? hasta lo que voy entendiendo no es necesario, ¿por qué no simplemente crearle memoria dinámica a last?

    return last;//regresamos una dirección, la de newNode(por que eso guarda last) y así mismo con la característica que solo tiene last(no la tiene newNode) que es hacia dónde apunta next//jeje en mi opinión más complejo de lo necesario
    //estaba más chido si la función recibia la dirección de last y ya de ahí obteniamos lo que queriamos, es más, ni hubieramos tenido que regresar algo
}//fijate que al final de la función no queda rastro del newNode, me refiero al nombre, creo que no recordamos a los nodos por sus nombres

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
    if(last==NULL) return addToEmpty(last, data); //pos qué no ya vale algo last ahí en el main? lee bien sonia, jaja, me espantas, dice ==
    //literal la línea anterior solo se va a ajecutar cuando el programador se equivoque y ponga un addEnd antes de un addToEmpty, este tipo de funciones se me hacen bien inútiles, programamos para cuando el usuario se equivoca

    //Se asigna memoria al nuevo nodo
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    
    //Se agrega dato al nuevo nodo
    newNode->data=data;

    //Se almacena la direción del nodo cabeza al siguiente del nuevo nodo
    newNode->next=last->next;//es por que agregamos al final//con está línea concluimos que last siempre va a estar al final/derecha, a diferencia de head

    //Se apunta al actual último nodo al nuevo nodo
    last->next=newNode;//yo sé que ya lo sabes, pero los next apuntan a nodos, aunque cuando veas holis->next->next ¿es un next que apunta a otro next? no, yo no lo veo así, yo lo veo como el next del (next de holis)

    //Se hace al nuevo nodo como el último nodo
    last=newNode;

    return last;//aquí si entiendo que regresas al nuevo last
}

//Insertar nodo después de un nodo específico
struct Node* addAfter(struct Node* last, int data, int item) 
{
    //Se revisa si la lista está vacía
    if(last==NULL) return NULL;//mira esto es muy útil cuando quieres terminar una función, pero no puedes devolver algo válido

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
void deleteNode(struct Node** last, int key)//es el único que tiene un **
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

//creo que pa' imprimir la lista
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
    struct Node* last=NULL;/*esta línea es crear un apuntador que guarda la dirección de un tipo de dato como struct Node
    Lo que se me hace curioso es que no quiero la dirección de la variable, por algo la estoy modificando a NULL*/
    //Voy descubriendo que no hay función para crear un nodo
    //a este nodo podiamos haberle creado su memoria aquí, ¿te preguntabas por que era pointer? por que es memoria dinámica, las variables son pointer
    //segpun yo era lo mismo que last=NULL;

    /*muy interesante a last no se le crea memoria dinámica, el addToEmpty le crea memoria dinámica al newNode, pero es
    curioso que cuando last=newNode en esa función pero a last no le creamos memoria dinámica*/

    last=addToEmpty(last, 2);/*¿lo debemos aplicar una sola vez a fuerzas? es que supongo que todos los add crean un newNode*/
    /*¿que es last? debe de ser una dirección, pero para esta primera vez la dirección es NULL, entonces enviamos NULL, mejor dicho, enviamos la dirección NULL, 
    por que eso es lo que recibe la función, una dirección*/
    //last ahora vale una dirección, dicho de otra forma el apuntador last vale una dirección

    last=addEnd(last, 20);/*¿cuál es la finalidad de last? sabes es bien curioso pero la única forma de 
    llegar a un nodo es por un único nodo(el cual es last), así que por eso siempre tenemos presente a last, por que p/e
    para llegar al primer nodo de la lista utilizaré last, para llegar a un nodo en medio de la lista utilizaré last,
    y es que como tal lista no es, necesito de nodos (empezando por last) para llegar a otros nodos para llegar a otros nodos*/
    last=addEnd(last, 22);
    last=addEnd(last, 3);

    last=addFront(last, 19);
    last=addFront(last, 55);
    last=addFront(last, 56);

    last=addAfter(last, 10, 2);
    last=addAfter(last, 17, 3);//el item es lo que tiene que buscar, no es una posición, supongo que es lógico pues no es un arreglo
    last=addAfter(last, 1, 2);

    traverse(last);

    deleteNode(&last, 8);//enviamos la dirección del apuntador

    traverse(last);

    return 0;
}
//antes no entendía head, ahora no entiendo last
//todos los nodos creados se llaman newNode, hasta los que llegan a ser last, pero no nos importa su nombre por que no los utilizamos por su nombre si no por enlaces(next) de los nodos(empezando por last)