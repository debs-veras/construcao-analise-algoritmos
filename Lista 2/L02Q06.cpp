#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int kmin(int *X, int *Y, int px, int rx, int py, int ry, int k);

int main() {
  int A[] = {1, 2, 7, 8, 10},
      B[] = {3, 4, 5, 6, 9},
      n = sizeof(A) / sizeof(int);

  printf("%d\n", kmin(A, B, 0, n - 1, 0, n - 1, 5));
  return 0;
}

int kmin(int *X, int *Y, int px, int rx, int py, int ry, int k) {
  int qx, qy, nx, ny, nt;

  if (px > rx)
    return Y[py + k - 1];
  else
    if (py > ry)
      return X[px + k - 1];
    else {
      qx = (px + rx) / 2;
      qy = (py + ry) / 2;
      nx = qx - px + 1;
      ny = qy - py + 1;

      if (k >= nx + ny)
        if (X[qx] < Y[qy])
          return kmin(X, Y, qx + 1, rx, py, ry, k - nx);
        else
          return kmin(X, Y, px, rx, qy + 1, ry, k - ny);
      else
        if (X[qx] < Y[qy])
          return kmin(X, Y, px, rx, py, qy - 1, k);
        else
          return kmin(X, Y, px, qx - 1, py, ry, k);
     }
}
