#ifndef STRING
#define STRING
#define s21_NULL ((void *)0)

int s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *dest, const char *src);
char *s21_strcat(char *dest, const char *src);
char *s21_strchr(const char *str, int c);
int s21_strstr(const char *haystack, const char *needle);

#endif
