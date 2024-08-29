#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n);
void input(double ***matrix, int *n);
void output(double determinant);
void exit();

int main() {
    double **matrix;
    int n;

    input(&matrix, &n);
    double determinant = det(matrix, n);
    output(determinant);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void input(double ***matrix, int *n) {
    if (scanf("%d", n) != 1 || *n <= 0) {
        printf("n/a");
        exit(0);
    }

    *matrix = (double **)malloc(*n * sizeof(double *));
    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (double *)malloc(*n * sizeof(double));
    }
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            if (scanf("%lf", &(*matrix)[i][j]) != 1) {
                printf("n/a");
                for (int k = 0; k <= i; k++) {
                    free((*matrix)[k]);
                }
                free(*matrix);
                exit(0);
            }
        }
    }
}

double det(double **matrix, int n) {
    double determinant = 0;
    for (int i = 0; i < n; ++i) {
        double max_element = fabs(matrix[i][i]);
        int idx = i;

        for (int j = i + 1; j < n; ++j) {
            if (fabs(matrix[j][i]) > max_element) {
                max_element = fabs(matrix[j][i]);
                idx = j;
            }
        }
        if (max_element == 0) {
            return 0.0;
        }
        if (idx != i) {
            for (int j = 0; j < n; ++j) {
                double temp = matrix[i][j];
                matrix[i][j] = matrix[idx][j];
                matrix[idx][j] = temp;
            }
            determinant = -determinant;
        }
        for (int k = i + 1; k < n; ++k) {
            double t = matrix[k][i] / matrix[i][i];
            for (int j = i; j < n; ++j) {
                matrix[k][j] -= matrix[i][j] * t;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        determinant *= matrix[i][i];
    }

    return determinant;
}

void output(double determinant) {
    if (determinant == 0) {
        printf("0.000000");
    } else if (determinant != determinant) {
        printf("n/a");
    } else {
        printf("%.6lf", determinant);
    }
}
