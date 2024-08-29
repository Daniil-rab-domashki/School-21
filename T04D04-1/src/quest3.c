#include <math.h>
#include <stdio.h>
int fib(int N);

int main() {
    int N;
    if (scanf("%d", &N) != 1) {
        printf("n/a\n");
        return 0;
    } else {
        if (N < 0) {
            printf("n/a\n");
            return 0;
        } else {
            printf("%d", fib(N));
            return 0;
        }
    }
}

int fib(int N) {
    if (N == 0 || N == 1) {
        return N;
    } else {
        return fib(N - 1) + fib(N - 2);
    }
}
