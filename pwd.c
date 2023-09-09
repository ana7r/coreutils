/*
 * copyright 2023 Mohamed Abdelhamed
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char buf[1024];
  if (getcwd(buf, 1023)) {
    puts(buf);
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}
