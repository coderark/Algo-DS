#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where
// the pattern starts in the text.
vector<int> compute_prefix(const string& text){
    int l=text.length();
    vector<int> prefix(l);
    int border=0;
    prefix[0]=0;
    for(int i=1; i<l; i++){
        while(border>0 && text[border]!=text[i]){
            border=prefix[border-1];
        }
        if(text[border]==text[i]){
            border++;
        }
        else{
            border=0;
        }
        prefix[i]=border;
    }
    return prefix;
}

vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  string str=pattern+'$'+text;
  vector<int> prefix=compute_prefix(str);
  int pl=pattern.length(), l=str.length();
  for(int i=pl+1; i<l; i++){
      if(prefix[i]==pl){
          result.push_back(i-2*pl);
      }
  }
  // Implement this function yourself
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
