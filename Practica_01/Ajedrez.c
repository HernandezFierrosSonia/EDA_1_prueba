#include <stdio.h>

int main()
{
    int opcion;
    int x, y;
    char tablero[8][8];//nota, este no empieza desde cero
    int i, j;
    while(1)
    {
        printf("Choose an option:\n");
        printf("1) Alfil\n");
        printf("2) Torre\n");
        printf("3) Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("\n");
                printf("Escribe las coordenadas (desde 1 a 8):\n");
                printf("Coordenada x: ");
                scanf("%i", &x);
                printf("Coordenada y: ");
                scanf("%i", &y);
                printf("\n");
                
                x=x-1;
                y=y-1;

                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        tablero[i][j]='o';
                    }
                }
                tablero[x][y]='A';

                i=x;
                j=y;
                
                //superior derecha
                while(((i>0)&&(j>0))&&((i<=7)&&(j<=7)))
                {
                    i-=1;
                    j-=1;//j-=1
                    tablero[i][j]='x';
                    //printf("%d,%d \n", i, j);
                }
                
                //superior izquierda
                i=x;
                j=y;
                while(((i>0)&&(j>=0))&&((i<=7)&&(j<7)))
                {
                    i-=1;
                    j+=1;
                    tablero[i][j]='x';
                    //printf("%d,%d \n", i, j);
                }
                        
                //inferior izquierda
                i=x;
                j=y;
                while(((i>=0)&&(j>0))&&((i<7)&&(j<=7)))
                {
                    i+=1;
                    j-=1;
                    tablero[i][j]='x';
                    //printf("%d,%d \n", i, j);
                }
                        
                //inferior derecha
                i=x;
                j=y;
                while(((i>=0)&&(j>=0))&&((i<7)&&(j<7)))
                {
                    i+=1;
                    j+=1;
                    tablero[i][j]='x';
                    //printf("%d,%d \n", i, j);
                }
                        
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        printf("%c", tablero[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
                break;
            case 2:
                printf("\n");
                printf("Escribe las coordenadas (desde 1 a 8):\n");
                printf("Coordenada x: ");
                scanf("%i", &x);
                printf("Coordenada y: ");
                scanf("%i", &y);
                printf("\n");

                x-=1;
                y-=1;

                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        tablero[i][j]='o';
                    }
                }
                tablero[x][y]='T';

                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        if((i!=x)||(j!=y))//no entra si es la coordenada que nos dió el usuario
                        {
                            if((i==x)||(j==y))
                            {
                                //printf("%d, %d \n", i,j);
                                tablero[i][j]='x';
                            }
                        }
                    }
                }
                
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                    printf("%c", tablero[i][j]);
                    }
                    printf("\n");
                } 
                printf("\n");
                break;
            case 3:
                return 12;
                break;
            default:
                printf("Opción no válida.\n");
        }
    }
}