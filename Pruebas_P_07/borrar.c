#include <stdio.h>
#include<stdlib.h>

int main()
{
    int *newNode=(int*)malloc(1*sizeof(int));
    int *last;
    last=newNode;
    
    *newNode=3;
    *(newNode)=5;
    *(newNode+0)=1;//son lo mismo
    
    printf("%p\n", newNode);
    printf("%p\n", last);//last tiene la ubicación de newNode

    printf("%d\n", *newNode);
    printf("%d\n", *(newNode+0));//este y el anterior son lo mismo, imprime 1
    *last=7;//esto me estropea todo lo que conozco sobre apuntadores, eso de utilizar los * originales de un apuntador te lleva al valor original, :c
    //no lo entiendas, solo recuérdalo
    //last=4;error
    printf("%d\n", *last);
    printf("%d\n", *(newNode));//cambió a 7
    
    return 0;
}
/*last como es apuntador, no puedes hacer *last=7, en cambio si puedes hacer *newNode=1 por que es memoria dinámica,
pero como ves si te permite *last=7, pero nota como se lleva de corbata a newNode, *last=7 no modifica el valor de last
(por que no se puede) modifica el valor de newNode*/
