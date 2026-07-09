#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define LOG_FILE "audit.log"
#define BUFFER_SIZE 4096

void add_entry(const char *message) {
    int fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        write(STDERR_FILENO, "Error: Cannot open log file\n", 28);
        exit(1);
    }
    
    write(fd, message, strlen(message));
    write(fd, "\n", 1);
    close(fd);
}

void view_log() {
    int fd = open(LOG_FILE, O_RDONLY);
    if (fd == -1) {
        write(STDERR_FILENO, "Error: Cannot open log file\n", 28);
        exit(1);
    }
    
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    int line_num = 1;
    int start = 0;
    int i;
    
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        for (i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\n') {
                char line[BUFFER_SIZE];
                int len = i - start;
                if (len > 0) {
                    memcpy(line, buffer + start, len);
                    line[len] = '\0';
                    char output[BUFFER_SIZE];
                    int n = snprintf(output, sizeof(output), "%d: %s\n", line_num++, line);
                    write(STDOUT_FILENO, output, n);
                }
                start = i + 1;
            }
        }
        
        if (start < bytes_read) {
            memmove(buffer, buffer + start, bytes_read - start);
            bytes_read -= start;
            start = 0;
        }
    }
    
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        write(STDERR_FILENO, "Usage: ./auditlog --add \"message\" or ./auditlog --view\n", 54);
        return 1;
    }
    
    if (strcmp(argv[1], "--add") == 0) {
        if (argc < 3) {
            write(STDERR_FILENO, "Error: Missing message for --add\n", 33);
            return 1;
        }
        add_entry(argv[2]);
    } else if (strcmp(argv[1], "--view") == 0) {
        view_log();
    } else {
        write(STDERR_FILENO, "Error: Unknown command. Use --add or --view\n", 43);
        return 1;
    }
    
    return 0;
}
