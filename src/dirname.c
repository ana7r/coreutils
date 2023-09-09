/*
 * copyright 2023 Mohamed Abdelhamed
 */

#include <libgen.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "%s: missing operand\n", argv[0]);
    return 1;
  }

  char *c = dirname(argv[1]);
  fprintf(stdout, "%s\n", c);
  return 0;
}
