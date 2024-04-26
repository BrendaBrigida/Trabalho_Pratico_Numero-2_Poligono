#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float X;
    float Y;
} Ponto;


float AreaTriangulo(Ponto A, Ponto B, Ponto C){
    return 0.5 * ((A.X * (B.Y - C.Y)) + (B.X * (C.Y - A.Y)) + (C.X * (A.Y - B.Y)));
}

    //Funcao para ler os pontos do arquivo e calcular a area do poligono
float CalcularAreaPoligono(FILE *arquivo){
    int numVertices;
    fscanf(arquivo, "%d", &numVertices); 

    Ponto *vertices = malloc(numVertices * sizeof(Ponto));

    //lendo vertices
    for (int i = 0; i < numVertices; i++){
        fscanf(arquivo, "%f %f", &(vertices[i].X), &(vertices[i].Y));
    }

    //calculando a area do poligono   
    float areaTotal = 0;
    for (int i = 1; i < numVertices - 1; i++){
        areaTotal += AreaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }

    free(vertices); 

    return areaTotal;
}

int main(){
    //Lembre-se de criar um arquivo texto chamado "PoligonoABC"
    FILE *arquivo;
    arquivo = fopen("PoligonoABC.txt", "r"); 

    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    float area = CalcularAreaPoligono(arquivo); 
    printf("A area do poligono e %.2f\n", area);

    fclose(arquivo); 

    return 0;
}