#include <bits/stdc++.h>

using namespace std;

int c = 0;

typedef struct {
          char nome;
        } torre;

// Transfere n discos de t1 para t2, usando t3 como auxiliar
void hanoi(int n, torre &t1, torre &t2, torre &t3);

int main() {
  torre t1, t2, t3;
  int d, n = 50;

  t1.nome = 'A';
  t2.nome = 'B';
  t3.nome = 'C';

  hanoi(n, t1, t2, t3);
  printf("Qtd. de movimentos: %d\n", c);
  return 0;
}

void hanoi(int n, torre &t1, torre &t2, torre &t3) {
  if (n == 1) {
    printf("Transferir um disco de %c para %c\n", t1.nome, t2.nome);
    c++;
  }
  else {
    hanoi(n-1, t1, t3, t2);
    printf("Transferir um disco de %c para %c\n", t1.nome, t2.nome);
    c++;
    hanoi(n-1, t3, t2, t1);
  }
}
