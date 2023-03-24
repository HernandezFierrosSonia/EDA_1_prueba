#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Una estructura que representa una pila
struct Stack {
	int top;
	unsigned capacity;//para que no tenga tipo de dato, para que tenga una capacity dinàmica
	int* array;
};

// Funcion para crear una pila dada una capacidad. Inicia su tamaño de
// pila como 0
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));//es como un arreglo de 1//malloc no inicia a 20
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

// La pila esta llena cuando el tope es igual al ùltimo indice
int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;//es booleano
}

// La pila esta vacia cuando el tope es igual a -1
int isEmpty(struct Stack* stack)
{
	return stack->top == -1;//booleano false or true
}

// Funcion para agregar un elemento a la pila. Incrementa el tope en 1
void push(struct Stack* stack, int item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
	printf("%d push a la pila\n", item);
}

// Funcion para quitar un elemento de la pila. Decrementa el tope en 1
int pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

// Funcion para regresar el valor del tope de la pila sin quitarlo
int peek(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}

// Funcion principal para probar las operaciones.
int main()
{
	struct Stack* stack = createStack(100);

	push(stack, 10);
	push(stack, 20);
	push(stack, 30);

	printf("%d eliminado de la pila\n", pop(stack));
    printf("El elemento al tope es: %d\n", peek(stack));

	return 0;
}
