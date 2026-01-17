#include <bits/stdc++.h>

void intercala(int *A, int p, int q, int r);
void mergesort(int *A, int p, int r);

int main() {
  int A[] = {1, 5, 2, 3, 9, 8, 3, 1, 4}, i, n;

  n = sizeof(A) / sizeof(int);
  mergesort(A, 0, n-1);

  printf("A:");

  for (i = 0; i < n; i++)
    printf(" %d", A[i]);

  printf("\n");
  return 0;
}

void intercala(int *A, int p, int q, int r) {
  int nl, nr, i, j, k;
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
    else
      A[k] = R[j++];

  free(L);
  free(R);
}

void mergesort(int *A, int p, int r) {
  int q;

  if (p < r) {
    q = (p + r) / 2;
    mergesort(A, p, q);
    mergesort(A, q+1, r);
    intercala(A, p, q, r);
  }
}
