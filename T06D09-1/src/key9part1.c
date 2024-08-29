#include <stdio.h>
#define NMAX 10
int input(int *buffer, int *length);
void output(int sum, int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int length = 0, buffer[NMAX], numbers[NMAX], sum = 0, chislo = 0;
    if (input(buffer, &length) == 1) {
        sum = sum_numbers(buffer, length);
        chislo = find_numbers(buffer, length, sum, numbers);
        output(sum, numbers, chislo);

    } else {
        printf("n/a");
        return 0;
    }

    return 0;
}

int input(int *buffer, int *length) {
    char ch;
    int flags = 1;
    if ((scanf("%d%c", length, &ch)) == 2 && *length <= NMAX && *length > 0 && ch == '\n') {
        for (int i = 0; i < *length; i++) {
            scanf("%d%c", &buffer[i], &ch);
            if (i < *length - 1) {
                if (ch != ' ') {
                    flags = 0;
                    return flags;
                }
            } else if (ch != '\n') {
                flags = 0;
                return flags;
            }
        }
    } else {
        flags = 0;
        return flags;
    }
    return flags;
}

void output(int sum, int *buffer, int length) {
    printf("%d\n", sum);
    for (int i = 0; i < length; i++) {
        printf("%d ", buffer[i]);
    }
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count] = buffer[i];
            count += 1;
        }
    }
    return count;
}
