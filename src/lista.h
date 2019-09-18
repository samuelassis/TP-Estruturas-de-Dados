#ifndef LISTA_H
#define LISTA_H

struct Cell{
	int value;
	Cell* next;
	Cell* previous;
};

class Lista{
	private:
		Cell* first;
		Cell* last;
		int n_elements;
	public:
		Lista();
		~Lista();
		void add_element(int);
		void remove_element(int);
		void print_list();
		int get_n_elements();
};

#endif
