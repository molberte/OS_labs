#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){
  int n = fork();
  if (n == 0) {
    printf("Hello from child [%d - %d]\n", getpid(), n);
  }
  else {
    printf("Hello from parent [%d - %d]\n", getpid(), n);
  }
  return 0;
}