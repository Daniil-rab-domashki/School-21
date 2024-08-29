#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
void sort_vertical(int n, int m, int **result_matrix);
void sort_horizontal(int n, int m, int **result_matrix);
void input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);
void free_matrix(int **matrix, int n);

int main() {
    int **matrix = NULL, **result = NULL;
    int n, m;
    input(&matrix, &n, &m);
    if (n <= 0 || m <= 0 || matrix == NULL) {
        printf("n/a");
        return 0;
    }
    result = (int **)malloc(n * sizeof(int *));
    if (result == NULL) {
        printf("n/a");
        free_matrix(matrix, n);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        result[i] = (int *)malloc(m * sizeof(int));
        if (result[i] == NULL) {
            printf("n/a");
            free_matrix(result, i);
            free_matrix(matrix, n);
            return 0;
        }
    }
    sort_vertical(n, m, result);
    output(result, n, m);
    sort_horizontal(n, m, result);
    output(result, n, m);
    free_matrix(matrix, n);
    free_matrix(result, n);

    return 0;
}

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

void sort_vertical(int n, int m, int **result_matrix) {
    int current_value = 1;
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++) {
                result_matrix[i][j] = current_value;
                current_value++;
            }
        } else {
            for (int i = n - 1; i >= 0; i--) {
                result_matrix[i][j] = current_value;
                current_value++;
            }
        }
    }
}

void sort_horizontal(int n, int m, int **result_matrix) {
    int current_value = 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                result_matrix[i][j] = current_value;
                current_value++;
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                result_matrix[i][j] = current_value;
                current_value++;
            }
        }
    }
}

void input(int ***matrix, int *n, int *m) {
    if (scanf("%d %d", n, m) != 2 || *n <= 0 || *m <= 0) {
        printf("n/a");
        exit(0);
    }

    *matrix = (int **)malloc(*n * sizeof(int *));
    if (*matrix == NULL) {
        printf("n/a");
        exit(0);
    }

    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (int *)malloc(*m * sizeof(int));
        if ((*matrix)[i] == NULL) {
            printf("n/a");
            free_matrix(*matrix, i);
            exit(0);
        }
        for (int j = 0; j < *m; j++) {
            scanf("%d", &(*matrix)[i][j]);
        }
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(int **matrix, int n) {
    if (matrix == NULL) exit(0);
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
