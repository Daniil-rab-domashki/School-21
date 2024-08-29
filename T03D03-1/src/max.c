#include <stdio.h>
void max(int a, int b);
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a != (int)a || b != (int)a) {
        printf("n/a\n");
        return 0;
    }
    max(a, b);
    return 0;
}
void max(int a, int b) {
    if (a > b) {
        printf("%d\n", a);
    } else {
        printf("%d\n", b);
    }
}
