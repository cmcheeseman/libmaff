#include <stdio.h>
#include <stdlib.h>
#include "maff.h"
#include <time.h>

int main(int argc, char **argv) {
  int x = atoi(argv[1]);
  struct node *list = createlist(x);
  for (int i = 0; i < x; i++) {
    addnode(list, randomnum(x));
  }
  printlist(list);
  printf("\n\n");
  clock_t start = clock();
  llistsortoptimized(list, x);
  clock_t end = clock();
  printlist(list);
  printf("\n\n%f\n", (float)(end - start) / CLOCKS_PER_SEC);
  free(list);
  return 0;
}
