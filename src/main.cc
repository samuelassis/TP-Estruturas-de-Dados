#include <cstdio>
#include <iostream>
#include "lista.h"
#include "functions.h"

int main() {
  int amount;
  Lista Containers;
  char command;
  while(scanf("%d %c", &amount, &command) != EOF) {
    if (command == 'p'){
      //Chama função de calcular operações
      std::cout << operation(amount, Containers)<<std::endl;
    }else if(command == 'i'){
      //Adiciona recipiente na lista
      Containers.add_element(amount,0);
    }else if(command == 'r'){
      //Remove recipiente da lista
      Containers.remove_element(amount);
    }
  }
  return 0;
}
