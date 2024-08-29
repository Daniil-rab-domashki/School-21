#include "sort.h"

#include <stdio.h>
#include <stdlib.h>

void sort(double *data, int n) {
    double prob;
    for (int j = n; j > 1; j--) {
        for (int i = 1; i < j; i++) {
            if (data[i] < data[i - 1]) {
                prob = data[i];
                data[i] = data[i - 1];
                data[i - 1] = prob;
            }
        }
    }
}
