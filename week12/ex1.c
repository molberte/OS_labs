#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  FILE *file_in;
  FILE *file_out;

  file_in = fopen("/dev/random", "r");
  file_out = fopen("ex1.txt", "w");
  char *file_temp;
  file_temp = (char *) malloc(sizeof(char));
  char *str = fgets(file_temp, 20, file_in);
  fprintf(file_out, str);
  fclose(file_out);
  return 0;
};
