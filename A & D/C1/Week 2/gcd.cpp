#include <iostream>

using namespace std;
int gcd(int a, int b) {
  //write your code here
  if (a%b==0) {
      return b;
  }
  return gcd(b, a%b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  if(a>b){
      std::cout << gcd(a, b) << std::endl;
  }
  else{
      std::cout << gcd(b, a) << std::endl;
  }

  return 0;
}
