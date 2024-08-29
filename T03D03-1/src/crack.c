#include <math.h>
#include <stdio.h>

void mathema(float x);
int main() {
    float x, y;
    scanf("%f%f", &x, &y);
    if (x != (float)x || y != (float)y) {
        printf("n/a\n");
        return 0;
    }
    if (pow(x, 2) + pow(y, 2) <= 25) {
        printf("GOTCHA");
        return 0;
    } else {
        printf("MISS");
        return 0;
    }
}
