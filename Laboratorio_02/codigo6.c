#include<stdio.h>
/*
    Se imprimen 3 valores de un arreglo a través
    de aritmética de direcciones.
*/

int main()
{
    int arr[5] = {91,28,73,46,55};
    int *apArr;
    apArr = arr;//apArr=&arr[0];
    //recuerda que en el caso de arreglos es diferente, en una variable 'normal' si se pone &

    //apunta al inicio del arreglo
    printf("*apArr = %i\n",*apArr);//valor/contenido original del ìndice 0, imprime 91

    // suma una localidad al inicio del arreglo e imprime su valor
    printf("*(apArr+1) = %i\n",*(apArr+1)); 
    printf("*(apArr+2) = %i\n",*(apArr+2));
    return 0;
 }