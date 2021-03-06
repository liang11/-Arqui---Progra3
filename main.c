#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatriz();
void sumaMatriz(int **matrizA,int **matrizB,int filas, int columnas);
void escalarXmatriz(int **matrizA,int escalar,int filas, int columnas);
void transpuesta(int **matriz,int filas,int columnas);
void mulMatriz(int **matrizA,int filasA,int columnasA,int **matrizB,int filasB,int columnasB);
void guardarMatriz(char **matriz,int filas,int columnas,char nombre);


int main(){
    srand(time(NULL));

    int filas;
    int columnas;

    printf("Ingrese el numero de filas: \n");
    scanf("%d", &filas);


    printf("Ingrese el numero de columnas: \n");
    scanf("%d", &columnas);


    int i,j;

    char **matriz=(char **)malloc(filas*sizeof(char *));
    for(i=0;i<filas;i++){
        matriz[i]=(char *)malloc(columnas*sizeof(char));
    };
    for(i = 0;i<filas;i++){
        for(j = 0;j<columnas;j++){
            matriz[i][j] = (rand()%200) + (-100);
            printf("%d \t",matriz[i][j]);
        };
        printf("\n");
    };

    /*printf("\n");
    printf("\n");

    printMatriz(matriz,filas,columnas);

    printf("+ \n");
    printf("\n");

    sumaMatriz(matriz,matriz,filas,columnas);

    printf(" * \n");
    printf("\n");

    escalarXmatriz(matriz,2,filas,columnas);

    printf("\n");
    printf("transpuesta \n");

    transpuesta(matriz,filas,columnas);


    printf("\n");
    printf("mult Matriz \n");

    mulMatriz(matriz,filas,columnas,matriz,filas,columnas);*/

    /*FILE * fPointer;

    fPointer = fopen("hola.txt","w");

    fprintf(fPointer,"Esto lo escribi yo");

    fclose(fPointer);*/
    char nombre = 'Rob.txt';
    guardarMatriz(matriz,filas,columnas,nombre);

    return 0;
}

void printMatriz(int **matriz,int filas,int columnas){
    int i,j;
    for(i = 0;i<filas;i++){
        for(j = 0;j<columnas;j++){
            printf("%d \t",matriz[i][j]);
        }
        printf("\n");
    }
}

void sumaMatriz(int **matrizA,int **matrizB,int filas, int columnas){
    int i,j;
    for(i = 0;i<filas;i++){
        for(j = 0;j<columnas;j++){
            matrizA[i][j] = matrizA[i][j] + matrizB[i][j];
            printf("%d \t",matrizA[i][j]);
        }
        printf("\n");
    }
}

void escalarXmatriz(int **matrizA,int escalar,int filas, int columnas){
    int i,j;
    for(i = 0;i<filas;i++){
        for(j = 0;j<columnas;j++){
            matrizA[i][j] = matrizA[i][j] * escalar;
            printf("%d \t",matrizA[i][j]);
        }
        printf("\n");
    }
}

void transpuesta(int **matriz,int filas,int columnas){
    int i,j;
    for(i = 0;i<filas;i++){
        for(j = 0;j<columnas;j++){
            printf("%d \t",matriz[j][i]);
        }
        printf("\n");
    }
}

void mulMatriz(int **matrizA,int filasA,int columnasA,int **matrizB,int filasB,int columnasB){
    int i,j,k,temp;
    for(i = 0;i<filasA;i++){
        for(j = 0;j<columnasB;j++){
            temp = 0;
            for(k = 0;k<filasA;k++){
               temp += matrizA[i][k] * matrizB[k][j];
            }
            printf("%d \t",temp);
        }
        printf("\n");
    }
}

void guardarMatriz(char **matriz,int filas,int columnas,char nombre){
    FILE * file;

    file = fopen("hola.txt","w");

    int i,j;
    for(i = 0;i<filas;i++){
        for(j = 0;j<columnas;j++){
            //printf("%f \t",matriz[j][i]);
             fprintf(file,"%d ",matriz[i][j]);
        }
        fprintf(file,"\n");
    }

    //fprintf(fPointer,"Esto lo escribi yo");

    fclose(file);
}
