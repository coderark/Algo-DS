#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

int bipartite(vector<list<int> > &adj) {
  vector<int> color(adj.size(), 0);
  color[0]=1;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
      int u=q.front();
      q.pop();
      for(list<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++){
          if(color[*it]==0){
              q.push(*it);
              color[*it]=(-color[u]);
          }
          else{
              if(color[*it]==color[u]){
                  return 0;
              }
          }
      }
  }
  return 1;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<list<int> > adj(n, list<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  cout << bipartite(adj);
}
