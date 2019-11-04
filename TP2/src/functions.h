#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <string>

struct Planet{
	int time;
	std::string name;
	int month;
};

void CountingSort(int, Planet[], Planet[]);
void print_Parray(int,Planet[]);
void print_Iarray(int, int[]);
void Scheduler(int,int, Planet[]);
//void RadixSort();

#endif
