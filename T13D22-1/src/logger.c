#include "logger.h"

#include <stdlib.h>
#include <time.h>

static FILE *log_file = NULL;

void log_init(const char *filename) {
    log_file = fopen(filename, "a");
    if (log_file == NULL) {
        perror("Could not open log file");
    }
}

void logcat(LogLevel level, const char *message) {
    if (log_file == NULL) {
        return;
    }

    const char *level_strings[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    char time_buffer[26];
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_info);

    fprintf(log_file, "[%s] [%s] %s\n", time_buffer, level_strings[level], message);
    fflush(log_file);
}

void log_close() {
    if (log_file != NULL) {
        fclose(log_file);
        log_file = NULL;
    }
}
