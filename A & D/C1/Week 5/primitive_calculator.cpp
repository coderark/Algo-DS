#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n) {
  vector<int> sequence, arr(n+1);
  arr[0]=0, arr[1]=0;
  for(int i=2; i<=n; i++){
    if(i%3==0 && i%2==0){
        int tempstep=min(min(arr[i/3], arr[i/2]), arr[i-1]);
        arr[i]=tempstep+1;
    }
    else if(i%3==0){
        int tempstep=min(arr[i/3], arr[i-1]);
        arr[i]=tempstep+1;
    }
    else if(i%2==0){
        int tempstep=min(arr[i/2], arr[i-1]);
        arr[i]=tempstep+1;
    }
    else{
        arr[i]=arr[i-1]+1;
    }
  }

  for(int i=n; i>1; ){
      sequence.push_back(i);
      if(i%3==0 && i%2==0){
          if(arr[i/3]<arr[i/2]){
              if(arr[i-1]<arr[i/3]){
                  i--;
              }
              else{
                  i/=3;
              }
          }
          else{
              if(arr[i-1]<arr[i/2]){
                  i--;
              }
              else{
                  i/=2;
              }
          }
      }
      else if(i%3==0){
          if(arr[i-1]<arr[i/3]){
              i--;
          }
          else{
              i/=3;
          }
      }
      else if(i%2==0){
          if(arr[i-1]<arr[i/2]){
              i--;
          }
          else{
              i/=2;
          }
      }
      else{
          i--;
      }
  }
  sequence.push_back(1);
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (int i = sequence.size()-1; i >=0; --i) {
    std::cout << sequence[i] << " ";
  }
}
