#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct node{
    int v, d;
    node(int v, int d):
        v(v), d(d) {}
};

bool priority(node a, node b){
    return a.d>b.d;
}

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
    priority_queue<node, vector<node>, function<bool(node, node)>> pq(priority);
    vector<bool> processed(adj.size(), false);
    vector<int> dist(adj.size(), 1000000);
    dist[s]=0;
    pq.push(node(s, 0));
    while(!pq.empty()){
        while(processed[pq.top().v]){
            pq.pop();
        }
        int u=pq.top().v;
        pq.pop();
        processed[u]=true;
        if(u==t){
            return dist[u];
        }
        for(int i=0; i<adj[u].size(); i++){
            if(!processed[adj[u][i]] && dist[adj[u][i]]>dist[u]+cost[u][i]){
                dist[adj[u][i]]=dist[u]+cost[u][i];
                pq.push(node(adj[u][i], dist[adj[u][i]]));
            }
        }
    }
  return -1;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  cin >> s >> t;
  s--, t--;
  cout << distance(adj, cost, s, t);
}
