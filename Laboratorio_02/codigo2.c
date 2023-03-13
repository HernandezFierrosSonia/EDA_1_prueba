#include <stdio.h>
/*
    Este programa crea un apuntador de tipo carácter.
*/
int main () 
{
    //char *ap, c;//declaraciòn de una variable y un char
    char c;
    char *ap;
    c = 'x'; 
    ap = &c;

    //imprime el carácter de la localidad a la que apunta
    printf("Carácter: %c\n",*ap);//contenido original//contenido original de la localidad a la que apunta

    //imprime el código ASCII de la localidad a la que apunta 
    printf("Código ASCII: %d\n",*ap);//imprime 120
    printf("Prueba Código ASCII: %d\n", c);//imprime 20

    //imprime la dirección de memoria de la localidad a la que apunta 
    printf("Dirección de memoria: %p\n",ap);//dirección original

    return 0; 
}