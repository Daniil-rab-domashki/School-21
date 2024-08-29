#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define row 25
#define col 80

void fill_matrix(int matrix[row][col]);
void check_live(int matrix_temp[row][col], int matrix[row][col]);
int count_live(int matrix[row][col], int r, int c);
void print_matrix(int matrix[row][col]);
int change_speed(char speed, int *flag, int time);
void update_matrix(int matrix[row][col], int matrix_temp[row][col], int matrix_prev[row][col]);
int check_end(int matrix_temp[row][col], int matrix_prev[row][col]);

int main() {
    int matrix[row][col], matrix_temp[row][col], matrix_prev[row][col];
    int time = 300;
    int exit_1 = 0;
    fill_matrix(matrix);
    if (freopen("/dev/tty", "r", stdin)) initscr();
    nodelay(stdscr, true);
    while (exit_1 != 1) {
        char speed = getch();
        time = change_speed(speed, &exit_1, time);
        usleep(time * 1000);
        clear();
        check_live(matrix_temp, matrix);
        if (check_end(matrix_temp, matrix_prev)) {
            exit_1 = 1;
        }
        update_matrix(matrix, matrix_temp, matrix_prev);
        print_matrix(matrix);
    }
    endwin();
    printf("Конец игры.\n");
    return 0;
}

int check_end(int matrix_temp[row][col], int matrix_prev[row][col]) {
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix_temp[i][j] == matrix_prev[i][j]) count++;
        }
    }
    if (count == 2000)
        return 1;
    else
        return 0;
}

void update_matrix(int matrix[row][col], int matrix_temp[row][col], int matrix_prev[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix_prev[i][j] = matrix[i][j];
            matrix[i][j] = matrix_temp[i][j];
        }
    }
}

void fill_matrix(int matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void check_live(int matrix_temp[row][col], int matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int neighbour_live_amount = count_live(matrix, i, j);
            if (matrix[i][j] == 1 && (neighbour_live_amount == 2 || neighbour_live_amount == 3)) {
                matrix_temp[i][j] = 1;
            }

            else if (matrix[i][j] == 0 && neighbour_live_amount == 3) {
                matrix_temp[i][j] = 1;
            }

            else {
                matrix_temp[i][j] = 0;
            }
        }
    }
}

int count_live(int matrix[row][col], int r, int c) {
    int i, j, i1, j2, count = 0;
    for (i = r - 1; i <= r + 1; i++) {
        for (j = c - 1; j <= c + 1; j++) {
            int tp1 = 0, tp2 = 0;
            if ((i == r && j == c)) {
                continue;
            }
            if (i < 0) {
                tp1 = 1;
                i1 = row - 1;
            }
            if (i >= row) {
                tp1 = 1;
                i1 = 0;
            }
            if (j < 0) {
                tp2 = 1;
                j2 = col - 1;
            }
            if (j >= col) {
                tp2 = 1;
                j2 = 0;
            }
            if (tp1 == 1 && tp2 == 0) {
                if (matrix[i1][j] == 1) {
                    count++;
                }
            }
            if (tp1 == 1 && tp2 == 1) {
                if (matrix[i1][j2] == 1) {
                    count++;
                }
            }
            if (tp1 == 0 && tp2 == 1) {
                if (matrix[i][j2] == 1) {
                    count++;
                }
            }
            if (tp1 == 0 && tp2 == 0) {
                if (matrix[i][j] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

int change_speed(char speed, int *flag, int time) {
    if (speed == '1')
        time = 900;
    else if (speed == '2')
        time = 300;
    else if (speed == '3')
        time = 70;
    else if (speed == 'q')
        *flag = 1;

    return time;
}

void print_matrix(int matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j != (col - 1)) {
                printw("%d ", matrix[i][j]);
            } else {
                if (i != (row - 1)) {
                    printw("%d\n", matrix[i][j]);
                } else {
                    printw("%d", matrix[i][j]);
                }
            }
        }
    }
}
