#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

void sort(int *a, int n);
int input(int *a, int n);
void output(int *a, int n);

int main() {
    int n;
    char ch;
    if ((scanf("%d%c", &n, &ch)) != 2 && n <= NMAX && n > 0 && ch != '\n') {
        printf("n/a");
        return 0;
    }
    int *data = (int *)malloc(n * sizeof(int));
    if (input(data, n) == 1) {
        printf("n/a");
        free(data);
        return 0;
    } else {
        sort(data, n);
        output(data, n);
    }
    free(data);
    return 0;
}

int input(int *a, int n) {
    char ch;
    int flags = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%c", &a[i], &ch);
        if (i < n - 1) {
            if (ch != ' ') {
                flags = 1;
                return flags;
            }
        } else if (ch != '\n') {
            flags = 1;
            return flags;
        }
    }
    return flags;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%c", a[i], (i == n - 1) ? '\0' : ' ');
    }
}

void sort(int *a, int n) {
    int prob;
    for (int j = n; j > 1; j--) {
        for (int i = 1; i < j; i++) {
            if (a[i] < a[i - 1]) {
                prob = a[i];
                a[i] = a[i - 1];
                a[i - 1] = prob;
            }
        }
    }
}
