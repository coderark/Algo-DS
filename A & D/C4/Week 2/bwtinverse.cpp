#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct bi{
    char c;
    int i;
};

bool comp(bi bi1, bi bi2){
    return bi1.c<bi2.c;
}

string InverseBWT(const string& bwt) {
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
  //cout<<endl;
  int pos=0;
  for(int i=0; i<l; i++){
      text+=biv[pos].c;
      pos=index[pos];
  }
  reverse(text.begin(), text.end());
  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
