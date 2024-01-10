#include <math.h>
#include "maff.h"

int areasquare(int b, int h) {
  return b * h;
}

int areatriangle(int b, int h) {
  int x = b * h;
  return x / 2;
}

#define PI 3.14159

float areacircle(int r) {
  int x = r * r;
  return PI * x;
}
