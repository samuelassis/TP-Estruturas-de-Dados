#include "functions.h"
#include "lista.h"
#include <iostream>


int operation (int quantity, Lista &master){
	Lista Accrued;
	Cell* it_master = master.first;
	//Check if the searched value is already in the master list and copy Master to Accrued
	for(int a=0; a<master.get_n_elements(); a++){
		it_master = it_master->next;
		if(it_master->value == quantity){
			return 1;
		}else{
			Accrued.add_element(it_master->value,1);
		}
	}

	Cell* it_accrued = Accrued.first->next;
	int s = 1;
	int sum, sub;
	bool found = false;
	//Sum and substract the elements from the lists until find the given value
	while(!found){
		it_master = master.first->next;
		for(int b=0;b<master.get_n_elements();b++){
			sum = it_master->value + it_accrued->value;
			sub = it_accrued->value - it_master->value;
			if(sum > 0)
				Accrued.add_element(sum, s+1);
			if(sub > 0)
				Accrued.add_element(sub,s+1);
			if((sum == quantity)||(sub == quantity)){
				found = true;
				if(Accrued.last->value == quantity)
					return Accrued.last->step;
				else if(Accrued.last->previous->value == quantity)
					return Accrued.last->previous->step;
			}
			it_master = it_master->next;
		}
		if(it_accrued->next->step != s)
			s++;		
		it_accrued = it_accrued->next;
	}
	
	/*
	bool x = false;
	Cell* cont = Accrued.last;
	while(!x){
		if(quantity == cont->value)
			return cont->step;
		cont = cont->previous;
	}
	*/
}
