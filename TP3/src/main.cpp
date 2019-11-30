#define t_size 128

#include <cstdio>
#include <iostream>
#include <string>
#include "lista.h" 
#include "functions.h"
using namespace std;

int main() {
  Lista hash [t_size];
  int n;
  scanf("%d", &n);
  string word;
  for (int i = 0; i < n; ++i) {
    cin >> word;
    hash[hashing(word, t_size)].incremental(word);
  }
  char op;
  Cell aux;
  Node* data = new Node[n_words(hash,t_size)];
  
  //BuildHuffman();
  

  while (cin >> op >> word) {
    if (op == 'q'){
    	hash[hashing(word,t_size)].search(word,aux);
    	cout<< aux.count<<endl;
    }else if(op == 'c'){

    }
  }
  delete [] data;
  return 0;
}
