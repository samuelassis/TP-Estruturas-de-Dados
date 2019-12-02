#define t_size 128

#include <cstdio>
#include <iostream>
#include <string>
#include "lista.h" 
#include "functions.h"
using namespace std;

void printBT(const string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        cout<<"{"<<node->word<<"-"<<node->count<<"-"<<node->leave<<"}"<<endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}
void printBT(const Node* node)
{
    printBT("", node, false);    
}


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
  
  int d_size = n_words(hash,t_size);
  Node* data = new Node[d_size];
  data_transfer(data,hash,t_size);
  	
  	while(d_size !=2){
		Node*min1 = new Node();
		Node*min2 = new Node();
		Node marker;
		ExtractMin(data,d_size, min1, min2);
		MergeNode(min1,min2,marker);
		swap(data[0],marker);
		d_size--;
	}
	Node tree;
	string codigo;
	MergeNode(&data[0],&data[1],tree);
 	//EncodeWords(&tree, hash,t_size,'r',codigo);
  	
  while (cin >> op >> word) {
    if (op == 'q'){
    	
    	hash[hashing(word,t_size)].search(word,aux);
    	cout<< aux.count<<endl;
    }else if(op == 'p'){
    	printBT(&tree);
    }else if(op == 'c'){
    	hash[hashing(word,t_size)].search(word,aux);
    	cout<<aux.code<<endl;
    }
  }
  delete [] data;
  return 0;
}

