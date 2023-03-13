#include <stdio.h>

struct pelicula
{
    char *nombre;
    char *genero;
    int year;
    int numDirectores;
    char *directores[10];
 };

 void imprimirDatosPelicula(struct pelicula);
 struct pelicula llenarDatosPelicula(char *, char *, int , int , char *[10]);

int main()
{
    char *directores[10];
    directores[0] = "Lana Wachowski"; 
    directores[1] = "Andy Wachowski";
    struct pelicula matrix = llenarDatosPelicula("The matrix", "Ciencia ficción", 1999, 2, directores);
    imprimirDatosPelicula(matrix);
    return 0;
}
  
struct pelicula llenarDatosPelicula(char *nombre, char *genero, int year, int numDirectores, char *directores[10])
{
    struct pelicula movie; 
    movie.nombre = nombre; 
    movie.genero = genero;
    movie.year = year;
    movie.numDirectores = numDirectores;
    int cont = 0;
    for ( ; cont < movie.numDirectores ; cont++)
    {
        movie.directores[cont] = directores[cont];
    }
    return movie;
}

void imprimirDatosPelicula(struct pelicula movie)
{
    printf("PELICULA: %s\n", movie.nombre);
    printf("GENERO: %s\n", movie.genero);
    printf("AÑO: %d\n", movie.year);
    printf("DIRECTOR(ES):\n");
    int cont = 0;
    for ( ; cont < movie.numDirectores ; cont++)
    {
        printf("%s\n", movie.directores[cont]);
    }
}