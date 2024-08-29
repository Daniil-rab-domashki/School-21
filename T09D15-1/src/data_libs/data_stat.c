#include "data_stat.h"

#include <stdio.h>
#include <stdlib.h>

double mean(double *data, int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += data[i];
    }
    return res / n;
}

double variance(double *data, int n) {
    double res = 0;
    double expec = mean(data, n);

    for (int i = 0; i < n; i++) {
        res += (data[i] - expec) * (data[i] - expec);
    }
    return res / n;
}

double max(double *data, int n) {
    double resmax = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] > resmax) {
            resmax = data[i];
        }
    }
    return resmax;
}

double min(double *data, int n) {
    double resmin = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < resmin) {
            resmin = data[i];
        }
    }
    return resmin;
}
