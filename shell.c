#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int pid_t = fork();
	if (pid_t == 0) {
		sleep(5);
		printf("Child process: %d:%d\n", getpid(), getpgid(getpid()));
	} else {
		int status;
		waitpid(-1, &status, 0);
		printf("Parent process: %d:%d\n", getpid(), getpgid(getpid()));
		printf("Child process status: %d\n", status);
	}
}
