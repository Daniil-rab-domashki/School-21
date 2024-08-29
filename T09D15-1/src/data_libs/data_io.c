#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

void input(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &data[i]) != 1) {
            printf("n/a");
            exit(0);
        }
    }
}
void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        (i == n - 1) ? (printf("%.2lf", data[i])) : (printf("%.2lf ", data[i]));
    }
}
