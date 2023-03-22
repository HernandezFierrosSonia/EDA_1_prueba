#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int *arreglo, num, i;
    printf("¿Cuantos elementos tiene el conjunto?\n");
    scanf("%d",&num);
    arreglo=(int *)calloc(num, sizeof(int));//calloc() inicializa todos los bytes del bloque de memoria asignada a cero.
    if (arreglo!=NULL) 
    {
        printf("Vector reservado:[ "); 
        for (i=0 ; i<num ; i++)
            printf(" %d",*(arreglo+i));//%x da lo mismo//el asterisco es la parte que te garantiza que se va a imprimir un número, lo que esta adentro es una dirección

        printf(" ]");
        printf("\nSe libera el espacio reservado.\n");
        free(arreglo);
    }
    return 0;
}