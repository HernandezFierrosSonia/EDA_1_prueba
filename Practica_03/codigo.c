#include <stdio.h>

/*Mira, no puedes elegir la de arreglos, a menos que me quede más claro para usar solo un arreglo.
Puedes crear un estruct en el main(uno para cada pieza) con la asignación de una función a donde envías los datos, incluyendo las coordenadas, y así 
la función es del mismo tipo estruct*/

struct bishop
{
    int x;
    int y;
    char tablero[8][8];//se me hace muy feo crear un arreglo por cada struct, es más se van a crear muchisismos, aunque no sé explicar por qué

};// caballo

struct pawn //alfil
{
    int x;
    int y;
    char tablero[8][8];
    
};

struct rook //torre
{
    int x;
    int y;
    char tablero[8][8];
    
};

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
void alfil(struct pawn *);
void torre(struct rook* );
void reina(struct queen*);
void rey(struct king* );

int main()
{
    int opcion;

    for(;;)//while(1) while(true)
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
                struct bishop* arreglo[1];//una pieza, solo quería ser excentrica
                caballo(arreglo);//estas enviando una dirección
                break;
            case 2:
                struct pawn pieza;
                alfil(&pieza);
                break;
            case 3:
                struct rook piececita;//luego probar si puedo poner igual pieza
                torre(&piececita);
                break;
            case 4:
                struct queen* piecezota[1];
                reina(piecezota);
                break;
            case 5:
                struct king piece;
                rey(&piece);
                break;
            case 6:
                return 18;
                break;
            default:
                printf("Opción inválida\n");
        }

    }
}

void caballo(struct bishop arreglo[1])//me pregunto que pasa si no lo recibo como un arreglo de uno y solo como una variable
{//sinónimo de alfil
    arreglo[1].x=3;
    arreglo[1].y=7;
    arreglo[1].tablero={
    'o','o','o','o','o','o','o','o',
    'o','o','o','o','o','o','o','o', 
    'o','o','o','o','o','o','C','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    };
}

void alfil(struct pawn obispo)//recibimos direcciones
{
    obispo.x=2;
    obispo.y=8;
    obispo.tablero={
    'o','o','o','o','o','o','o','o',
    'o','o','o','o','o','o','o','A', 
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    };
}

void torre(struct rook roque)//torre antiguamente conocida como roque
{
    roque.x=1;
    roque.y=3;
    roque.tablero={'o','o','T','o','o','o','o','o',
    'o','o','o','o','o','o','o','o', 
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    };
}

void reina(struct queen array[1])
{
    array[1].x=5;
    array[1].y=2;
    array[1].tablero={
    'o','o','o','o','o','o','o','o',
    'o','o','o','o','o','o','o','o', 
    'o','o','o','o','o','o','C','o',    
    'o','o','o','o','o','o','o','o',    
    'o','Q','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    };
}

void rey(struct king monarca)
{
    monarca.x=1;
    monarca.y=4;
    monarca.tablero={
    'o','o','o','R','o','o','o','o',
    'o','o','o','o','o','o','o','o', 
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    'o','o','o','o','o','o','o','o',    
    };
}