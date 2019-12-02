#include "huffman.h"
#include "lista.h"
#include "functions.h"
#include <iostream>
#include <string>
using namespace std;

void swap(Node*  a, Node* b){
	Node temp;
	temp.word  = a->word;
	temp.count = a->count;
	temp.left  = a->left;
	temp.right = a->right;
	temp.leave = a->leave;

	a->word  = b->word;
	a->count = b->count;
	a->left  = b->left;
	a->right = b->right;
	a->leave = b->leave;

	b->word  = temp.word;
	b->count = temp.count;
	b->left  = temp.left;
	b->right = temp.right;
	b->leave = temp.leave;
}

void Heapify(Node data[], int size, int parent){
	int minimum = parent;
	int left = 2*parent + 1;
	int right = 2*parent + 2;

	if(left < size && data[left].count <= data[minimum].count){
		if(data[left].count == data[minimum].count){ // To treat data conflict
			if(data[left].leave <= data[minimum].leave){
				if(data[left].leave == data[minimum].leave){
					if(data[left].word < data[minimum].word){
						minimum = left;
					}
				}else{
					minimum = left;
				}
			}
		}else{
			minimum = left;
		}
	}
	if(right<size && data[right].count <= data[minimum].count){
		if(data[right].count == data[minimum].count){
			if(data[right].leave <= data[minimum].leave){
				if(data[right].leave == data[minimum].leave){
					if(data[right].word < data[right].word){
						minimum = right;
					}
				}else{
					minimum = right;
				}
			}
		}else{
			minimum = right;
		}
	}
	if(minimum != parent){
		swap(data[minimum],data[parent]);
		Heapify(data,size,minimum);
	}
}


void MakeHeap(Node array[], int size){
	int root = (size/2) - 1;
	for(int i = root; i>=0; i--){
		Heapify(array, size,i);
	}
}

void MergeNode(Node* x, Node* y, Node& root){
	root.count = x->count + y->count;
	root.leave = x->leave + y->leave;

	if(x->word > y->word){
		root.word = y->word;
	}else{
		root.word = x->word;
	}

	if(x->count > y->count){
		root.left  = y;
		root.right = x;
	}else{
		
		if(x->count == y->count){
			
			if(x->leave > y->leave){				
				root.left  = y;
				root.right = x;
			}else{
				if(x->leave == y->leave){
					if(x->word > y->word){
						root.left  = y;
						root.right = x;
					}else{
						root.left  = x;
						root.right = y;
					}
				}else{
					root.left  = x;
					root.right = y;				
				}
			}
		}else{
			
			root.left  = x;
			root.right = y;
		}
	}
}


void EncodeWords(Node* tree, Lista HashTable[],int t_size,char b,string& code){
	if(tree == nullptr){
		return;
	}

	if(b != 'r'){
		code.append(&b);
	}
	if(tree->left == nullptr && tree->right == nullptr){
		Cell aux;
		HashTable[hashing(tree->word,t_size)].set_code(tree->word,code);
		code = "/0";
	}
	EncodeWords(tree->left,HashTable,t_size,'0',code);
	EncodeWords(tree->right,HashTable,t_size,'1',code);
}

void CopyNode(Node& b, Node* a){
	a->word  = b.word;
	a->count = b.count;
	a->left  = b.left;
	a->right = b.right;
	a->leave = b.leave;
}
void ExtractMin(Node data[],int s, Node* m1, Node* m2){
	MakeHeap(data,s);
	CopyNode(data[0], m1);
	swap(data[0],data[s-1]);
	MakeHeap(data,s-1);
	CopyNode(data[0],m2);
}


// EXTRA UNUSED FUNCTIONS!

void HeapifyUp(Node data[], int idx){
	int father = (idx - 1)/2;
	if(idx > 0 && data[father].count >= data[idx].count){
		if(data[father].count == data[idx].count){
			if(data[father].leave >= data[idx].leave){
				if(data[father].leave == data[idx].leave){
					if(data[father].word > data[idx].word){
						swap(data[father], data[idx]);
					}
				}else{
					swap(data[father], data[idx]);
				}
			}
		}else{
			swap(data[father], data[idx]);
		}
	}
}

int CompareNode(Node a, Node b){
	if(a.count <= b.count){
		if(a.count == b.count){
			if(a.leave <= b.leave){
				if(a.leave == b.leave){
					if(a.word < b.word){
						return 1;
					}else{
						return 2;
					}
				}else{
					return 1;
				}
			}else{
				return 2;
			}
		}else{
			return 1;
		}
	}else{
		return 2;
	}
}

void TreeWalk(Node* tree){
	if(tree != nullptr){
		cout<<"{"<<tree->word<<"-"<<tree->count<<"-"<<tree->leave<<"}"<<endl;
		TreeWalk(tree->left);
		TreeWalk(tree->right);
	}
}

Tree::Tree(Node* element){
	this-> root = element;
	element->left = nullptr;
	element->right = nullptr;
}
