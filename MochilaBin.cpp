#include <bits/stdc++.h>

/* ===================================================================================
   Dados as sequências de pesos (P) e valores (V) de n produtos e uma capacidade C
   1. M[i,j]: Maior lucro obtido com os i primeiros produtos e mochila de capacidade j
   2. M[i,j]= 0, se i=0 ou j=0
              M[i-1,j], se i>0, j>0 e P[i-1]>j
              max(V[i-1] + M[i-1,j-P[i-1]], M[i-1,j]), c. c.
   3. M[n,C]
   =================================================================================== */

int R[100][100];

int mochilabin(int *P, int *V, int n, int C);
void rastreio(int *P, int *V, int i, int j);

int main() {
  int P[] = { 8, 3,  6, 5, 4},
      V[] = {18, 7, 13, 9, 8}, n, l, C = 15;

  n = sizeof(P) / sizeof(int);
  l = mochilabin(P, V, n, C);
  printf("Lucro máximo: %d\n", l);
  printf("Possivel solução:\n");
  rastreio(P, V, n, C);
  return 0;
}

int mochilabin(int *P, int *V, int n, int C) {
  int M[n+1][C+1], i, j, q;

  for (i = 0; i <= n; i++)
    M[i][0] = 0;

  for (j = 0; j <= C; j++)
    M[0][j] = 0;

  for (i = 1; i <= n; i++)
    for (j = 1; j <= C; j++) {
      M[i][j] = M[i-1][j];

      if (P[i-1] <= j) {
        q = V[i-1] + M[i-1][j-P[i-1]];

        if (q > M[i][j]) {
          M[i][j] = q;
          R[i][j] = 1;
        }
      }
    }

  return M[n][C];
}

void rastreio(int *P, int *V, int i, int j) {
  if (i && j)
    if (R[i][j] == 1) {
      rastreio(P, V, i-1, j-P[i-1]);
      printf("Coletar o produto %d que pesa %d e vale %d\n", i, P[i-1], V[i-1]);
    }
    else
      rastreio(P, V, i-1, j);
}
