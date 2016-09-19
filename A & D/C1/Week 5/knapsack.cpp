#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int numw=w.size();
  vector<vector<int>> arr(numw+1, vector<int>(W+1));
  for(int i=0; i<=numw; i++){
      arr[i][0]=0;
  }

  for(int i=0; i<=W; i++){
      arr[0][i]=0;
  }
  for(int i=1; i<=numw; i++){
      for(int j=1; j<=W; j++){
          arr[i][j]=arr[i-1][j];
          if(j-w[i-1]>=0 && arr[i][j]<arr[i-1][j-w[i-1]]+w[i-1]){
              arr[i][j]=arr[i-1][j-w[i-1]]+w[i-1];
          }
      }
  }
  return arr[numw][W];
}

int main() {
  int n, W;
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
