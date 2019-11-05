#define n_alphabet 26
#include "functions.h"
#include <string>
#include <iostream>

void print_Parray(int size, Planet array[]){
	for(int a = 0; a<size; a++){
		std::cout<<"["<< array[a].name <<"|"<< array[a].time<<"] ";
	}
}
void print_Iarray(int size, int array[]){
	for(int b=0; b<size; b++){
		std::cout<<"["<< array[b] <<"] ";
	}
}

void CountingSort(int n,int begin,int end, Planet main[]){
	Planet* sorted = nullptr
	int indexes[n_alphabet];
	
	for(int i=0;i<n_alphabet;i++){
		indexes[i] = 0;
	}

	for(int i=0; i<n; i++){
		indexes[main[i].time]++;
	}

	for(int i=1;i<bigger+1;i++){
		indexes[i] += indexes[i-1];
	}
	sorted = new Planet[n]
	for(int i=n-1; 0 <= i ; i--){
		sorted[indexes[main[i].time] - 1].time = main[i].time;
		sorted[indexes[main[i].time] - 1].name = main[i].name;
		indexes[main[i].time]--;
	}
	
	for(int i = 0; i < n; i++){
		main[i].time = sorted[i].time;
		main[i].name = sorted[i].name;
	}
	delete results [];
}

void Scheduler(int n,int t_max,Planet planets[]){
	/*
	int cont = 0;
	int j = 0;
	int k = 0;
	int i = 0;
	while(i < n-1){
		cont += planets[i].time;
		if(cont <= t_max){
			k++;
			schedule[k][j].time = planets[i].time;
			schedule[k][j].name = planets[i].name;
		}else{
			cont = planets[i].time;
			k = 0;
			j++;
			schedule[k][j].time = planets[i].time;
			schedule[k][j].name = planets[i].name;
		}
	i++;
	}
	*/
}
