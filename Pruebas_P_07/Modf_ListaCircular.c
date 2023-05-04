//Código para implementar operaciones en una lista ligada circular

#include <stdio.h>
#include <stdlib.h>

struct Node//verás que se vuelve a llamar a sí misma
{//bro nunca terminare de entender estructuras, me acuerdo que en ajedrez ni podía usarlas normal
    int data;
    struct Node* next;//mira el * es por que guarda direcciones, next guar5da direcciones, weno, tecnicamente apunta a nodos, pero los nodos son direcciones, es por eso que es struct Node, por que ese tipo de dato guarda, no por que sea un ciclo
    //esto es una referencia(enlace)/apuntador al siguiente nodo de la lista
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
    newNode->next=last->next;//en este caso last->next es un nodo, es fácil saberlo por que los next no apuntan a otros next, apuntan a un nodo

    //Se hace el nuevo nodo como la ¿cabeza?
    last->next=newNode;
    
    //ojo que aquí no se se hace last=newNode; por lo que concluimos que last siempre estará en el último elemento de la derecha

    return last;//supongo que regresa last por que se modificó, y como de este si tenemos que tener rastro (no como los newNodes por que esos se conectan pero se pierden)
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
    newNode->next=last->next;/*rear y front es como lo mismo, mi pregunta es ¿esta bien decir que en este programa la lista circular se comporta como una pila?, es que insertamos donde este last. Respuesta: No,
    no esta bien decir eso, por que last es nuestra referencia, con last nos ubicamos, por eso la usamos en todo tipo de add's, pero en realidad para front y end insertra no es exactamente "donde este last", 
    por que insertamos antes(addFront) y después(addEnd)*/

    //Se apunta al actual último nodo al nuevo nodo
    last->next=newNode;//yo sé que ya lo sabes, pero los next apuntan a nodos, aunque cuando veas holis->next->next ¿es un next que apunta a otro next? no, yo no lo veo así, yo lo veo como el next del (next de holis)

    //Se hace al nuevo nodo como el último nodo
    last=newNode;

    return last;//aquí si entiendo que regresas al nuevo last, no bro, last significa último en entrar, no es como rear
}

//Insertar nodo después de un nodo específico
struct Node* addAfter(struct Node* last, int data, int item) 
{
    //Se revisa si la lista está vacía
    if(last==NULL) return NULL;//mira esto es muy útil cuando quieres terminar una función, pero no puedes devolver algo válido

    struct Node *newNode, *p;//en lugar d ep podías poner temp

    p=last->next;//es decir el primer nodo. por que last es como rear (confirmado)
    //last->next es un nodo, para que algo sea igual a ese nodo tiene que ser struct Node*

    do
    {
        if(p->data==item)//Si se encontró el elemento, se coloca el nuevo nodo después de él
        //p->data es un entero. Empezamos por el primero
        {
            //Se asigna memoria al nuevo nodo
            newNode=(struct Node*)malloc(sizeof(struct Node));

            //Se agrega dato al nodo
            newNode->data=data;

            //Se hace como siguiente el nodo actual siguiente del nuevo nodo
            newNode->next=p->next;//p->next es un nodo//curioso es que esta línea también funciona por si p es el último nodo
            
            //Se pone al nuevo nodo como el siguiente de p
            p->next=newNode;//los next siempre apuntan a un nodo o a NULL

            //Si p es el último nodo, se hace al nuevo nodo como el último nodo
            if(p==last) last=newNode;
            return last;//ojo, con que entre una vez a este if y nos regresamos
        }

        p=p->next;//como empezamos en el primer nodo vamos avanzando hacia allá ->
    } while(p!=last->next);//esta condición es pa' que no demos la vuelta, pa' que no repitamos pues
    //p y last->next son enteros

    printf("\nEl nodo dado no esta presente en la lista.");
    return last;
    
}

//Borrar un nodo
void deleteNode(struct Node** lasti, int key)/*es el único que tiene un **, es que le envié &last, el cual es la dirección de un apuntador,
es como escirbir struct Node** lasti=&last; */
//mira manta ya investigué y es lo mismo *lasti que en otras funciones es last, solo que el profesor nos quería hacer sufrir, si no mre crees revisa el documento apuntadores_entendiendolos_con_struct_y_memDinamic
{
    //Si la lista ligada está vacía
    if(*lasti==NULL) return;//es lo mismo que last==NULL en main y en las otras funciones

    //Si la lista contiene solo un nodo
    if((*lasti)->data==key && (*lasti)->next==(*lasti))/*utilizar *lasti en esta función(ya sé que es struct Node**lasti) equivale a usar last en main, 
    last en main es una dirección*/
    //brother es muy importante poner los paréntesis de (*lasti)->, por que como que se equivoca si pones *lasti->, por cierto (*lasti) es lo mismo que last en otras funciones
    {
        free(*lasti);//mira de algo estoy segura, con esto eliminamos el cuadro que viene siendo el nodo, lo que viene siendo data y next
        //es como hacer en el main free(last), sin embargo last y *last no es lo mismo, por lo que este free(una dirección)
        *lasti=NULL;//no sé pero si no haces *lasti=NULL queda valiendo la dirección que nos dio la memoria dinámica, no entiendo por qué, es que *lasti (o last en main) valen un nodo, así que si no tiene un nodo al qué señalar el last, entonces =NULL tal como en el main
        return;//por que no puede devolver algo
    }

    struct Node *temp=*lasti;//tu ve ese *lasti como last en cualquier función incluyendo main
    struct Node *d;

    //Si se va a eliminar el último
    if((*lasti)->data==key)
    {
        //Encontrar el nodo antes del último nodo
        while(temp->next != *lasti) temp=temp->next;//eso jeje, encuentra el anterior a last o *lasti, sin modificar last o lo que e slo mismo *lasti

        //Apuntar un nodo temporal al siguiente del último, es decir el primer nodo
        temp->next=(*lasti)->next;
        free(*lasti);//mira de algo estoy segura, con esto eliminamos el cuadro que viene siendo el nodo, lo que viene siendo data y next
        *lasti=temp->next;//ah caray, por que cambiamos a last al frente, si de hecho eso pasa
        //se me hace bien curioso que a pesar de haber liberado *lasti, aun podamos ocuparlo, creo que nunca voy a entender free()
        //temp->next es un nodo
    }

    //Recorrido al nodo que va a ser eliminado
    while(temp->next!=(*lasti) && temp->next->data!=key) temp=temp->next;
    //iniciamos con que temp=last así que esta parte temp->next!=lasti, es para que no completemos una vuelta
    //y esta parte temp->next->data!=key yo entiendo que es para que quede de forma que el siguiente a temp sea key

    //Si el nodo a eliminar se encuentra
    if(temp->next->data==key)//por que no sabemos si lo encontró
    {
        d=temp->next;
        temp->next=d->next;
        free(d);//nunca entenderé free(), y si lo entiendo debería ser posibloe asignarle un valor a d, pero ahora que lo veo d no es memora dinámica
    }
}

//creo que pa' imprimir la lista
void traverse(struct Node* last)//aquí recibo la dirección del nodo que guarda last
{
    struct Node* p;

    if(last==NULL)//las es una dirección, como nota NULL y direcciones tienen una bella amistad
    {
        printf("La lista está vacía");
        return;//por que no puede devolver algo
    }

    p=last->next;//last->next es un nodo y es el primero de hecho, siempre es el primero.

    do
    {
        printf("%d ", p->data);
        p=p->next;

    } while(p!=last->next);//p y last->next son nodos, esta línea evita que empecemos de nuevo, es decir que demos la vuelta
    printf("\n");
}

int main() 
{
    struct Node* last;/*=NULL;esta línea es crear un apuntador que guarda la dirección de un tipo de dato como struct Node
    Lo que se me hace curioso es que no quiero la dirección de la variable, por algo la estoy modificando a NULL*/
    //Voy descubriendo que no hay función para crear un nodo
    //a este nodo podiamos haberle creado su memoria aquí, ¿te preguntabas por que era pointer? por que es memoria dinámica, las variables son pointer
    //segpun yo era lo mismo que 
    last=NULL;

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

    last=addFront(last, 19);//recibimos una copia del last actualizado (con lo que le hicimos dentro de la función) y la hacemos la original(con el igual)
    last=addFront(last, 55);
    last=addFront(last, 56);

    last=addAfter(last, 10, 2);
    last=addAfter(last, 17, 3);//el item es lo que tiene que buscar, no es una posición, supongo que es lógico pues no es un arreglo
    last=addAfter(last, 1, 2);/*supongo que siempre tengo que devolver last actualizado y no devulevo los newNode's por que como que con after voy a acceder a cualquier cosa
    , pero todas estas funciones me regresan una copia de last?..., ¿que es exactamente esa copia?, entender cómo fue creado last es muy díficil, por que a todas las funciones le
    estoy mandando la dirección que guarda last, en un principio esa dirección era NULL, pero luego en addToEmpty me dieron la dirección de un nodo, 
    desde entonces last vale la dirección de los nodos(entonces last noe s exactamente un nodo, ni parecido...)*/

    traverse(last);

    deleteNode(&last, 20);//enviamos la dirección del apuntador
    //deleteNode elimina en base a buscar un número entero en tu lista

    deleteNode(&last, 17);

    traverse(last);

    deleteNode(&last, 55);

    traverse(last);

    return 0;
}
//antes no entendía head, ahora no entiendo last. last guarda direcciones, es un apuntador, no es un nodo, guarda la dirección del último nodo, ese nodo como todos se llama newNode, solo que tiene un bicho pegado a él que absorbe su dirección y se llama last
//todos los nodos creados se llaman newNode, hasta los que llegan a ser last, pero no nos importa su nombre por que no los utilizamos por su nombre si no por enlaces(next) de los nodos(empezando por last)
//a pesar de que es lista circular, al imprimirlo no se ve como circulo, con esto quiero decir que hay front y rear/end