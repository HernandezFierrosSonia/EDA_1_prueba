#include <stdio.h>

struct board 
{
    char tablita[8][8];
};

struct bishop
{
    int x;
    int y;
    struct board tab;
}piecezota;// caballo

struct pawn //alfil
{
    int x;
    int y;
    char tablero[8][8];
}pieza;

struct rook //torre
{
    int x;
    int y;
    char tablero[8][8];
}piececita;

struct queen
{
    int x;
    int y;
    char tablero[8][8];
}arreglo[1];

struct king
{
    int x;
    int y;
    char tablero[8][8];
}piece;

void caballo(struct bishop* );
struct pawn alfil();
void torre();
void reina(struct queen*);
void rey(int , int , char (*)[8]);

int main()
{
    int opcion;
                    int i,j;
    for(;;)
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
                caballo(&piecezota);
                break;
            case 2:
                pieza=alfil();
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                        printf("%c", pieza.tablero[i][j]);
                    printf("\n");
                }
                printf("\n");
                break;
            case 3:
                torre();
                break;
            case 4:
                reina(arreglo);
                break;
            case 5:
                printf("Escribe las coordenadas (desde 1 a 8):\n");
                printf("Ingresa la coordenada x: ");
                scanf("%i", &piece.x);
                piece.x-=1;
                printf("Ingresa la coordenada y: ");
                scanf("%i", &piece.y);
                piece.y-=1;
                rey(piece.x, piece.y, &piece.tablero[0][0]);
                break;
            case 6:
                return 18;
                break;
            default:
                printf("Opción inválida\n");
        }
    }
}

void caballo(struct bishop* jinete)
{
    int i,j;

    printf("Escribe las coordenadas (desde 1 a 8):\n");
    printf("Ingresa la coordenada x: ");
    scanf("%i", &jinete->x);
    printf("Ingresa la coordenada y: ");
    scanf("%i", &jinete->y);
    (jinete->x)-=1;
    (jinete->y)-=1;
    
    for(i=0; i<=7; ++i)
        for(j=0; j<=7; ++j)
            jinete->tab.tablita[i][j]='o';

    i=(jinete->x);
    j=(jinete->y);

    jinete->tab.tablita[i][j]='C';

    if((i-2)>=0)
    {
        if((j-1)>=0)
            jinete->tab.tablita[i-2][j-1]='x';
        if((j+1)<=7)
            jinete->tab.tablita[i-2][j+1]='x';
    }
    if((i+2)<=7)
    {
        if((j-1)>=0)
            jinete->tab.tablita[i+2][j-1]='x';
        if((j+1)<=7)
            jinete->tab.tablita[i+2][j+1]='x';
    }
    if((j-2)>=0)
    {
        if((i-1)>=0)
            jinete->tab.tablita[i-1][j-2]='x';
        if((i+1)<=7)
            jinete->tab.tablita[i+1][j-2]='x';
    }
    if((j+2)<=7)
    {
        if((i-1)>=0)
            jinete->tab.tablita[i-1][j+2]='x';
        if((i+1)<=7)
            jinete->tab.tablita[i+1][j+2]='x';
    }
    printf("\n\n");
    for(i=0; i<=7; ++i)
    {
        for(j=0; j<=7; ++j)
            printf("%c", jinete->tab.tablita[i][j]);
        printf("\n");
    }
}

struct pawn alfil()
{
    struct pawn obispo;

    int i, j, z;

    printf("\n");
    printf("Escribe las coordenadas (desde 1 a 8):\n");
    printf("Coordenada x: ");
    scanf("%i", &obispo.x);
    printf("Coordenada y: ");
    scanf("%i", &obispo.y);
    printf("\n");
                
    obispo.x=obispo.x-1;
    obispo.y=obispo.y-1;

    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            obispo.tablero[i][j]='o';

    obispo.tablero[obispo.x][obispo.y]='A';

    //SUPERIORES
    i=obispo.x;
    j=z=obispo.y;
    while(i>0)
    {
        i-=1;
        //superior izquierda
        if(j>0)
            obispo.tablero[i][j-=1]='x';
        //superior derecha
        if(z<7)
            obispo.tablero[i][z+=1]='x';
    }

  //INFERIORES
    i=obispo.x;
    j=z=obispo.y;
    while(i<7)
    {
        i+=1;
        //inferior izquierda
        if((j>0))
            obispo.tablero[i][j-=1]='x';
        //inferior derecha
        if(z<7)
            obispo.tablero[i][z+=1]='x';
    }        
    return obispo;
}

void torre()
{    
    int i, j;

    printf("\n");
    printf("Escribe las coordenadas (desde 1 a 8):\n");
    printf("Coordenada x: ");
    scanf("%i", &piececita.x);
    printf("Coordenada y: ");
    scanf("%i", &piececita.y);
    printf("\n");

    piececita.x-=1;
    piececita.y-=1;

    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            piececita.tablero[i][j]='o';

    piececita.tablero[piececita.x][piececita.y]='T';

    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if((i!=piececita.x)||(j!=piececita.y))//no entra si es la coordenada que nos dió el usuario
                if((i==piececita.x)||(j==piececita.y))
                    piececita.tablero[i][j]='x';
                
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            printf("%c", piececita.tablero[i][j]);
        printf("\n");
    } 
    printf("\n");
}


void reina(struct queen array[1])
{
    int i, j, z;

    printf("\n");
    printf("Escribe las coordenadas (desde 1 a 8):\n");
    printf("Coordenada x: ");
    scanf("%i", &array[0].x);//% es el tipo del último valor 
    printf("Coordenada y: ");
    scanf("%i", &array[0].y);
    printf("\n");

    array[0].x-=1;
    array[0].y-=1;

    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            array[0].tablero[i][j]='o';
    array[0].tablero[array[0].x][array[0].y]='Q';

    //SUPERIORES
    i=array[0].x;
    j=z=array[0].y;
    while(i>0)
    {
        i-=1;
        //superior izquierda
        if(j>0)
            array[0].tablero[i][j-=1]='x';
        //superior derecha
        if(z<7)
            array[0].tablero[i][z+=1]='x';
    }

  //INFERIORES
    i=array[0].x;
    j=z=array[0].y;
    while(i<7)
    {
        i+=1;
        //inferior izquierda
        if((j>0))
            array[0].tablero[i][j-=1]='x';
        //inferior derecha
        if(z<7)
            array[0].tablero[i][z+=1]='x';
    }

    //Verticales y horizontales
    for(i=0;i<=7;i++)
        for(j=0;j<=7;j++)
            if((i!=array[0].x)||(j!=array[0].y))//no entra si es la coordenada que nos dió el usuario
                if((i==array[0].x)||(j==array[0].y))
                    array[0].tablero[i][j]='x';

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            printf("%c", array[0].tablero[i][j]);
        printf("\n");
    }
    printf("\n");
}

void rey(int x, int y, char (*monarca)[8])
{
    int i, j;

    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            monarca[i][j]='o';
    monarca[x][y]='R';

    //superiores
    if(x>0)
    {
        //superior izquierda
        if(y>0)
            monarca[x-1][y-1]='x';
        //superior derecha
        if(y<7)
            monarca[x-1][y+1]='x';
    }
    
    //inferiores
    if(x<7)
    {
        //inferior izquierda
        if(y>0) 
            monarca[x+1][y-1]='x';
        //inferior derecha
        if(y<7)
            monarca[x+1][y+1]='x';
    }

    //Horizontal y vertical
    if(y<7)//derecha
        monarca[x][y+1]='x';
    if(y>0)//izquierda
        monarca[x][y-1]='x';//x no se modifica 
    if(x<7)//abajo
        monarca[x+1][y]='x';
    if(x>0)//arriba
        monarca[x-1][y]='x';

    printf("\n");
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            printf("%c", monarca[i][j]);
        printf("\n");
    }
    printf("\n");
}