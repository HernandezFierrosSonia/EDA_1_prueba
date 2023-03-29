#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Una estructura que representa una pila
struct Stack 
{
	int top;
	int capacity;//para que no tenga tipo de dato, para que tenga una capacity dinàmica
	int* array;
};

// Función para crear una pila dada una capacidad. Inicia su tamaño de
// pila como 0
struct Stack* createStack(int capacity)
{
	struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));//es como un arreglo de 1//malloc no inicia a 20
	stack->capacity=capacity;
	stack->top=-1;
	stack->array=(int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

// La pila esta llena cuando el tope es igual al ùltimo indice
int isFull(struct Stack* stack)
{
	return stack->top==stack->capacity-1;//es booleano
}

// La pila esta vacia cuando el tope es igual a -1
int isEmpty(struct Stack* stack)
{
	return stack->top==-1;//booleano false or true
}

// Función para agregar un elemento a la pila. Incrementa el tope en 1
void push(struct Stack* stack, int item)
{
	if(isFull(stack))
		return;//por que este puede no regresar nada, pero los otros no
	stack->array[++stack->top]=item;//aquí si cambia top//array[0]=21;//esta línea en las notas se describe como: primero se incrementa el índice y en ese índice se guarda el elemento
	printf("%d push a la pila\n", item);
	//por cierto, creo que es lo mismo stack->top++
}

// Función para quitar un elemento de la pila. Decrementa el tope en 1
int pop(struct Stack* stack)
{
	if(isEmpty(stack))
		return 20;
	return stack->array[stack->top--];//top si se modifica//cuando quitas, quitas en top(recordando que top es el que se va moviendo)//esta línea en las notas se describe como: primero se disminuye el índice y se devuelve el valor en ese índice
	//simplemente perdemos el rastro, no lo eliminamos//pero es díficil de entender, top siempre queda digamos apuntando a un numero extra del que en realidad estamos, al disminuir top apuntamos al último elmento, es por eso que
	//podemos regresar el elemento que queremos olvidar/elimnar por que la siguiente vez que hagamos push(después de este/un pop) se sobreescribirá
	//por cierto, creo que es lo mismo --stack->top
}

// Funcion para regresar el valor del tope de la pila sin quitarlo
int peek(struct Stack* stack)//en las notas del profesor este es top
{
	if(isEmpty(stack))
		return 22;
	return stack->array[stack->top];
}

// Función principal para probar las operaciones.
int main()
{
	struct Stack* stack=createStack(5);

	push(stack, 21);//envaimos dirección
	push(stack, 2);
	push(stack, 56);
    push(stack, 55);
    push(stack, 19);

	printf("%d eliminado de la pila\n", pop(stack));//no es muy ejemplificador, pero esa función nos regresa un int, 
    printf("El elemento al tope es: %d\n", peek(stack));//te muestra el elemento que esta en el tope

	return 0;
}
//Nunca liberamos memoria :c. Por cierto, solo usamos dos veces malloc
//nosotros vamos metiendo en top y vamos sacando por top