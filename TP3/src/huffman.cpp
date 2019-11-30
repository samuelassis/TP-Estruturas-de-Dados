#include "huffman.h"
#include "lista.h"
#include "functions.h"

Tree::Tree(Node* element){
	this-> root = element;
	element->left = nullptr;
	element->right = nullptr;
}

void swap(Node  a [], Node b[]){
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
	int minimum = data[parent].count;
	int left = 2*parent + 1;
	int right = 2*parent + 2;

	if(left < size && data[left].count < data[minimum].count){
		minimum = left;
	}
	if(right<size && data[right].count < data[minimum].count){
		minimum = right;
	}
	if(minimum =! parent){
		swap(&data[minimum],&data[parent]);
		Heapify(data,size,minimum);
	}
}

void MakeHeap(Node array[], int size){
	int root = (size/2) - 1;
	for(int i = root; i>=0; i--){
		Heapify(array, size,i);
	}
}

void MergeNode(Node x[], Node y [], Node& root){
	Node root;
	root.count = x->count + y->count;
	if(x->leave == 0 && y->leave == 0 ){
		root.leave = 2;
	}else{
		root.leave = x->leave + y->leave;
	}

	if(x->count > y->count){
		root.left  = y;
		root.right = x;
	}else{
		
		if(x->count == y->count){
			
			if(x->word > y->word){				
				root.left  = x;
				root.right = y;
			}else{
				root.left  = y;
				root.right = x;
			}
		}else{
			
			root.left  = y;
			root.right = x;
		}
	}
}

void EncondeWords(Node& tree, Lista HashTable[],int n_tree){

}

void BuildHuffman(Node array[], Lista table[], int t_size, int a_size){
	while(array[1] != nullptr){
	
		MakeHeap(array, size);
		MergeNode(array[0], array[2]);
		delete array[0];
	}


}