#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include "lista.h"

struct Node{
	std::string word;
	int count;
	int leave;
	Node* left;
	Node* right;
};

struct Tree{
	Node* root;
	int n_nodes;

	Tree(Node*);
};

void swap(Node*, Node*);
void MakeHeap(Node [], int);
void HeapifyUp(Node [], int);
void Heapify(Node [], int, int);
int CompareNode(Node,Node);
void ExtractMin(Node[],int , Node*, Node*);
void TreeWalk(Node*);
void MergeNode(Node*, Node*, Node&);
void EncodeWords(Node*, Lista[],int,char,std::string&);

#endif