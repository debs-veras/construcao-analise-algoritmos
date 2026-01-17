#include <bits/stdc++.h>

/* ====================================================================
   Dada uma sequencia de valores A[0..n-1]
   1. S[i] : tamanho da maior subsequencia de A[0..i], incluindo o A[i]
   2. S[i] = 1, se i = 0
             1, se i > 0 e não existe j < i com A[j] < A[i]
             max{1 + S[j] | j < i e A[j] < A[i]}, caso contrário
   3. Calcular o maior valor de S[0..n-1]
   ==================================================================== */

int R[100] = {0};

int sscmax(int *A, int n, int &p);
void rastreio(int *A, int p);

int main() {
  int A[] = {3, 1, 8, 6, 2, 5, 4, 7, 2}, n, m, p;

  n = sizeof(A) / sizeof(int);
  m = sscmax(A, n, p);
  printf("Tamanho da maior sub. seq.: %d\n", m);
  printf("Possivel subsequencia:");
  rastreio(A, p);
  return 0;
}

int sscmax(int *A, int n, int &p) {
  int S[n], i, j, m, q;

  S[0] = m = 1;
  p = 0;

  for (i = 1; i < n; i++) {
    S[i] = 1;
    R[i] = i;

    for (j = 0; j < i; j++)
      if (A[j] < A[i]) {
        q = 1 + S[j];

        if (q > S[i]) {
          S[i] = q;
          R[i] = j;
        }
      }

    if (S[i] > m) {
      m = S[i];
      p = i;
    }
  }

  return m;
}

void rastreio(int *A, int p) {
  if (R[p] != p)
    rastreio(A, R[p]);

  printf(" %d", A[p]);
}
