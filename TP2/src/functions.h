#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <string>

struct Planet{
	int time;
	int month;
	std::string name;
};

void CountingSort(int,int,int, Planet[]);
void print_Parray(int,Planet[]);
void print_Iarray(int, int[]);
void Scheduler(int,int, Planet[]);
void MergeSort(Planet[], Planet[], int, int);
void Merge(Planet[], Planet[], int, int, int);
//void RadixSort();

#endif
