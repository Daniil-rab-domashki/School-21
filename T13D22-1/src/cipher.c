#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"

void read(const char *file_path);
void write(const char *file_path);
void caesar_cipher(const char *directory, int shift);
void clear_header_files(const char *directory);

char file_path[256];

int main() {
    int operation;
    while (1) {
        scanf("%d", &operation);
        getchar();
        if (operation == -1) {
            logcat(LOG_INFO, "Program terminated.");
            break;
        }
        switch (operation) {
            case 1:
                scanf("%s", file_path);
                read(file_path);
                logcat(LOG_INFO, "Operation 1 executed.");
                break;
            case 2:
                write(file_path);
                logcat(LOG_INFO, "Operation 2 executed.");
                break;
            case 3: {
                char directory[256];
                int shift;
                scanf("%s", directory);
                scanf("%d", &shift);
                caesar_cipher(directory, shift);
                clear_header_files(directory);
                break;
            }
            case 4: {
                char directory[256];
                int shift;

                printf("Enter directory path: ");
                scanf("%s", directory);
                printf("Enter shift value for Caesar cipher: ");
                scanf("%d", &shift);
                caesar_cipher(directory, shift);
                clear_header_files(directory);
                break;
            }
            default:
                logcat(LOG_ERROR, "Invalid operation.");
                printf("Invalid operation\n");
        }
    }
    log_close();
    return 0;
}

void read(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("n/a\n");
        return;
    }
    if (fgetc(file) == EOF) {
        printf("n/a\n");
        return;
    }
    rewind(file);
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void write(const char *file_path) {
    if (file_path[0] == '\0') {
        printf("n/a\n");
        return;
    }
    FILE *file = fopen(file_path, "a");
    if (file == NULL) {
        printf("n/a\n");
        return;
    }
    char input[256];
    scanf(" %[^\n]", input);
    if (strcmp(input, "-1") == 0) {
        fclose(file);
        return;
    }
    fprintf(file, "%s\n", input);
    fclose(file);
    read(file_path);
}

void caesar_cipher(const char *directory, int shift) {
    DIR *dir = opendir(directory);
    struct dirent *entry;

    if (!dir) {
        printf("n/a\n");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".c") != NULL) {
            char file_path[512];
            snprintf(file_path, sizeof(file_path), "%s/%s", directory, entry->d_name);
            FILE *file = fopen(file_path, "r+");
            if (file) {
                char ch;
                while ((ch = fgetc(file)) != EOF) {
                    if (ch >= 'a' && ch <= 'z') {
                        ch = ((ch - 'a' + shift) % 26) + 'a';
                    } else if (ch >= 'A' && ch <= 'Z') {
                        ch = ((ch - 'A' + shift) % 26) + 'A';
                    }
                    fseek(file, -1, SEEK_CUR);
                    fputc(ch, file);
                }
                fclose(file);
            }
        }
    }
    closedir(dir);
}

void clear_header_files(const char *directory) {
    DIR *dir = opendir(directory);
    struct dirent *entry;

    if (!dir) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".h") != NULL) {
            char file_path[512];
            snprintf(file_path, sizeof(file_path), "%s/%s", directory, entry->d_name);
            remove(file_path);
        }
    }
    closedir(dir);
}
