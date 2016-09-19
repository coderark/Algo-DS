#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// int get_majority_element(vector<int> &a, int left, int right) {
//   if (left == right) return -1;
//   if (left + 1 == right) return a[left];
//   //write your code here
//   return -1;
// }

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  sort(a.begin(), a.end());
  int c=1, m=1;
  for(int i=1; i<n; i++){
      if(a[i]==a[i-1]){
          c++;
      }
      else{
          if(c>m){
              m=c;
          }
          c=1;
      }
  }
  if(c>m){
      m=c;
  }
  if(m>n/2){
      cout<<1<<endl;
  }
  else{
      cout<<0<<endl;
  }
}
