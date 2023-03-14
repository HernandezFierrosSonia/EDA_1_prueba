#include<stdio.h>
#define TAM 2
#define NUM_DIR 2 //solo dos directores
//una estructura por cada pieza, coordenada en cada estruct
//puedes crear una estructura para el tablero
//este código sí lee del usuario
//este código usa apuntadores

struct pelicula
{
    char nombre[20];//maximo de caracteres, pero pudo haber sido char *nombre;
    char genero[20];
    int  year;
    int numDirectores;
    char directores[NUM_DIR][20];//ha de ser el máximo de letras que puedes poner 
};

void llenarArreglo(struct pelicula *);
void imprimirArreglo(struct pelicula *);
 
int main()
{
    struct pelicula arreglo[TAM];//son 2 peliculas, ya que tam vale 2
    llenarArreglo (arreglo);//me creas o no envió una dirección, ya que arreglo=&arreglo[0]=&arreglo (aguas solo para los casos en que arreglo no es apuntador, si lo es creo que arreglito=&arreglito[0]!=&arreglito
    imprimirArreglo (arreglo);//envió dirección
    return 0;
}  

void llenarArreglo(struct pelicula arreglo [TAM])//yo no sé si por que esta declarado que va a recibir * ya lo hace ser uno. Confirmo
{//creo una variable movie tipo struct pelicula y la vaoy enviando el número de veces que el arreglo tenga de índice
    int i, n;

    /*la única razón por la que trabajo con copias pese haber enviado el original es por que es un arreglo 
    pero de que se puede se puede, esta es la manera floja de evitar entender el manejo de apuntadores*/

    for (i=0 ; i<TAM ; i++)//son solo dos veces que se repite el ciclo
    {
        struct pelicula movie;//se puede sacar del for, pa' que no se cree doble y solo se sobreescriba
        printf("####### Película %d #######\n", i+1);
        printf("Ingrese nombre película: ");
        scanf("%s", movie.nombre);
        printf("Ingrese género película: ");
        scanf("%s", movie.genero);
        printf("Ingrese año película: ");
        scanf("%d", &movie.year);
        movie.numDirectores = NUM_DIR;
        for (n=0 ; n<NUM_DIR ; n++)
        {
            printf("Ingrese director %d: ", n+1);
            scanf("%s", movie.directores[n]);
        }
        arreglo[i]=movie;//lo guarda antes de terminar el for
    }
}

void imprimirArreglo(struct pelicula arreglo [TAM])
{
    int i, n;
    printf("####### Contenido del arreglo #######\n");
    for (i=TAM-1 ; i>=0 ; i--)//por que hacerlo tan raro e imprimir primero la última película
    {
        printf("####### Película %d #######\n", i+1);
        printf("PELÍCULA: %s\n", arreglo[i].nombre);
        printf("GÉNERO: %s\n", arreglo[i].genero);
        printf("AÑO: %d\n", arreglo[i].year);
        printf("DIRECTOR(ES):\n");
        for (n=0 ; n<arreglo[i].numDirectores ; n++)
            printf("%s\n", arreglo[i].directores[n]);
    }
}