#include <stdio.h>
//TYPA es struct pelicula
//en este código no lee
TYPA
{
    char *nombre;//así se declara un string
    char *genero;
    short year;
    short numDirectores;
    char *directores[10];
};

void imprimirDatosPelicula(TYPA);
TYPA llenarDatosPelicula(char *, char *, short , short , char *[10]);

int main()
{
    char *directores[10];//despercio de memoria para los que no se llenaron
    //la línea anterior es un apuntador de arreglo, pero creo que los arreglos funcionan diferente a las variables normales, aquí si lo ocupas sin * es como el contenido, no la dirección como sería en las normales
    //de esta manera también se usarn los apuntadores de arrglos en funciones, es decir sin *
    //la verdad es que es muy raro y nuevo, ver un arreglo que es un apuntador

    directores[0]="Chris Columbus"; 
    directores[1]="Alfonso Cuaron";
    directores[2]="Mike Newell";
    TYPA HARRY = llenarDatosPelicula("Harry Potter", "Misterio y aventuras", 2001, 3, directores);//envie directores, envie una dirección, otra forma de hacerlo es declarar el arrego sin ser apuntador y aquí mandar &arreglo
    imprimirDatosPelicula(HARRY);
    return 0;
}
  
TYPA llenarDatosPelicula(char *nombre, char *genero, short year, short numDirectores, char *directores[10])//entiendele bien a esto mana
{/*¿Por que los recibió como arreglos a algunos? Entiendo a directores, eso es una dirección, pero Harry Potter no es una dirección
Ha ya, por que son string, char *nombre="Harry Potter"   es totalmente válido*/
    TYPA movie;//me gustaban más los pauntadores
    //aquí por ejemplo creó una variable igual a la que tiene que devolver, al igual que el otro código
    movie.nombre = nombre; 
    movie.genero = genero;
    movie.year = year;
    movie.numDirectores = numDirectores;
    int i;
    for (i=0;i<movie.numDirectores;i++)
        movie.directores[i] = directores[i];
    return movie;
}

void imprimirDatosPelicula(TYPA movie)//envió una copia
{
    int i;
    printf("PELICULA: %s\n", movie.nombre);
    printf("GENERO: %s\n", movie.genero);
    printf("AÑO: %d\n", movie.year);
    printf("DIRECTOR(ES):\n");
    for (i=0;i<movie.numDirectores;i++)//que pasa si no hubiera inicializado la línea anterior, supongo que error por que lo pones en casillas al i
        printf("%s\n", movie.directores[i]);
}