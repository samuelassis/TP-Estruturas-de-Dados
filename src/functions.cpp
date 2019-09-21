#include "functions.h"
#include "lista.h"
#include <iostream>

void copy(Lista& main, Lista& copy){
	Cell* it_main = main.first;
	for(int i=0;i<main.get_n_elements();i++){
		it_main = it_main->next;
		copy.add_element(it_main->value);
	}
}

int operation (int quantity, Lista &master){
	bool flag = false;
	int sum, sub;
	int n_operation = 0;
	Cell* it_master = master.first;
	Lista accrued;
	Cell* it_accrued = accrued.first;
	copy(master,accrued);
	//while(flag == false){
		
		for(int i=0; i<master.get_n_elements(); i++){
			it_master = it_master->next;
			for(int j=0;j<master.get_n_elements();j++){
				it_accrued = it_accrued->next;
				
				sum = it_master->value + it_accrued->next->value;
				sub = it_master->value - it_accrued->next->value;
				if(sum > 0){
					accrued.add_element(sum);
				}
				if(sub > 0){
					accrued.add_element(sub);
				}
				if((sum == quantity)||(sub == quantity)){
					flag = true;					
				}
			}
	//	}
		n_operation++;
		std::cout<<"\nLista Master:\n";
		master.print_list();
		std::cout<<"\nLista Accrued:\n";
		accrued.print_list();
	}
	std::cout<<"\nOPERACOES: "<<n_operation<<std::endl;
	/*
	int size = master.get_n_elements();
	int containers [size];
	Lista* iterator = master->head
	for(int i = 0; i< size; )
	Lista sum_master;
	for(int i = 0; i < size; i++){
		int sum = containers[]
	}
	*/

	// achar o tamanho da lista master, os recipientes que tenho
	//chamar a função que soma e subtrai tudo e volta a lista
	//somar e subtrair cada valor em master um pelos outros e armazenar em sum

	//somar e subtrair cada valor de master pelos valores em sum ate achar o quantity(condição de parada: flag ser verdadeiro)

}