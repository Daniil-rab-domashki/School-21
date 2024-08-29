#include "decision.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double variance(double *data, int n);
double max(double *data, int n);
double min(double *data, int n);
double mean(double *data, int n);

int make_decision(double *data, int n) {
    int decision = 1;

    double m = mean(data, n);
    double sigma = sqrt(variance(data, n));
    double max_value = max(data, n);
    double min_value = min(data, n);

    decision &= (max_value <= m + 3 * sigma) && (min_value >= m - 3 * sigma) && (m >= GOLDEN_RATIO);

    return decision;
}
