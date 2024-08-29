#include <math.h>
#include <stdio.h>
void mathema(float x);
int main() {
    float x;
    scanf("%f", &x);
    if (x != (float)x || x == 0) {
        printf("n/a\n");
        return 0;
    }
    mathema(x);
    return 0;
}
void mathema(float x) {
    float y = (7e-3 * pow(x, 4) + ((22.8 * pow(x, 1 / 3) - 1e3) * x + 3) / (x * x / 2) -
               x * pow((10 + x), (2 / x)) - 1.01);
    printf("%.1f\n", y);
}
