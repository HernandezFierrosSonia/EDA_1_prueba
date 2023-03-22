#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[4];
    int *p;
    p=&array[0];

    array[0]=55;
    array[1]=73;
    array[2]=12;
    array[3]=1;

    //printf("%p", p);//imprime la dirección de array[0]
    printf("%d\n", *p);//*p es el VALOR en &array[0]//imprime 55//si no ubieras inicializado array[0] imprimiría 0
    //en las variables normales *p es el valor original y p sería la dirección
    //pues aquí es algo similar, *p es el valor original en [0] y p es la direccion del [0]
    printf("%d\n", *(p+0));//es lo mismo que la línea 16
    printf("%d\n", *p+1);//a 55 le suma 1//si no ubieras inicializado array[0] imprimiría 1
    printf("%d\n", *p+2);//a 55 le suma 2//si no ubieras inicializado array[0] imprimiría 2
    printf("%d\n", *p+3);//a 55 le suma 3//si no ubieras inicializado array[0] imprimiría 3
    printf("%d\n", *p+4);//a 55 le suma 4//si no ubieras inicializado array[0] imprimiría 4
    printf("%d\n", *(p+0)+4);//es lo mismo que la línea anterior
    printf("Hola\n");

    printf("%d\n", *(p+0));//es lo mismo que printf("%d\n", *(p));//debería imprimir 55
    printf("%d\n", *(p+1));//imprime 73
    printf("%d\n", *(p+2));//imprime 12//LOL HACKEÉ LA REALIDAD, te juro que me había dado 73 con esta línea, pero weno
    //si fuera uno bidimensional se imprime *(*(p+0)+0)

    printf("Mochi\n");
    int *arreglito;
    //arreglito=recibe una direcci+on
    arreglito=(int*)malloc(4*sizeof(int));
    arreglito[0]=112;
    arreglito[1]=14;
    arreglito[2]=23;
    arreglito[3]=170;
    printf("%d\n",*(arreglito+0));//debe imprimir 112//es lo mismo que printf("%d\n",*(arreglito))
    printf("%d\n",*(arreglito+1));//debe imprimir 14
    printf("%d\n",*(arreglito+2));//debe imprimir 123
    printf("%d\n",*(arreglito+3));//debe imprimir 170
}