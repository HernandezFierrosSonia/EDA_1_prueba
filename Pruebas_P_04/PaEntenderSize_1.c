#include <stdio.h>
#include <stdlib.h>//esto por si solo no modifica nada
int cabeza=18;//las globales inicializadas modifican data(aumenta) y bss(disminuye por 4), no inicializadas no modifican

int main()
{
    int hola;//esto no modifica nada
    int vida;
    int adios=5;//esto no modifica nada
    int *dolor;//no modifica nada//es lo mismo char que int
    dolor=(int*)malloc(7*sizeof(int));//esto modifica text(aumenta), data(aumenta en 6), dec(aumenta) y hex(aumenta)//es lo mismo char que int
    if(dolor!=NULL)
    {
        free(dolor);//text aumenta, data aumento en 8, bss no cambia, dec aumenta y hex aumenta
    }
    return 0;
}
//los renglones vacíos no modifican nada