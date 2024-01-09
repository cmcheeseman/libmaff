#include "maff.h"


void vadd(struct vector *target, struct vector *source) {
  target->x = target->x + source->x;
  target->y = target->y + source->y;
}

void vaddi(struct vector *target, int x, int y) {
  target->x = target->x + x;
  target->y = target->y + y;
}

void vsub(struct vector *target, struct vector *source) {
  target->x = target->x - source->x;
  target->y = target->y - source->y;
}

void vsubi(struct vector *target, int x, int y) {
  target->x = target->x - x;
  target->y = target->y - y;
}

void vmul(struct vector *target, struct vector *source) {
  target->x = target->x * source->x;
  target->y = target->y * source->y;
}

void vmuli(struct vector *target, int x, int y) {
  target->x = target->x * x;
  target->y = target->y * y;
}
