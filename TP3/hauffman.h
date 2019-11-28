#define HAUFFMAN_H
#ifndef HAUFFMAN_H

#include <string>

struct Node{
	std::string word;
	int count;
	Node* left;
	Node* right;
};

struct Tree{
	Node* root;
	int
};

#endif