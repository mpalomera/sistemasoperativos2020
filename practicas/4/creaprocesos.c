#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void signalHandler(int signum) {
  int status;
  wait(&status);
  printf("Mi hijo termino con status %d",status);
}

void controlC(int singnum){

}


int main(int argc, char **argv) {
  signal(17, signalHandler);
  signal(2,controlC);
  unsigned pid = fork();
  if (pid == 0) {
      sleep(5);
    printf("Soy el proceso hijo\n");
    // execv(argv[1],&argv[1]);
    return 1;
  } else {
    printf("Soy el proceso padre y mi hijo es %u\n", pid);
    while (1) {
      sleep(2);
      printf("trabajando \n");
    }
  }
  printf("Hola mundo \n");
  return 0;
}