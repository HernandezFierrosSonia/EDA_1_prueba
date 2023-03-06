 #include<stdio.h>
/*
    Se recorre un arreglo bidimensional a través de un apuntador
*/

int main()
{
    int nums[3][3]={{99,88,77}, {66,55,44}, {33,22,11}};
    int *ap, indice;
    ap = nums;//ap = &nums[0];//ap=&nums
    //dezconozco por qué el warning

    for(indice=0; indice<9 ; indice++)
    {
        if((indice%3)==0)
            printf("\n");//muy tonto el código, solo los primeros cumplen, inútil en mi opinión
            //cuando una cadena se repita varias veces puedes convertirla a raw string, creo
        printf("%p\t",(ap+indice));//imprime dirección?
    }
    return 0;
}