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

void Merge(int *saida, int *auxiliar, int inicio, int meio, int fim){
    int i, j, k;
    i = inicio;
    j = meio + 1;
    k = inicio;
    while(i <= meio && j <= fim){
        if(auxiliar[i] < auxiliar[j]){
            saida[k] = auxiliar[i];
            i++;
        }
        else{
            saida[k] = auxiliar[j];
            j++;
        }
        k++;
    }
    while(i <= meio){
        saida[k] = auxiliar[i];
        i++;
        k++;
    }
    while(j <= fim){
        saida[k] = auxiliar[j];
        j++;
        k++;
    }
    //Copia os elementos que foram ordenados para o auxiliar
    for(int p = inicio; p <= fim; p++)
        auxiliar[p] = saida [p];
}

void MergeSort(/*int *saida, int *auxiliar, int inicio, int fim*/){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        mergeSort(saida, auxiliar, inicio, meio);
        mergeSort(saida, auxiliar, meio + 1, fim);
        merge(saida, auxiliar, inicio, meio, fim);
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
