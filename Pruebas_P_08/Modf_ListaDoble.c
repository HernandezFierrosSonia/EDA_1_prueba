//Ejemplo de implementación de lista doblemente ligada
#include <stdio.h>
#include <stdlib.h>

//Creación de nodo
struct Node 
{
    int data;
    struct Node* next;//mira un Node, solo es el nombre, pues es después de todo es una estructura, aunque no cualquiera, como que se manda a llamar a si misma para crear la misma estructura
    struct Node* prev;
};/*según yo carcaterísticas de un node: es una estructura, algo que ya sabiamos que podiamos hacer en estructuras es en ellas tener miembros que son de otras estructuras, pero en un nodo
tenemos un miembro (más específicamente una variable apuntadora) del mismo tipo que el current/actual nodo*/

//Insertar nodo por el frente
void insertFront(struct Node** head, int data)//Esta fucnión sirve pa' cuando la lista esta vacía
{
    //Asignar memoria al nuevo nodo
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    //Asignar dato al nuevo nodo
    newNode->data=data;

    //Hacer al nuevo nodo como la cabeza
    newNode->next=(*head);//aquí es más fácil por que podemos encontrar el primer nodo al intánte con head
    //esta función tiene la posibilidad de que head y en si la lista esten vacios, así que puede quedar como newNode->NULL; 

    //Asignar como null al nodo prev
    newNode->prev=NULL;

    //prev a head (ahora cabeza es el segundo nodo) esta el nuevo nodo
    if((*head) != NULL)//Hay más pasos en caso de que head no esté vacía, recuerda que esta fucnión sirve pa' cuando head esta vacía-
        (*head)->prev=newNode;//esto es como nuevo para mi, por que ahora hay previo

    //Cabeza apunta al nuevo nodo
    (*head)=newNode;
}

//Insertar un nodo después de un nodo específico
void insertAfter(struct Node* prev_node, int data)//inserta después del nodo deseado
{
    //Comprobar si el nodo previo está null, el nodo previo es head 
    if(prev_node==NULL)//el prev_node es un nodo en el que a la derecha le vamos a insertar, tiene que existir, sino la función no tiene sentido
    //por lo que yo entiendo no puedes poner esta función primero en el main, pues head va a ser igual a NULL. Esto nos dice que al menos debe haber un nodo, no puede ser la primera vez que llenas
    {
        printf("Nodo previo no puede ser null");
        return;
    }

    //Asignar memoria para el nuevo nodo
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    //Asignar dato al nuevo nodo
    newNode->data=data;

    //Establecer next del nuevo nodo al next del nodo prev
    newNode->next=prev_node->next;//prev_node->next es un nodo, lo puedes ver así: lo que apunta el next del prev_node
    //has de cuenta que queremos que quede así: prev_node y después newNode 

    //Establecer next del nodo prev como nuevo nodo
    prev_node->next=newNode;

    //Establecer prev del nuevo nodo al nodo previo
    newNode->prev=prev_node;

    //Establecer prev del nuevo nodo a next del nuevo nodo
    if(newNode->next != NULL)
        newNode->next->prev=newNode;
}

//Insertar un nuevo nodo al final de la lista
void insertEnd(struct Node** head, int data)//este también sirve pa' cuando la lista está vacía
//esta función es un poquito díficil por que no tenemos cómo llegar al final de manera directa, pues no tenemos last, but head
{
    //Asignar memoria para el nodo
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

    //Asignar dato al nuevo nodo
    newNode->data=data;

    //Asignar null al siguiente del nuevo nodo
    newNode->next=NULL;//es que no es circular, por eso el next puede llegar a apuntar a NULL

    //Si la lista ligada está vacía, hacer el nuevo nodo como cabeza
    if(*head == NULL) 
    {
        newNode->prev=NULL;//y pus el next ya lo pusimos a NULL
        *head=newNode;
        return;
    }

    // almacenar el nodo cabeza temporalmente (para uso posterior)
    struct Node* temp=*head;//nota esta línea la moví pa' abajo 

    //Si la lista ligada no está vacía, recorrer hasta el final de la lista ligada//lo que pasa es que aquí no hay last, solo head
    while(temp->next!=NULL)
        temp=temp->next;
    //Ahora, el último nodo de la lista ligada es un nodo temporal

    //Se asigna next del último nodo (temp) al nuevo nodo
    temp->next=newNode;

    //Se asigna prev del nuevo nodo a temp
    newNode->prev=temp;
    //ehi, y el newNode->prev ya lo habiamos puesto a NULL
}

//Eliminar un nodo de la lista ya teniendo su dirección
void deleteNode(struct Node** head, struct Node* del_node)
/*para borrar en las Lista Doble es difente que la Lista Circular, aquí no envias un key (el cual es un entero y se compara con los datas)
, aquí envias un nodo, entonces es importante notar que ya tienes la dirección del nodo a borrar, ya no tienes que buscarlo, esta función se
encarga de borrarlo así como también antes cambiar su next y prev*/
{
    //Si cabeza o del es null, no se puede borrar
    if(*head == NULL || del_node == NULL)//la única forma en que se me ocurre que head=NULL es por que no hemos insertado y estamos tratando de eliminar
    //¿pero por qué del_node sería NULL? creeme el usuario ni siquiera se le ocurriría poner NULL
        return;

    //Si del_node es el nodo cabeza, apuntar el apuntador de la cabeza al siguiente de del_node
    if(*head == del_node)//no sé como pero velo así if(head==del_node)
    //no he econtradi ningún ejemplo en el que entre
    {
        printf("2° if\n");
        *head=del_node->next;
        //podriamos poner aquí return;?
    }

    //Se encarga de verificar que del_node no sea el último nodo(mi pregunta es qu'e pasa si es el último nodo? Respuesta=no entra a este if, pero si entra al 3° if
    if (del_node->next != NULL)
    {
        printf("3° if\n");
        del_node->next->prev=del_node->prev;/* puedes verlo así del_node->next->prev=nodo;
        Mira [del_node->next->prev] no es un nodo(aunque si se le da =nodo, es decir si se le da valor de nodo, weno el valor es la dirección de un nodo), es un next (refiriendome al enlace, en dibujo es una flechita →) aunque no sabría explicarlo, (del_node->next)->prev puedes verlo como que la parte que esta en paréntesis si es un nodo, 
        pero estaría mal de alguna manera verlo así, pues podrías llegar a pensar que (del_node->next)->prev si lo que esta en paréntesis es un nodo entonces [(nodo)->next] lo que está en corchetes es un nodo, pero no, por que como ya dijimos, de alguna manera es un next,
        La única forma que pude entender la línea de código anterior fue de esta manera. Pero es que una vez dicho esto, me cuesta entender qué es correcto, por que unNodo->next->next si es un nodo.
        
        Pues mira, cuando veas un nodo->next->next= o un nodo->next->prev= o un nodo->prev->next= se refiere a un enlace(next, prev y next respectivamente), despues de todo van a ser igual a un nodo.
        Cuando veas funcion(nodo->next->next) o funcion(nodo->next->prev) o funcion(nodo->prev->next) se refiere a un nodo.
        */
        /*Mira voy a escribir esto para el reporte, pero no lo leas mana, básicamente voy a describir qué hace la línea anterior
        significa que el prev del nodo después del NODO A ELIMINAR apunte al nodo anterior de NODO A ELIMINAR*/

        //así que si te das cuenta no eliminamos de la memoria al NODO A ELIMINAR, solo lo perdemos de vista, lo olvidamos, cortamos todo elnacxe/conexión que nos pueda hacer llegar a él
    }

    //Se encarga de verificar que del_node no sea el primer nodo(pues pa' ello ya tenemos el segundo if de esta función, si ese 2° if tuviera return ¿ya no tendriamos este if?) Respuesta: el segundo if no puede tener return por que puede entrar al 3° if, ya lo confirmé.
    if (del_node->prev != NULL)
    {
        printf("4° if\n");

        //printf("del_node->prev->next es %d\n", del_node->prev->next->data);//imprime el data de del_node. Lo escribo nadamas por curiosidad, no te sirve en tu explicación, ni te sirve para entender algo, pero nadamás si te da curiosidad.

        //no es posible imprimir un nodo, a menos que quiera ves la dirección del nodo.., en cambio si quieres visualizar mejor como esta tu lista puedes imprimir sus datas

        del_node->prev->next=del_node->next;//del_node->prev->next=(del_node->next) la parte que pusé en paréntesis es un nodo, pero eso vale NULL cuando el elemento a borrar es el último nodo
        /*Mira voy a escribir esto para el reporte, pero no lo leas mana, básicamente voy a describir qué hace la línea anterior
        significa que el next del nodo anterior al NODO A ELIMINAR apunte al nodo siguiente del NODO A ELIMINAR*/
        
        //ERROR pensar que del_node->prev->next es lo mismo que del_node, como que pensé que se eliminaban

        /*del_node->prev->next=NULL; esto si funciona (borrando la otra línea de código) pero solo para cuando el elemento a borrar sea el último. 
        Mi conclusión es que tienes razón en cuanto a =del_node->next es lo mismo que =NULL, PERO solo cuando es el último nodo el que se va a a eliminar*/

        //ERROR: pensar que del NODO A ELIMINAR hay que hacer algo con enlaces (sus next y prev), algo como apuntarlos a NULL, pero en realidad no, simplemente olvidamos al NODO A ELIMINAR, no es como que devilvamos su memoria con free o algo así.
        /*MI debilidad al inciio de la practica es cuando se va a a eliminar un nodo que p/e esta en el medio(es decir no está a los extremos), no sepa conectar el nodo anterior (conectar su enlace de next) al NODO A ELIMINAR con el nodo siguiente al NODO A ELIMINAR y viceversa; 
        no saber conectar el nodo siguiente (conectar su enlace de prev) al NODO A ELIMINAR con el nodo anterir al NODO A ELIMINAR*/

        /*otros errores derivados de no recordar que por ejemplo nodoCualquiera->next es un nodo, y p/e nodoCualquiera->prev es un nodo, en cambio nodoCualquiera->next->prev es un prev y nodoCualquiera->prev->next es un next*, 
        Mira, los que son next o prev si se les pone =unNodo, por que necesitan guardar un nodo, necesitan guardar una dirección de un nodo. 
        En cambio los que ya son nodos no se les da =unNodo, se les puede igualar (==) con nodos, pero no se puede hacer Nodo=unNodo, son estructuras, no puedes poner estructura=unaEstructura. Mira no te lo confirmo, pero haciendo pruebas
        del_node->prev=del_node->next; me dió segmentation fault, pero no te puedo confirmar que hacer structura=structura me de segmentatio fault*/
        
        //ERROR muy estúpido y raro, pensar que un ->data puede valer NULL

        //así que si te das cuenta no eliminamos de la memoria al NODO A ELIMINAR, solo lo perdemos de vista, lo olvidamos, cortamos todo elnacxe/conexión que nos pueda hacer llegar a él
    }

    /*nota si entra al 3° y al 4° if es por que el nodo a eliminar no esta en los extremos, es decir esta en el medio
    así que si es posible que entre a dos if*/

    //Se libera memoria de del_node
    free(del_node);//ptr es pointer
}

//Imprimir la lista doblemente ligada
void displayList(struct Node* node) 
{
    //struct Node* last;//ya te extrañaba last :c//ni modo lo quité

    while (node != NULL) 
    {
        printf("%d->", node->data);
        //last=node;//¿para qué es esto? pos lo borré
        node=node->next;
    }

    if (node == NULL)
        printf("NULL\n");//¿pa' qué?¿qué necesidad?
}

int main() 
{
    //Se inicializa un nodo vacío
    struct Node* head=NULL;//no entiendo pa' que ponerle NULL, si de todas formas este apuntador lo voy a utilizar

    insertEnd(&head, 5);//oki, esto va a estar díficil//tengo una pregunta ¿a fuerzas empiezo con insertEnd?
    insertFront(&head, 1);
    insertFront(&head, 6);
    insertEnd(&head, 9);/*que curioso, nuestras funciones son void, enviamos &head y no lo recibimos
    la diferencia es esta:
    struct Node* add(struct Node* last)//circular
    {
        return last;
    }
    int main()
    {
        last=add(last);
    }

    void insert(struct Node** head)//doble//yo no lo llamaría head, pues es un apuntador que apunta a head, así que no es exactamente head
    {
        if((*head)==)
            (*head)=
    }
    int main()
    {
        insert(&head);//enviamos la dirección de un apuntador
    }
    */

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
//weno al menos aquí si se usa head
//apliqué deletNote en el último nodo, en un nodo de en medio y en el primer nodo, respectivamente.
