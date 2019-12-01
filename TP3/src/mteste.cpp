
#include "functions.h"
#include "lista.h"
#include "huffman.h"

#include <iostream>
#include <string>
using namespace std;

void PrintANode(Node a[], int size){
	for(int i=0; i<size; i++){
		cout<<"{"<<a[i].word<<" - "<<a[i].count<<" - "<<a[i].leave<<"}"<<endl;
	}
}
void PrintTree(Node* tree, char c){
	if(tree == nullptr){
		return;
	}
	cout<<"{"<<tree->word<<"-"<<tree->count<<"-"<<tree->leave<<"("<<c<<")"<<"}"<<endl;
	PrintTree(tree->right,'d');
	PrintTree(tree->left, 'e');
	
}



void PrintNode(Node* x){
	cout<<"{"<< x->word<<"-"<<x->count<<"-"<<x->leave<<"}"<<endl;
}

int main(){
	Node xot;
	Lista dot[2];
	Node xp [5];
	xp[0].word  = "alto";
	xp[0].count = 3;
	xp[0].leave = 1;
	xp[1].word  = "nada";
	xp[1].count = 5;
	xp[1].leave = 1;
	xp[2].word  = "acho";
	xp[2].count = 1;
	xp[2].leave = 1;
	xp[3].word  = "carai";
	xp[3].count = 6; 
	xp[3].leave = 1;
	xp[4].word  = "pois";
	xp[4].count = 2;
	xp[4].leave = 1;

	/*
	PrintANode(xp,5);
	swap(xp[0], xp[3]);
	cout<<"---------------\n";
	PrintANode(xp,5);
	MakeHeap(xp,5);
	cout<<"---------------\n";
	PrintANode(xp,5);
	MergeNode(xp[0],xp[1],xot);
	PrintTree(&xot,'r');
	*/
	BuildHuffman(xp,dot,2,5);
	//cout<<"---------------\n";
	//PrintANode(xp,5);
	//PrintTree(&xp[0], 'r');
	//TreeWalk(&xp[0]);




	return 0;
}