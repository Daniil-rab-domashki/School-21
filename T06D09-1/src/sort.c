#include <stdio.h>
#define NMAX 10

void sort(int *a, int n);
int input(int *a, int const *n);
void output(int *a, int n);

int main() {
    int n = 10, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
        return 0;
    } else {
        sort(data, n);
        output(data, n);
    }
    return 0;
}

int input(int *a, int const *n) {
    char ch;
    int flags = 0;
    for (int i = 0; i < *n; i++) {
        scanf("%d%c", &a[i], &ch);
        if (i < *n - 1) {
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
