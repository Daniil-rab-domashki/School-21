#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
int max(const int *a, int n);
int min(const int *a, int n);
double mean(const int *a, int n);
double variance(const int *a, int n);
void output(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

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

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("\n%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 1) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    } else {
        printf("n/a");
        return 0;
    }

    return 0;
}

double mean(const int *a, int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i];
    }
    return res / n;
}

double variance(const int *a, int n) {
    double res = 0;
    double expec = mean(a, n);

    for (int i = 0; i < n; i++) {
        res += (a[i] - expec) * (a[i] - expec);
    }
    return res / n;
}

int max(const int *a, int n) {
    int resmax = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > resmax) {
            resmax = a[i];
        }
    }
    return resmax;
}

int min(const int *a, int n) {
    int resmin = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < resmin) {
            resmin = a[i];
        }
    }
    return resmin;
}
