#include "maff.h"

int volumerectp(int w, int l, int h) {
  int ret = w * l;
  return ret * h;
}

int volumetrip(int w, int h, int l) {
  int ret = (w * h) / 2;
  return ret * w;
}
