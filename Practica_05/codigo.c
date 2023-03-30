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
	stack->top=-1;//lo que pasa es que en push lo primero que se hace es sumar así con ++ (aqunque no esta muy obvio)
	return stack;
}

void push(struct Stack* stack, int item)
{
	stack->array[++stack->top]=item;//stack->array[] es como *stack.array[]. Es muy importante que entiendas que usar * es para que tu apuntador guarde valores, si asignas algo al nombre del apuntador, ese algo debe ser dirección, practicamente nunca lo vas a usar así. 
	/*Lo que acabo de decir al último es 
		int/struct Stack/char *pointer_name;
		pointer_name=dirección;//practicamente nunca lo vas a usar  
		*pointer_name=valor;//el valor ya depende que tipo hayas eleigido  //es por eso que como aquí no podemos usar *stack. usamos stack->
	*/
	printf("Se agregó a la pila el elemento %d", item);
}

int pop(struct Stack* stack)
{
	int item;
	item=stack->array[stack->top--];//revisa lo del top
	return item;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
struct Queue* createQueue(int capacity)
{
	struct Queue* queue=(struct Queue*)calloc(1, sizeof(struct Queue));//no te confundas, no se pone capacity en lugar de 1, estamos creando UNA pila no 10 cola
	queue->capacity=capacity;//nota que no hay problema con que se llamen igual
	queue->rear=queue->capacity-1;//rear=9, pero vas a ver que luego luego vale 0 en enqueue
	queue->front=queue->size=0;
	return queue;
}

void enqueue(int item)
{
	printf("Se agrego a la cola el elemento %d", item);
}

int dequeue()
{
	int item;
	return item;
}

int main()
{
	struct Stack* stack=createStack(10);
	struct Queue* queue=createQueue(10);
    int opcion;
    int item;
	int i;

	for(i=1;i<=10;++i)
		push(stack, i);

    printf("Bienvenido al sistema de turnos.\n");
    printf("Opciones disponibles:\n");
    printf("\n\t1-Formarse\n\t2-Salir.\n");
    scanf("%i", &opcion);

    for(;;)
    {
        switch(opcion)
        {
            case 1:
                printf("Ingresa elemento(tipo entero): ");
                scanf("%i", &item);
                push(enqueue, item);
                priintf("Turno");
                break;
            case 2:
				top(stack);
				rear(queue);
                return 56;
                break;
            default:
                break;    
        }
    }

	printf("%d eliminado de la pila\n", pop(stack));//no es muy ejemplificador, pero esa función nos regresa un int, 
    printf("El elemento al tope es: %d\n", peek(stack));//te muestra el elemento que esta en el tope

	return 0;
}