#define prime 0

#include <cstdio>
#include <iostream>
#include "functions.h"

int main() {

  int t;
  int p;
  int c;
  Planet* planets = nullptr;
  Planet* order_planets = nullptr;
  int period;
  std::string planet_tag;
  while(scanf("%d %d %d", &t, &p, &c) != EOF) {
	planets = new Planet [p];
	order_planets = new Planet [p];
    for(int i=0; i<p; i++){
    	std::cin>> period;
    	std::cin>> planet_tag;
    	planets[i].time = period;
    	planets[i].name = planet_tag;
    }
    print_Parray(p,planets);
   	//print_Parray(p, order_planets);
    //Chamar o a Merge e ordenar planets por tempo (com o limite t);
    MergeSort(planets,order_planets, prime, p-1);
    delete [] planets;
    print_Parray(p, order_planets);
    //Jogar os planetas de cada mes em months
    //Scheduler(p,t,order_planets);
    //Chamar Radix e ordenar cada posição pelo nome dos planetas
  }
   
   delete [] order_planets;

  return 0;
}
