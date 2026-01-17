#include <bits/stdc++.h>

using namespace std;

int main() {
  int B[] = {5, 1, 5, 4, 2, 3}, F[1000001] = {0}, i, n, t = 0;

  n = sizeof(B) / sizeof(int);

  for (i = 0; i < n; i++) {
    if (F[B[i] + 1])
      F[B[i] + 1]--;
    else {
      printf("Lancar uma flecha na altura %d\n", B[i]);
      t++;
    }

    F[B[i]]++;
  }

  printf("Qtd. min. de flechas: %d\n", t);
  return 0;
}
