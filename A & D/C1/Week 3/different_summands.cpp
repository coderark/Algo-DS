#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int tmp=0, last=0;
  for(int i=1; i<(n-tmp)/2; i++){
      summands.push_back(i);
      last=i;
      tmp+=i;
  }
  if(tmp<n){
      if((n-tmp)%2==0){
          summands.push_back(n-tmp);
      }
      else{
          int x=(n-tmp)/2;
          int y=n-tmp-x;
          if(x==y || x<=last){
            summands.push_back(x+y);
          }
          else{
            summands.push_back(x);
            summands.push_back(y);
          }

      }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  //for(int j=1; j<=n; j++){
      vector<int> summands = optimal_summands(n);
      cout << summands.size() << '\n';
      for (int i = 0; i < summands.size(); ++i) {
        cout << summands[i] << ' ';
      }
      //cout<<endl;
  //}
}
