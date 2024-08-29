#include <stdio.h>
#define NMAX 10
#include <math.h>

int input(int *a, int *n);
double mean(const int *a, int n);
double threesigma(int *a, int n);
void output_result(int const *a, int n, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 1) {
        output_result(data, n, mean(data, n), threesigma(data, n));

    } else {
        printf("n/a");
        return 0;
    }

    return 0;
}

int input(int *a, int *n) {
    char ch;
    int flags = 1;
    if ((scanf("%d%c", n, &ch)) == 2 && *n <= NMAX && *n > 0 && ch == '\n') {
        for (int i = 0; i < *n; i++) {
            scanf("%d%c", &a[i], &ch);
            if (i < *n - 1) {
                if (ch != ' ') {
                    flags = 0;
                    return flags;
                }
            } else if (ch != '\n') {
                flags = 0;
                return flags;
            }
        }
    } else {
        flags = 0;
        return flags;
    }
    return flags;
}

void output_result(int const *a, int n, double mean_v, double variance_v) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] >= mean_v && a[i] <= variance_v) {
            res = a[i];
            break;
        }
    }
    printf("%d", res);
}

double mean(const int *a, int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i];
    }
    return res / n;
}

double threesigma(int *a, int n) {
    double res = 0;
    double expec = mean(a, n);

    for (int i = 0; i < n; i++) {
        res += (a[i] - expec) * (a[i] - expec);
    }
    return (mean(a, n) + 3) * sqrt(res / n);
}
