#include <stdio.h>

int main() {
    int a, b, sum, dif, work, private;
    scanf("%d %d", &a, &b);
    if (a != (int)a || b != (int)a) {
        printf("n/a\n");
        return 0;
    }
    sum = a + b;
    dif = a - b;
    work = a * b;
    printf("%d ", sum);
    printf("%d ", dif);
    printf("%d ", work);

    if (b == 0) {
        printf("n/a\n");
    } else {
        private = a / b;
        printf("%d\n", private);
    }
    return 0;
}

/*

void sum(int a, int b)
void dif(int a, int b)
void work(int a, int b)
void private(int a, int b)

int main() {
    int num1, num2
    scanf("%d%d", &num1, &num2);
    sum(num1, num2);
    dif(num1, num2);
    work(num1, num2);
    private(num1, num2);
    return 0;
}

void sum(int a, int b) {
    printf("%d", a+b);
}

void dif(int a, int b) {
    printf (%d, a-b);
}

void work(int a, int b) {
    printf (%d, a*b);
}

void private(int a, int b) {
    printf (%d, a/b);
}
*/
