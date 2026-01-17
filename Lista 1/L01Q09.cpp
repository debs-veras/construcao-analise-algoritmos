#include <bits/stdc++.h>

int main() {
  bool V[1000001] = {0};
  int i, j, r, n;

  r = 1000;
  n = 1000000;

  V[0] = V[1] = true;

  for (i = 2; i <= r; i++)
    if (!V[i])
      for (j = 2 * i; j <= n; j += i)
        V[j] = true;

  printf("Primos menores que %d:", n);

  for (i = 2; i <= n; i++)
    if (!V[i])
      printf(" %d", i);

  return 0;
}
