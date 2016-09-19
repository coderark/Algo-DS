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
int LtoI(char c){
    switch (c) {
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
        default:
            return 0;
    }
}

vector<int> SortCharacters(string& text){
    int l=text.length();
    vector<int> order(l), count(5, 0);
    for(int i=0; i<l; i++){
        count[LtoI(text[i])]++;
    }
    for(int i=1; i<5; i++){
        count[i]+=count[i-1];
    }
    for(int i=l-1; i>=0; i--){
        int ind=LtoI(text[i]);
        count[ind]--;
        order[count[ind]]=i;
    }
    return order;
}

vector<int> ComputeCharClasses(string& text, vector<int> order){
    int l=text.length();
    vector<int> classes(l);
    classes[order[0]]=0;
    for(int i=1; i<l; i++){
        if(text[order[i]]!=text[order[i-1]]){
            classes[order[i]]=classes[order[i-1]]+1;
        }
        else{
            classes[order[i]]=classes[order[i-1]];
        }
    }
    return classes;
}

vector<int> SortDoubled(string& text, int L, vector<int> order, vector<int> classes){
    int l=text.length();
    vector<int> newOrder(l), count(l, 0);
    for(int i=0; i<l; i++){
        count[classes[i]]++;
    }
    for(int i=1; i<l; i++){
        count[i]+=count[i-1];
    }
    for(int i=l-1; i>=0; i--){
        int st=(order[i]-L+l)%l;
        count[classes[st]]--;
        newOrder[count[classes[st]]]=st;
    }
    return newOrder;
}

vector<int> UpdateClasses(vector<int> newOrder, vector<int> classes, int L){
    int l=newOrder.size();
    vector<int> newClasses(l);
    newClasses[newOrder[0]]=0;
    for(int i=1; i<l; i++){
        int cur=newOrder[i], prev=newOrder[i-1], mid=cur+L, midPrev=(prev+L)%l;
        if(classes[cur]!=classes[prev] || classes[mid]!=classes[midPrev]){
            newClasses[cur]=newClasses[prev]+1;
        }
        else{
            newClasses[cur]=newClasses[prev];
        }
    }
    return newClasses;
}

vector<int> BuildSuffixArray(string& text) {
  vector<int> order, classes;
  order=SortCharacters(text);
  classes=ComputeCharClasses(text, order);
  int L=1, l=text.length();
  while(L<l){
      order=SortDoubled(text, L, order, classes);
      classes=UpdateClasses(order, classes, L);
      L*=2;
  }
  return order;
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
