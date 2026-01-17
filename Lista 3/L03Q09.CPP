#include <bits/stdc++.h>

/* ===========================================================================
   Dada uma fila de carros C[0..n-1], onde cada ci indica o tamanho do carro i,
   e o tamanho das pistas da balsa (l)

   1. M[k,i,j] : Maior número de carros que podem ser colocados da fila C[k..n-1]
                 considerando pista 1 com tamanho i e a 2 com tamanho j
   2. M[k,i,j] = 0, se k >= n, ou Ck > i e Ck > j
                 1 + M[k+1, i-Ck, j], se k < n e i >= Ck > j
                 1 + M[k+1, i, j-Ck], se k < n e i < Ck <= j
                 1 + max(M[k+1, i-Ck, j], M[k+1, i, j-Ck]), caso contrário.
   3. M[0,l,l] = ?
   =========================================================================== */

int R[100][100][100] = {{{0}}};

int MaxCarros(int *C, int n, int l);
void Rastreio(int *C, int n, int k, int i, int j);

int main() {
  int C[] = {6, 5, 3, 4, 2, 3, 4}, n, l = 10, m;

  n = sizeof(C) / sizeof(int);
  m = MaxCarros(C, n, l);
  printf("Maior numero de carros: %d\n", m);
  printf("Possivel disposição dos carros na balsa:\n");
  Rastreio(C, n, 0, l, l);
  return 0;
}

int MaxCarros(int *C, int n, int l) {
  int M[n+1][l+1][l+1] = {{{0}}}, i, j, k, q;

  for (k = n-1; k >= 0; k--) {
    for (i = 0; i <= l; i++)
      for (j = 0; j <= l; j++)
        if (C[k] <= i || C[k] <= j)
          if (C[k] > j && C[k] <= i) {
            M[k][i][j] = 1 + M[k+1][i-C[k]][j];
            R[k][i][j] = 1;
          }
          else
            if (C[k] > i && C[k] <= j) {
              M[k][i][j] = 1 + M[k+1][i][j-C[k]];
              R[k][i][j] = 2;
            }
            else {
              M[k][i][j] = 1 + M[k+1][i-C[k]][j];
              R[k][i][j] = 1;
              q = 1 + M[k+1][i][j-C[k]];

              if (q > M[k][i][j]) {
                M[k][i][j] = q;
                R[k][i][j] = 2;
              }
            }
  }

  return M[0][l][l];
}

void Rastreio(int *C, int n, int k, int i, int j) {
   if (k < n && R[k][i][j]) {
     printf("Colocar o carro %d na pista %d\n", k, R[k][i][j]);

     if (R[k][i][j] == 1)
       Rastreio(C, n, k+1, i-C[k], j);
     else
       if (R[k][i][j] == 2)
         Rastreio(C, n, k+1, i, j-C[k]);
   }
}
