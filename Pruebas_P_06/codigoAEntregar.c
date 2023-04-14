#include<stdio.h>
#include<stdlib.h>
#define MAX 26//cuando se ingresa un string, va a haber in empty character constant que va a ocupar un espacio después de la palabra, si pongo 26, es para ese extra carcater en caso extraordinadio que se agreguen 25 caracteres

int size_of_word;//si la modificas en cualquier función, cambia su valor en todas

void enqueueFront(char *, char, int *, int *);
void enqueueRear(char *, char, int *, int *);
char dequeueFront(char *, int *, int *);
char dequeueRear(char *, int *, int *);
void display(char *);
int count(char *);
int contador_de_letras(char *);

void enqueueFront(char *arr, char item, int *front, int *rear)//en una cola simple o en una cola circular no encolamos en front 
/*nota como un arreglo entero unidimensional se recibe en esta función, se nos envió una dirección
la recibimos como tal, recibimos una dirección como tal, para este caso no le importa a la función saber el tamaño(se puede mandar [tamaño1][tamaño2] o solamente[][tamaño2]).
La cosa cambia en arreglo entero bidimensional, por que ahí a la función si le importa el tamaño, pero la diferencia
es que recibe el arreglo como si fuera entero no como una dirección, pese a que si mandaste una dirección.*/
{
//este queue ingresa para su izquierda
    int i, k, c;

    if(*front==0 && *rear==(size_of_word-1)) 
    {
        printf("\nFalló, deque esta llena.\n");
        return;
    }

    if(*front==-1)//también puede ser if(*rear==-1)//es la primera vez que encolamos
    {
        *front=*rear=0;//los dos apuntan al mismo elemento
        arr[*front]=item;
        return;
    }

    if(*rear!=(size_of_word-1))
    {
        c=count(arr);
        k=*rear+1;//rear no va a cambiar

        for(i=1; i<=c; i++)//dentro de las instrucciones de for no se ocupa i.
        //era más bonito cuando rear==MAX-1 en la función de enqueueRear
        //recorremos el arreglo entero un espacio para adelante, lo recorremos pa' alla->
        {
            arr[k]=arr[k-1];//recorremos espacio por espacio, al final el arreglo entero se recorre SOLO un espacio//el 7 tiene lo de 6, el 6 tiene lo de 5, el  5 tiene lo de 4, ...
            k--;//puedes ahorrarte esta línea poniendo k-- arribita, no creo que pase nada
        }
        arr[k]=item;//sobreescribe//k tiene este valor k=k-c, k no queda con valor de rear
        *front=k;//como que front nunca cambia
        (*rear)++;//rear vale un espacio más, por que recorrimos el arreglo entero un espacio, lo recorrimos hacia aca ->, es decir hacia la derecha
    } 
    else// rear==9
    {
        (*front)--;//front agrega hacia la izquierda
        arr[*front]=item;
    }
}

void enqueueRear(char *arr, char item, int *front, int *rear)
//cuando rear mete, si es que aplica primero recorre todo el arreglo un espacio hacia atrás
//enqueue rear siempre agrega hacia la derecha, y nunca rebasa de 9 para pasarse a 0
{
    int i, k;

    if(*front==0 && *rear==(size_of_word-1))
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

    if(*rear==(size_of_word-1))//todo lo que veras a continuación es para recorrer el arreglo un lugar hacia atrás, tiene sentido por que no es cola doble circular, que tonta toy
    {
        for(i=(*front-1); i<(size_of_word-1); i++)//podríamos i=k pero nop se puede//originalmente MAX-1 era *rear
        {
            if(i==(size_of_word-1))//rear ya está ahí, lo sé por el if anterior
            //oie, nunca va a estrar aquí, por que i no llega al valor max-1 es decir 9, llega a uno menos, <9
                arr[i]=' ';//eliminamos a nuestra manera, aunque este no es dequeue, en realidad estamos limpiando este espacio, voy a ver más tarde si en estas instrucciones podía insertar el item
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

char dequeueFront(char *arr, int *front, int *rear) 
//se va quedando calvo del lado que conocemos como el frente de la cola, pero no recorre el arreglo ni nada
{//lo sobreescribe con un cero donde este front, recorre front a su derecha, pero no recorre el arreglo
    int item;

    if(*front==-1) 
    {
        printf("\nFalló, la double queue (deque) esta vacia.\n");
        return 0;
    }

    item=arr[*front];
    arr[*front]=' ';//no elimina, solo sobreescribe

    if(*front==*rear)//si solo había un elemento
        *front=*rear=-1;
    else
        (*front)++;

    return item;
}

char dequeueRear(char *arr, int *front, int *rear)//en una cola circular o en una cola simple no desencolamos en rear 
{//ningún dequeue de este codigo recorre la cola, solo borra, se va quedando calva la parte que conocemos como parte trasera
    int item;

    if(*front==-1)
    {
        printf("\nFalló, deque esta vacía.\n");
        return 0;
    }

    item=arr[*rear];
    arr[*rear]=' ';//es nuestra forma de eliminarlo
    (*rear)--;

    if(*rear==-1)//significa que la cola está vacía?
        *front=-1;

    return item;
}

int contador_de_letras(char *arr)//cuenta cuantos lugares tenemos ocupados
//es la única función que puede usar MAX
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

int count(char *arr)//cuenta cuantos lugares tenemos ocupados
{
    int c=0, i;

    for(i=0; i<size_of_word; i++)
    {
        if(arr[i]!=' ')//no te preocupes, al arreglo no pasamos el índice vacío
            //a que curioso, es la forma de comprobar que el arreglo no este vacío, pero esto no funciona con tipo de dato char
            //lo que no tiene en cuenta, es qué pasa si el usuario me da 0 como valor para encolarlo
            c++;
    }
    //nota que no tiene nada que ver: después de un for, i si se modificó, siempre y cuando i no este declarada dentro de for, incluso dentro del for la i tiene sus limitacones, no lo hagas
    return c;
}

void display(char *arr)//solo deberías usarlo con arreglo y no con palabra, ya que tienen tamaños diferentes
{
    int i;

    printf("\n frente:  ");
    for(i=0; i<size_of_word; i++)
        printf("  %c", arr[i]);
    printf("  :parte trasera");
}

int main()
{
    char palabra[MAX];
    char *array;//un arreglo es una dirección bro, si lo piensas bien cuanda haces algo como arreglo[i], en realidad le estas diciendo cuantos digamos bloques de memoria estas recorriendo
    int i;
    int front, rear;

    for(i=0;i<MAX;++i)
        palabra[i]=' ';

    /*no puedo pedir memoria cuando ya esta corriendo por lo que no puedo crear la variable para palabra
    de acuerdo a la longitud, a menos que sea por memoria dinámica, pero ahí tienes que saber que tan grander la necesita y eso depende enteramente del usuario*/
    printf("Bienvenido al verificador de palabras palíndromas\n");
    printf("Ingresa una palabra en minúsculas de máximo 25 caracteres\n");//carácter si lleva tilde, carácteres no, es como la palabra examenes
    printf("Si es más de una palabra, no ingrese espacio: ");
    scanf("%s", palabra);//es que la palabra palabra por si sola es una dirección
	printf("Gatito");
    size_of_word=contador_de_letras(palabra)-1;//se sumaba sin querer una empty character pointer, pero tranquila no tiene el valor de índices, no empieza en cero
    printf("La longitud de la palabra es de: %d", size_of_word);//aguas, no es índice es cuantas letras tiene la palabra//le quite 1 por el empty character constant, para no modificar mucho la función cont

    array=(char*)malloc((size_of_word)*sizeof(char));//este
    if(array)//array!=NULL
    {
        /*for(i=0;i<size_of_word;i++)//después de todo c ó size_of_word guardan cantidad de letras, no empieza en cero
        {
            *(array+i)=palabra[i];
        }
        for(i=0;i<size_of_word;i++)
        {
            printf("\narray[%d]=%c", i, *(array+i));
        }*/
        for(i=(size_of_word-1);i>=0;i--)//size_of_word no es índice, es cantidad de palabras, necesito quitarle 1 pa' que empieze en el índice correcto
        //no modifica size_of_word
        //empiezo de esa forma, por que enqueueFront el primero que ingresa al final termina hasta atrás
        {
            enqueueFront(array, palabra[i], &front, &rear);//decidí usar este pa' ver como recorre el arreglo, en una cola normal ingresas elementos por rear, no hay que ser ordinarios
            //no vas a mandar donde lo quieres meter, es decir no vas a mandar array+i, solo array
        }
        for(i=0;i<size_of_word;i++)//es creo lo mismo que display
        {
            printf("\narray[%d]=%c", i, *(array+i));//es que array es una dirección, además los arrays de memoria dinámica no funcionan como los arrays normales, a estos tienes que sumarles como que los espacios de memoria, pero es incorrecto decir eso por que en malloc es un solo bloque de memoria
        }
        display(array);
        free(array);
    }
    printf("Valor de la variable size_of_word %d", size_of_word);
    return 0;
}

/*algo aprendido es que el array de memoria dinámica en nuestras funciones si se ocupaba como lo harías con una array normal,
pero en el main no, ahí si tienes que sumarle al array su digamos bloque de memoria*/