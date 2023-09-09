/*
 * copyright 2023 Mohamed Abdelhamed
 */

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char name[HOST_NAME_MAX] = {0};
  gethostname(name, HOST_NAME_MAX);
  printf("%s\n", name);
  return 0;
}
