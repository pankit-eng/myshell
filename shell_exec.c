#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>


char  **get_input(char input[]) {
	char **args = malloc(sizeof(char*)*8);
	int id = 0;
	const char *sep = " ";
	char *cmd = strtok(input, sep);
	args[id++] = cmd;
    while(cmd) {
		cmd = strtok(NULL, sep);
		args[id++] = cmd;
	}
	args[id] = NULL;
    return args;
}


int main() {
	do {
        char* buf = readline("mysh>");

		if (!strcmp(buf, "quit")) {
			break;
		}

		char **args = get_input(buf);
		
		int pid = fork();
		
		if (pid==0) {
			execvp(args[0], args);
			printf("Error occured");
			break;
		} else {	
			int status;
			waitpid(-1, &status, 0);
			if(status) {
				printf("Child returned with status %d", status);
			}
		}
	} while(1);
}
