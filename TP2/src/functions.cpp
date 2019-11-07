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
void Merge(Planet main[], int l, int m, int r) 
{ 
    int i, j, k; 
    int size_l = m - l + 1; 
    int size_r =  r - m; 
  
    Planet* L = new Planet [size_l];
    Planet* R = new Planet [size_r]; 
    for (i = 0; i < size_l; i++){
		L[i].time = main[l + i].time; 
		L[i].name = main[l + i].name; 
    }
    for (j = 0; j < size_r; j++){
		R[j].time = main[m + 1+ j].time;
		R[j].name = main[m + 1+ j].name;
    }
    i = 0;
    j = 0;
    k = l;
    while (i < size_l && j < size_r) { 
        if (L[i].time <= R[j].time) 
        { 
            main[k].time = L[i].time; 
            main[k].name = L[i].name;
            i++; 
        } 
        else
        { 
            main[k].time = R[j].time;
            main[k].name = R[j].name;
            j++; 
        } 
        k++; 
    } 

    while (i < size_l) { 
        main[k].time = L[i].time; 
        main[k].name = L[i].name;
        i++; 
        k++; 
    } 
    while (j < size_r) { 
        main[k].time = R[j].time;
        main[k].name = R[j].name;
        j++; 
    	k++; 
    }
    delete[] L;
    delete[] R;
} 
  
void MergeSort(Planet main[], int left, int right) 
{ 
    if (left < right) { 
        int middle = left+(right-left)/2;
        MergeSort(main, left, middle); 
        MergeSort(main, middle+1, right); 
        Merge(main, left, middle, right); 
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
