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
      std::cout << operation(amount, Containers)<<std::endl;
    }else if(command == 'i'){
      Containers.add_element(amount,0);
    }else if(command == 'r'){
      Containers.remove_element(amount);
    }
  }
  return 0;
}
