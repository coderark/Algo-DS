#include <iostream>
#include <string>
#include <vector>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  int l1=str1.length();
  int l2=str2.length();
  vector<vector<int>> arr(l1+1, vector<int>(l2+1));
  for(int i=0; i<=l1; i++){
      arr[i][0]=i;
  }
  for(int i=0; i<=l2; i++){
      arr[0][i]=i;
  }
  for(int i=1; i<=l1; i++){
      for(int j=1; j<=l2; j++){
          int ins=arr[i-1][j]+1;
          int del=arr[i][j-1]+1;
          int mis=arr[i-1][j-1]+1;
          int mat=arr[i-1][j-1];
          if(str1[i-1]==str2[j-1]){
              arr[i][j]=min(min(ins, del), mat);
          }
          else{
              arr[i][j]=min(min(ins, del), mis);
          }
      }
  }
  return arr[l1][l2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
