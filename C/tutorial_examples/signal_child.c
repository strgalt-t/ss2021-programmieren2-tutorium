#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

// function child process
void worker_child() {
        printf("\t Child Process!\n");
        sleep(2);
        printf("\t I'm terminating! \n");
}

// handler function
static void handler(int signr) {
    printf("Child signal received, it's safe to quit now!\n");
    exit(EXIT_SUCCESS);
}

int main() {
    pid_t pid;

    struct sigaction sa;

    sigemptyset(&sa.sa_mask);

    sa.sa_flags = 0;
    sa.sa_handler = handler;

    if (sigaction(SIGCHLD, &sa, NULL) < 0 ) {
        printf("Error: sigaction() \n");
        return EXIT_FAILURE;
    }

    switch (pid = fork()) {
        case -1:
            printf("Error: failed fork()\n");
            exit(EXIT_FAILURE);
            break;
        case 0:
            // child process
            worker_child();
            break;
        default:
            while (1) {
                printf("I'm working\n");
                sleep(10);
            }
    }

    return EXIT_SUCCESS;
}