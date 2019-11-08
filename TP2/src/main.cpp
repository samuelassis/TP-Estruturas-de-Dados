#define prime 0

#include <cstdio>
#include <iostream>
#include "functions.h"

int main(){

  int t;
  int p;
  int c;
  Planet* planets = nullptr;
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
    MergeSort(planets, prime, p-1);
//    print_Parray(p, planets);
    Scheduler(p,t,c,planets);
//    std::cout<<"\n";
    print_Parray(p, planets);
  }
  delete [] planets;

  return 0;
}
