#include <bits/stdc++.h>

using namespace std;

bool anagramas(int n1, int n2);
int  menornum(int n);
int  maiornum(int n);

int main() {
  int i, n = 152784, li, ls, r, imp, p;

  li = n + menornum(n);
  ls = n + maiornum(n);
  r = sqrt(li);

  if (r * r < li) {
    r++;
    li = r * r;
  }

  imp = 2 * r - 1;

  for (i = li; i <= ls; i += imp) {
    p = i - n;
    imp += 2;

    if (anagramas(p, n))
      printf("%d\n", p);
  }

  return 0;
}

bool anagramas(int n1, int n2) {
  int Q[10] = {0}, i, d;

  while (n1) {
    d = n1 % 10;
    Q[d]++;
    n1 /= 10;
  }

  while (n2) {
    d = n2 % 10;
    Q[d]--;
    n2 /= 10;
  }

  for (i = 0; i <= 9; i++)
    if (Q[i])
      return false;

  return true;
}

int menornum(int n) {
  char s[100];
  int num, t, i;

  sprintf(s, "%d", n);
  t = strlen(s);
  sort(s, s+t);

  for (i = 0; s[i] && s[i] == '0'; i++);

  swap(s[0], s[i]);
  sscanf(s, "%d", &num);
  return num;
}

int maiornum(int n) {
  char s[100];
  int num, t;

  sprintf(s, "%d", n);
  t = strlen(s);
  sort(s, s+t, greater<int>());
  sscanf(s, "%d", &num);
  return num;
}
