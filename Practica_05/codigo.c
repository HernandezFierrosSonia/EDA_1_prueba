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
	struct Stack* stack=(struct Stack*)malloc(1*sizeof(struct Stack));
	stack->capacity=capacity;
	stack->top=-1;
	stack->array=(int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFullPila(struct Stack* stack)
{
	return stack->top==stack->capacity-1;
}

int isEmptyPila(struct Stack* stack)
{
	return stack->top==-1;//stack->top==(-1);
}

void push(struct Stack* stack, int item)
{
	if(isFullPila(stack))//enviamos una dirección
		return;
	
	stack->array[++stack->top]=item; 
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
	struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity=capacity;//nota que no hay problema con que se llamen igual
	queue->rear=capacity-1;
	queue->front=queue->size=0;
	queue->array=(int*)malloc(queue->capacity*sizeof(int));
	return queue;

	//front siempre va a apuntar en tiempo real al primer elemento (por donde sacamos/dequeue)que encuentre en la cola
	//rear siempre va a apuntar en tiempo real al último elemento (por donde metemos/enqueue) que encuentre en la cola
}

int isEmptyCola(struct Queue* queue)//es in pero es bool
{
	return queue->size==0;
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
	queue->size=queue->size+1;
	printf("\nSe agregó a la cola el elemento %d\n", item);
}

int rear(struct Queue* queue)
{
	if (isEmptyCola(queue))
		return 90;
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

    for(;;)
    {
		printf("\n\nBienvenido al sistema de turnos.");
		printf("\nOpciones disponibles:");
    	printf("\n\t1-Formarse en la cola\n\t2-Salir.\n");
    	scanf("%i", &opcion);
        switch(opcion)
        {
            case 1://formarse
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
					printf("El elemento se encuentra formado en la cola con el turno %d.", peek(stack));
					item=pop(stack);//solo hay 10 turnos
 					enqueue(queue, item);//solo se permite 10 veces
				}
                break;
            case 2://Salir
				printf("\nÚltimo elemento en el tope de pila: %d", peek(stack));
				printf("\nÚltimo elemento formado en la cola: %d.", rear(queue));
				return 18;
                break;
            default:
                printf("\nOpción inválida");
        }
    }
	return 0;
}
