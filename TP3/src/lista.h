#ifndef LISTA_H
#define LISTA_H

#include <string>

struct Cell{
	std::string term;
	int count;
	std::string code;
	Cell* next;
	Cell* previous;
};

struct Lista{
	Cell* first;
	Cell* last;
	int n_elements;

	Lista();
	~Lista();
	void add_element(std::string);
	void remove_element(std::string);
	void print_list();
	void incremental(std::string);
	void set_code(std::string,std::string);
	int get_n_elements();
	void search(std::string,Cell&);
};

#endif
