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
	std::cout<<"\nmaior = "<<bigger<<"\n";
	
	int indexes[bigger+1];
	
	for(int i=0;i<bigger+1;i++){
		indexes[i] = 0;
	}

	for(int i=0; i<n; i++){
		indexes[main[i].time]++;
	}
	std::cout<<"\ncontou valores main\n";
	
	print_Iarray(bigger+1, indexes);
	for(int i=1;i<bigger+1;i++){
		indexes[i] += indexes[i-1];
	}
	std::cout<<"\nsomou indexes\n";
	print_Iarray(bigger+1,indexes);
	for(int i=n; 0 < i ; i--){
		std::cout<<"ENTROU no role"<< i;
		result[indexes[main[i].time]-1].time = main[i].time;
		result[indexes[main[i].time]-1].name = main[i].name;
		indexes[main[i].time]--;
	}
	std::cout<<"\ntrocou os vetores\n";
}
