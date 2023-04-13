#include<stdio.h>
#include <string.h>
#define MAX 25

/*int dequeueRear()
{

}

int dequeueFront()
{

}*/

int count(char *arr)//cuenta cuantos lugares tenemos ocupados
{
    int c=0, i;
    //pienso que cuando leemos la palabra agrega un espacio
    //o tal vez no, por que se sigue metiendo
    for(i=0; i<MAX; i++)
    {
        if(arr[i]!=('.'))
        {
            c++;
            printf("%d %d %c gato\n", i, c, arr[i]);//no imprimas i, por que eso es para acceder al arreglo, c es para CONTAR carácteres, c no empieza en cero, i esta un número debajo de c.
        }
    }
    for(i=0;i<MAX;i++)
    {
        printf("%c", arr[i]);
    }
    if(arr[9]=='.')
    {
        printf("Cangrejo en problemas");//esto es muy malo
    }
    return c;
}

int main()
{
    char palabra[MAX];
    int i;
    for(i=0;i<25;++i)
        palabra[i]='.';

    /*no puedo pedir memoria cuando ya esta corriendo por lo que no puedo crear la variable para palabra
    de acuerdo a la longitud, a menos que sea por memoria dinámica, pero ahí tienes que saber que tan grander la necesita y eso depende enteramente del usuario*/
    printf("Bienvenido al verificador de palabras palíndromas\n");
    printf("Ingresa una palabra en minúsculas de máximo 25 caracteres: ");//carácter si lleva tilde, caracteres no, es como la palabra examenes
    scanf("%s", palabra);//es que la palabra palabra por si sola es una dirección
	
    printf("La longitud de la palabra es de: %d", count(palabra));//aguas, no es índice es cuantas letras tiene la palabra
}