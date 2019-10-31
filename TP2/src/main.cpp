#define n_months 12

#include <cstdio>
#include <iostream>
#include "functions.h"

int main() {
  int t;
  int p;
  int c;
  Planet* planets = nullptr;
  //Planet* months = nullptr;
  Planet months[n_months];
  int period;
  std::string planet_tag;
  while(scanf("%d %d %d", &t, &p, &c) != EOF) {
	planets = new Planet [p];   
    for(int i=0; i<p; i++){
    	std::cin>> period;
    	std::cin>> planet_tag;
    	planets[i].time = period;
    	planets[i].name = planet_tag;
    }
    //Chamar o a Counting e ordenar planets por tempo (com o limite t);
    
    //Jogar os planetas de cada mes em months
    
    //Chamar Radix e ordenar cada posição pelo nome dos planetas
    
    delete [] planets;
  }
  return 0;
}
