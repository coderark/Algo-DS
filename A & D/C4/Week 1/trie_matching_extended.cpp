#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];
    bool leaf=false;
	Node ()
	{
		fill (next, next + Letters, NA);
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
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
		default: assert (false); return -1;
	}
}

vector<Node> build_trie(vector<string> &patterns){
    vector<Node> trie;
    int t_Nodes=1;
    for(int i=0; i<patterns.size(); i++){
        int c_Node=0;
        for(int j=0; j<patterns[i].length(); j++){
            char c=patterns[i][j];
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
            if(j+1==patterns[i].length()){
                trie[c_Node].leaf=true;     
            }
        }
    }
    return trie;
}

bool trie_matching(string &text, int ind, vector<Node> &trie){
    int c_Node=0;
    for(int i=ind; i<text.length() && !trie[c_Node].isLeaf(); i++){
        if(trie[c_Node].leaf){
            return true;
        }
        int chk=trie[c_Node].next[letterToIndex(text[i])];
        if(chk!=NA){
            c_Node=chk;
        }
        else{
            return false;
        }
    }
    if(trie[c_Node].isLeaf() || trie[c_Node].leaf){
        return true;
    }
    else{
        return false;
    }
}

vector <int> solve (string &text, int n, vector <string> &patterns)
{
	vector <int> result;
    vector<Node> trie=build_trie(patterns);
    for(int i=0; i<text.length(); i++){
        if(trie_matching(text, i, trie)){
            result.push_back(i);
        }
    }
	return result;
}

int main (void)
{
	string text;
	cin >> text;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (text, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
