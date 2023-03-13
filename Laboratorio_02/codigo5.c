#include<stdio.h>

 void pasarValor(int);
 void pasarReferencia(int *);

 int main()
 {
    int nums[] = {55,44,33,22,11};
    int *ap, cont;
    ap = nums;// ap = &nums[0]; //¿ap=&nums?//es un poco diferente con los arreglos, por que aquí no necesariamente tienes que poner &
    //int *ap=num

    printf("Pasar valor: %d\n", *ap);//imprime valor original pero del indice 0//imprime 55
    pasarValor(*ap);//enviamos valor original del indice 0? yo creo, por que lo recibe como integer

    printf("Pasar referencia: %d\n", *ap);//imprime valor original pero del indice 0//imprime 55
    pasarReferencia(ap);//enviamos una dirección

    printf("Valor final: %d\n", *ap);
    return 0;
}

void pasarValor(int equis)
{
    printf("%d\n", equis);//imprime valor original del indice 0 por que ahí quedó apuntando el apunatdor, pero no se ve
    equis = 128;
    printf("%d\n", equis);//imprime 128
    //no se ha cambiado el valor fuera de esta función
}

void pasarReferencia(int *equis)//int *equis=dirección //int*equis=&nums  ó  int*equis=&nums[0]  ó  int*equis=nums
{//como aquí si enviamos la dirección original, si modifica
    printf("%d\n", *equis);//imprime el valor original del ìndice 0
    *equis = 133; //ah mira no habiamos tenido mucha interacción con esto, int *equis, equis=direción, *equis=valor.
    printf("%d\n", *equis);//valor, cuando escribes un apunatdor con su *
}