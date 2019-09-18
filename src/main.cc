#include <cstdio>
#include "lista.h"
#include "functions.h"

void main() {
  int q;
  char e;
  while(scanf("%d %c", &q, &e) != EOF) {
    if (e == 'p')
      // veja que a funcao bar() sempre retorna 1, entao o programa sempre
      // vai imprimir 1.
      // Troque essa funcao (inclusive o nome dela) caso queira tirar uma nota
      // melhor no TP!
      printf("%d\n", operation());
  }
}
