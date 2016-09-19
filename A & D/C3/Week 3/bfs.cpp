#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int distance(vector<list<int> > &adj, int s, int t) {
  queue<int> q;
  vector<int> dist(adj.size(), 1000000);
  dist[s]=0;
  q.push(s);
  while(!q.empty()){
      int u=q.front();
      q.pop();
      for(list<int>::iterator it=adj[u].begin(); it!=adj[u].end(); it++){
          if(dist[*it]==1000000){
              if((*it)==t){
                  return dist[u]+1;
              }
              q.push(*it);
              dist[*it]=dist[u]+1;
          }
      }
  }
  return -1;
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
  int s, t;
  cin >> s >> t;
  s--, t--;
  cout << distance(adj, s, t);
}
