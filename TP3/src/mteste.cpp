
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


int main(){
	Node xot;
	Lista dot[2];
	int a_size = 11;
	Node xp [a_size];
	for(int i=0;i<a_size;i++){
		xp[i].leave = 1;
		xp[i].right = nullptr;
		xp[i].left  = nullptr;
	}

	xp[0].word  ="acho";
	xp[0].count = 1;
	xp[1].word  ="mundo";
	xp[1].count = 1;
	xp[2].word  ="nao";
	xp[2].count = 1;
	xp[3].word  ="que";
	xp[3].count = 1;
	xp[4].word  ="todo";
	xp[4].count = 1;
	xp[5].word  ="nem";
	xp[5].count = 2;
	xp[6].word  ="ou";
	xp[6].count = 2;
	xp[7].word  ="vai";
	xp[7].count = 2;
	xp[8].word  ="ganhar";
	xp[8].count = 3;
	xp[9].word  ="quem";
	xp[9].count = 3;
	xp[10].word  ="perder";
	xp[10].count = 5;
	
	while(a_size !=2){
		Node*min1 = new Node();
		Node*min2 = new Node();
		Node marker;
		ExtractMin(xp,a_size, min1, min2);
		MergeNode(min1,min2,marker);
		swap(xp[0],marker);
		a_size--;		
	}
	Node tree;
	MergeNode(&xp[0],&xp[1], tree);
	//TreeWalk(&tree);
	printBT(&tree);
	
	/*

	if(xp[5].word < xp[9].word){
		cout<<"é menor\n";
	}else{
		cout<<"é maior\n";
	}

	
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
	//BuildHuffman(xp,dot,2,5);
	//cout<<"---------------\n";
	//PrintANode(xp,5);
	//PrintTree(&xp[0], 'r');
	//TreeWalk(&xp[0]);




	return 0;
}