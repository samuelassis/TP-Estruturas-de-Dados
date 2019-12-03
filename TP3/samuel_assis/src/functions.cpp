
#include "lista.h"
#include "functions.h"
#include "huffman.h"
#include <string>
#include <cmath>
#include <iostream>
int hashing(std::string word, int size){
	char c;
	int value, weigth,code;
	code = 0;
	int i = 0;
	while(c != '\0'){
		weigth = (pow(2,i*0.5)*31);
		value = word[i] * weigth;
		code =+ value;
		c = word[i+1];
		i++;
	}
	return (code % size);
}

int n_words(Lista table[],int size){
	int acc = 0;
	for(int i=0; i<size; i++){
		acc += table[i].get_n_elements();
	}
	return acc;
}

void data_transfer(Node a_data[], Lista table[], int size){
	int l_size;
	int index = 0;
	Cell* c_aux;
	for(int i=0; i<size;i++){
		l_size = table[i].get_n_elements();
		c_aux = table[i].first;
		if(l_size > 0){
			for(int j=0; j<l_size;j++){
				c_aux = c_aux->next;
				a_data[index].word  = c_aux->term;
				a_data[index].count = c_aux->count;
				a_data[index].leave = 1;
				a_data[index].right = nullptr;
				a_data[index].left  = nullptr;
				index++;
			}
		}

	}
}