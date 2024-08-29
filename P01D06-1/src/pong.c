#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    initscr();
    timeout(0);
    clear();
    fflush(stdout);
    int winner = 0;
    int bally = 13;
    int ballx = 39;
    int mvx = 1;
    int mvy = 1;
    int pl_1 = 10;  // начальное положение ракетки
    int pl_2 = 10;
    int pl_1_point = 0;  // колличество очков
    int pl_2_point = 0;
    do {  //играем до 21
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 80; j++) {
                // boll
                if (i == bally && j == ballx) {
                    printw("*");

                } else if (j == 39) {
                    printw("|");
                } else {
                    printw(" ");
                }
                // rocket
                if ((i == pl_1 || i == pl_1 + 1 || i == pl_1 + 2) && j == 1) {
                    printw("]");
                    j += 1;
                }
                if ((i == pl_2 || i == pl_2 + 1 || i == pl_2 + 2) && j == 77) {
                    printw("[");
                    j += 1;
                }
            }
            printw("\n");
        }
        printw("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        ballx = ballx + mvx;
        bally = bally + mvy;
        //отскок от ракеток
        if ((ballx == 3 && (bally == pl_1 || bally == pl_1 + 1 || bally == pl_1 + 2)) ||
            (ballx == 77 && (bally == pl_2 || bally == pl_2 + 1 || bally == pl_2 + 2))) {
            mvx = -mvx;
        }
        //отскок от стен
        if (bally == 0 || bally == 24) {
            mvy = -mvy;
        }
        //начисление очков
        if (ballx <= 0) {
            ballx = 39;
            mvx = -mvx;  //смена направление при голе
            pl_2_point += 1;
        } else if (ballx >= 78) {
            ballx = 39;
            mvx = -mvx;  //смена направление при голе
            pl_1_point += 1;
        }
        printw("                          PL1 : %02d     vs     PL2 : %02d \n", pl_1_point,
               pl_2_point);  //вывод счетчика

        // rocket move

        switch (char bind = getch()) {
            case 'a':
                ((pl_1) != 0) ? (pl_1 -= 1) : pl_1;
                break;
            case 'z':
                ((pl_1) != 25 - 3) ? (pl_1 += 1) : pl_1;
                break;
            case 'k':
                ((pl_2) != 0) ? (pl_2 -= 1) : pl_2;
                break;
            case 'm':
                ((pl_2) != 25 - 3) ? (pl_2 += 1) : pl_2;
                break;
            case 'A':
                ((pl_1) != 0) ? (pl_1 -= 1) : pl_1;
                break;
            case 'Z':
                ((pl_1) != 25 - 3) ? (pl_1 += 1) : pl_1;
                break;
            case 'K':
                ((pl_2) != 0) ? (pl_2 -= 1) : pl_2;
                break;
            case 'M':
                ((pl_2) != 25 - 3) ? (pl_2 += 1) : pl_2;
                break;
        }

        refresh();
        usleep(50000);
        //счетчик

        if (pl_1_point == 21) {
            winner = 1;
        } else {
            winner = 2;
        }
        clear();
        fflush(stdout);
    } while (pl_1_point < 21 && pl_2_point < 21);
    clear();
    fflush(stdout);
    printf("Поздравляю %d игрок!", winner);
    endwin();
    return 0;
}

