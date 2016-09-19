#include <iostream>

using namespace std;
int get_fibonacci_last_digit(int n) {
  int a=0, b=1;
  for(int i=2; i<n+1; i++){
      int temp=a;
      a=b;
      b=(b+temp)%10;
  }
  return b;
}

int main() {
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
