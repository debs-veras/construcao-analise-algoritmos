#include <bits/stdc++.h>

using namespace std;

int particione(int *A, int p, int r);
void quicksort(int *A, int p, int r);

int main() {
  int A[] = {1, 5, 2, 3, 9, 8, 3, 1, 4}, i, n;

  n = sizeof(A) / sizeof(int);
  quicksort(A, 0, n-1);

  printf("A:");

  for (i = 0; i < n; i++)
    printf(" %d", A[i]);

  printf("\n");
  return 0;
}

int particione(int *A, int p, int r) {
  int i, j;

  i = p-1;

  for (j = p; j < r; j++)
    if (A[j] < A[r])
      swap(A[++i], A[j]);

  swap(A[++i], A[r]);
  return i;
}

void quicksort(int *A, int p, int r) {
  int q;

  if (p < r) {
    q = particione(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}
