#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rnd(int position) {
    if (position % 2 == 0) {
        return (double)(1 + rand() % 9);
    }
    else {
        return (double)(1 + rand() % 9) / 10 + (double)(1 + rand() % 9);
    }
}

void matrix_out(int N, int M, double matrix[N][M]){
    for (size_t i = 0; i < N; i++){
        for (size_t j = 0; j < M; j++){
            printf("%lf", matrix[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(0));

    int N = 1 + rand() % 9;
    int M = 1 + rand() % 9;
    int step = 0;
    double matrix[N][M];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            matrix[i][j] = rnd(step);
            step++;
        }
    }

    matrix_out(N, M, matrix);


    return 0;
}
