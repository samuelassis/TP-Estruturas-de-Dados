#include "lista.h"
#include <iostream>

Lista::Lista(){
	Cell head = new Cell();
	head->next = head->previous = nullptr;
	first* = last* = head;
	head.value = NULL;
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

Lista::add_element(int element){
	Cell newbie = new Cell();
	newbie->next = nullptr;
	newbie->previous = last;
	last = newbie;
	n_elements++;
}

Lista::remove_element(int element){
	int i;
	bool found;
	Cell* removed = first;
	while((found == false) && (i < n_elements)){
		removed = removed->next;
		if (removed.value == element){
			found = true;
		}
		i++
	}
	if(removed->next == nullptr){
		last = removed->previous;
		removed->previous->next = nullptr;
		delete removed;
	}else{
		removed->previous->next = removed->next;
		removed->next->previous = removed->previous;
		delete removed;
	}
}

Lista::print_list(){
	Cell* aux = first->next;
	for(int i=0; i <n_elements; i++){
		std::cout<<" ["<<aux.value<<"] "<<;
	}
}

