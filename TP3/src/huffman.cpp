#include "huffman.h"
#include "lista.h"
#include "functions.h"
#include <iostream>
using namespace std;

Tree::Tree(Node* element){
	this-> root = element;
	element->left = nullptr;
	element->right = nullptr;
}

void swap(Node&  a, Node& b){
	Node temp;
	temp.word  = a.word;
	temp.count = a.count;
	temp.left  = a.left;
	temp.right = a.right;
	temp.leave = a.leave;

	a.word  = b.word;
	a.count = b.count;
	a.left  = b.left;
	a.right = b.right;
	a.leave = b.leave;

	b.word  = temp.word;
	b.count = temp.count;
	b.left  = temp.left;
	b.right = temp.right;
	b.leave = temp.leave;
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

void HeapifyUp(Node data[], int idx){
	int father = (idx - 1)/2;
	if(idx && data[father].count >= data[idx].count){
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

void MakeHeap(Node array[], int size){
	int root = (size/2) - 1;
	for(int i = root; i>=0; i--){
		Heapify(array, size,i);
	}
}

void MergeNode(Node& x, Node& y, Node& root){
	root.count = x.count + y.count;
	root.leave = x.leave + y.leave;

	if(x.word > y.word){
		root.word = y.word;
	}else{
		root.word = x.word;
	}

	if(x.count > y.count){
		root.left  = &y;
		root.right = &x;
	}else{
		
		if(x.count == y.count){
			
			if(x.leave > y.leave){				
				root.left  = &y;
				root.right = &x;
			}else{
				if(x.leave == y.leave){
					if(x.word > y.word){
						root.left  = &y;
						root.right = &x;
					}else{
						root.left  = &x;
						root.right = &y;
					}
				}else{
					root.left  = &x;
					root.right = &y;				
				}
			}
		}else{
			
			root.left  = &x;
			root.right = &y;
		}
	}
}

void EncodeWords(Node& tree, Lista HashTable[],int t_size){

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
void CopyNode(Node& b, Node& a){
	a.word  = b.word;
	a.count = b.count;
	a.left  = b.left;
	a.right = b.right;
	a.leave = b.leave;
}
void ExtractMin(Node data[],int s, Node& m1, Node& m2){
	MakeHeap(data,s);
	CopyNode(data[0], m1);
	swap(data[0],data[s-1]);
	MakeHeap(data,s-1);
	CopyNode(data[0],m2);
}
void BuildHuffman(Node array[], Lista table[], int t_size, int a_size){
	Node min1,min2,marker;
	while(a_size !=2){
		ExtractMin(array,a_size, min1, min2);
		MergeNode(min1,min2,marker);
		swap(array[0],marker);
		a_size--;		
	}












/*

	int min_idx;
	while(a_size != 2){
		Node aux;
		MakeHeap(array, a_size);
		min_idx = CompareNode(array[1],array[2]);
		MergeNode(array[0], array[min_idx],aux);
		swap(array[min_idx], aux);
		swap(array[0], array[a_size-1]);
		a_size--;
		HeapifyUp(array, a_size);
	}
	Node tree;
	MergeNode(array[0],array[1],tree);
	TreeWalk(&tree);
	
	EncodeWords(array[0],table,t_size);

*/

}