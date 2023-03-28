#include <stdio.h>
#include <stdlib.h>

struct pawn //alfil
{
    int x;
    int y;
    char tablero[8][8];
}*pieza;

int main()
{
    pieza=(struct pawn*)malloc(sizeof(struct pawn));

}