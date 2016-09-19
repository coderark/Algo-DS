#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct knp{
    int weight, value;
    double vpu;
} ;

bool comp(knp a, knp b){
    return a.vpu>b.vpu;
}

double get_optimal_value(int capacity, vector<knp> vec) {
  double value = 0.0;
  sort(vec.begin(), vec.end(), comp);
  // for(int i=0; i<vec.size(); i++){
  //     std::cout << vec[i].vpu<< std::endl;
  // }
  // write your code here
  for(int i=0; i<vec.size() && capacity>0; i++){
      if(vec[i].weight>capacity){
          value+=capacity*vec[i].vpu;
          return value;
      }
      capacity-=vec[i].weight;
      value+=vec[i].value;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<knp> vec(n);
  for (int i = 0; i < n; i++) {
    std::cin >> vec[i].value >> vec[i].weight;
    vec[i].vpu=vec[i].value/(double)vec[i].weight;
  }

  double optimal_value = get_optimal_value(capacity, vec);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
