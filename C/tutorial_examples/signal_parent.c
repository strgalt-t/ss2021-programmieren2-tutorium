#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

// child process loop
void worker_child() {
        printf("\t Child Process!\n");
        while (1) {
            sleep(10);
        };
}

// handler function: if SIGUSR1 received,quit
static void handler(int signr) {
    printf("\tSIGUSR1 received. Quitting!\n");
    exit(EXIT_SUCCESS);
}

int main() {
    pid_t pid;

    struct sigaction sa;

    sigemptyset(&sa.sa_mask);

    sa.sa_flags = 0;
    sa.sa_handler = handler;

    if (sigaction(SIGUSR1, &sa, NULL) < 0 ) {
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
        // parent process
        printf("Parent task\n");
        sleep(1);
        kill(pid, SIGUSR1);
        printf("Signal send!\n");
        sleep(2);
        printf("Quit parent process!\n");
    }

    return EXIT_SUCCESS;
}