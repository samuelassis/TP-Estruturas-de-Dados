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

void Merge(Planet main[],Planet sorted[], int begin, int middle, int end){
    int i, j, k,r;
    i = begin;
    j = middle + 1;
    k = begin;
    while(i <= middle && j <= end){
        if(sorted[i].time < sorted[j].time){
            main[k].time = sorted[i].time;
            main[k].name = sorted[i].name;
            i++;
        }
        else{
            main[k].time = sorted[j].time;
            main[k].name = sorted[j].name;
            j++;
        }
        k++;
    }
    while(i <= middle){
        main[k].time = sorted[i].time;
        main[k].name = sorted[i].name;
        i++;
        k++;
    }
    while(j <= end){
        main[k].time = sorted[j].time;
        main[k].name = sorted[j].name;
        j++;
        k++;
    }
    for(r = begin; r <= end; r++){
        sorted[r].time = main[r].time;
        sorted[r].name = main[r].name;
    }
}

void MergeSort(Planet main[], Planet sorted[], int begin, int end){
    if(begin < end){
        int middle = (begin + end) / 2;
        MergeSort(main, sorted, begin, middle);
        MergeSort(main, sorted, middle + 1, end);
        Merge(main, sorted, begin, middle, end);
    }
}

void CountingSort(int n,int begin,int end, Planet main[]){
	Planet* sorted = nullptr;
	int indexes[n_alphabet];
	
	for(int i=0;i<n_alphabet;i++){
		indexes[i] = 0;
	}

	for(int i=0; i<n; i++){
		indexes[main[i].time]++;
	}

	for(int i=1;i<n_alphabet;i++){
		indexes[i] += indexes[i-1];
	}
	sorted = new Planet[n];
	for(int i=n-1; 0 <= i ; i--){
		sorted[indexes[main[i].time] - 1].time = main[i].time;
		sorted[indexes[main[i].time] - 1].name = main[i].name;
		indexes[main[i].time]--;
	}
	
	for(int i = 0; i < n; i++){
		main[i].time = sorted[i].time;
		main[i].name = sorted[i].name;
	}
	delete [] sorted;
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
