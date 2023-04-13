#include<stdio.h>
#include<stdlib.h>
#define MAX 26//cuando se ingresa un string, va a haber in empty character constant que va a ocupar un espacio después de la palabra, si pongo 26, es para ese extra carcater en caso extraordinadio que se agreguen 25 caracteres

int size_of_word;//si la modificas en cualquier función, cambia su valor en todas

void enqueueRear(int *arr, int item, int *front, int *rear)
//cuando rear mete, si es que aplica primero recorre todo el arreglo un espacio hacia atrás
//enqueue rear siempre agrega hacia la derecha, y nunca rebasa de 9 para pasarse a 0
{
    int i, k;

    if(*front==0 && *rear==MAX-1)
    {
        printf("\nFalló, la double queue (deque) está llena.\n");
        return;
    }

    if(*front==-1)//es la primera vez que agregamos 
    //creo también podría ser if(*rear==-1)
    //recuerda que como es apuntador, para ver o usar el valor original necesitamos el número de asteriscos original
    {
        *rear=*front=0;//colocamos los dos 
        arr[*rear]=item;
        return;
    }

    if(*rear==MAX-1)//todo lo que veras a continuación es para recorrer el arreglo un lugar hacia atrás, tiene sentido por que no es cola doble circular, que tonta toy
    {
        for(i=(*front-1); i<(MAX-1); i++)//podríamos i=k pero nop se puede//originalmente MAX-1 era *rear
        {
            if(i==MAX-1)//rear ya está ahí, lo sé por el if anterior
            //oie, nunca va a estrar aquí, por que i no llega al valor max-1 es decir 9, llega a uno menos, <9
                arr[i]=0;//eliminamos a nuestra manera, aunque este no es dequeue, en realidad estamos limpiando este espacio, voy a ver más tarde si en estas instrucciones podía insertar el item
            else
                arr[i]=arr[i+1];//no modifica i//recorremos todo el arreglo un espacio pa atrás
                //el 1 tiene lo que tiene el 2, el 2 tiene lo que tiene el 3,...
        }
        (*front)--;//son índices recuerda
        (*rear)--;//con la finalidad de que rear no se modifique
    }
    
    (*rear)++;
    arr[*rear]=item;
}

int count(char *arr)//cuenta cuantos lugares tenemos ocupados
//me lo pude haber arrado con strlen
{
    int c=0, i;
    for(i=0; i<MAX; i++)
    {
        if(arr[i]!=(' '))//al leer la palabra, al siguiente índice agrega '', se conoce como empty character constant, por eso entra, ''!=' ' es correcto.
        {
            c++;//suma primero //cuenta palabras, antes de imprimirla hay que sumar, no queremos imprimir un 0
            //printf("índice %d, número en la suma %d, letra %c gato\n", i, c, arr[i]);//no imprimas i, por que eso es para acceder al arreglo, c es para CONTAR carácteres, c no empieza en cero, i esta un número debajo de c.
            //va a haber un índice que este ocupado por algo vacío
        }
    }
    //c--;//no hay mucho que pueda hacer por ese empty character constant, pero puedo bajar un valor a c, por que sé que entra a la condición

    /*for(i=0;i<MAX;i++)
    {
        printf("%c", arr[i]);
    }
    printf("%s", arr);*/
    return c;//c ya no es necesaria, size_of_word puede haberse utilizado en su lugar
}

int main()
{
    char palabra[MAX];
    char *array;//un arreglo es una dirección bro
    int i;
    for(i=0;i<MAX;++i)
        palabra[i]=' ';

    /*no puedo pedir memoria cuando ya esta corriendo por lo que no puedo crear la variable para palabra
    de acuerdo a la longitud, a menos que sea por memoria dinámica, pero ahí tienes que saber que tan grander la necesita y eso depende enteramente del usuario*/
    printf("Bienvenido al verificador de palabras palíndromas\n");
    printf("Ingresa una palabra en minúsculas de máximo 25 caracteres\n");//carácter si lleva tilde, carácteres no, es como la palabra examenes
    printf("Si es más de una palabra, no ingrese espacio: ");
    scanf("%s", palabra);//es que la palabra palabra por si sola es una dirección
	
    size_of_word=count(palabra)-1;
    printf("La longitud de la palabra es de: %d", size_of_word);//aguas, no es índice es cuantas letras tiene la palabra//le quite 1 por el empty character constant, para no modificar mucho la función cont

    array=(char*)malloc((size_of_word)*sizeof(char));
    if(array)//array!=NULL
    {
        for(i=0;i<size_of_word;i++)//después de todo c ó size_of_word guardan cantidad de letras, no empieza en cero
        {
            array[i]=palabra[i];
        }
        free(array);
        for(i=0;i<size_of_word;i++)
        {
            printf("\narray[%d]=%c", i, array[i]);
        }
    }
    funcion();
    return 0;
}