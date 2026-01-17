#include <bits/stdc++.h>

using namespace std;

int main() {
  char S[100], T[100];
  int i, t = 1, d;

  printf("Digite o número: ");
  scanf("%[0-9]", S);
  printf("Digite a quantidade de dígitos a serem removidos: ");
  scanf("%d", &d);
  T[0] = S[0];

  for (i = 1; S[i]; i++) {
    while ((d > 0) && (t > 0) && (S[i] > T[t-1])) {
      t--;
      d--;
    }

    T[t++] = S[i];
  }

  T[t-d] = '\0';
  printf("%s\n", T);
  return 0;
}
