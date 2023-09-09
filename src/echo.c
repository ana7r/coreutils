/*
 * copyright 2023 Mohamed Abdelhamed
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void show_usage(char *argv[]) {
  printf("Usage: %s [SHORT-OPTION]... [STRING]...\n"
         "  or:  %s LONG-OPTION\n"
         "Echo the STRING(s) to standard output.\n\n"
         "  -n         do not output the trailing newline\n"
         "  -e         enable interpretation of backslash escapes\n"
         "  -E         disable interpretation of backslash escapes (default)\n"
         "  -h         display this help and exit\n",
         argv[0], argv[0]);
}

int main(int argc, char **argv) {
  int use_newline = 1;

  int process_escapes = 0;

  int opt;
  while ((opt = getopt(argc, argv, "neEh")) != -1) {
    switch (opt) {
    case 'n':
      use_newline = 0;
      break;
    case 'e':
      process_escapes = 1;
      break;
    case 'E':
      process_escapes = 0;
      break;
    case '?':
    case 'h':
      show_usage(argv);
      return 1;
    }
  }

  for (int i = optind; i < argc; ++i) {
    if (process_escapes) {
      char *c = argv[i];
      while (*c) {
        if (*c == '\\') {
          c++;
          switch (*c) {
          case 'n':
            putchar('\n');
            break;
          case 't':
            putchar('\t');
            break;
          default:
            putchar('\\');
            putchar(*c);
            break;
          }
        } else {
          putchar(*c);
        }
        c++;
      }
    } else {
      printf("%s", argv[i]);
    }
  }

  if (use_newline) {
    printf("\n");
  }

  fflush(stdout);
  return 0;
}
