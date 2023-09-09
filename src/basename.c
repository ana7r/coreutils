/*
 * Copyright 2023 Mohamed Abdelhamed
 */

#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_suffix(char *name, char *suffix) {
  // basename.cpp
  //            ^
  //         ^
  char *np = name + strlen(name);
  char *sp = np - strlen(suffix);

  char *sp_new = strstr(sp, suffix);
  if (sp_new)
    *sp_new = '\0';
}

void usage(int argc, char *argv[]) {
  fprintf(stdout, "Usage: %s NAME [SUFFIX]\n", argv[0]);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "%s: missing operand\n", argv[0]);
    fprintf(stderr, "Try '%s --help' for more information.\n", argv[0]);
    return EXIT_FAILURE;
  }

  if (strcmp("--help", argv[1]) == 0) {
    usage(argc, argv);
    return EXIT_SUCCESS;
  }

  char *c = basename(argv[1]);
  if (argc > 2)
    remove_suffix(c, argv[2]);

  fprintf(stdout, "%s\n", c);
  return EXIT_SUCCESS;
}
