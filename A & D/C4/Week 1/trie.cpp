#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  int t_nodes=1;
  for(int i=0; i<patterns.size(); i++){
    int c_node=0;
    for(int j=0; j<patterns[i].length(); j++){
        char c=patterns[i][j];
        if(!t.empty() && c_node<t.size() && t[c_node].find(c)!=t[c_node].end()){
            c_node=t[c_node][c];
        }
        else if(!t.empty() && c_node<t.size()){
            edges tmp;
            t[c_node][c]=t_nodes;
            t.push_back(tmp);
            c_node=t_nodes++;
        }
        else{
            edges tmp, tmp1;
            tmp[c]=(t_nodes);
            t.push_back(tmp);
            t.push_back(tmp1);
            c_node=t_nodes++;
        }
    }
  }
  return t;
}

int main() {
  size_t n;
  cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}
