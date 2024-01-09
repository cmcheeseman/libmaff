#include "maff.h"
#include <stdio.h>
#include <stdlib.h>


int* setarray(int size, const int content) {
  int* ret = malloc(size * 4);
  for (int i = 0; i < size; i++) {
    ret[i] = content;
  }
  return ret;
}

void printarr(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}


void iterate(int* arr, int size) {
  int max = size - 1;
  for (int i = 0; i < size; i++) {
    if (i == max) {
      int x = arr[i - 1];
      int y = arr[i];
      if (x > y) {
        arr[i - 1] = y;
        arr[i] = x;
      }
    } else {
      int x = arr[i];
      int y = arr[i + 1];
      if (x > y) {
        arr[i] = y;
        arr[i + 1] = x;
      }
    }
  }
}

void sort(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    iterate(arr, size);
  }
}


int sum(int *list, int len) {
  int x = 0;
  for (int i = 0; i < len; i++) {
    x = x + *list;
    list++;
  }
  return x;
}

