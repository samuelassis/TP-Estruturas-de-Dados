#include <cstdio>
#include <iostream>
#include "lista.h"
#include "functions.h"

void main() {
  int amount;
  Lista Containers;
  char command;
  while(scanf("%d %c", &amount, &command) != EOF) {
    if (command == 'p'){
      //Chama função de calcular operações
      std::cout << operation(amount, Containers)<<std::endl;
    }else if(command == 'i'){
      //Adiciona recipiente na lista
      Containers.add_element(amount);
    }else if(command == 'r'){
      //Remove recipiente da lista
      Containers.remove_elements(amount);
    }
  }
}
