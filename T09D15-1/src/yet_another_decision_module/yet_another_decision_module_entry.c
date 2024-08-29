#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"
int make_decision(double *data, int n);

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
    } else {
        double *data = malloc(n * sizeof(double));
        input(data, n);
        if (make_decision(data, n)) {
            printf("YES");
            free(data);
        } else {
            printf("NO");
            free(data);
        }
    }
}
