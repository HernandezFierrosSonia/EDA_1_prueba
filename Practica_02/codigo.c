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

    char tablero[8][8];
    char (*chessboard)[8];
    chessboard=tablero;

    while(1)
    {
        printf("Elige una opción:\n");
        printf("1) Reina\n");
        printf("2) Rey\n");
        printf("3) Salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                coordenada(equis, &y);
                reina(chessboard, x, y);
                break;
            case 2:
                coordenada(&x, igriega);
                rey(chessboard, x, y);
                break;
            case 3:
                return 18;
                break;
            default:
                printf("Opción inválida\n");
        }

    }
}

void coordenada(int *x, int *y)
{
    invalid:
    printf("\nCoordenadas entre 1 y 8 por favor.\n");
    printf("Ingresa la coordenada x: ");
    scanf("%d", &*x);
    *x-=1;
    printf("Ingresa la coordenada y: ");
    scanf("%d", &*y);
    if(((*y<1)||(*y>8))&&((*x<1)||(*x>8))) goto invalid;
    *y-=1;
}

void tablero_empty(char (*tab)[8], int x, int y)
{
    int i, j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            tab[i][j]='o';
    tab[x][y]='R';
}

void reina(char (*tabl)[8], int x, int y)
{
    int i, j, z;
    tablero_empty(tabl, x, y);

    //SUPERIORES
    i=x;
    j=z=y;
    while(i>0)
    {
        i-=1;
        //superior izquierda
        if(j>0)
            tabl[i][j-=1]='x';
        //superior derecha
        if(z<7)
            //z+=1;
            tabl[i][z+=1]='x';
    }

  //INFERIORES
    i=x;
    j=z=y;
    while(i<7)
    {
        i+=1;
        //inferior izquierda
        if((j>0))
            tabl[i][j-=1]='x';
        //inferior derecha
        if(z<7)
            tabl[i][z+=1]='x';
    }

    //Verticales y horizontales
    for(i=0;i<=7;i++)
        for(j=0;j<=7;j++)
            if((i!=x)||(j!=y))//no entra si es la coordenada que nos dió el usuario
                if((i==x)||(j==y))
                    tabl[i][j]='x';

    imprimir_tablero(tabl);
}

void rey(char (*tabl)[8], int x, int y)
{
    tablero_empty(tabl, x, y);

    //superiores
    if(x>0)
    {
        //superior izquierda
        if(y>0)
            tabl[x-1][y-1]='x';
        //superior derecha
        if(y<7)
            tabl[x-1][y+1]='x';
    }
    
    //inferiores
    if(x<7)
    {
        //inferior izquierda
        if(y>0) 
            tabl[x+1][y-1]='x';
        //inferior derecha
        if(y<7)
            tabl[x+1][y+1]='x';
    }

    //Horizontal y vertical
    if(y<7)
    //derecha
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
            printf("%c", board[i][j]);
        printf("\n");
    }
    printf("\n");
}