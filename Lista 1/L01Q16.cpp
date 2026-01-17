#include <bits/stdc++.h>

typedef long int lint;

int main() {
  lint n, b, q, d, s, l, f, lin, col;

  printf("Digite o valor de n: ");
  scanf("%ld", &n);
  printf("Digite o valor de b: ");
  scanf("%ld", &b);

  if (b == n * n) {
    lin = col = n / 2 + 1;

    if (n % 2 == 0)
      col--;
  }
  else {
    q = ceil((n - sqrt(n * n - b)) / 2);
    s = 4 * (n - q + 1) * (q - 1);
    b -= s;
    l = n -2 * (q - 1);
    f = (b - 1) / (l - 1);
    b -= f * (l - 1);

    switch (f) {
      case 0: lin = q;
              col = b + q - 1;
              break;
      case 1: lin = b + q - 1;
              col = n - q + 1;
              break;
      case 2: lin = n - q + 1;
              col = q + l - b;
              break;
      case 3: lin = q + l - b;
              col = q;
    }
  }

  printf("Endereco: (%ld,%ld)\n", lin, col);
}
