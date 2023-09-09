/*
 * copyright 2023 Mohamed Abdelhamed
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINK_SIZE 4096

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "%s: missing operand\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *path = NULL;
  char buf[MAX_LINK_SIZE];

  for (int i = 1; i < argc; i++) {
    path = argv[i];
    if (readlink(path, buf, sizeof(buf)) < 0) {
      return EXIT_FAILURE;
    }
    fprintf(stdout, "%s\n", buf);
  }
  return EXIT_SUCCESS;
}
