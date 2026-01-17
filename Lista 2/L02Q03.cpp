#include <bits/stdc++.h>

int majoritario(int *A, int p, int r);

int main() {
  int A[] = {1, 2, 3, 2, 1, 1, 2, 1, 2}, m, n;

  n = sizeof(A) / sizeof(int);
  m = majoritario(A, 0, n-1);

  if (m == -1)
    printf("Nao existe elemento majoritario!\n");
  else
    printf("Majoritario: %d\n", m);

  return 0;
}

int majoritario(int *A, int p, int r) {
  int ml, mr, cl, cr, i, q, n;

  if (p < r) {
    q = (p + r) / 2;
    ml = majoritario(A, p, q);
    mr = majoritario(A, q+1, r);
    cl = cr = 0;
    n = (r - p + 1);

    for (i = p; i <= r; i++)
      if (A[i] == ml)
        cl++;
      else
        if (A[i] == mr)
          cr++;

    if (cl > n/2)
      return ml;

    if (cr > n/2)
      return mr;

    return -1;
  }
  else
    return A[p];
}
