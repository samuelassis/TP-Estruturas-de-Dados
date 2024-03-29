#ifndef LISTA_H
#define LISTA_H

struct Cell{
	int value;
	int step;
	Cell* next;
	Cell* previous;
};

struct Lista{
	Cell* first;
	Cell* last;
	int n_elements;

	Lista();
	~Lista();
	void add_element(int,int);
	void remove_element(int);
	void print_list();
	int get_n_elements();
};

#endif
