//#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Una estructura que representa una cola
struct Queue 
{
	int front;//creo que es head
    int rear;//creo que es tail
    int size;
	int capacity;
	int* array;
};

// Función para crear una cola dada una capacidad. Inicia su tamaño de
// cola como 0
struct Queue* createQueue(int capacity)
{
	struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));//solo creamos uno, así que chiste, además es int, ya quisiera ver char 2d
	queue->capacity=capacity;
	queue->front=queue->size=0;//iniciamos dos de una vez :)

	// Esto es importante ver en operación encolar
	queue->rear=capacity-1;//4 en este caso
	queue->array=(int*)malloc(queue->capacity * sizeof(int));//pa' que veas como se inicializa, lo malo es que es entero no char
	return queue;//esta es una dirección, exactamente la dirección de una estructura cola
}

// La cola esta llena cuando se vuelve
// igual a la capacidad
int isFull(struct Queue* queue)
{
	return (queue->size==queue->capacity);//capacidad no cambia, siempre vale lo que vale
    //es un valor booleano, si son iguales devuelve true supongo
    //para agregar la edad del guero 1==5 false
}

// La cola esta vacia cuando su tamano es cero
int isEmpty(struct Queue* queue)
{
	return (queue->size==0);//yo no lo llamaría size pero weno, es muy confuso, size si va cambiando, es como nuestra flecha, solo que simplemente es un entero. Tiene el valor del número de elementos que tiene nuestra cola
}

// Función para agregar un elemento a la cola.
// Cambia la parte trasera y el tamano.
void enqueue(struct Queue* queue, int item)//le estoy enviando la dirección de una estructura cola
{
	if(isFull(queue))//si devuelve true/verdadero si entra
		return;//que curioso regresa, eso me sirve, creo, solo toma en cuenta que es por que la función es void, es bastante inútil(por que ¿porque querrías devolver algo cuando la función no devuelve nada?), pero te evita poner un else
		//¿por qué no imprime un mensaje de aviso?
	queue->rear=(queue->rear+1) % queue->capacity;//rear=4+1%5=5%5=0//rear=0+1%5=1%5=1///rear=1+1%5=2  ah caray!//pero no entiendo por qué no poner rear directamente en cero y evitar esta línea
	queue->array[queue->rear]=item;//array[0]=21;//array[1]=2;//array[2]=56;
	queue->size+=1;//queue->size+1;//++queue->size;//size=0+1;//size=2//size=3
	printf("%d agregado a la cola\n", item);
	//solo para dejar claro que rear esta al inicio
}

// Función para eliminar un elemento de la cola.
// Cambia el frente y el tamano.
int dequeue(struct Queue* queue)
{
	if (isEmpty(queue))
		return 3;//¿por qué no imprime un mensaje de aviso?
	int item=queue->array[queue->front];//array[0] sabemos que es 21//array[1]=2//array[2]=56;
	queue->front=(queue->front+1) % queue->capacity;//front=0+1%5=1//front=1+1%5=2;//front=2+1%5=3;
	queue->size-=1;//queue->size - 1;//size=3//size=2;//size=1
	return item;
	//solo para dejar claro que front esta al final de la cola
}

// Función para obtener el frente de la cola.
int front(struct Queue* queue)
{
	if (isEmpty(queue))
		return 20;
	return queue->array[queue->front];
}

// Función para obtener la parte trasera de la cola
int rear(struct Queue* queue)//aquí es muy curioso, por que antes pensaba que el tipo de dato que regresas debe ser cel mismo tipo que los parámetros
{
	if (isEmpty(queue))
		return 90;//???
	return queue->array[queue->rear];
}

// Función principal para probar las operaciones.
int main()//first in, first out
{
	struct Queue* queue=createQueue(5);//nos regresa la colita ya creada

	enqueue(queue, 21);//como que ya me voy acostumbrando a que si no escribo el * de un apuntador estoy dando la dirección del apuntador
	enqueue(queue, 2);
	enqueue(queue, 56);
	enqueue(queue, 55);
    enqueue(queue, 19);

	printf("%d eliminado de la cola\n", dequeue(queue));
	printf("%d eliminado de la cola\n", dequeue(queue));
	printf("%d eliminado de la cola\n", dequeue(queue));
	printf("%d eliminado de la cola\n", dequeue(queue));
	printf("El elemento de enfrente es: %d\n", front(queue));
	printf("El elemento de al final es: %d\n", rear(queue));//se me hace curioso que con rear encolemos(lo cual se lleva a cabo en el inicio del arreglo), pero aun así sea capaz de darnos el último elemento
	
	enqueue(queue, 21);//esto ya no se podía, como va avanzando hacia enfrente, ya me acabe mi arreglo
	enqueue(queue, 2);
	enqueue(queue, 56);
	printf("El elemento de enfrente es: %d\n", front(queue));
	printf("El elemento de al final es: %d\n", rear(queue));

	return 0;
}
//nunca liberamos memoria :c. Usamos dos veces malloc()
//nostros vamos emtiendo por rear, y vamos sacando por front, size es el que se va moviendo
//is full and is empty utilizan size 
//cola es la única que crea un int para devolver
//solo en cola no modifica el valor nadamas +1 ó -1