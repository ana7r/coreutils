/*
 * copyright 2023 Mohamed Abdelhamed
 */

#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "%s: argument expected\n", argv[0]);
    return 1;
  }

  int ret = 0;
  for (int i = 1; i < argc; ++i) {
    // Append to file if exists else create
    FILE *f = fopen(argv[i], "a");
    if (!f) {
      fprintf(stderr, "%s: %s: %s\n", argv[0], argv[i], strerror(errno));
      ret = 1;
      continue;
    }
    fclose(f);
  }

  return ret;
}
