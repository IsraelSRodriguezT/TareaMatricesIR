#include <stdio.h>
void szof(int filas, int columnas, int matriz[filas][columnas]){
    int totalBytes=filas*columnas*sizeof(matriz[0][0]);
    int rowBytes=columnas*sizeof(matriz[0][0]);
    int colBytes=sizeof(matriz[0][0]);
    int filasSzof=totalBytes/rowBytes;
    int columnasSzof=rowBytes/colBytes;
    printf("Matriz:[%d][%d]\n", filasSzof, columnasSzof);
}
void bucles(int filas, int columnas, int matriz[filas][columnas], int naccion){
    for(int i=0;i<filas;i++){
        printf("|");
        for(int j=0;j<columnas;j++){
            if(naccion==1){
                printf(" %d |", matriz[i][j]);
            }
            if(naccion==2){
                if((i==0&&j==0)||(i==0&&j==(columnas-1))||(i==(filas-1)&&j==0)||(i==(filas-1)&&j==(columnas-1))){
                    printf(" %d |", matriz[i][j]);
                } else{
                    printf("   |");
                }
            }
            if(naccion==3){
                if (((matriz[i][j])%2)==0){
                    printf(" %d |", matriz[i][j]);
                } else{
                    printf("   |");
                }
            }
            if(naccion==4){
                if (((matriz[i][j])%2)!=0){
                    printf(" %d |", matriz[i][j]);
                } else{
                    printf("   |");
                }
            }
            if(naccion==5){
                if((i==0&&j==0)||(i==0&&j==(columnas-1))||(i==(filas-1)&&j==0)||(i==(filas-1)&&j==(columnas-1))){
                    printf("   |");
                } else{
                    printf(" %d |", matriz[i][j]);
                }  
            }
            if(naccion==9){
                if(i==j){
                    printf(" %d |", matriz[i][j]);
                } else{
                    printf("   |", matriz[i][j]); 
                }
            }
            if(naccion==10){
                 if(j==(columnas-1-i)){
                    printf(" %d |", matriz[i][j]);
                } else{
                    printf("   |");
                }
            }
            if(naccion==11){
                if((i==1&&j==1)||(i==1&&j==(columnas/2))||(i==(filas/2)&&j==1)||(i==(filas/2)&&j==(columnas/2))){
                    printf("   |");
                } else{
                    printf(" %d |", matriz[i][j]);
                } 
            }
        }
        printf("\n");
    }
}
void bucleinversa(int filas, int columnas, int matriz[filas][columnas], int naccion){
    float matrizIdn[filas][columnas];
    float matrizAux[filas][columnas];  
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (i == j) {
                matrizIdn[i][j] = 1;
            } else {
                matrizIdn[i][j] = 0;
            }
            matrizAux[i][j] = matriz[i][j];
        }
    }
    for (int i = 0; i < filas; i++) {
        float divisor = matrizAux[i][i];
        for (int j = 0; j < columnas; j++) {
            matrizAux[i][j] /= divisor;
            matrizIdn[i][j] /= divisor;
        }
        for (int k = 0; k < filas; k++) {
            if (i != k) {
                float factor = matrizAux[k][i];
                for (int j = 0; j < columnas; j++) {
                    matrizAux[k][j] -= factor * matrizAux[i][j];
                    matrizIdn[k][j] -= factor * matrizIdn[i][j];
                }
            }
        }
    }
    printf("Matriz inversa:\n");
    for (int i = 0; i < filas; i++) {
        printf("|");
        for (int j = 0; j < columnas; j++) {
            printf(" %.2f |", matrizIdn[i][j]);
        }
        printf("\n");
    }
}
void bucletrn(int filas, int columnas, int matriz[filas][columnas], int naccion){
    int sim;
    for(int i=0;i<columnas;i++){
        printf("|");
        for(int j=0;j<filas;j++){
            if(naccion==7){
               printf(" %d |", matriz[j][i]); 
            }
            if(naccion==8){
                if((matriz[i][j])!=(matriz[j][i])){
                    sim=0;
                    j=(columnas-1);
                    i=(filas-1);
                } else if((matriz[i][j])==(matriz[j][i])){
                    sim=1;
                    printf(" %d |", matriz[j][i]); 
                }
            }
        }
        printf("\n");
    }
    if(naccion==8){
        if(sim==0){
            printf("La matriz no es simetrica\n");
        } else if (sim==1){
            printf("La matriz si es simetrica:\n");
        }
    }
}
int main(){
    printf("Bienvenido al programa para crear una matriz\n");
    int nfilas, ncolumnas, condbucle, naccion;
    printf("Establezca el numero de filas que va a poseer su matriz\n");
    scanf("%d", &nfilas);
    printf("Establezca el numero de columnas que va a poseer su matriz\n");
    scanf("%d", &ncolumnas);
    int matriz[nfilas][ncolumnas];
    for(int i=0;i<nfilas;i++){
        for(int j=0;j<ncolumnas;j++){
            printf("Escriba un valor a ingresar: ");
            scanf("%d", &matriz[i][j]);
        }
    }
    do{
        printf("Escriba la accion que desea realizar:\n");
        printf("1 -> Para imprimir todos los elementos\n");
        printf("2 -> Para imprimir los elementos de las esquinas (la matriz debe de ser cuadrada)\n");
        printf("3 -> Para imprimir los elementos pares\n");
        printf("4 -> Para imprimir los elementos impares\n");
        printf("5 -> Para no imprimir los elementos de las esquinas (la matriz debe de ser cuadrada)\n");
        printf("6 -> Para imprimir la matriz inversa de la matriz original (la matriz debe de ser cuadrada)\n");
        printf("7 -> Para imprimir la matriz transpuesta de la matriz original\n");
        printf("8 -> Para imprimir la matriz simetrica de la matriz original\n");
        printf("9 -> Para imprimir la diagonal principal de la matriz (La matriz debe de ser cuadrada)\n");
        printf("10 -> Para imprimir la diagonal secundaria de la matriz (La matriz debe de ser cuadrada)\n");
        printf("11 -> Para imprimir el contorno de la matriz (La matriz debe de ser cuadrada)\n");
        scanf("%d", &naccion);
        if(naccion==1||(naccion==2&&nfilas==ncolumnas)||naccion==3||naccion==4||(naccion==5&&nfilas==ncolumnas)||
        (naccion==9&&nfilas==ncolumnas)||(naccion==10&&nfilas==ncolumnas)||(naccion==11&&nfilas==ncolumnas)){
            szof(nfilas, ncolumnas, matriz);
            bucles(nfilas, ncolumnas, matriz,naccion);
        } else if(naccion==6&&nfilas==ncolumnas){
            szof(nfilas, ncolumnas, matriz);
            bucleinversa(nfilas,ncolumnas,matriz,naccion);
        }else if(naccion==7||(naccion==8&&nfilas==ncolumnas)){
            szof(ncolumnas, nfilas, matriz);
            bucletrn(nfilas,ncolumnas,matriz,naccion);
        }else if(naccion==2||naccion==5||naccion==6||naccion==8||naccion==9||naccion==10||naccion==11){
            szof(nfilas, ncolumnas, matriz);
            printf("La matriz ingresada no es cuadrada\n");
        }
        printf("Deseas realizar otra accion?\n");
        printf("1 -> Si\n");
        printf("2 -> No\n");
        scanf("%d", &condbucle);
    } while(condbucle==1);
    return 0;
}