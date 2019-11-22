
#include "lista.h"
#include "functions.h"
#include <string>
#include <cmath>
int hashing(std::string word, int size){
	char c;
	int value, weigth,code;
	code = 0;
	int i = 0;
	while(c != '\0'){
		weigth = pow(2, i+1);
		value = word[i] * weigth;
		code =+ value;
		c = word[i+1];
		i++;
	}
	return (code % size);
}