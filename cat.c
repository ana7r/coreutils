/*
 * copyright 2023 Mohamed Abdelhamed
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void cat(int fd) {
  while (1) {
    char buf[4096];
    memset(buf, 0, 4096);
    ssize_t r = read(fd, buf, 4096);
    if (!r)
      return;
    write(STDOUT_FILENO, buf, r);
  }
}

int main(int argc, char **argv) {
  int ret = 0;

  if (argc == 1) {
    cat(STDIN_FILENO);
  }

  for (int i = 1; i < argc; ++i) {
    // Read from input stream
    if (!strcmp(argv[i], "-") || !strcmp(argv[i], "--")) {
      cat(STDIN_FILENO);
      continue;
    }
    // Try open file
    int fd = open(argv[i], O_RDONLY);
    if (fd < 0) {
      fprintf(stderr, "%s: %s: %s\n", argv[0], argv[i], strerror(errno));
      ret = 1;
      continue;
    }

    struct stat _stat;
    fstat(fd, &_stat);

    if (S_ISDIR(_stat.st_mode)) {
      fprintf(stderr, "%s: %s: Is a directory\n", argv[0], argv[i]);
      close(fd);
      ret = 1;
      continue;
    }

    cat(fd);

    close(fd);
  }

  return ret;
}
