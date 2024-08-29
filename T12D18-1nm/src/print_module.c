#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    time_t now;
    struct tm* local;
    char time_str[9];
    // Получение текущего времени
    time(&now);
    local = localtime(&now);
    // Форматирование времени в строку
    strftime(time_str, sizeof(time_str), "%H:%M:%S", local);
    // Вывод формата логов
    for (int i = 0; Log_prefix[i] != '\0'; i++) {
        print(Log_prefix[i]);
    }
    print(' ');  // Разделитель
    for (int i = 0; time_str[i] != '\0'; i++) {
        print(time_str[i]);
    }
    print(' ');  // Разделитель
    for (int j = 0; message[j] != '\0'; j++) {
        print(message[j]);
    }  // Завершение строки
}