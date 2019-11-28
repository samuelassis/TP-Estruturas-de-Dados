#include "lista.h"
#include <iostream>

Lista::Lista(){
	Cell* head = new Cell();
	first = head;
	last = head;
	head->next = head->previous = nullptr;
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
	delete a;
}

void Lista::add_element(std::string element){
	Cell* newbie = new Cell();
	newbie->term = element;
	
	if(n_elements == 0){ // Tests if insertion is the first
		first->next = newbie;
		newbie->previous = first;
		newbie->next = nullptr;
		last = newbie;
		newbie->count = 1;
	}else{	
		last->next = newbie;
		newbie->previous = last;
		newbie->next = nullptr;
		last = newbie;
		newbie->count = 1;
	}
	n_elements++;
}

void Lista::remove_element(std::string element){
	int i = 0;
	bool found = false;
	Cell* removed = first;
	while((found == false) && (i < n_elements)){ // Browse list for the element
		removed = removed->next;
		if (removed->term == element){
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
		std::cout<<" ["<<aux->term<<"/"<<aux->count<<"] ";
	}
}

void Lista::incremental(std::string text){
	
	if(n_elements == 0){
		add_element(text);
		return;
	}

	Cell *it = first->next;
	bool flag = false;
	for(int i=0; i < n_elements; i++){
		if((it->term.compare(text)) == 0){
			it->count++;
			flag = true;
		}
		it = it->next;
	}
	if(!flag){
		add_element(text);
	}
}
void Lista::search(std::string text ,Cell& node){
	Cell* aux = first->next;
	for(int i=0; i <this->n_elements; i++){
		if(aux->term == text){
			node.term = aux->term;
			node.count = aux->count;
		}
		aux = aux->next;
	}
}


int Lista::get_n_elements(){
	return n_elements;
}
