#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        return 0;
    } else {
        squaring(data, n);
        output(data, n);
    }
    return 0;
}

int input(int *a, int *n) {
    char ch;
    if ((scanf("%d%c", n, &ch)) == 2 && *n <= NMAX && *n > 0 && ch == '\n') {
        for (int i = 0; i < *n; i++) {
            scanf("%d%c", &a[i], &ch);
            if (i < *n - 1) {
                if (ch != ' ') {
                    printf("n/a");
                    return 1;
                }
            } else if (ch != '\n') {
                printf("n/a");
                return 1;
            }
        }
    } else {
        printf("n/a");
        return 1;
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] *= a[i];
    }
}
