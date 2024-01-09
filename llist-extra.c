#include "maff.h"
#include <stdlib.h>
#include <stdio.h>


void llistiterate(struct node *list, int size) {
  for (int i = 0; i < size; i++) {
    if (i == (size - 1)) {
      int x = getnodedat(list, i - 1);
      int y = getnodedat(list, i);
      if (x > y) {
        setnodedat(list, y, i - 1);
        setnodedat(list, x, i);
      }
    } else {
      int x = getnodedat(list, i);
      int y = getnodedat(list, i + 1);
      if (x > y) {
        setnodedat(list, y, i);
        setnodedat(list, x, i + 1);
      }
    }
  }
}

void llistsort(struct node *list, int size) {
  for (int i = 0; i < size; i++) {
    llistiterate(list, size);
  }
}


// creates a map of a linked list for use with llistsortoptimizediterate
struct node **llistsortoptimizedinit(struct node *list, int size) {
  struct node **listmap = malloc(size * sizeof(list));
  struct node *current = list;
  for (int i = 0; i < size; i++) {
    listmap[i] = current;
    current = current->next;
  }
  return listmap;
}

// partialy sorts a linked list, must be called multiple times to fully sort list. needs map of linked list to work
void llistsortoptimizediterate(struct node *list, int size, struct node **map) {
  for (int i = 0; i < size - 1; i++) {
    if (i == size - 1) {
      int x = map[i - 1]->dat;
      int y = map[i]->dat;
      if (x > y) {
        map[i - 1]->dat = y;
        map[i]->dat = x;
      }
    } else {
      int x = map[i]->dat;
      int y = map[i + 1]->dat;
      if (x > y) {
        map[i]->dat = y;
        map[i + 1]->dat = x;
      }
    }
  }
}

void llistsortoptimized(struct node *list, int size) {
  struct node **map = llistsortoptimizedinit(list, size);
  for (int i = 0; i < size; i++) {
    llistsortoptimizediterate(list, size, map);
  }
  free(map);
}
