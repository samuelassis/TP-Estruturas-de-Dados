#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include "lista.h"

struct Node{
	std::string word;
	int count;
	int leave;
//  int or string code;
	Node* left;
	Node* right;
};

struct Tree{
	Node* root;
	int n_nodes;

	Tree(Node*);
};

void Heapify(Node [], int, int);
Node MergeNode(Node[], Node[]);
void EncondeWords(Node&, Lista,int);
void BuildHuffman(Node[],Lista[],int, int);

#endif