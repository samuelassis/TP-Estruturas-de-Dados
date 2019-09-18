#include "lista.h"
#include <iostream>

Lista::Lista(){
	Cell* head = new Cell();
	first = head;
	last = head;
	head->next = head->previous = nullptr;
	head->value = 0;
	n_elements = 0;
}

Lista::~Lista(){
	Cell* a = first;
	Cell* b = nullptr;
	
	while(b!= nullptr){
		b = a;
		a = b->next;
		delete b;
	}
}

void Lista::add_element(int element){
	Cell* newbie = new Cell();
	newbie->value = element;
	
	if(n_elements == 0){ // Tests if insertion is the first
		first->next = newbie;
		newbie->previous = first;
		newbie->next = nullptr;
		last = newbie;
	}else{	
		last->next = newbie;
		newbie->previous = last;
		newbie->next = nullptr;
		last = newbie;	
	}
	n_elements++;
}

void Lista::remove_element(int element){
	int i = 0;
	bool found = false;
	Cell* removed = first;
	while((found == false) && (i < n_elements)){ // Browse list for the element
		removed = removed->next;
		if (removed->value == element){
			found = true;
		}
		i++;
	}
	if(found == true){ // Tests if the element exists on the list and where it's
		if(removed->next == nullptr){
			last = removed->previous;
			removed->previous->next = nullptr;
		}else{
			removed->previous->next = removed->next;
			removed->next->previous = removed->previous;
		}
		delete removed;
		n_elements--;
	}
}

void Lista::print_list(){
	Cell* aux = first;
	int i;
	for(i =0; i < n_elements; i++){
		aux = aux->next;
		std::cout<<" ["<<aux->value<<"] ";
	}
}

int Lista::get_n_elements(){
	return n_elements;
}
