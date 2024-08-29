#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>
#define s21_NULL ((void *)0)

int s21_strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int s21_strcmp(const char *str_first, const char *str_two) {
    while (*str_first && (*str_first == *str_two)) {
        str_first++;
        str_two++;
    }
    return *str_first - *str_two;
}

char *s21_strcpy(char *ctrlc, const char *src_copy) {
    char *original = ctrlc;
    while ((*ctrlc++ = *src_copy++) != '\0') continue;
    return original;
}

char *s21_strcat(char *ctrlc, const char *src_cat) {
    int length = 0;
    while (*ctrlc) {
        ctrlc++;
        length++;
    }
    while (*src_cat) {
        *ctrlc = *src_cat;
        ctrlc++;
        src_cat++;
        length++;
    }
    *ctrlc = '\0';
    ctrlc -= length;
    return ctrlc;
}

char *s21_strchr(const char *str_chr, int number) {
    char *result = s21_NULL;
    while (*str_chr++) {
        if (*str_chr == number) {
            result = (char *)str_chr;
            break;
        }
    }
    return result;
}

int s21_strstr(const char *stack, const char *need) {
    int pos;
    int error = 0;
    char *need_stack = (char *)stack;
    if (s21_strlen(need) == 0) {
        pos = -1;
    } else {
        for (int i = 0; i < (int)s21_strlen(need_stack); i++) {
            if (need_stack[i] == need[0]) {
                pos = i;
                for (int j = i, k = 0; j < (int)s21_strlen(need) + i; j++, k++) {
                    if (need_stack[j] != need[k]) {
                        error = 1;
                    }
                }
                if (error == 0) {
                    break;
                } else {
                    pos = -1;
                    error = 0;
                    continue;
                }
            }
        }
    }
    return pos;
}


char *s21_strtok(char *str_tok, const char *split) {
    static char *last;
    register int ch;

    if (str_tok == 0) {
        str_tok = last;
    }
    do {
    if ((ch = *str_tok++) == '\0') {
    return 0;
    }
    } while (s21_strchr(split, ch));
    --str_tok;
    last = str_tok + s21_strcspn(str_tok, split);
    if (*last != 0) {
        *last++ = 0;
    }
    return str;
}
