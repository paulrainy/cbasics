//idk what was there
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrix_out(int N, int M, int matrix[N][M]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%d", matrix[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int N, M;
    N = 1 + rand() % 11;
    M = 1 + rand() % 11;
    int matrix[N][M];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            matrix[i][j] = rand() % 9;
        }
    }

    matrix_out(N, M, matrix);


}
