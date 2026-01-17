#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int mediana(int X[], int Y[], int px, int rx, int py, int ry);

int main() {
  int A[] = {1, 2, 5, 9, 10},
      B[] = {3, 4, 6, 7, 8},
      n = sizeof(A) / sizeof(int);

  printf("Mediana = %d\n", mediana(A, B, 0, n-1, 0, n-1));
  return 0;
}

int mediana(int X[], int Y[], int px, int rx, int py, int ry) {
  int qx, qy;

  if (px == rx)
    return min(X[px], Y[py]);
  else {
    qx = (px + rx) / 2;
    qy = (py + ry) / 2;

    if (X[qx] == Y[qy])
      return X[qx];
    else
      if (X[qx] < Y[qy]) {
        if (rx - qx > qy - py)
          qx++;

        return mediana(X, Y, qx, rx, py, qy);
      }
      else {
        if (ry - qy > qx - px)
          qy++;

        return mediana(X, Y, px, qx, qy, ry);
      }
  }
}
