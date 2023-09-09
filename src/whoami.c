/*
 * copyright 2023 Mohamed Abdelhamed
 */

#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  struct passwd *p = getpwuid(geteuid());
  if (!p)
    return EXIT_FAILURE;

  puts(p->pw_name);
  endpwent();

  return EXIT_SUCCESS;
}
