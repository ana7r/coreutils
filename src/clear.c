/*
 * copyright 2023 Mohamed Abdelhamed
 */

#include <stdio.h>

int main(int argc, char **argv) {
  /*
   * \033 stands for ESC (ANSI value 27).
   * ESC [ is a kind of escape sequence called Control Sequence Introducer
   * (CSI). \033[H moves the cursor to the top left corner of the screen
   * (ie,the first column of the first row in the screen).
   * \033[J clears the part of the screen from the cursor to the end of the
   * screen.
   */
  printf("\033[H\033[2J");
  fflush(stdout);
  return 0;
}
