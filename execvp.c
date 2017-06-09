# include <stdlib.h>
# include <unistd.h>

int main() {
	char *argv[] = {"ls",  NULL};
	execvp(argv[0], argv);
}
