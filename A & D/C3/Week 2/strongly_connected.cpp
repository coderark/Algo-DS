#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int c=0;
bool exp1=false;
vector<int> porder, vorder;
void reach(vector<list<int>> &adj, vector<bool> &visited, int x){
    visited[x]=true;
    for(list<int>::iterator it=adj[x].begin(); it!=adj[x].end(); it++){
        if(!visited[*it]){
            reach(adj, visited, *it);
        }
    }
    if(!exp1){
        porder[x]=c;
        vorder[c]=x;
        c++;
    }
}

int number_of_strongly_connected_components(vector<list<int> > adj) {
  int result = 0;
  vector<bool> visited(adj.size(), false);
  for(int i=vorder.size()-1; i>=0; i--){
      if(!visited[vorder[i]]){
          reach(adj, visited, vorder[i]);
          result++;
      }
  }
  return result;
}

void dfs(vector<list<int> > adj){
    vector<bool> visited(adj.size(), false);
    for(int i=0; i<adj.size(); i++){
        if(!visited[i]){
            reach(adj, visited, i);
        }
    }
}

int main() {
  size_t n, m;
  cin >> n >> m;
  porder.resize(n);
  vorder.resize(n);
  vector<list<int> > adj(n, list<int>());
  vector<list<int> > adjR(n, list<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adjR[y - 1].push_back(x - 1);
  }
  dfs(adjR);
  exp1=true;
  cout << number_of_strongly_connected_components(adj);
}
