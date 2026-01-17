#include <bits/stdc++.h>

using namespace std;

void bubblesort(int *A, int n);
void insertionsort(int *A, int n);
void selectionsort(int *A, int n);

int main() {
  int *A, i, n = 10000;
  double ti, tf;

  A = (int *) calloc(n, sizeof(int));

  for (i = 0; i < n; i++)
    A[i] = n - 1;

  ti = clock();
  selectionsort(A, n);
  tf = clock();
  printf("Tempo: %f\n", (tf - ti) / CLOCKS_PER_SEC);

  free(A);
  return 0;
}

void bubblesort(int *A, int n) {
  int i, j;

  for (i = n-1; i >= 1; i--)
    for (j = 0; j < i; j++)
      if (A[j] > A[j+1])
        swap(A[j], A[j+1]);
}

void insertionsort(int *A, int n) {
  int i, j, x;

  for (i = 1; i < n; i++) {
    x = A[i];
    j = i-1;

    while ((j >= 0) && (A[j] > x)) {
      A[j+1] = A[j];
      j--;
    }

    A[j+1] = x;
  }
}

void selectionsort(int *A, int n) {
  int i, j, k;

  for (i = 0; i < n-1; i++) {
    k = i;

    for (j = i+1; j < n; j++)
      if (A[j] < A[k])
        k = j;

    swap(A[i], A[k]);
  }
}
