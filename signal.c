#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void signalhandler(int signo){
	if(signo == SIGUSR1){
		printf("Parent ID:%d\n",getppid());
	}
  if(signo == SIGINT){
    printf("Hey\n");
    exit(0);
  }
}
int main(){
	signal(SIGUSR1,signalhandler);
  signal(SIGINT,signalhandler);
	while(1){
		printf("%d\n",getpid());
		sleep(1);
	}
	return 0;
}
