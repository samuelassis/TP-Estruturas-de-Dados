#define n_alphabet 26
#include "functions.h"
#include <string>
#include <iostream>

void print_Parray(int size, Planet array[]){
	for(int a = 0; a<size; a++){
		std::cout<<"["<< array[a].month<<"|"<< array[a].name <<"|"<< array[a].time<<"] ";
	}
}
void print_Iarray(int size, int array[]){
	for(int b=0; b<size; b++){
		std::cout<<"["<< array[b] <<"] ";
	}
}
void Merge(Planet main[], int l, int m, int r){ 
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
  
void MergeSort(Planet main[], int left, int right){ 
    if (left < right) { 
        int middle = left+(right-left)/2;
        MergeSort(main, left, middle); 
        MergeSort(main, middle+1, right); 
        Merge(main, left, middle, right); 
    } 
} 

void CountingSort(int begin, int end, int n_name, int n, Planet main[]){
	Planet* sorted = nullptr;
	int indexes[n_alphabet];
	int place;

	for(int j = n_name-1; j >= 0; j--){
		
		for(int i=0;i<n_alphabet;i++){
			indexes[i] = 0;
		}
//		std::cout<<"vai ir de "<<begin<<" a "<<end<<"\n";
		for(int i=begin; i<end; i++){
			indexes[((int)main[i].name[j]-97)]++;
//			std::cout<<"Letra: "<<main[i].name[j]<<" --> "<<(int)main[i].name[j]<<"-"<<(int)main[i].name[j]-97<<"\n";
		}
		//std::cout<<"\n index: ";
//		print_Iarray(n_alphabet, indexes);

		for(int i=1;i<n_alphabet;i++){
			indexes[i] += indexes[i-1];
		}

		sorted = new Planet[n];
		for(int i=end-1; begin <= i ; i--){
			place = (indexes[((int)main[i].name[j]-97)]-1)+begin;
			sorted[place].name = main[i].name;
			sorted[place].time = main[i].time;
			sorted[place].month = main[i].month;
			indexes[((int)main[i].name[j]-97)]--;
		}

		for(int i = 0; i < n; i++){
			main[i].time = sorted[i].time;
			main[i].name = sorted[i].name;
			main[i].month = sorted[i].month;
		}
		delete [] sorted;
	}
}

void SetMonth(Planet master[],int size, int t_max){
	int cont = 0;
	int m = 1;
	int i = 0;
	while(i < size){
		cont += master[i].time;
		if(cont <= t_max){
			master[i].month = m;
		}else{
			m++;
			master[i].month = m;
			cont = master[i].time;
		}
		i++;
	}
}

void Scheduler(int size,int max_t, int n_char, Planet planets[]){
	SetMonth(planets, size, max_t);
	std::cout<<"\n";
	//print_Parray(size,planets);

	int i = 0;
	int j = 1;
	while(j < size){
		if(planets[i].month < planets[j].month){
			CountingSort(i, j,n_char,size,planets);
			i = j;
		}
		j++;
	}
}
