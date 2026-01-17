#include <bits/stdc++.h>

/* ====================================================================
   Dada uma haste de tamanho n e preços P[0..n]
   1. L[i] : lucro máximo obtido com uma haste de tamanho i
   2. L[i] = 0, se i = 0
             max{L[j] + P[i-j] | 0 <= j < i}, caso contrário
   3. Calcular L[n]
   ==================================================================== */

int R[100] = {0};

int cutrod(int *P, int n);
void rastreio(int *P, int n);

int main() {
  int P[] = {0, 1, 5, 8, 9}, n, l;

  n = sizeof(P) / sizeof(int) - 1;
  l = cutrod(P, n);
  printf("Lucro maximo com haste de tamanho %d: %d\n", n, l);
  rastreio(P, n);
  return 0;
}

int cutrod(int *P, int n) {
  int L[n+1] = {0}, i, j, q;

  for (i = 1; i <= n; i++) {
    L[i] = P[i];
    R[i] = 0;

    for (j = 1; j < i; j++) {
      q = L[j] + P[i-j];

      if (q > L[i]) {
        L[i] = q;
        R[i] = j;
      }
    }
  }

  return L[n];
}

void rastreio(int *P, int n) {
  int Q[n+1] = {0}, i, l=n;

  while (l > 0) {
    Q[l-R[l]]++;
    l = R[l];
  }

  for (i = 1; i <= n; i++)
    if (Q[i])
      printf("Cortar %d peca(s) de tamanho %d\n", Q[i], i);
}
