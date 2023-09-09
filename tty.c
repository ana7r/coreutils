/*
 * copyright 2023 Mohamed Abdelhamed
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (isatty(STDIN_FILENO) == 0) {
    fprintf(stderr, "not a tty\n");
    return 1;
  }
  fprintf(stdout, "%s\n", ttyname(STDIN_FILENO));
  return 0;
}
