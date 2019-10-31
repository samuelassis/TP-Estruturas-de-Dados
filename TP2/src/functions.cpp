#include "functions.h"
#include <string>
#include <iostream>


void CountingSort(int n, Planet main[], Planet result[]){
	int bigger = main[0];
	
	for(int i=0; i<n;i++){
		if(main[i] > bigger)
			bigger = main[i];
	}
	int indexes[bigger];
	
	for(i=0;i<bigger;i++){
		indexes[i] = 0;
	}
		
}
