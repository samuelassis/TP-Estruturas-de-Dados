#include "lista.h"
#include "functions.h"
#include <iostream>
using namespace std;
int main(){
	Lista teste;
	teste.add_element(10);
	teste.add_element(30);
	operation(100,teste);
	/*
	for(int i = 1; i <= 20; i++){
		if(i % 2 != 0){
			teste.add_element(i);	
		}	
	}
	cout<<teste.get_n_elements()<<endl;
	
	
	cout << "\n#-#-#-#-#-#-#-#-#-#-#-Teste de Remocao-#-#-#-#-#-#-#-#-#-#-#-#-#"<<endl;
	
	for(int k = 0;teste.get_n_elements() != 0; k++){
		cout<<"Lista:"<<endl;
		teste.print_list();
		cout<<"\nEscolha um valor a ser removido:";

		cin >> x;
		teste.remove_element(x);
	}
	*/

return 0;
}