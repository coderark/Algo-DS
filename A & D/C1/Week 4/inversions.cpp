#include <iostream>
#include <vector>

using namespace std;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, int left, int right) {
  long long number_of_inversions = 0;
  //cout<<left<<' '<<right<<endl;
  if (right <= left){
      return number_of_inversions;
  }
  int ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  int m=ave+1, l=left;
  for(int i=l; i<=right; i++){
      b[i]=a[i];
  }
  int i;
  for(i=l; l<=ave && m<=right; i++){
      if(b[l]<=b[m]){
          a[i]=b[l];
          l++;
      }
      else{
          number_of_inversions+=(long long)(ave-l+1);
          a[i]=b[m];
          m++;
      }
  }
  while(l<=ave){
      a[i]=b[l];
      l++;
      i++;
  }
  while(m<=right){
      a[i]=b[m];
      m++;
      i++;
  }
  // for(i=left; i<=right; i++){
  //     cout<<a[i]<<' ';
  // }
  // cout<<endl;
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (int i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
