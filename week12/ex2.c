#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s[2] = "w";
    char *buff;
    unsigned int len;

    getline(&buff, &len, stdin);
    puts(buff);

    printf("%s", buff);

    if (argc < 2){
      printf("No arguments found");
      return 0;
    }

    if (strncmp(argv[1], "-a", 2) == 0){
        strcpy(s, "a");
    }

    for(int i=2; i<argc; i++){
        FILE *file;
        file = fopen(argv[i], s);
        fprintf(file, "%s", buff);
    }
    return 0;
}
