#include <stdio.h>
/*
    Este programa crea un apuntador de tipo entero
    que apunta al inicio de un arreglo.
*/
int main ()
{
    int arr[5], *apArr;   //short arr[5], *apArr;
    apArr = &arr[0];     //apArr=arr;

    // imprime la dirección de memoria del arreglo en la posición [0]
    printf("Dirección del arreglo en la primera posición: &arr[0]= %p\n",&arr[0]);//en short lleva %x
    printf("Dirección del arreglo en la primera posición: &arr[1]= %p\n",&arr[0]+1);

    printf("La linea 12 y esta son iguales %p\n", arr);
    printf("                               %p\n", arr+1);//te imprime &arr[1]
    
    printf("&arr[1]= %p\n",&arr[1]);//son diferentes a ínidce 0
    printf("&arr[2]=%p\n",&arr[2]);//son diferentes a ínidce 0

    // imprime la dirección de memoria del arreglo
    // (el nombre del arreglo es un apuntador)
    printf("Dirección del arreglo: %p\n",&arr);//la dirección del arreglo es la misma que el arreglo en su primer índice
                                               //&arr=&arr[0]=arr
    printf("                      %p\n",&arr+1);

    // imprime la dirección de memoria del apuntador apArr
    printf("Dirección del apuntador: %p\n", apArr);//direcciòn original//dirección de arr[0], es decir &arr[0]
    printf("Dirección del apuntador: %p\n", apArr+1);//te imprime &arr[1]
    printf("Dirección del apuntador: %p\n", apArr+2);//te imprime &arr[2]
    return 0;
}
 