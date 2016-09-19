#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.

struct bi{
    char c;
    int i;
};

bool comp(bi bi1, bi bi2){
    return bi1.c<bi2.c;
}

vector<int> InverseBWT(const string& bwt) {
  string text = "";
  int l=bwt.length();
  vector<bi> biv(l);
  for(int i=0; i<l; i++){
      biv[i].c=bwt[i];
      biv[i].i=i;
  }
  stable_sort(biv.begin(), biv.end(), comp);
  vector<int> index(l);
  for(int i=0; i<l; i++){
      //cout<<biv[i].c;
      index[biv[i].i]=i;
  }
  vector<int> res(l);
  int pos=0;
  for(int i=0; i<l; i++){
      res[pos]=l-i-1;
      pos=index[pos];
  }
  return res;
}

vector<int> BWT(const string& text) {
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
  return InverseBWT(result);
}

vector<int> BuildSuffixArray(const string& text) {
  return BWT(text);
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
