#include <iostream>
#include <vector>

using std::vector;
using std::swap;

vector<int> partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  vector<int> part(2);
  int k=j;
  for(int i=j-1; i>=l; i--){
      if(a[i]==x){
          k--;
          swap(a[i], a[k]);
      }
  }
  part[0]=k;
  part[1]=j;
  return part;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> part(2);
  part = partition2(a, l, r);

  randomized_quick_sort(a, l, part[0]-1);
  randomized_quick_sort(a, part[1]+1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
