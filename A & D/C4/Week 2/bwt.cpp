#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string BWT(const string& text) {
  string result = "";
  int l=text.length();
  vector<string> mat(l);
  for(int i=0; i<l; i++){
      string tmp=text.substr(i, l-i).append(text, 0, i);
      mat[i]=tmp;
  }
  sort(mat.begin(), mat.end());
  for(int i=0; i<l; i++){
      result+=mat[i][l-1];
  }
  return result;
}

int main() {
  string text;
  cin >> text;
  cout<<BWT(text)<<endl;
  return 0;
}
