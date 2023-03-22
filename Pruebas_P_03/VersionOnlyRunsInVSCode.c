#include <stdio.h>
//soy muy floja, el caso es que tendría que hacer una función para vaciarlo y una función imprimir tablero para cada struct
//así que solo lo imprimí ya sea en el main o en su función correspondiente
struct board 
{
    char tablita[8][8];
};

struct bishop
{
    int x;
    int y;
    //int i;
    //int j;
    struct board tab;
};// caballo

struct pawn //alfil
{
    int x;
    int y;
    char tablero[8][8];
    //int i;
    //int j;
}pieza, alf;

typedef struct rook //torre
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
};

struct king
{
    int x;
    int y;
    char tablero[8][8];
};

void caballo(struct bishop* );
struct pawn alfil();
void torre(struct rook* );
void reina(struct queen*);
void rey(int , int , char (*)[8]);
/*void vaciar_tablero(int, int**, struct bishop*);bro, the problem is where do you want to call it, in main, in function
and what parametro do you want to put. Pero me decidí por floja que se mandanden a llamar desde main, soy realista mana*/

//void Alfil_tablero_empty();
//void Alfil_coordenada()

int main()
{
    int opcion;
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
                struct bishop piecezota;
                piecezota.x=22;
                piecezota.y=23;
                caballo(&piecezota);//contiene en su pedir coordenadas y le quita 1, vaciar tablero, escribe la posición de la pieza e imprimir
                printf("%i, %i\n", piecezota.x, piecezota.y);
                break;
            case 2:
                pieza.x=23;
                pieza.y=24;
                alf.x=13;
                alf.y=12;
                printf("%i, %i\n", pieza.x, pieza.y);
                printf("%i, %i\n", alf.x, alf.y);
                pieza=alfil();//contiene en su pedir coordenadas y le quita 1, vaciar tablero, escribe la posición de la pieza e imprimir

                break;
            case 3:
                piececita piececita2;
                piececita2.x=17;
                piececita2.y=18;
                printf("%i, %i\n", piececita2.x, piececita2.y);
                torre(&piececita2);//contiene en su pedir coordenadas y le quita 1, vaciar tablero, escribe la posición de la pieza e imprimir
                break;
            case 4:
                struct queen arreglo[1];
                arreglo[0].x=22;
                arreglo[0].y=23;
                printf("%i, %i\n", arreglo[0].x, arreglo[0].y);
                reina(arreglo);//contiene en su pedir coordenadas y le quita 1, vaciar tablero, escribe la posición de la pieza e imprimir
                printf("%i, %i\n", arreglo[0].x, arreglo[0].y);
                
                break;
            case 5:
                struct king piece;
                printf("Ingresa la coordenada x: ");
                scanf("%i", &piece.x);
                piece.x-=1;
                printf("Ingresa la coordenada y: ");
                scanf("%i", &piece.y);
                piece.y-=1;
                rey(piece.x, piece.y, &piece.tablero[0][0]);//creo que también era lo mismo piece.tablero
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
    int i,j;//la puedo poner en el struct
    printf("Ingresa la coordenada x: ");
    scanf("%i", &jinete->x);
    printf("Ingresa la coordenada y: ");
    scanf("%i", &jinete->y);
    (jinete->x)-=1;
    (jinete->y)-=1;
    printf("Verificando como tengo que  usar mi variable apuntador %d , %d\n", jinete->x, jinete->y);//vi que %d es para *int así que por eso lo uso, no se si tenga razon o si se pueda usar con %i
    
    //vaciar_tablero(jinete->x, &jinete->y, &jinete->tab.tablero[0][0]);//envias un *pointer(entero pues), envias una dirección  de un *pointer, envias la dirección de * un pointer a char

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
    obispo.x=2;
    obispo.y=8;

    int i, j;//no las puse en struct

    //Alfil_coordenada(int *x, int *y);

    printf("\n");
    printf("Escribe las coordenadas (desde 1 a 8):\n");
    printf("Coordenada x: ");
    scanf("%i", &obispo.x);
    printf("Coordenada y: ");
    scanf("%i", &obispo.y);
    printf("\n");
                
    obispo.x=obispo.x-1;
    obispo.y=obispo.y-1;

    //Alfil_tablero_empty(char (*tab)[8], int x, int y);

    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            obispo.tablero[i][j]='o';

    obispo.tablero[obispo.x][obispo.y]='A';

    i=obispo.x;
    j=obispo.y;
                
    //superior izquierda
    while(((i>0)&&(j>0))&&((i<=7)&&(j<=7)))
    {
        i-=1;
        j-=1;
        obispo.tablero[i][j]='x';
        //printf("%d,%d \n", i, j);
    }
                
    //superior derecha
    i=obispo.x;
    j=obispo.y;
    while(((i>0)&&(j>=0))&&((i<=7)&&(j<7)))
    {
        i-=1;
        j+=1;
        obispo.tablero[i][j]='x';
        //printf("%d,%d \n", i, j);
    }
                        
    //inferior izquierda
    i=obispo.x;
    j=obispo.y;
    while(((i>=0)&&(j>0))&&((i<7)&&(j<=7)))
    {
        i+=1;
        j-=1;
        obispo.tablero[i][j]='x';
        //printf("%d,%d \n", i, j);
    }
                        
    //inferior derecha
    i=obispo.x;
    j=obispo.y;
    while(((i>=0)&&(j>=0))&&((i<7)&&(j<7)))
    {
        i+=1;
        j+=1;
        obispo.tablero[i][j]='x';
        //printf("%d,%d \n", i, j);
    }
                        
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("%c", obispo.tablero[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return obispo;
}

void torre(struct rook* roque)
{    
    int i, j;
    roque->x=1;
    roque->y=3;

    printf("\n");
    printf("Escribe las coordenadas (desde 1 a 8):\n");
    printf("Coordenada x: ");
    scanf("%i", &roque->x);
    printf("Coordenada y: ");
    scanf("%i", &roque->y);
    printf("\n");

    roque->x-=1;
    roque->y-=1;

    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            roque->tablero[i][j]='o';

    roque->tablero[roque->x][roque->y]='T';

    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if((i!=roque->x)||(j!=roque->y))//no entra si es la coordenada que nos dió el usuario
                if((i==roque->x)||(j==roque->y))
                    //printf("%d, %d \n", i,j);
                    roque->tablero[i][j]='x';
                
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            printf("%c", roque->tablero[i][j]);
        printf("\n");
    } 
    printf("\n");
}


void reina(struct queen array[1])
{
    int i, j, z;

    array[0].x=5;
    array[0].y=2;
    array[0].tablero[3][4]='x';

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
            //z+=1;
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
    printf("%i, %i", x, y);

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
    if(y<7)
    //derecha
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