#include<stdio.h>

void caballo();
void alfil();
void torre();
void reina();
void rey();

struct bishop// caballo
{
    int x;
    int y;
    char tablero[8][8];//se me hace muy feo crear un arreglo por cada struct, es más se van a crear muchisismos, aunque no sé explicar por qué
    
};

struct pawn //alfil
{
    int x;
    int y;
    char tablero[8][8];//se me hace muy feo crear un arreglo por cada struct, es más se van a crear muchisismos, aunque no sé explicar por qué
    
};

struct rook //torre
{
    int x;
    int y;
    char tablero[8][8];//se me hace muy feo crear un arreglo por cada struct, es más se van a crear muchisismos, aunque no sé explicar por qué
    
};

struct queen
{
    int x;
    int y;
    char tablero[8][8];//se me hace muy feo crear un arreglo por cada struct, es más se van a crear muchisismos, aunque no sé explicar por qué

};

struct king
{
    int x;
    int y;
    char tablero[8][8];//se me hace muy feo crear un arreglo por cada struct, es más se van a crear muchisismos, aunque no sé explicar por qué
    
};

int main()
{
    int opcion;

    char tablero[8][8];
    char (*chessboard)[8];
    chessboard=tablero;

    for(;;)//while(1) while(true)
    {
        printf("Elige una opción:\n");
        printf("1) Caballo\n");
        printf("2) ALfil\n");
        printf("3) Torre\n");
        printf("4) Reina\n");
        printf("5) Rey\n");
        printf("6) Salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                caballo(chessboard, x, y);
                break;
            case 2:
                alfil(chessboard, x, y);
                break;
            case 3:
                torre(chessboard, x, y);
                break;
            case 4:
                reina(chessboard, x, y);
                break;
            case 5:
                rey(chessboard, x, y);
                break;
            case 6:
                return 18;
                break;
            default:
                printf("Opción inválida\n");
        }

    }
}

void caballo()
{

}

void alfil()
{

}

void torre()
{

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

void rey()
{

}