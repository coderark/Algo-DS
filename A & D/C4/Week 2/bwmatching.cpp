#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Preprocess the Burrows-Wheeler Transform bwt of some text
// and compute as a result:
//   * starts - for each character C in bwt, starts[C] is the first position
//       of this character in the sorted array of
//       all characters of the text.
//   * occ_count_before - for each character C in bwt and each position P in bwt,
//       occ_count_before[C][P] is the number of occurrences of character C in bwt
//       from position 0 to position P inclusive.
void PreprocessBWT(const string& bwt, map<char, int>& starts, map<char, vector<int> >& occ_count_before) {
    int l=bwt.length();
    string bwts=bwt;
    sort(bwts.begin(), bwts.end());
    occ_count_before['A'].resize(l);
    occ_count_before['C'].resize(l);
    occ_count_before['G'].resize(l);
    occ_count_before['T'].resize(l);
    occ_count_before['$'].resize(l);
    occ_count_before['A'][0]=0;
    occ_count_before['C'][0]=0;
    occ_count_before['G'][0]=0;
    occ_count_before['T'][0]=0;
    occ_count_before['$'][0]=0;
    occ_count_before[bwt[0]][0]++;
    starts[bwts[0]]=0;
    for(int i=1; i<l; i++){
        char c=bwt[i];
        if(starts.find(bwts[i])==starts.end()){
            starts[bwts[i]]=i;
        }
        occ_count_before['A'][i]=occ_count_before['A'][i-1];
        occ_count_before['C'][i]=occ_count_before['C'][i-1];
        occ_count_before['G'][i]=occ_count_before['G'][i-1];
        occ_count_before['T'][i]=occ_count_before['T'][i-1];
        occ_count_before['$'][i]=occ_count_before['$'][i-1];
        occ_count_before[c][i]++;
    }
    // map<char, int>::iterator it=starts.begin();
    // while (it!=starts.end()) {
    //     cout<<it->first<<" "<<it->second<<" ";
    //     it++;
    // }
    // cout<<endl;
    // for(int i=0; i<l; i++){
    //     cout<<occ_count_before['A'][i]<<" ";
    // }
    // cout<<endl;
}

// Compute the number of occurrences of string pattern in the text
// given only Burrows-Wheeler Transform bwt of the text and additional
// information we get from the preprocessing stage - starts and occ_counts_before.
int CountOccurrences(const string& pattern, const string& bwt, map<char, int>& starts, map<char, vector<int> >& occ_count_before) {
    int l=bwt.length(), pl=pattern.length();
    int t=0, b=l-1, i=pl-1;
    while(t<=b){
        if(i>=0){
            char c=pattern[i--];
            if(bwt[t]!=c && occ_count_before[c][t]!=occ_count_before[c][b]){
                t=starts[c]+occ_count_before[c][t];
                b=starts[c]+occ_count_before[c][b]-1;
            }
            else if(bwt[t]==c){
                t=starts[c]+occ_count_before[c][t]-1;
                b=starts[c]+occ_count_before[c][b]-1;
            }
            else{
                return 0;
            }
        }
        else{
            return b-t+1;
        }
    }
}


int main() {
  string bwt;
  cin >> bwt;
  int pattern_count;
  cin >> pattern_count;
  // Start of each character in the sorted list of characters of bwt,
  // see the description in the comment about function PreprocessBWT
  map<char, int> starts;
  // Occurrence counts for each character and each position in bwt,
  // see the description in the comment about function PreprocessBWT
  map<char, vector<int> > occ_count_before;
  // Preprocess the BWT once to get starts and occ_count_before.
  // For each pattern, we will then use these precomputed values and
  // spend only O(|pattern|) to find all occurrences of the pattern
  // in the text instead of O(|pattern| + |text|).
  PreprocessBWT(bwt, starts, occ_count_before);
  for (int pi = 0; pi < pattern_count; ++pi) {
    string pattern;
    cin >> pattern;
    int occ_count = CountOccurrences(pattern, bwt, starts, occ_count_before);
    printf("%d ", occ_count);
  }
  printf("\n");
  return 0;
}
