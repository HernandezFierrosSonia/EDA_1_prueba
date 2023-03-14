#include <stdio.h>
//brother, ya odio este compilador, me sale erro pero en otro compilador no


/*Mira, no puedes elegir la de arreglos, a menos que me quede más claro para usar solo un arreglo.
Puedes crear un estruct en el main(uno para cada pieza) con la asignación de una función a donde envías los datos, incluyendo las coordenadas, y así 
la función es del mismo tipo estruct*/

struct bishop
{
    int x;
    int y;
};// caballo

struct pawn //alfil
{
    int x;
    int y;
}pieza;

typedef struct rook //torre
{
    int x;
    int y;
}piececita;

struct queen
{
    int x;
    int y;
};

struct king
{
    int x;
    int y;
};

/*void caballo(struct bishop* );
void alfil(struct pawn *);
void torre(struct rook* );
void reina(struct queen*);
void rey(struct king* );*/

int main()
{
    int opcion;

    while(1)//while(true) for(;;)
    {
        printf("Elige una opción:\n");//no podemos crear un arreglo de las piezas por qu eno serían del mismo tipo(struct)
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
                struct bishop arreglo[1];//una pieza, solo quería ser excentrica
                
                break;
            case 2:
                //struct pawn pieza;
                //ya no cleclaré solo use;
                pieza.x=23;
                pieza.y=24;
                break;
            case 3:
                //struct rook piececita;//luego probar si puedo poner igual pieza
                piececita piececita2; 
                piececita2.x=17;
                piececita2.y=18;
                break;
            case 4:
                struct queen* piecezota[1];
                
                break;
            case 5:
                struct king piece;
                printf("Ingresa la coordenada x: ")
                scanf("%d", piece.x);
                //piece.x=19;
                piece.y=20;
                printf("Ingresa la coordenada y: ")
                scanf("%d", piece.y);
                rey(piece.x, piece.y);//estoy enviando enteros, recibe int
                break;
            case 6:
                return 18;
                break;
            default:
                printf("Opción inválida\n");
        }

    }
}
/*
void caballo(struct bishop arreglo[1])//me pregunto que pasa si no lo recibo como un arreglo de uno y solo como una variable, quién sabe, por que en la practica 2 no sabía eso y recibí la dirección del arreglo muchas veces
{//sinónimo de alfil
    arreglo[1].x=3;
    arreglo[1].y=7;
}

void alfil(struct pawn* obispo)//recibimos direcciones
{
    obispo->x=2;
    obispo->y=8;
}

void torre(struct rook* roque)//torre antiguamente conocida como roque
{
    roque->x=1;
    roque->y=3;
}

void reina(struct queen array[1])//creo que los arreglos son los únicos a quienes cuando los declaras hasta arriba como apuntadores, aquí ya no hace falta
{
    array[1].x=5;
    array[1].y=2;
}

void rey(struct king* monarca)
{
    monarca->x=1;
    monarca->y=4;
}*/