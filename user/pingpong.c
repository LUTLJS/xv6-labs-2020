#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main () {
	char e[] = "a", buffer[1];
	int fd1[2], fd2[2];

	if(pipe(fd1) == -1) {
		exit(1);
	}	
	if(pipe(fd2) == -1) {
		exit(1);
	}

	int p = fork();
	
	if(p < 0) {
		exit(1);
	} else if(p > 0) {
		close(fd1[0]);
		write(fd1[1], e, 1);
		close(fd1[1]);
		
		wait(0);

		close(fd2[1]);
		read(fd2[0], buffer, 1);
		close(fd2[0]);

		int pid = getpid();
		printf("%d: received pong\n", pid);

		exit(0);
	} else {
		close(fd1[1]);
		read(fd1[0], buffer, 1);
		close(fd1[0]);

		int pid = getpid();
		printf("%d: received ping\n", pid);

		close(fd2[0]);
		write(fd2[1], buffer, 1);
		close(fd2[1]);

		exit(0);
	}
}
