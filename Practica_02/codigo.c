#include <stdio.h>

void coordenada(int *, int *);
void reina(char (*)[8], int, int);
void rey(char (*)[8], int, int);
void tablero_empty(char (*)[8], int, int);
void imprimir_tablero(char (*)[8]);

int main()
{
    int opcion;

    int x, y;
    int *equis=&x;
    int *igriega=&y;

    char tablero[8][8];//un arreglo es un apuntador: *(*(tablero+8)+8), tons ya no tenía que apuntarlo?
    char (*chessboard)[8];
    chessboard=tablero;

    while(1)
    {
        printf("Elige una opci%cn:\n", 162);
        printf("1) Reina\n");
        printf("2) Rey\n");
        printf("3) Salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                coordenada(equis, igriega);
                reina(chessboard, x, y);
                break;
            case 2:
                coordenada(equis, igriega);
                rey(chessboard, x, y);
                break;
            case 3:
                return 18;
                break;
            default:
                printf("Opción inválida");
        }

    }
}

void coordenada(int *x, int *y)
{
    printf("Coordenadas entre 1 y 8.\n");
    printf("Ingresa la coordenada x: ");
    scanf("%d", &*x);
    *x-=1;
    printf("Ingresa la coordenada y: ");
    scanf("%d", &*y);
    *y-=1;
    printf("x=%d, y=%d\n", *x, *y);
}

void tablero_empty(char (*tab)[8], int x, int y)
{
    int i, j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            tab[i][j]='o';
    tab[x][y]='R';//para este código, rey y reina se representan con la misma letra
}

void reina(char (*tabl)[8], int x, int y)
{
    int i, j, z;
    tablero_empty(tabl, x, y);

  //SUPERIORES
    i=x;
    j=z=y;
    while((i>0)&&(i<=7))
    {
        i-=1;
        //superior izquierda
        //printf("%d", i);
        if((j>0)&&(j<=7))
        {
            j-=1;
            tabl[i][j]='x';
            //printf("%d,%d \n", i, j);
        }
        //superior derecha
        if((z>=0)&&(z<7))
        {
            z+=1;
            tabl[i][z]='x';
            //printf("%d,%d \n", i, z);
        }
    }

  //INFERIORES
    i=x;
    j=z=y;
    while((i>=0)&&(i<7))
    {
        i+=1;
        //inferior izquierda
        if((j>0)&&(j<=7))
        {
            j-=1;
            //printf("%d,%d \n", i, j);
            tabl[i][j]='x';
        }
        //inferior derecha
        if((z>=0)&&(z<7))
        {
            z+=1;
            //printf("%d,%d \n", i, j);
            tabl[i][z]='x';
        }
   }

    //Verticales y horizontales
    for(i=0;i<=7;i++)//i>=0 y i<7
        for(j=0;j<=7;j++)////i>=0 y i<7
            if((i!=x)||(j!=y))//no entra si es la coordenada que nos dió el usuario
                if((i==x)||(j==y))
                    //printf("%d, %d \n", i, j);
                    tabl[i][j]='x';
    imprimir_tablero(tabl);
}

void rey(char (*tabl)[8], int x, int y)
{
    tablero_empty(tabl, x, y);

    //superiores
    //superiores
    if((x>0)&&(x<=7))
    {
        //superior izquierda
        if((y>0)&&(y<=7))
            tabl[x-1][y-1]='x';
        //superior derceha
        if((y>=0)&&(y<7))
            tabl[x-1][y+1]='x';
    }
    
    //inferiores
    if((x>=0)&&(x<7))//cambié las i por x al cabo no se modifica x
    {  
        //inferior izquierda
        if((y>0)&&(y<=7)) 
            tabl[x+1][y-1]='x';
        //inferior derecha
        if((y>=0)&&(y<7))//como son &&, puedes ponerla en un if dentro de un if sin importar cual condición pongas primero
            tabl[x+1][y+1]='x';
    }

    //Horizontal y vertical
    if(y<7)//podías poner todos estos if anidados
    //derecha, si no entra no tiene
        tabl[x][y+1]='x';
    if(y>0)//izquierda
        tabl[x][y-1]='x';//x no se modifica 
    if(x<7)//abajo
        tabl[x+1][y]='x';
    if(x>0)//arriba
        tabl[x-1][y]='x';

    imprimir_tablero(tabl);
}

void imprimir_tablero(char (*board)[8])
{
    int i, j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void izquierdas_reina()
{
    if((j>0)&&(j<=7))
    {
        j-=1;
        //printf("%d,%d \n", i, j);
        tabl[i][j]='x';
    }
}

void derechas_reina()
{
    if((z>=0)&&(z<7))
    {
        z+=1;
        //printf("%d,%d \n", i, j);
        tabl[i][z]='x';
    }
}