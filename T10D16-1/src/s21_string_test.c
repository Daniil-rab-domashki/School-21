#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();

int main() {
#ifdef Quest_1
    s21_strlen_test();
#endif
#ifdef Quest_2
    s21_strcmp_test();
#endif
#ifdef Quest_3
    s21_strcpy_test();
#endif
#ifdef Quest_4
    s21_strcat_test();
#endif
#ifdef Quest_5
    s21_strchr_test();
#endif
#ifdef Quest_6
    s21_strstr_test();
#endif
    return 0;
}

void s21_strlen_test() {
    char me_str1[] = "abcdif";
    int n = 6;
    int result = s21_strlen(me_str1);
    printf("%s\n", me_str1);
    printf("%d\n", result);
    if (n == result) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    char me_str2[] = "leobalam";
    n = 8;
    result = s21_strlen(me_str2);
    printf("%s\n", me_str2);
    printf("%d\n", result);
    if (n == result) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    char me_str3[] = "fsfpekwofvopsd";
    n = 13;
    result = s21_strlen(me_str3);
    printf("%s\n", me_str3);
    printf("%d\n", result);
    if (n == result) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcmp_test() {
    char arr_test1[] = "kovorking";
    char arr_test2[] = "kovorking";
    int result = s21_strcmp(arr_test1, arr_test2);
    printf("%s\n", arr_test1);
    printf("%s\n", arr_test2);
    if (result == 0) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    char arr_test3[] = "123456";
    char arr_test4[] = "654321";
    result = s21_strcmp(arr_test3, arr_test4);
    printf("%s\n", arr_test3);
    printf("%s\n", arr_test4);
    if (result == 0) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    char arr_test5[] = "AIROFLOT";
    char arr_test6[] = "airoflot";
    result = s21_strcmp(arr_test5, arr_test6);
    printf("%s\n", arr_test5);
    printf("%s\n", arr_test6);
    if (result == 0) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcpy_test() {
    char giga_arr1[s21_strlen("123")];
    s21_strcpy(giga_arr1, "123");
    printf("123\n");
    printf("%s\n", giga_arr1);
    if (s21_strcmp(giga_arr1, "123") == 0) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    char giga_arr2[s21_strlen("124452141")];
    s21_strcpy(giga_arr2, "1221423523");
    printf("124452141\n");
    printf("%s\n", giga_arr2);
    if (s21_strcmp(giga_arr2, "124452141") == 0) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    char giga_arr3[s21_strlen("olivki")];
    s21_strcpy(giga_arr3, " olivki");
    printf("olivki\n");
    printf("%s\n", giga_arr3);
    if (s21_strcmp(giga_arr3, "olivki") == 0) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcat_test() {
    char arr_t1[] = "123";
    char arr_t2[] = "456";
    char *result1 = s21_strcat(arr_t1, arr_t2);
    printf("123 456\n");
    printf("%s\n", result1);
    if (s21_strcmp(result1, "123456") == 0) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    char arr_t3[] = "21";
    char arr_t4[] = "school";
    char *result2 = s21_strcat(arr_t3, arr_t4);
    printf("21 school\n");
    printf("%s\n", result2);
    if (s21_strcmp(result2, "21school") == 0) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    char arr_t5[] = "wild";
    char arr_t6[] = "berries";
    char *result3 = s21_strcat(arr_t5, arr_t6);
    printf("wild berries\n");
    printf("%s\n", result3);
    if (s21_strcmp(result3, "wildberries") == 0) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strchr_test() {
    char arr_t1_ch[] = "123456";
    char *result1 = s21_strchr(arr_t1_ch, '2');
    printf("123456\n");
    printf("%s\n", result1);
    if (*result1 == arr_t1_ch[1]) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    char arr_t2_ch[] = "AbVgDeEjZ";
    char *result2 = s21_strchr(arr_t2_ch, 'Z');
    printf("AbVgDeEjZ\n");
    printf("%s\n", result2);
    if (*result2 == arr_t2_ch[8]) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    char arr_t3_ch[] = "qwerty";
    char *result3 = s21_strchr(arr_t3_ch, 'e');
    printf("qwerty\n");
    printf("%s\n", result3);
    if (*result3 == arr_t3_ch[2]) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strstr_test() {
    char array_t1[] =
        "Я вас любил: любовь еще, быть может,\n"
        "В душе моей угасла не совсем\n"
        "Но пусть она вас больше не тревожит\n"
        "Я не хочу печалить вас ничем.\n"
        "Я вас любил безмолвно, безнадежно,\n"
        "То робостью, то ревностью томим\n"
        "Я вас любил так искренно, так нежно,\n"
        "Как дай вам Бог любимой быть другим.\n";
    char array_t2[] = "В душе моей угасла не совсем";
    int result_t1 = s21_strstr(array_t1, array_t2);
    printf("%s\n", array_t1);
    printf("В душе моей угасла не совсем\n");
    if (result_t1 == 64) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    char array_t3[] =
        "Сижу за решеткой в темнице сырой.\n"
        "Вскормленный в неволе орел молодой,\n"
        "Мой грустный товарищ, махая крылом,\n"
        "Кровавую пищу клюет под окном,\n"
        "Клюет, и бросает, и смотрит в окно,\n"
        "Как будто со мною задумал одно.\n"
        "Зовет меня взглядом и криком своим\n"
        "И вымолвить хочет: «Давай улетим!\n"
        "Мы вольные птицы; пора, брат, пора!\n"
        "Туда, где за тучей белеет гора,\n"
        "Туда, где синеют морские края,\n"
        "Туда, где гуляем лишь ветер… да я!..»\n";
    char array_t4[] = "И вымолвить хочет: «Давай улетим!\n";
    int result_t2 = s21_strstr(array_t3, array_t4);
    printf("%s\n", array_t3);
    printf("И вымолвить хочет: «Давай улетим!\n");
    if (result_t2 == 431) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    char array_t6[] =
        "Ночь, улица, фонарь, аптека,\n"
        "Бессмысленный и тусклый свет.\n"
        "Живи еще хоть четверть века —\n"
        "Всё будет так. Исхода нет.\n"
        "Умрёшь — начнёшь опять сначала\n"
        "повторится всё, как встарь:\n"
        "Ночь, ледяная рябь канала,\n"
        "Аптека, улица, фонарь.\n";
    char array_t7[] = "Всё будет так. Исхода нет.\n";
    int result_t3 = s21_strstr(array_t6, array_t7);
    printf("%s\n", array_t6);
    printf("Всё будет так.\n");
    if (result_t3 == 159) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }
}
