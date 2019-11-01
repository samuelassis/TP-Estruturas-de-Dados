#define n_months 12

#include <cstdio>
#include <iostream>
#include "functions.h"

int main() {
  int t;
  int p;
  int c;
  Planet* planets = nullptr;
  Planet* order_planets = nullptr;
  Planet* months = nullptr;
  int period;
  std::string planet_tag;
  while(scanf("%d %d %d", &t, &p, &c) != EOF) {
	planets = new Planet [p];
	order_planets = new Planet [p];
	months = new Planet[p][n_months];
    for(int i=0; i<p; i++){
    	std::cin>> period;
    	std::cin>> planet_tag;
    	planets[i].time = period;
    	planets[i].name = planet_tag;
    }
    print_Parray(p,planets);
    print_Parray(p, order_planets);
    //Chamar o a Counting e ordenar planets por tempo (com o limite t);
    CountingSort(p, planets,order_planets);
    print_Parray(p, order_planets);
    //Jogar os planetas de cada mes em months
    Scheduler(p,t,order_planets, months);
    //Chamar Radix e ordenar cada posição pelo nome dos planetas
    

  }
   delete [] planets;
   delete [] order_planets;
   delete [] months;
  return 0;
}
