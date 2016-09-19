#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(const vector<int> &a, int x, int l, int r) {
   if(l>r){
       return -1;
   }
   int m=l+(r-l+1)/2;
   if(a[m]==x){
       return m;
   }
   else if(a[m]<x){
       binary_search(a, x, m+1, r);
   }
   else{
       binary_search(a, x, l, m-1);
   }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin>>a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin>>b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    cout<<binary_search(a, b[i], 0, n-1)<<' ';
  }
}
