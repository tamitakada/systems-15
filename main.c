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
  char line[100] = "1 2 string other";
  char **args = parse_args(line);
  int i;
  for (i = 0; i < 4; i++) {
    printf("%s\n", args[i]);
  }
}
