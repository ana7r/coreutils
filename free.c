/*
 * copyright 2023 Mohamed Abdelhamed
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  int total;
  int used;
  int free;
  int available;
} meminfo_t;

int get_entry(char *buf) {
  char *token = strtok(buf, " ");
  token = strtok(NULL, token);
  return atoi(token);
}

meminfo_t parse_meminfo() {
  meminfo_t m = {0};
  FILE *f = fopen("/proc/meminfo", "r");
  if (!f)
    return m;

  char buf[1024] = {0};

  fgets(buf, 1024, f);
  m.total = get_entry(buf);

  fgets(buf, 1024, f);
  m.free = get_entry(buf);

  fgets(buf, 1024, f);
  m.available = get_entry(buf);

  m.used = (m.total - m.free);
  return m;
}

int main(int argc, char *argv[]) {
  const meminfo_t m = parse_meminfo();
  printf("%-5s%10s%10s%10s%12s\n", " ", "total", "used", "free", "available");
  printf("%-5s%8dMi%8dMi%8dMi%10dMi\n", "Mem:", m.total / 1024, m.used / 1024,
         m.free / 1024, m.available / 1024);
  return 0;
}
