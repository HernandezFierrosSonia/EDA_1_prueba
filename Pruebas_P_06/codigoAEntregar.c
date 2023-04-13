#include<stdio.h>
#include <string.h>

/*int dequeueRear()
{

}

int dequeueFront()
{

}*/

int main()
{
    char palabra[25];
    /*no puedo pedir memoria cuando ya esta corriendo por lo que no puedo crear la variable para palabra
    de acuerdo a la longitud, a menos que sea por memoria dinámica, pero ahí tienes que saber que tan grander la necesita y eso depende enteramente del usuario*/
    printf("Bienvenido al verificador de palabras palíndromas\n");
    printf("Ingresa una palabra en minúsculas de máximo 25 caracteres: ");//carácter si lleva tilde, caracteres no, es como la palabra examenes
    scanf("%s", palabra);//es que la palabra palabra por si sola es una dirección
    int longitud=strlen(palabra);
	printf("La longitud de la cadena '%s' es: %d", palabra, longitud);

}