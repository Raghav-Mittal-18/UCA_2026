#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Global variable to count signal triggers
volatile sig_atomic_t signal_count = 0;

// Signal handler for Ctrl+C (SIGINT)
void handle_sigint(int sig) {
    signal_count++;

    if (signal_count < 3) {
        printf("\nCtrl+C caught! Press Ctrl+C %d more time(s) to exit.\n",
               3 - signal_count);
        fflush(stdout);
    } else {
        printf("\nCtrl+C pressed 3 times. Exiting...\n");
        fflush(stdout);
        exit(0);
    }
}

int main() {
    // Register the signal handler
    struct sigaction sa;

    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Program running (PID: %d). Try pressing Ctrl+C...\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}

