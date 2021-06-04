#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// function that the handler invokes when a stated signal arrives
// remember: only 1 argument allowed and that has to be the signal number
static void handler_1(int sig) {
    switch (sig) {
        case SIGHUP:
            printf("Received SIGHUP \n");
            break;

        case SIGUSR1:
            printf("Received SIGUSR1\n");
            break;

        default:
            break;
    }
}


int main() {
    // current pid -> used for testing purposes (kill -s SIGNAL PID)
    printf("\t current pid = %i\n", getpid());

    struct sigaction sa, sa2;
    
    // empty mask
    sigemptyset(&sa.sa_mask);

    // Haven't used flags -> ignore
    sa.sa_flags = 0;
    sa2.sa_flags = 0;

    // sa2 ignores incoming signals
    sa2.sa_handler = SIG_IGN;
    // sa calls the handler_1 function
    sa.sa_handler = handler_1;

    //"activate"
    if ((sigaction(SIGHUP, &sa, NULL) < 0) || (sigaction(SIGUSR1, &sa, NULL) < 0)) {
        printf("Error: sigaction func!\n");
        return EXIT_FAILURE;
    } 

    if (sigaction(SIGINT, &sa2, NULL) < 0) {
        printf("Error: sigaction func 2!\n");
        return EXIT_FAILURE;
    }

    // eternal loop
    while (1) {
        printf("Hello World! \n");
        sleep(5);
    }

    return EXIT_SUCCESS;
}