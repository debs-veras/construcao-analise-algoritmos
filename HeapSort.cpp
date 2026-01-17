#include <bits/stdc++.h>

using namespace std;

void MaxHeapify(int *A, int i, int n);
void BuildMaxHeap(int *A, int n);
void HeapSort(int *A, int n);

int main() {
  int A[] = {10, 9, 3, 4, 5, 8, 7, 6, 2, 1}, n, i;

  n = sizeof(A) / sizeof(int);
  HeapSort(A, n);
  printf("A:");

  for (i = 0; i < n; i++)
    printf(" %d", A[i]);

  printf("\n");
  return 0;
}

void MaxHeapify(int *A, int i, int n) {
  int m, l, r;

  l = 2 * i + 1;
  r = 2 * i + 2;
  m = i;

  if ((l < n) && (A[l] > A[m]))
    m = l;

  if ((r < n) && (A[r] > A[m]))
    m = r;

  if (m != i) {
    swap(A[i], A[m]);
    MaxHeapify(A, m, n);
  }
}

void BuildMaxHeap(int *A, int n) {
  int i;

  for (i = n/2 - 1; i >= 0; i--)
    MaxHeapify(A, i, n);
}

void HeapSort(int *A, int n) {
  int i;

  BuildMaxHeap(A, n);

  for (i = n-1; i > 0; i--) {
    swap(A[0], A[i]);
    MaxHeapify(A, 0, i);
  }
}
