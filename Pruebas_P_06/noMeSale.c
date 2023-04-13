#include<stdio.h>
#include<string.h>
#define MAX 25
/*los arreglos, al menos los char, tienen un problemon
que no tiene solución*/

int main()
{
    int i;
    char palabrita[MAX];
    char palabra[MAX];
    char word[MAX];

    for(i=0;i<25;++i)
    {
        palabrita[i]='.';
        palabra[i]='.';
        word[i]='.';
    }

    //prueba 1, iniciarla dentro del programa
    palabrita[0]='m';
    palabrita[1]='a';
    palabrita[2]='m';
    palabrita[3]='a';
    
    for(i=0;i<=3;i++)//la imprimimos
    {
        printf("%c", palabrita[i]);
    } 

    if(palabrita[4]=='.')
    {
        printf("\nPalabrita Hell yea cangrejo\n");
    }

    if(palabrita[4]==' ')
    {
        printf("\nPalabrita oh no cangrejo\n");
    }

    //prueba 2, string pedida al usuario, voy a ingresar papa
    printf("Ingresa una palabra en minúsculas de máximo 25 caracteres: ");
    scanf("%s", palabra);

    if(palabra[4]=='.')
    {
        printf("\nPalabra Hell yea cangrejo\n");
    }

    if(palabra[4]==' ')
    {
        printf("\nPalabra oh no cangrejo\n");
    }
    
    for(i=0; i<=4;i++)
    {
        if(palabra[i]==' ')//'' significa empty character constant
        {//no entró nunca
            printf("Hola %d\n", i);
        }
    }
    printf("Palabra cangrejo confuso '%c'", palabra[4]);//es que me imprime algo inexistente, imprime esto Palabra cangrejo confuso '', ves no existe, por eso no entra a ninguna opción
    
    //prueba 3, pedir cada caracter uno por uno, voy a ingresar pama
    
    /*printf("Letra 1: ");
    scanf("%c", &word[0]);
    printf("Ño");
    
    printf("Letra 2: ");
    scanf("%c", &word[1]);
    printf("Ño");*/
    
    printf("Letra 3: ");
    scanf("%c", &word[2]);
    printf("Ño");
    
    /*printf("Letra 4: ");
    scanf("%c", &word[3]);
    printf("Ño");*/

    if(word[4]==' ')
    {
        printf("\nWord oh no cangrejo en problemas\n");
    }

    if(word[4]=='.')//leer caracter por caracter sería la mejor opción, pero no sé como
    {
        printf("\nWord Hell yea cangrejo\n");
    }
    
}