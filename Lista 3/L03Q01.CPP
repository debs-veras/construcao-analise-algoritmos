#include <bits/stdc++.h>

/* ========================================================================================
   LCS: Longest Common Subsequence
   Dadas duas strings X[0..m-1] e Y[0..n-1]
   1. L[i,j]: tamanho da maior subsequencia comum de X[0..i-1] e y[0..j-1]
   2. L[i,j]= 0, se i=0 ou j=0
              1 + L[i-1,j-1], se i>0, j>0 e X[i-1]=Y[j-1]
              max(L[i,j-1],L[i-1,j]), caso contrário
   3. L[m,n] = ?
   ======================================================================================== */

int R[100][100] = {{0}};
char X[100], Y[100];

int lcs(char *X, char *Y, int m, int n);
void rastreio(int i, int j);

int main() {
  int m, n, l;

  strcpy(X, "ACCGGTCGAGTGCGCGGAAG");
  strcpy(Y, "GCGTTCGGAATGCCGTTGC");
  m = strlen(X);
  n = strlen(Y);
  l = lcs(X, Y, m, n);
  printf("Tamanho da LCS: %d\n", l);
  printf("Possivel solucao: ");
  rastreio(m, n);
  return 0;
}

int lcs(char *X, char *Y, int m, int n) {
  int L[m+1][n+1] = {{0}}, i, j, q;

  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
      if (X[i-1] == Y[j-1]) {
        L[i][j] = 1 + L[i-1][j-1];
        R[i][j] = 1;
      }
      else
        if (L[i-1][j] > L[i][j-1]) {
          L[i][j] = L[i-1][j];
          R[i][j] = 2;
        }
        else {
          L[i][j] = L[i][j-1];
          R[i][j] = 3;
        }

  return L[m][n];
}

void rastreio(int i, int j) {
  if (i && j)
    if (R[i][j] == 1) {
      rastreio(i-1, j-1);
      printf("%c", X[i-1]);
    }
    else
      if (R[i][j] == 2)
        rastreio(i-1, j);
      else
        rastreio(i, j-1);
}
