// Implementación de cola circular en C

#include <stdio.h>
#define SIZE 5

int arreglo[SIZE];//a mi profesor anterior no le gustan las variables globales
int front=-1, rear=-1;/*supongo que nos trae menos problemas que si empezara en 0.
Ya que si empieza en cero, en el caso de enqueue y por lo tanto uso de rear, primero agregaría el item pues ya esta en array[0]
y después sumaría 1 a rear, así que la desventaja aquí es que nos deja arriba de donde agregamos, por lo que 
en otras funciones tendrían que quitarle 1 a rear*/

// Se revisa si la cola esta llena
int isFull_circular() 
{
    if((front==rear+1)||(front==0 && rear==SIZE-1))//si entra esta llena
    /*lo que pasa en el primero, rear ya haya dado una vuelva y puede estar en el índice 0 o más, pero no en el de hasta arrriba(el índice mayor pues) ya que front debe estar arriba de rear, 
    entonces rear estaría luego luego debajo de front si es que estuviera llena.
    En el segundo caso, si está apuntando a índice 0 es por que front queda apuntando a lo que quitaría si llamaran a dequeue, 
    . Date cuenta que el primer caso es para cuando rear está en cero o más, pero no en el último índice, PERO importante front esta en algo distinto a cero. Este caso es para cuando front está en el índice cero. 
    aunque...que pasa si nunca desencolamos y por lo tanto rear vale -1. 
    No, sé, me cuesta entender como es que este if cubre todos los posibles casos.
    Pero en caso de rear, hay que tener en cuenta que rear es índice e importante, queda apuntando justo lo que insertó, 
    así que aunque este en el índice más alto, siempre va a estar por debajo de nuestra capacidad máxima(llamada SIZE)
    por lo que o a rear le sumamos 1 o a SIZE le quitamos 1.
    */
        return 1;//true
    return 0;//false//jeje, por fin encontramos return que tiene sentido
}

// Se revisa si la cola esta vacia
int isEmpty_circular() 
{
    if(front==-1)/*por si no lo has notado, hay una razón del por qué hay funciones vacías, es por que no creamos un queue, esto pues struct Queue* queue.
    es por ello que front y rear Y el arreglo son globales*/
    /*front sirve para quitar. La única manera de que front este en algo distinto a -1 es por que debe de haber algo en la cola, 
    es decir debe de haber un elemento, dicho de otra forma rear debe de estar en cero o más y por lo tanto front igual front.
    Jejeje eso no emplica mucho SONIA
    ¿Qué pasa si rear y front apuntaban al único elemento el cual está en índice 3, pero desencolamos? ¿a qué apuntando front a 4? y también importante ¿que pasa con rear? 
    ¿Que pasa si front esta en medio y no en -1, existe este caso tan siquiera?*/
        return 1;
    return 0;
}

// Añadir un elemento
void enQueue(int item) 
{
    if(isFull_circular())
        printf("\n La cola esta llena!! \n");
    else 
    {
        if(front==-1)//teniendo en cuenta que ya descartamos que este llena, significa que hay espacios al menos en el primer índice, es decir índice 0 
            front=0;
        rear=(rear+1)%SIZE;//0%5=0//sumamos en rear, por que está señalando aun el último elemento que metimos
        /*nunca entendí el porciento, ¿por que simplemente no poner rear=rear+1?, de cualquier forma, 
        se supone que si rear llega a en este caso 5, rear se hace 0, pero ¿para qué nos sirve eso? 
        si de todas maneras no dejamos que se llene la cola*/
        arreglo[rear]=item;
        printf("\nInsertado %d", item);
    }
}

// Eliminar un elemento
int deQueue()//no eliminamos, solo perdemos el rastro
{
    int element;
    if(isEmpty_circular()) 
    {
        printf("\n La cola esta vacía !! \n");
        return(-1);//deveríamos poner algo en main por si regresa -1, jeje. Pa' qué?, si no realizó ninguna acción y ya mandamos mensaje de error.
    }
    else 
    {
        element=arreglo[front];/*entonces...front apunta al elemento que va a quitar, por supuesto, 
        no va a quedar apuntando a algo vacío*/
        if(front==rear)
        /*apoco pueden quedar juntos????? Esto solo sucede en un caso, cuando solo hay un elemento y estamos en el primer índice(no es correcto decir que estamos en el inicio a contniuación te explico por qué)
        sin embargo no es correcto decir que a esta condición entra cuando estamos en el inicio, pues lo que hace el contenido/instrucciónes/acciones de este if hace "reinicar la cola"
        pero algo es seguro, ambos índices(front y rear representan índices)apuntan a cero.
        hay dos formas de llegar hasta ahí,
        cuando solo hemos insertado un elemento o, cuando ya dimos una vuelta entera y solo hay 1 elemento.En esos dos 
        casos, rear queda apuntando al que insertó y front queda apuntando al próximo por quitar. 
        */
        {
            front=-1;
            rear=-1;
        } 

        else//me cuesta imaginar que casos abarca este else
        {
            front=(front+1)%SIZE;//si front estaba en algo que no es cero(ya expliqué por qué), por ejemplo 3, entonces front=3+1%8=4, esto cobra sentido por que front se mueve hacia arriba por eso suma 1 cuando queremos "eliminar" un elemento.
        }
        printf("\n Elemento eliminado -> %d \n", element);
        return(element);
    }
}

// Se muestra la cola
void display() 
{
    int i;
    if(isEmpty_circular())
        printf(" \n Cola vacia\n");
    else 
    {
        printf("\n Frente -> %d ", front);
        printf("\n Elementos -> ");
        for (i=front; i!=rear; i=(i+1)%SIZE) 
        {
            printf("%d ", arreglo[i]);
        }
        printf("%d ", arreglo[i]);
        printf("\n Parte trasera -> %d \n", rear);
    }
}

int main() 
{
    // Fracasa porque front=-1//que curioso, antes cola simple no restaba -1
    deQueue();

    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);

    // Fracasa en encolar porque front==0 && rear==SIZE-1 //que curioso, antes cola simple no restaba -1
    enQueue(6);

    display();
    deQueue();

    display();

    enQueue(7);
    display();//muestra front, reare y los elementos

    // Fracasa en encolar porque front == rear + 1
    enQueue(8);

    return 0;
}

//elementos son valores
//rear y front representan índices