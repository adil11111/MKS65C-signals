#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


void errHand(){
  printf("There was an error:%s\n", strerror(errno));
}

void handle(){
  int fd;
  fd = open("exit.txt", O_WRONLY | O_APPEND| O_CREAT,0644);
  if(fd < 0){
    errHand();
  }
  write(fd,"Program exited due to SIGINT\n",29);
  close(fd);
}

static void signalhandler(int signo){
  if(signo == SIGUSR1){
    printf("Parent ID:%d\n",getppid());
  }
  if(signo == SIGINT){
    handle();
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
