#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "maff.h"

struct node *createlist(int size) {
  struct node *list = calloc(sizeof(struct node), size);
  return list;
}

struct node *getnodeloc(struct node *list, int id) {
  int i = id;
  struct node *nodeloc = list;
  while (i > 0) {
    if (nodeloc->next == NULL) {
      break;
    }
    nodeloc = nodeloc->next;
    --i;
  }
  return nodeloc;
}

struct node *findlast(struct node *list) {
  struct node *nodeloc = list;
  while (nodeloc->next != NULL) {
    nodeloc = nodeloc->next;
  }
  return nodeloc;
}

struct node *findfree(struct node *list) {
  struct node *freeloc = list;
  while (true) {
    if (freeloc->occ != true) {
      return freeloc;
    }
    ++freeloc;
  }
  return NULL;
}

int addnode(struct node *list, int data) {
  if (list->occ != true) {
    list->occ = true;
    list->next = NULL;
    list->dat = data;
    return 1;
  }
  struct node *freeloc = findfree(list);
  struct node *lastloc = findlast(list);
  freeloc->next = NULL;
  freeloc->dat = data;
  freeloc->occ = true;
  lastloc->next = freeloc;
  return 0;
}

void printlist(struct node *list) {
  struct node *nodeloc = list;
  while (nodeloc->next != NULL) {
    printf("%d ", nodeloc->dat);
    nodeloc = nodeloc->next;
  }
  printf("%d\n", nodeloc->dat);
}

int removenode(struct node *list, int id) {
  if (id == 0) {
    return -1;
  }
  struct node *prevnode = getnodeloc(list, id - 1);
  struct node *currnode = getnodeloc(list, id);
  if (currnode->next == NULL) {
    currnode->occ = false;
    prevnode->next = NULL;
    return 1;
  }
  struct node *nextnode = getnodeloc(list, id + 1);
  currnode->occ = false;
  prevnode->next = nextnode;
  return 0;
}

int getnodedat(struct node *list, int id) {
  struct node *nodeloc = getnodeloc(list, id);
  return nodeloc->dat;
}

void setnodedat(struct node *list, int dat, int id) {
  struct node *nodeloc = getnodeloc(list, id);
  nodeloc->dat = dat;
}
