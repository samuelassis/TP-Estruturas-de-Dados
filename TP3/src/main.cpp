#define t_size 64

#include <cstdio>
#include <iostream>
#include <string>
#include "lista.h" 
#include "functions.h"
using namespace std;

int main() {
  Lista hash [t_size];
 // Hash = new Lista[t_size];
  int n;
  scanf("%d", &n);
  string word;
  for (int i = 0; i < n; ++i) {
    cin >> word;
    hash[hashing(word, t_size)].incremental(word);
    // insira/atualize o contador de `word` na estrutura de busca aqui
  }
  char op;  // CUIDADO para não ler o '\n' ao invés da operação
            // o espaço antes do %c está lá pra isso
  while (cin >> op >> word) {
    if (op == 'q'){
    	Cell aux;
    	hash[hashing(word,t_size)].search(word,aux);
    	cout<< aux.count<<endl;
    }
  }
  return 0;
}
