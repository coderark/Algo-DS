#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    5;
int const NA      =   -1;

struct Node
{
	int next [Letters];

	Node ()
	{
		fill (next, next + Letters, NA);
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA && next[4]==NA);
	}
};

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
    case '$': return 4; break;
		default: assert (false); return -1;
	}
}

vector<Node> build_trie(string &text){
    vector<Node> trie;
    int t_Nodes=1;
    for(int i=0; i<text.length(); i++){
        int c_Node=0;
        for(int j=i; j<text.length(); j++){
            char c=text[j];
            if(trie.empty()){
                Node tmp, tmp1;
                tmp.next[letterToIndex(c)]=t_Nodes;
                trie.push_back(tmp);
                trie.push_back(tmp1);
                c_Node=t_Nodes++;
            }
            else if(trie[c_Node].next[letterToIndex(c)]==NA){
                Node tmp;
                trie[c_Node].next[letterToIndex(c)]=t_Nodes;
                trie.push_back(tmp);
                c_Node=t_Nodes++;
            }
            else{
                c_Node=trie[c_Node].next[letterToIndex(c)];
            }
        }
    }
    return trie;
}

void suffix(int node, string s, vector<string> &result, vector<Node> &trie){
  if(trie[node].isLeaf()){
    result.push_back(s);
    return;
  }
  if((trie[node].next[0]!=NA && trie[node].next[1]==NA && trie[node].next[2]==NA && trie[node].next[3]==NA && trie[node].next[4]==NA) || (trie[node].next[0]==NA && trie[node].next[1]!=NA && trie[node].next[2]==NA && trie[node].next[3]==NA && trie[node].next[4]==NA) || (trie[node].next[0]==NA && trie[node].next[1]==NA && trie[node].next[2]!=NA && trie[node].next[3]==NA && trie[node].next[4]==NA) || (trie[node].next[0]==NA && trie[node].next[1]==NA && trie[node].next[2]==NA && trie[node].next[3]!=NA && trie[node].next[4]==NA) || (trie[node].next[0]==NA && trie[node].next[1]==NA && trie[node].next[2]==NA && trie[node].next[3]==NA && trie[node].next[4]!=NA)){
    if(trie[node].next[0]!=-1){
      suffix(trie[node].next[0], s.append("A"), result, trie);
    }
    else if(trie[node].next[1]!=-1){
      suffix(trie[node].next[1], s.append("C"), result, trie);
    }
    else if(trie[node].next[2]!=-1){
      suffix(trie[node].next[2], s.append("G"), result, trie);
    }
    else if(trie[node].next[3]!=-1){
      suffix(trie[node].next[3], s.append("T"), result, trie);
    }
    else{
      suffix(trie[node].next[4], s.append("$"), result, trie);
    }
  }
  else{
    result.push_back(s);
    if(trie[node].next[0]!=-1){
      suffix(trie[node].next[0], "A", result, trie);
    }
    if(trie[node].next[1]!=-1){
      suffix(trie[node].next[1], "C", result, trie);
    }
    if(trie[node].next[2]!=-1){
      suffix(trie[node].next[2], "G", result, trie);
    }
    if(trie[node].next[3]!=-1){
      suffix(trie[node].next[3], "T", result, trie);
    }
    if(trie[node].next[4]!=-1){
      suffix(trie[node].next[4], "$", result, trie);
    }
  }

}

// Build a suffix tree of the string text and return a vector
// with all of the labels of its edges (the corresponding
// substrings of the text) in any order.
vector<string> ComputeSuffixTreeEdges(string text) {
  vector<string> result;
  vector<Node> trie=build_trie(text);
  suffix(0, "", result, trie);
  return result;
}

int main() {
  string text;
  cin >> text;
  vector<string> edges = ComputeSuffixTreeEdges(text);
  for (int i = 0; i < edges.size(); ++i) {
    if(edges[i].compare("")){
      cout << edges[i] << endl;
    }
  }
  return 0;
}
