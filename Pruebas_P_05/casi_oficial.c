#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int top;
	int capacity;
	int *array;
};

struct Queue
{
	int front;
	int rear;
	int size;
	int capacity;
	int *array;
};

struct Stack* createStack(int capacity)
{
	struct Stack* stack=(struct Stack*)malloc(1*sizeof(struct Stack));//no te confundas, no se pone capacity en lugar de 1, estamos creando UNA pila no 10 pilas
	stack->capacity=capacity;
	stack->top=-1;//lo que pasa es que en push lo primero que se hace es sumar así con ++ (aqunque no esta muy obvio)
	stack->array=(int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFullPila(struct Stack* stack)
{
	return stack->top==stack->capacity-1;
}

int isEmptyPila(struct Stack* stack)//a mi se me hace muy curioso que sea entero cuando devuelve booleano
{
	return stack->top==-1;//stack->top==(-1);
}

void push(struct Stack* stack, int item)
{
	if(isFullPila(stack))//enviamos una dirección
		return;
	
	stack->array[++stack->top]=item;//stack->array[] es como *stack.array[]. Es muy importante que entiendas que usar * es para que tu apuntador guarde valores, si asignas algo al nombre del apuntador, ese algo debe ser dirección, practicamente nunca lo vas a usar así. 
	/*Lo que acabo de decir al último es 
		int/struct Stack/char *pointer_name;
		pointer_name=dirección;//practicamente nunca lo vas a usar  
		*pointer_name=valor;//el valor ya depende que tipo hayas elegido  //es por eso que como aquí no podemos usar *stack. usamos stack->
	*/
	printf("Se agregó a la pila el elemento %d", item);
}

int pop(struct Stack* stack)
{
	if(isEmptyPila(stack))//booleano
		return 20;
	return stack->array[stack->top--];//top si cambia//top esta apuntando en el último elemento, al quitar uno, estara apuntando al valor anterior, provocando que se sobreescriba en este lugar del que pedimos rastro.
}

int peek(struct Stack* stack)
{
	if(isEmptyPila(stack))
		return 22;
	return stack->array[stack->top];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
struct Queue* createQueue(int capacity)
{
	struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));//=(struct Queue*)calloc(1, sizeof(struct Queue));//no te confundas, no se pone capacity en lugar de 1, estamos creando UNA cola no 10 
	queue->capacity=capacity;//nota que no hay problema con que se llamen igual
	queue->rear=capacity-1;//queue->rear=queue->capacity-1;//rear=9, pero vas a ver que luego luego vale 0 en enqueue
	queue->front=queue->size=0;
	queue->array=(int*)malloc(queue->capacity*sizeof(int));//(capacity*sizeof(int));
	return queue;

	//front siempre va a apuntar en tiempo real al primer elemento (por donde sacamos/dequeue)que encuentre en la cola
	//rear siempre va a apuntar en tiempo real al último elemento (por donde metemos/enqueue) que encuentre en la cola
}

int isEmptyCola(struct Queue* queue)//es in pero es bool
{
	return queue->size==0;//recuerda que queue-> es lo mismo que *queue.  recordando que *variable nos permita ¿desreferenciar? weno nos permite trabajar con el valor
}

int isFullCola(struct Queue* queue)//es int pero es bool
{
	return queue->size==queue->capacity;//capacity no cambia a lo largo del código
}

void enqueue(struct Queue* queue, int item)
{
	if(isFullCola(queue))//enviamos una dirección
		return;
	queue->rear=(queue->rear+1)%queue->capacity;
	queue->array[queue->rear]=item;//rear contiene en tiempo real el número de índice en que vamos a agregar 
	queue->size=queue->size+1;//queue->size+=1;
	printf("\nSe agregó a la cola el elemento %d\n", item);
}

int dequeue(struct Queue* queue)//su igual en pila es pop, pero en esa no se crea un int aquí si.
{
	if(isEmptyCola(queue))
		return 3;
	int item=queue->array[queue->front];
	queue->front=(queue->front+1)%queue->capacity;
	queue->size-=1;
	return item;
}

int rear(struct Queue* queue)//aquí es muy curioso, por que antes pensaba que el tipo de dato que regresas debe ser cel mismo tipo que los parámetros
{
	if (isEmptyCola(queue))
		return 90;//???
	return queue->array[queue->rear];
}

int main()
{
	struct Stack* stack=createStack(10);
	struct Queue* queue=createQueue(10);
    int opcion;
    int item;
	int i;

	for(i=10;i>=1;--i)
		push(stack, i);

	printf("El elemento al tope es: %d\n", peek(stack));

    for(;;)
    {
		printf("\n\nBienvenido al sistema de turnos.");
		printf("\nOpciones disponibles:");
    	printf("\n\t1-Formarse en la cola\n\t2-Salir.\n");
    	scanf("%i", &opcion);
        switch(opcion)
        {
            case 1://formarse
				/*creo que ya entendí por que cola, por que así como van llegando los anteriores se van llendo por que ya terminaron sus 
				business, la pila no te permite eso. Aclaro, lo que mencioné no tiene necesariamente que ver con el programa, solo es mi forma de darle sentido con realismo*/
				if(isEmptyPila(stack))	
				{
					printf("\nYa no hay turnos disponibles");
					//existe la posibilidad de que ya no haya nada en la pila, si das peek y no hay nada, va a haber un error pues no te puede devolver un valor cuando no hay nada dentro de ella
					printf("\nÚltimo elemento en el tope de pila: NULL (ya que no hay ningún elemento)");
					printf("\nÚltimo elemento formado en la cola: %d.\n", rear(queue));
					return 20;
				}
				else//la pila aun tiene turnos
				{
					printf("El elemento se encuentra formado en la cola con el turno %d.", peek(stack));//digamos que empezamos por elemento 1
					item=pop(stack);//solo hay 10 turnos
 					enqueue(queue, item);//solo se permite 10 personas, pero nunca sabremos cuando se van :D por que no parece que deba,mos usar dequeue
				}
                break;
            case 2://Salir
				printf("\nÚltimo elemento en el tope de pila: %d", peek(stack));
				printf("\nÚltimo elemento formado en la cola: %d.", rear(queue));
				return 18;
                break;//creo que este no es necesario
            default:
                printf("\nOpción inválida");
        }
    }

	return 0;
}
//creo que en este programa no se va a utilizar dequeue

//creo que los turnos no son realmente de pila, sino de cola
//existe la posibilidad de que el profesor hable de elemento cuando se trate de cola
//si es que se puede intenta probar entender que elemento y persona es lo mismo
//tus elementos pueden iniciar valiendo desde cero ó desde 1

//otra cosa que he notado es que contrario a la pila, la cola se va llenando, la pila se va vaciando