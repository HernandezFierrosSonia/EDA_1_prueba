#include <stdio.h>
//TYPA es struct pelicula
TYPA
{
    char *nombre;
    char *genero;
    short anio;
    short numDirectores;
    char *directores[10];
};

void imprimirDatosPelicula(TYPA);
TYPA llenarDatosPelicula(char *, char *, short , short , char *[10]);

int main()
{
    char *directores[10];
    directores[0]="Chris Columbus"; 
    directores[1]="Alfonso Cuaron";
    directores[2]="Mike Newell";
    TYPA HARRY = llenarDatosPelicula("Harry Potter", "Misterio y aventuras", 2001, 3, directores);
    imprimirDatosPelicula(HARRY);
    return 0;
}
  
TYPA llenarDatosPelicula(char *nombre, char *genero, short anio, short numDirectores, char *directores[10])
{
    TYPA movie; 
    movie.nombre = nombre; 
    movie.genero = genero;
    movie.anio = anio;
    movie.numDirectores = numDirectores;
    int cont = 0;
    for ( ; cont < movie.numDirectores ; cont++)
    {
        movie.directores[cont] = directores[cont];
    }
    return movie;
}

void imprimirDatosPelicula(TYPA movie)
{
    printf("PELICULA: %s\n", movie.nombre);
    printf("GENERO: %s\n", movie.genero);
    printf("ANIO: %d\n", movie.anio);
    printf("DIRECTOR(ES):\n");
    int i = 0;
    for ( ; i < movie.numDirectores ; i++)//que pasa si no hubiera inicializado la línea anterior, supongo que error por que lo pones en casillas al i
        printf("%s\n", movie.directores[i]);
}