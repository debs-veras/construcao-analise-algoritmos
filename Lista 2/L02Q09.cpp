#include <bits/stdc++.h>

int intercala(int *A, int p, int q, int r);
int inversoes(int *A, int p, int r);

int main() {
  int A[] = {1, 5, 2, 3, 9, 8, 3, 1, 4}, i, n;

  n = sizeof(A) / sizeof(int);
  printf("Inversoes: %d\n", inversoes(A, 0, n-1));
  return 0;
}

int intercala(int *A, int p, int q, int r) {
  int nl, nr, i, j, k, im = 0;
  int *L, *R;

  nl = q - p + 1;
  nr = r - q;
  L = (int *) calloc(nl, sizeof(int));
  R = (int *) calloc(nr, sizeof(int));

  for (i = 0; i < nl; i++)
    L[i] = A[p+i];

  for (j = 0; j < nr; j++)
    R[j] = A[q+j+1];

  i = j = 0;

  for (k = p; k <= r; k++)
    if ((j == nr) || (i < nl && L[i] <= R[j]))
      A[k] = L[i++];
    else {
      A[k] = R[j++];
      im += nl - i;
    }

  free(L);
  free(R);
  return im;
}

int inversoes(int *A, int p, int r) {
  int il, ir, im, q;

  if (p < r) {
    q = (p + r) / 2;
    il = inversoes(A, p, q);
    ir = inversoes(A, q+1, r);
    im = intercala(A, p, q, r);

    return il + ir + im;
  }

  return 0;
}
