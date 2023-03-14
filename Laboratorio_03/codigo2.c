#include<stdio.h>
#define TAM 2
#define NUM_DIR 2
//una estructura por cada pieza, coordenada en cada estruct
//puedes crear una estructura para el tablero

struct pelicula{
    char nombre[20];
    char genero[20];
    short anio;
    short numDirectores;
    char directores[NUM_DIR][20];//ha de ser el máximo de palabras
};

void llenarArreglo(struct pelicula *);
void imprimirArreglo(struct pelicula *);
 
int main()
{
    struct pelicula arreglo[TAM];//son 2 peliculas, ya que tam vale 2
    llenarArreglo (arreglo);
    imprimirArreglo (arreglo);
    return 0;
}  

void llenarArreglo(struct pelicula arreglo [TAM])//yo no sé si por que esta declarado que va a recibir * ya lo hace ser uno 
{
    int iesimo, enesimo;
    for (iesimo=0 ; iesimo<TAM ; iesimo++)//son solo dos veces que s erepite el ciclo
    {
        struct pelicula movie;
        printf("####### Película %d #######\n", iesimo+1);
        printf("Ingrese nombre película: ");
        setbuf(stdin, NULL);
        scanf("%s", movie.nombre);
        getchar();
        printf("Ingrese género película: ");
        setbuf(stdin, NULL);
        scanf("%s", movie.genero);
        getchar();
        printf("Ingrese año película: ");
        setbuf(stdin, NULL);
        scanf("%hd", &movie.anio);//lo único que corregí, antes era %d
        movie.numDirectores = NUM_DIR;
        for (enesimo=0 ; enesimo<NUM_DIR ; enesimo++)
        {
            printf("Ingrese director %d: ", enesimo+1);
            setbuf(stdin, NULL);
            scanf("%s", movie.directores[enesimo]);
            getchar();
        }
        arreglo[iesimo] = movie;
    }
}

void imprimirArreglo(struct pelicula arreglo [TAM])
{
    int iesimo, enesimo;
    printf("####### Contenido del arreglo #######\n");
    for (iesimo=TAM-1 ; iesimo>=0 ; iesimo--)
    {
        printf("####### Película %d #######\n", iesimo+1);
        printf("PELÍCULA: %s\n", arreglo[iesimo].nombre);
        printf("GÉNERO: %s\n", arreglo[iesimo].genero);
        printf("AÑO: %hd\n", arreglo[iesimo].anio);//aquí funciona con %hd y con %d
        printf("DIRECTOR(ES):\n");
        for (enesimo=0 ; enesimo<arreglo[iesimo].numDirectores ; enesimo++)
        {
            printf("%s\n", arreglo[iesimo].directores[enesimo]);
        }
    }
}
 
 