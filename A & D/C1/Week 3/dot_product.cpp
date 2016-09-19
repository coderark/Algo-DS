#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long min_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());
  for (int i = 0; i < a.size(); i++) {
    result += a[i] * (long long)b[i];
  }
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << min_dot_product(a, b) << std::endl;
}
