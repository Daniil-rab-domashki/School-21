#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

typedef enum { LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR } LogLevel;

void log_init(const char *filename);
void logcat(LogLevel level, const char *message);
void log_close();

#endif
