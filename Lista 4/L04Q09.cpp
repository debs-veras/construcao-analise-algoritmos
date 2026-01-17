#include <bits/stdc++.h>

using namespace std;

int main() {
  int A[] = {3,	4,	6,	8,	14,	15,	16,	17,	21,	25,	26,	27,	30,	31,	40,	41,	42,	43}, n, i, P[3], *D;

  n = sizeof(A) / sizeof(int);
  D = (int *) calloc(n, sizeof(int));

  for (i = 1; i < n; i++)
    D[i] = A[i] - A[i-1] - 1;

  P[0] = D[0];
  P[1] = D[1];
  P[2] = D[2];

  sort(P, P+3);

  for (i = 3; i < n; i++)
    if (D[i] > P[2]) {
      P[0] = P[1];
      P[1] = P[2];
      P[2] = D[i];
    }
    else
      if (D[i] > P[1]) {
        P[0] = P[1];
        P[1] = D[i];
      }
      else
        if (D[i] > P[0])
          P[0] = D[i];

  printf("Menor soma dos intervalos: %d\n", A[n-1] - A[0] + 1 - P[0] - P[1] - P[2]);

  printf("Intervalos:\n");

  for (i = 0; i < n; i++) {
    if (D[i] == P[0]) {
      P[0] = -1;
      printf("\n");
    }

    if (D[i] == P[1]) {
      P[1] = -1;
      printf("\n");
    }

    if (D[i] == P[2]) {
      P[2] = -1;
      printf("\n");
    }

    printf("%d ", A[i]);
  }

  return 0;
}
