#include <math.h>
#include <stdio.h>
double An(double y1);
double Be(double y2);
double Kv(double y3);

int main() {
    FILE *f = fopen("./data/door_data.txt", "w");

    double Pi = -3.1415927;
    double x, step = Pi * 2 / 41;
    for (int i = 0; i < 42; i++) {
        x = -Pi + i * step;
        An(x);
        Be(x);
        Kv(x);
        if (isnan(Be(x))) {
            fprintf(f, "%.7lf | %.7lf | - | %.7lf\n", x, An(x), Kv(x));
        } else {
            Be(x);
            fprintf(f, "%.7lf | %.7lf | %.7lf | %.7lf\n", x, An(x), Be(x), Kv(x));
        }
    }
    return 0;
}

double An(double y1) {
    y1 = pow(1, 3) / (pow(1, 2) + pow(y1, 2));
    return y1;
}

double Be(double y2) {
    y2 = sqrt(sqrt(pow(1, 4) + 4 * pow(y2, 2) * pow(1, 2)) - pow(y2, 2) - pow(1, 2));
    return y2;
}

double Kv(double y3) {
    y3 = 1 / pow(y3, 2);
    return y3;
}
