#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int *arreglo, num, i;
    printf("¿Cuantos elementos tiene el conjunto?\n");
    scanf("%d",&num);
    arreglo=(int *)malloc(num * sizeof(int));//* es una operación aritmética
    if (arreglo!=NULL) //NULL es como no existir?
    {
        for (i=0 ; i<num ; i++)
            printf("%d ",*(arreglo+i));//¿por qué imprime cero? malloc() no inicializa, pues los arreglos normales no incializan y aun así imprimen cero también

        printf("\nA continuación se libera el espacio reservado.\n");
        free(arreglo);
    }
    return 0;
}

 