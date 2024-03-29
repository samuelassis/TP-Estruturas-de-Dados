#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <string>

struct Planet{
	int time;
	int month;
	std::string name;
};

void CountingSort(int, int, int, Planet[], Planet[]);
void print_Parray(int, Planet[]);
void Scheduler(int, int, int, Planet[]);
void MergeSort(Planet[], int, int);
void Merge(Planet[], int, int, int);
void SetMonth(Planet[],int,int);

#endif
