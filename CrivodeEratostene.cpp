#include <bits/stdc++.h>

using namespace std;

int main() {
  bool *P;
  int n = 1000000;
  int r = 1000;

  P[0] = P[1] = 1;
  P = (bool *) calloc(n + 1, sizeof(bool));

  for(int i = 2; i <= r; i++)
    if(!P[i])
      for(int j = 2 * i; j<= n; j += i)
        P[j] = 1;
  
  free(P);
  return 0;
}
