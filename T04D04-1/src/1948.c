#include <math.h>
#include <stdio.h>
int maxprime(int num);
int prime(int n);

int main() {
    int a;
    char pr;

    if (((scanf("%d%c", &a, &pr) != 1) && (pr != '\n')) || (a == 0) || (a == 1)) {
        printf("n/a\n");
        return 0;
    }
    if (a < 0) {
        a = -a;
    }
    int res = maxprime(a);
    if (res != -1) {
        printf("%d", res);
    }
    return 0;
}

int prime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= (n * 0.5); i++) {
        int value = n;
        while (value >= i) {
            value = value - i;
        }
        if (value == 0) {
            return 0;
        }
    }
    return 1;
}

int maxprime(int num) {
    int max = -1;
    for (int i = 2; i <= num; i++) {
        int value = num;
        while (value >= i) {
            value = value - i;
        }
        if (value == 0 && prime(i)) {
            max = i;
        }
    }
    return max;
}
