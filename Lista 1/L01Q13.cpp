#include <bits/stdc++.h>

int main() {
  int d, m, n;

  printf("Digite o valor de n: ");
  scanf("%d", &n);
  printf("Digite o valor de m: ");
  scanf("%d", &m);
  d = int(m * log10(n)) + 1;
  printf("O numero %d elevado a %d possui %d digitos!\n", n, m, d);
  return 0;
}
