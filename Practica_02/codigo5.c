#include<stdio.h>

 void pasarValor(int);
 void pasarReferencia(int *);

 int main()
 {
    int nums[] = {55,44,33,22,11};
    int *ap, cont;
    ap = nums;// ap = &nums[0];
    printf("Pasar valor: %d\n", *ap);//imprime valor original pero del indice 0
    pasarValor(*ap);//enviamos valor original del indice 0?
    printf("Pasar referencia: %d\n", *ap);
    pasarReferencia(ap);
    printf("Valor final: %d\n", *ap);
    return 0;

}
void pasarValor(int equis)
{
    printf("%d\n", equis);//imprime valor original del indice 0 por que es un apuntador creo, pero no se ve
    equis = 128;
    printf("%d\n", equis);//imprime 128
}

void pasarReferencia(int *equis)
{
    printf("%d\n", *equis);//imprime el valor original dle ìndice 0
    *equis = 133;
    printf("%d\n", *equis);
}