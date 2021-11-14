#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char ** parse_args( char * line ) {
  char ** args = malloc(10 * sizeof(char));
  char * curr = line;

  int count = 0;
  while (curr) {
    char * token = strsep(&curr, " ");
    args[count] = token;
    count++;
  }
  
  return args;
}

int main(int argc, char **argv) {
    if (argc > 1) {
        char **args = parse_args(argv[1]);
        execvp(args[0], args);
    }
}
