#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int *arreglo, num, cont;
    printf("¿Cuantos elementos tiene el conjunto?\n");
    scanf("%d",&num);
    arreglo = (int *)malloc (num * sizeof(int));//* es una operacio¡òn aritmetica
    if (arreglo!=NULL) 
    {
        printf("Vector reservado:\n\t["); 
        for (cont=0 ; cont<num ; cont++)
        {
            printf("\t%d",*(arreglo+cont));//¿por què imprime cero? 
        }
        printf("\t]\n");
        printf("Se libera el espacio reservado.\n");
        free(arreglo);
    }
    return 0;
}

 