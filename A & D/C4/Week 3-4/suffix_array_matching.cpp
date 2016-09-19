#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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


vector<int> FindOccurrences(const string& pattern, const string& text, const vector<int>& suffix_array) {
  vector<int> result;

  return result;
}

int main() {
  char buffer[100001];
  scanf("%s", buffer);
  string text = buffer;
  text += '$';
  vector<int> suffix_array = BuildSuffixArray(text);
  int pattern_count;
  scanf("%d", &pattern_count);
  vector<bool> occurs(text.length(), false);
  for (int pattern_index = 0; pattern_index < pattern_count; ++pattern_index) {
    scanf("%s", buffer);
    string pattern = buffer;
    vector<int> occurrences = FindOccurrences(pattern, text, suffix_array);
    for (int j = 0; j < occurrences.size(); ++j) {
      occurs[occurrences[j]] = true;
    }
  }
  for (int i = 0; i < occurs.size(); ++i) {
    if (occurs[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}
