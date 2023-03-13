#include<stdio.h>
/*
    Se recorre un arreglo unidimensional a través de un apuntador
*/

int main()
{
    int nums[] = {55,44,33,22,11};
    int *ap, cont;
    ap = nums;//ap = &nums[0];//ap=&nums

    for (cont = 0; cont < 5 ; cont++)
    {
        printf("%p\n",(ap+cont));//en short se usa %x
    }

    //A continuación mi propia cosecha:
    printf("%d\n", *ap+1);//me da 56

    return 0;
}