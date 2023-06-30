//  Дана матрица D(N,M), N,M<=10, с элементами вещественного типа.
//  Написать программу на языке Паскаль или Си (консольный режим), которая
//  вводит матрицу, для каждой строки матрицы определяет максимальный
//  элемент и перемещает его на место последнего элемента этой строки.
//  Вывести на экран исходную и полученную после перестановки матрицы.
//  Максимальный элемент считать единственным.

// Created by Paul Rainy

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
    srand(time(NULL));

    int N, M, step;
//    fuck this way
//    printf("Enter the matrix first side <= 10:\n");
//    scanf("%d", &N);
//    printf("Enter the matrix second side <= 10:\n");
//    scanf("%d", &M);
    N = 2 + rand() % 9;
    M = 2 + rand() % 9;
    double matrix[N][M];

    step = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            matrix[i][j] = rnd(step);
            step++;
        }
    }

    matrix_out(N, M, matrix);

    double max_num = 0, slot;
    int j_max;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (matrix[i][j] > max_num){
                max_num = matrix[i][j];
                j_max = j;
            }
        }
        if (max_num != matrix[i][M-1]){
            slot = matrix[i][M-1];
            matrix[i][M-1] = max_num;
            matrix[i][j_max] = slot;
        }
        max_num = 0;
    }

    matrix_out(N, M, matrix);

    return 0;
}
