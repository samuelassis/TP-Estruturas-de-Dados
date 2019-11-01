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

void CountingSort(int n, Planet main[], Planet result[]){
	int bigger = main[0].time;
	
	for(int i=0; i<n;i++){
		if(main[i].time > bigger)
			bigger = main[i].time;
	}
	
	int indexes[bigger+1];
	
	for(int i=0;i<bigger+1;i++){
		indexes[i] = 0;
	}

	for(int i=0; i<n; i++){
		indexes[main[i].time]++;
	}

	for(int i=1;i<bigger+1;i++){
		indexes[i] += indexes[i-1];
	}

	for(int i=n-1; 0 <= i ; i--){
		result[indexes[main[i].time] - 1].time = main[i].time;
		result[indexes[main[i].time] - 1].name = main[i].name;
		indexes[main[i].time]--;
	}
}
//void Scheduler(int n,int t_max,Planet planets[],Planet schedule[][]);
void Scheduler(int n,int t_max,Planet planets[],Planet schedule[][12]){
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
}
