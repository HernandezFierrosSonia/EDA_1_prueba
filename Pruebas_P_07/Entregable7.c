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

void deleteNode(struct Node** lasti, int key)
{
    if(*lasti==NULL) return;

    if((*lasti)->data==key && (*lasti)->next==(*lasti))
    {
        free(*lasti);
        *lasti=NULL;
        return;
    }

    struct Node* temp=*lasti;
    struct Node* d;

    if((*lasti)->data==key)
    {
        while(temp->next != *lasti) temp=temp->next;

        temp->next=(*lasti)->next;
        free(*lasti);
        *lasti=temp->next;
    }

    //Recorrido al nodo que va a ser eliminado
    while(temp->next!=(*lasti) && temp->next->data!=key) temp=temp->next;
    
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

bool searchData(struct Node **lasti, int value)//esta función no modifica, es como peek
{//lo llamé lasti pa' que no haya confusión, pues se usa con * demás a diferencia de last en main
    struct Node* temp;//en lugar de llamarlo p lo llamé temp de temporal
    temp=(*lasti);

    do//aquí quise hacerle diferente al addAfter, en lugar de empezar por last->next empecé por last
    {
        return true;
    }while(temp!=(*lasti));
    return false;
}

bool search(struct Node* last, int value)
{
    struct Node* temp;//en lugar de llamarlo p lo llamé temp de temporal
    temp=last;

    do//aquí quise hacerle diferente al addAfter, en lugar de empezar por last->next empecé por last
    {
        return true;
    }while(temp!=last);
    return false;   
}

int main() 
{
    int valor; 
    bool resultado1=0;
    bool resultado2=1;
    //printf("%d", resultado);
    struct Node* last;
    last=NULL;//hay que ponerlo a NULL, por que aun no va a guardar dirección pero necesitamos enviarlo para que eso ocurra

    printf("Bienvenido. Introduzca el valor a buscar en la lista ligada circular: ");
    scanf("%d", &valor);

    last=addToEmpty(last, 2);//last así escrito, ya sea en un printf o solo para utilizarlo, es una dirección de una variable primitiva(int, float, bool) o apuntadora

    last=addEnd(last, 20);
    last=addEnd(last, 22);
    last=addEnd(last, 3);

    last=addFront(last, 19);
    last=addFront(last, 55);
    last=addFront(last, 56);

    last=addAfter(last, 10, 2);
    last=addAfter(last, 17, 3);
    last=addAfter(last, 1, 2);

    traverse(last);

    deleteNode(&last, 20);

    deleteNode(&last, 17);

    traverse(last);

    deleteNode(&last, 55);

    traverse(last);

    resultado1=searchData(&last, valor);

    if(resultado1==true)
    {
        printf("searchData. Tu valor ¡SI ESTÁ!");
    }
    else 
    {
        printf("searchData. Tu valor no está :c");
    }
    /////////////////////////////////////////
    resultado2=search(last, valor);/*estoy enviando last, 
    el cual es igual a una dirección. last debe tener la dirección de una varible de su mismo tipo, es decir struct Node, 
    aunque es bien curioso, es como hacer 
    int *p=jgwduk;
    int *pointer=g2sqw;
    p=pointer;

    solo que es 

    struct Nodo *p=jgwduk;
    struct Nodo *pointer=g2sqw;//digamos que en este, su memoria g2sqw, es por que es dinámico, y que de no ahber sido a sí, no sería *, weno no sería apuntador, solo sería sruct Nodo. Pero que gracias a que es memoria dinámica(apuntador) puede ser comparado con last. Es digamos una serendipia, algo conveniente pues.
    p=pointer;

    ¿last tiene las propiedades de los nodos(data, next y prev)?
    Es correcto decir que last es un nodo, pero entender por qué es raro, pues no se iniciliada como los newNode, se inicializa robando la información de los nweNode,
    last es un nodo que chupa la información(prev, next y data) del nodo que más le guste (ACOSADORA!),
    last es un nodo cuya información(prev, next y data) varía constantemente. 
    Last se hace nodo al alimentarse de la dirección de otros nodos, ¿la dirección de newNode (así se usa sin *) es esecialmente su información(data, next y prev)? quien sabe, 
    ¿cómo es que teniendo la dirección de un nodo tengo su información? lo que pasa es que se hace complejo explicarlo por que no es como imprimir solo un número, aquí hay además enlaces.
    Por que para mi se me hace fácil decir que en el siguiente ejemplo last tiene el valor(su única información es un entero, no data o enlaces) de newNode
        int *last;
        int *newNode=(int)malloc(1*sizeof(int*));
        last=newNode;

        *newNode=7;
        printf("PRESTA ATENCIÓN %d\n", *last);//imprime 7//last tiene la información de newNode

        *last=27//extra, con last se puede modificar el valor de newNode
        printf("%d\n", *newNode);//imprime 27

    
    Lo que pasa es que empieza siendo un apuntador, pero los nodos son apuntadores también, 
    lo curioso es que ambos son de tipo struct, la única diferencia es que los nuevos nodos son 
    dinámicos y last y head no son dinámicos, supongo que por que su existencia no hace falta que a lo largo del programa se eliminen.
    
    Los apuntadores head y last al ser struct Node, tienen las mismas propiedades que los nuevos nodos, así que técnicamente last si es un nodo.
    Lo que pasa es que su información(next o prev) cambia constantemente a lo largo del programa. Lo que pasa es que nos confunde que algo sea node y sea un tipo de dato, por que es lo mismo.
    Ve a last como un apuntador de tipo de dato(tipo de dato:struct Node) en lugar de como un nodo, lo digo por que los nuevos nodos también son apuntadores, pero son apuntadores por que son memoria dinámica,
    podriamos haberlo hecho sin memoria dinámica y los nodos no sería apunatdores(*). 
    
    Recuerda, struct1=struct2 es correcto, no puedes comparar estructuras(==), nada que ver pero los miembros si se pueden comparar(==) e igualar(=). 
    Así que last=newNode, son dos estructuras, la estructura last toma el valor de la estructura newNode. Casualmente las dos son apuntadores, 
    direcciónQueGuardaElNodoLast=direcciónDenewNode; por que estas ocupando apuntadores sin su *, apuntador sin su asterísco es un dirección ó guardar una dirección.
    
    */

    if(resultado2==true)
    {
        printf("search. Tu valor ¡SI ESTÁ!");
    }
    else 
    {
        printf("search. Tu valor no está :c");
    }
    

    return 0;
}
//¿puedo ocupar stdbool.h?