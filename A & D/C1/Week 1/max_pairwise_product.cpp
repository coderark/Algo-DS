#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  long long max1 = -1, max2=-2;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    if(numbers[i]>=max2){
        if (numbers[i]>=max1) {
            max2=max1;
            max1=numbers[i];
        }
        else{
            max2=numbers[i];
        }
    }
  }
  return max1*max2;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
