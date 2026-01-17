#include <bits/stdc++.h>

/* ========================================================================================
   Dada uma cadeia X[0..n-1]
   1. L[i,j]: maior subsequência de X[i..j] que é um palíndromo
   2. L[i,j]= 0, se i>j
              1, se i=j
              2 + L[i+1,j-1], se X[i]=X[j]
              max(L[i,j-1],L[i+1,j]), caso contrário
   3. L[0,n-1] = ?
   ======================================================================================== */

int R[100][100] = {{0}};
char X[100];

int lp(char *X, int n);

int main() {
  int n, l;

  strcpy(X, "ACCGGTCGAGTGCGCGGAAG");
  n = strlen(X);
  l = lp(X, n);
  printf("Tamanho do maior palíndromo: %d\n", l);
  return 0;
}

int lp(char *X, int n) {
  int L[n][n] = {{0}}, i, j;

  for (i = n-1; i >= 0; i--) {
    L[i][i] = 1;

    for (j = i+1; j < n; j++)
      if (X[i] == X[j])
        L[i][j] = 2 + L[i+1][j-1];
      else
        if (L[i+1][j] > L[i][j-1])
          L[i][j] = L[i+1][j];
        else
          L[i][j] = L[i][j-1];
  }

  return L[0][n-1];
}
