/*
 * Copyright 2023 Mohamed Abdelhamed
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char *yes_str = "y";
  if (argc > 1) {
    yes_str = argv[1];
  }
  while (1)
    printf("%s\n", yes_str);
  return EXIT_SUCCESS;
}
