#include<stdio.h>
#include<stdlib.h>
#define MAX 26

int size_of_word;

void enqueueFront(char *, char, int *, int *);
void enqueueRear(char *, char, int *, int *);
char dequeueFront(char *, int *, int *);
char dequeueRear(char *, int *, int *);
void display(char *);
int count(char *);
int contador_de_letras(char *);

void enqueueFront(char *arr, char item, int *front, int *rear)
{
    int i, k, c;

    if(*front==0 && *rear==(size_of_word-1)) 
    {
        printf("\nFalló, deque esta llena.\n");
        return;
    }

    if(*front==-1)
    {
        *front=*rear=0;
        arr[*front]=item;
        return;
    }

    if(*rear!=(size_of_word-1))
    {
        c=count(arr);
        k=*rear+1;

        for(i=1; i<=c; i++)
        {
            arr[k]=arr[k-1];
            k--;
        }
        arr[k]=item;
        *front=k;
        (*rear)++;
    } 
    else
    {
        (*front)--;
        arr[*front]=item;
    }
}

void enqueueRear(char *arr, char item, int *front, int *rear)
{
    int i;

    if(*front==0 && *rear==(size_of_word-1))
    {
        printf("\nFalló, la double queue (deque) está llena.\n");
        return;
    }

    if(*front==-1)
    {
        *rear=*front=0; 
        arr[*rear]=item;
        return;
    }

    if(*rear==(size_of_word-1))
    {
        for(i=(*front-1); i<(size_of_word-1); i++)
        {
            if(i==(size_of_word-1))
                arr[i]=' ';
            else
                arr[i]=arr[i+1];
        }
        (*front)--;
        (*rear)--;
    }
    
    (*rear)++;
    arr[*rear]=item;
}

char dequeueFront(char *arr, int *front, int *rear) 
{
    int item;

    if(*front==-1) 
    {
        printf("\nFalló, la double queue (deque) esta vacia.\n");
        return 0;
    }

    item=arr[*front];
    arr[*front]=' ';

    if(*front==*rear)
        *front=*rear=-1;
    else
        (*front)++;

    return item;
}

char dequeueRear(char *arr, int *front, int *rear)
{
    int item;

    if(*front==-1)
    {
        printf("\nFalló, deque esta vacía.\n");
        return 0;
    }

    item=arr[*rear];
    arr[*rear]=' ';
    (*rear)--;

    if(*rear==-1)
        *front=-1;

    return item;
}

int contador_de_letras(char *arr)
{
    int c=0, i;
    for(i=0; i<MAX; i++)
    {
        if(arr[i]!=(' '))
        {
            c++;
        }
    }
    
    return c;
}

int count(char *arr)
{
    int c=0, i;

    for(i=0; i<size_of_word; i++)
    {
        if(arr[i]!=' ')
            c++;
    }
    return c;
}

void display(char *arr)
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
    char *array;
    int i;
    int front, rear;

    front=rear=-1;	
	
    for(i=0;i<MAX;++i)
        palabra[i]=' ';

    printf("Bienvenido al verificador de palabras palíndromas\n");
    printf("Ingresa una palabra en minúsculas de máximo 25 caracteres\n");
    printf("Si es más de una palabra, no ingrese espacio: ");
    scanf("%s", palabra);
	printf("Gatito");
    size_of_word=contador_de_letras(palabra)-1;
    printf("La longitud de la palabra es de: %d", size_of_word);

    array=(char*)malloc((size_of_word)*sizeof(char));//este
    if(array)//array!=NULL
    {
        
        for(i=(size_of_word-1);i>=0;i--)
        {
            enqueueFront(array, palabra[i], &front, &rear);
        }
        for(i=0;i<size_of_word;i++)
        {
            printf("\narray[%d]=%c", i, *(array+i));
        }
        display(array);
        free(array);
    }
    printf("Valor de la variable size_of_word %d", size_of_word);
    return 0;
}
